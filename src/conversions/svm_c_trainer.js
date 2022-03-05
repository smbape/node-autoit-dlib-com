/* eslint-disable no-magic-numbers */

const setup_trainer = (impl, trainer_type) => {
    const trainer_type_obj = trainer_type[0].toUpperCase() + trainer_type.slice(1);

    impl.push(`
        #include "Dlib_${ trainer_type_obj }_Object.h"

        STDMETHODIMP CDlib_${ trainer_type_obj }_Object::get_gamma(DOUBLE* pVal) {
            AUTOIT_ASSERT(this->__self->get() != NULL);
            auto& trainer = *this->__self->get();
            *pVal = trainer.get_kernel().gamma;
            return S_OK;
        }

        STDMETHODIMP CDlib_${ trainer_type_obj }_Object::put_gamma(DOUBLE gamma) {
            AUTOIT_ASSERT(this->__self->get() != NULL);
            AUTOIT_ASSERT(gamma > 0);
            auto& trainer = *this->__self->get();
            trainer.set_kernel(${ trainer_type }::kernel_type(gamma));
            return S_OK;
        }

    `.trim().replace(/^ {8}/mg, ""));
};

module.exports = (header = [], impl = [], options = {}) => {
    setup_trainer(impl, "svm_c_trainer_radial_basis");
    setup_trainer(impl, "svm_c_trainer_sparse_radial_basis");
    setup_trainer(impl, "rvm_trainer_radial_basis");
    setup_trainer(impl, "rvm_trainer_sparse_radial_basis");
    return [header.join("\n"), impl.join("\n")];
};
