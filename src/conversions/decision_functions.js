/* eslint-disable no-magic-numbers */

const add_linear_df = (impl, function_type, sample_type, idltype) => {
    impl.push(`
        #include "Dlib_${ function_type }_Object.h"

        STDMETHODIMP CDlib_${ function_type }_Object::get_weights(${ idltype }* pVal) {
            CActCtxActivator ScopedContext(ExtendedHolder::_ActCtx);

            if (__self) {
                auto& df = *__self->get();
                return autoit_from(_get_weights<${ function_type }>(df), pVal);
            }
            return E_FAIL;
        }

        STDMETHODIMP CDlib_${ function_type }_Object::get_bias(DOUBLE* pVal) {
            CActCtxActivator ScopedContext(ExtendedHolder::_ActCtx);

            if (__self) {
                auto& df = *__self->get();
                return autoit_from(_get_bias<${ function_type }>(df), pVal);
            }
            return E_FAIL;
        }

        STDMETHODIMP CDlib_${ function_type }_Object::put_bias(DOUBLE newVal) {
            CActCtxActivator ScopedContext(ExtendedHolder::_ActCtx);

            if (__self) {
                auto& df = *__self->get();
                _set_bias<${ function_type }>(df, newVal);
                return S_OK;
            }
            return E_FAIL;
        }

        const double CDlib_${ function_type }_Object::call(${ sample_type }& sample, HRESULT& hr) {
            hr = S_OK;
            auto& df = *__self->get();
            return _predict<${ function_type }>(df, sample);
        }
    `.trim().replace(/^ {8}/mg, ""));
};

const add_df = (impl, function_type, sample_type) => {
    impl.push(`
        #include "Dlib_${ function_type }_Object.h"

        STDMETHODIMP CDlib_${ function_type }_Object::get_basis_vectors(VARIANT* pVal) {
            CActCtxActivator ScopedContext(ExtendedHolder::_ActCtx);

            if (__self) {
                auto& df = *__self->get();
                std::vector<sample_type> temp;
                for (long i = 0; i < df.basis_vectors.size(); ++i)
                    temp.push_back(sparse_to_dense(df.basis_vectors(i)));
                return autoit_from(temp, pVal);
            }
            return E_FAIL;
        }

        const double CDlib_${ function_type }_Object::call(${ sample_type }& sample, HRESULT& hr) {
            hr = S_OK;
            auto& df = *__self->get();
            return _predict<${ function_type }>(df, sample);
        }
    `.trim().replace(/^ {8}/mg, ""));
};

const add_normalized_df = (impl, function_type, sample_type) => {
    impl.push(`
        #include "Dlib_${ function_type }_Object.h"

        STDMETHODIMP CDlib_${ function_type }_Object::get_basis_vectors(VARIANT* pVal) {
            CActCtxActivator ScopedContext(ExtendedHolder::_ActCtx);

            if (__self) {
                auto& df = __self->get()->function;
                std::vector<sample_type> temp;
                for (long i = 0; i < df.basis_vectors.size(); ++i)
                    temp.push_back(sparse_to_dense(df.basis_vectors(i)));
                return autoit_from(temp, pVal);
            }
            return E_FAIL;
        }

        const double CDlib_${ function_type }_Object::call(${ sample_type }& sample, HRESULT& hr) {
            hr = S_OK;
            auto& df = *__self->get();
            return normalized_predict<${ function_type }>(df, sample);
        }

        const std::vector<double> CDlib_${ function_type }_Object::batch_predict(std::vector<${ sample_type }>& samples, HRESULT& hr) {
            hr = S_OK;
            auto& df = *__self->get();
            return normalized_predict_vec<${ function_type }>(df, samples);
        }

        const std::vector<double> CDlib_${ function_type }_Object::batch_predict(cv::Mat& samples, HRESULT& hr) {
            hr = S_OK;
            auto& df = *__self->get();
            return normalized_predict_vec<${ function_type }>(df, Mat_to_vector_sample_type(samples));
        }
    `.trim().replace(/^ {8}/mg, ""));
};

const setup_auto_train_rbf_classifier = impl => {
    impl.push(`
        #include "Dlib_Object.h"

        const _normalized_decision_function_radial_basis CDlib_Object::reduce(
            _normalized_decision_function_radial_basis& df,
            std::vector<sample_type>& x,
            long num_bv,
            double eps,
            HRESULT& hr
        ) {
            hr = S_OK;
            auto out = df;
            // null_trainer doesn't use y so we can leave it empty.
            std::vector<double> y;
            out.function = reduced2(null_trainer(df.function),num_bv,eps).train(x,y);
            return out;
        }

        const _normalized_decision_function_radial_basis CDlib_Object::reduce(
            _normalized_decision_function_radial_basis& df,
            cv::Mat& x_,
            long num_bv,
            double eps,
            HRESULT& hr
        ) {
            auto x = Mat_to_vector_sample_type(x_);
            return reduce(df, x, num_bv, eps, hr);
        }
    `.trim().replace(/^ {8}/mg, ""));
};

module.exports = (header = [], impl = [], options = {}) => {
    impl.push(`
        using namespace dlib;

        template <typename decision_function>
        double _predict (
            const decision_function& df,
            const typename decision_function::kernel_type::sample_type& samp
        )
        {
            typedef typename decision_function::kernel_type::sample_type T;
            if (df.basis_vectors.size() == 0)
            {
                return 0;
            }
            else if (is_matrix<T>::value && df.basis_vectors(0).size() != samp.size())
            {
                std::ostringstream sout;
                sout << "Input vector should have " << df.basis_vectors(0).size() 
                     << " dimensions, not " << samp.size() << ".";
                AUTOIT_ASSERT_THROW(false, sout.str().c_str());
            }

            return df(samp);
        }

        template <typename df_type>
        typename df_type::sample_type _get_weights(
            const df_type& df
        )
        {
            AUTOIT_ASSERT_THROW(df.basis_vectors.size() != 0, "Decision function is empty.");
            df_type temp = simplify_linear_decision_function(df);
            return temp.basis_vectors(0);
        }

        template <typename df_type>
        typename df_type::scalar_type _get_bias(
            const df_type& df
        )
        {
            AUTOIT_ASSERT_THROW(df.basis_vectors.size() != 0, "Decision function is empty.");
            return df.b;
        }

        template <typename df_type>
        void _set_bias(
            df_type& df,
            double b
        )
        {
            AUTOIT_ASSERT_THROW(df.basis_vectors.size() != 0, "Decision function is empty.");
            df.b = b;
        }

        template <typename normalized_function>
        double normalized_predict (
            const normalized_function& df,
            const typename normalized_function::sample_type& samp
        )
        {
            typedef typename normalized_function::sample_type T;
            if (df.function.basis_vectors.size() == 0)
            {
                return 0;
            }
            else if (is_matrix<T>::value && df.function.basis_vectors(0).size() != samp.size())
            {
                std::ostringstream sout;
                sout << "Input vector should have " << df.function.basis_vectors(0).size() 
                     << " dimensions, not " << samp.size() << ".";
                AUTOIT_ASSERT_THROW(false, sout.str().c_str());
            }
            return df(samp);
        }

        template <typename normalized_function>
        std::vector<double> normalized_predict_vec (
            const normalized_function& df,
            const std::vector<typename normalized_function::sample_type>& samps
        )
        {
            std::vector<double> out;
            out.reserve(samps.size());
            for (const auto& x : samps)
                out.push_back(normalized_predict(df, x));
            return out;
        }

        template <typename normalized_function>
        std::vector<double> normalized_predict_cv_vec (
            const normalized_function& df,
            const cv_image<double>& samps_
        )
        {
            auto samps = make_image_view(samps_);

            if (df.function.basis_vectors(0).size() != samps.nc())
            {
                std::ostringstream sout;
                sout << "Input vector should have " << df.function.basis_vectors(0).size() 
                     << " dimensions, not " << samps.nc() << ".";
                AUTOIT_ASSERT_THROW(df.function.basis_vectors(0).size() == samps.nc(), sout.str().c_str());
            }

            std::vector<double> out;
            out.reserve(samps.nr());
            sample_type temp(samps.nc());
            for (long r = 0; r < samps.nr(); ++r)
            {
                for (long c = 0; c < samps.nc(); ++c)
                    temp(c) = samps(r, c);
                out.push_back(normalized_predict(df, temp));
            }
            return out;
        }

    `.trim().replace(/^ {8}/mg, ""));

    add_linear_df(impl, "_decision_function_linear", "sample_type", "IDlib_SpaceVector_Object*");
    add_linear_df(impl, "_decision_function_sparse_linear", "sparse_vect", "VARIANT");

    add_df(impl, "_decision_function_histogram_intersection", "SpaceVector");
    add_df(impl, "_decision_function_sparse_histogram_intersection", "sparse_vect");

    add_df(impl, "_decision_function_polynomial", "SpaceVector");
    add_df(impl, "_decision_function_sparse_polynomial", "sparse_vect");

    add_df(impl, "_decision_function_radial_basis", "SpaceVector");
    add_df(impl, "_decision_function_sparse_radial_basis", "sparse_vect");

    add_df(impl, "_decision_function_sigmoid", "SpaceVector");
    add_df(impl, "_decision_function_sparse_sigmoid", "sparse_vect");

    add_normalized_df(impl, "_normalized_decision_function_radial_basis", "SpaceVector");

    setup_auto_train_rbf_classifier(impl);

    return [header.join("\n"), impl.join("\n")];
};
