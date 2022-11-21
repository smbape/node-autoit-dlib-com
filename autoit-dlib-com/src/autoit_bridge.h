#pragma once

#include "autoit_bridge_common.h"
#include "autoit_bridge_generated.h"

template<typename _Tp, long nr>
const bool is_assignable_from(dlib::matrix<_Tp, nr, 1>& out_val, VARIANT const* const& in_val, bool is_optional) {
	if (PARAMETER_MISSING(in_val)) {
		return is_optional;
	}

	if ((V_VT(in_val) & VT_ARRAY) != VT_ARRAY || (V_VT(in_val) ^ VT_ARRAY) != VT_VARIANT) {
		return false;
	}

	typename ATL::template CComSafeArray<VARIANT> vArray;
	vArray.Attach(V_ARRAY(in_val));

	LONG lLower = vArray.GetLowerBound();
	LONG lUpper = vArray.GetUpperBound();

	if (lUpper - lLower + 1 != nr) {
		vArray.Detach();
		return false;
	}

	HRESULT hr = S_OK;
	_Tp value;

	for (LONG i = 0; i < nr; i++) {
		auto& v = vArray.GetAt(i + lLower);
		VARIANT* pv = &v;
		if (!is_assignable_from(value, pv, false)) {
			hr = E_INVALIDARG;
			break;
		}
	}

	vArray.Detach();

	return SUCCEEDED(hr);
}

template<typename _Tp, long nr>
const HRESULT autoit_to(VARIANT const* const& in_val, dlib::matrix<_Tp, nr, 1>& out_val) {
	if (PARAMETER_MISSING(in_val)) {
		return S_OK;
	}

	if ((V_VT(in_val) & VT_ARRAY) != VT_ARRAY || (V_VT(in_val) ^ VT_ARRAY) != VT_VARIANT) {
		return E_INVALIDARG;
	}

	HRESULT hr = S_OK;
	typename ATL::template CComSafeArray<VARIANT> vArray;
	vArray.Attach(V_ARRAY(in_val));

	LONG lLower = vArray.GetLowerBound();
	LONG lUpper = vArray.GetUpperBound();

	out_val.set_size(nr);
	_Tp value;

	for (LONG i = 0; i < nr; i++) {
		auto& v = vArray.GetAt(i + lLower);
		VARIANT* pv = &v;

		if (!is_assignable_from(value, pv, false)) {
			hr = E_INVALIDARG;
			break;
		}

		hr = autoit_to(pv, value);
		if (FAILED(hr)) {
			break;
		}

		out_val(i) = value;
	}

	vArray.Detach();
	return hr;
}

template<typename _Tp, long nr>
const HRESULT autoit_from(const cv::Ptr<dlib::matrix<_Tp, nr, 1>>& in_val, VARIANT*& out_val) {
	return autoit_from(*in_val.get(), out_val);
}

template<typename _Tp, long nr>
const HRESULT autoit_from(const dlib::matrix<_Tp, nr, 1>& in_val, VARIANT*& out_val) {
	if (PARAMETER_MISSING(out_val)) {
		V_VT(out_val) = VT_ARRAY | VT_VARIANT;
		typename ATL::template CComSafeArray<VARIANT> vArray((ULONG)0);
		V_ARRAY(out_val) = vArray.Detach();
	}

	if ((V_VT(out_val) & VT_ARRAY) != VT_ARRAY || (V_VT(out_val) ^ VT_ARRAY) != VT_VARIANT) {
		return E_INVALIDARG;
	}

	HRESULT hr = S_OK;
	typename ATL::template CComSafeArray<VARIANT> vArray;
	vArray.Attach(V_ARRAY(out_val));

	vArray.Resize(in_val.size());

	for (LONG i = 0; SUCCEEDED(hr) && i < in_val.size(); i++) {
		VARIANT value = { VT_EMPTY };
		auto* pvalue = &value;
		hr = autoit_from(in_val(i), pvalue);

		if (SUCCEEDED(hr)) {
			vArray.SetAt(i, value);
		}

		VariantClear(&value);
	}

	vArray.Detach();
	return hr;
}

template<typename _Tp, long nr, long nc>
const bool is_assignable_from(dlib::matrix<_Tp, nr, nc>& out_val, VARIANT const* const& in_val, bool is_optional) {
	if (PARAMETER_MISSING(in_val)) {
		return is_optional;
	}

	if ((V_VT(in_val) & VT_ARRAY) != VT_ARRAY || (V_VT(in_val) ^ VT_ARRAY) != VT_VARIANT) {
		return false;
	}

	typename ATL::template CComSafeArray<VARIANT> vMatrixArray;
	vMatrixArray.Attach(V_ARRAY(in_val));

	LONG lLower = vMatrixArray.GetLowerBound();
	LONG lUpper = vMatrixArray.GetUpperBound();

	HRESULT hr = S_OK;
	if (lUpper - lLower + 1 != nr) {
		hr = E_INVALIDARG;
		goto end;
	}

	_Tp value;

	for (LONG i = 0; i < nr && SUCCEEDED(hr); i++) {
		auto& _row_v = vMatrixArray.GetAt(i + lLower);
		VARIANT* _row_in_val = &_row_v;

		if ((V_VT(_row_in_val) & VT_ARRAY) != VT_ARRAY || (V_VT(_row_in_val) ^ VT_ARRAY) != VT_VARIANT) {
			hr = E_INVALIDARG;
			break;
		}

		typename ATL::template CComSafeArray<VARIANT> vRowArray;
		vRowArray.Attach(V_ARRAY(_row_in_val));

		LONG lRowLower = vRowArray.GetLowerBound();
		LONG lRowUpper = vRowArray.GetUpperBound();

		if (lRowUpper - lRowLower + 1 != nc) {
			hr = E_INVALIDARG;
			goto endloop;
		}

		for (LONG j = 0; j < nc && SUCCEEDED(hr); i++) {
			auto& v = vRowArray.GetAt(i + lRowUpper);
			VARIANT* pv = &v;

			if (!is_assignable_from(value, pv, false)) {
				hr = E_INVALIDARG;
				break;
			}
		}

	endloop:
		vRowArray.Detach();
	}

end:
	vMatrixArray.Detach();
	return SUCCEEDED(hr);
}

template<typename _Tp, long nr, long nc>
const HRESULT autoit_to(VARIANT const* const& in_val, dlib::matrix<_Tp, nr, nc>& out_val) {
	if (PARAMETER_MISSING(in_val)) {
		return S_OK;
	}

	if ((V_VT(in_val) & VT_ARRAY) != VT_ARRAY || (V_VT(in_val) ^ VT_ARRAY) != VT_VARIANT) {
		return E_INVALIDARG;
	}

	typename ATL::template CComSafeArray<VARIANT> vMatrixArray;
	vMatrixArray.Attach(V_ARRAY(in_val));

	LONG lLower = vMatrixArray.GetLowerBound();
	LONG lUpper = vMatrixArray.GetUpperBound();

	HRESULT hr = S_OK;
	if (lUpper - lLower + 1 != nr) {
		hr = E_INVALIDARG;
		goto end;
	}

	_Tp value;

	for (LONG i = 0; i < nr && SUCCEEDED(hr); i++) {
		auto& _row_v = vMatrixArray.GetAt(i + lLower);
		VARIANT* _row_in_val = &_row_v;

		if ((V_VT(_row_in_val) & VT_ARRAY) != VT_ARRAY || (V_VT(_row_in_val) ^ VT_ARRAY) != VT_VARIANT) {
			hr = E_INVALIDARG;
			break;
		}

		typename ATL::template CComSafeArray<VARIANT> vRowArray;
		vRowArray.Attach(V_ARRAY(_row_in_val));

		LONG lRowLower = vRowArray.GetLowerBound();
		LONG lRowUpper = vRowArray.GetUpperBound();

		if (lRowUpper - lRowLower + 1 != nc) {
			hr = E_INVALIDARG;
			goto endloop;
		}

		for (LONG j = 0; j < nc && SUCCEEDED(hr); i++) {
			auto& v = vRowArray.GetAt(i + lRowUpper);
			VARIANT* pv = &v;

			if (!is_assignable_from(value, pv, false)) {
				hr = E_INVALIDARG;
				break;
			}

			out_val(i, j) = value;
		}

	endloop:
		vRowArray.Detach();
	}

end:
	vMatrixArray.Detach();
	return hr;
}

template<typename _Tp, long nr, long nc>
const HRESULT autoit_from(const cv::Ptr<dlib::matrix<_Tp, nr, nc>>& in_val, VARIANT*& out_val) {
	return autoit_from(*in_val.get(), out_val);
}

template<typename _Tp, long nr, long nc>
const HRESULT autoit_from(const dlib::matrix<_Tp, nr, nc>& in_val, VARIANT*& out_val) {
	if (PARAMETER_MISSING(out_val)) {
		V_VT(out_val) = VT_ARRAY | VT_VARIANT;
		typename ATL::template CComSafeArray<VARIANT> vArray((ULONG)0);
		V_ARRAY(out_val) = vArray.Detach();
	}

	if ((V_VT(out_val) & VT_ARRAY) != VT_ARRAY || (V_VT(out_val) ^ VT_ARRAY) != VT_VARIANT) {
		return E_INVALIDARG;
	}

	HRESULT hr = S_OK;
	typename ATL::template CComSafeArray<VARIANT> vMatrixArray;
	vMatrixArray.Attach(V_ARRAY(out_val));
	vMatrixArray.Resize(nr);

	for (LONG i = 0; i < nr && SUCCEEDED(hr); i++) {
		auto& _row_v_ = vMatrixArray.GetAt(i);
		VARIANT* _row_out_val = &_row_v_;

		if (PARAMETER_MISSING(_row_out_val)) {
			VARIANT value = { VT_EMPTY };
			auto* pvalue = &value;
			V_VT(pvalue) = VT_ARRAY | VT_VARIANT;
			typename ATL::template CComSafeArray<VARIANT> vArray((ULONG)0);
			V_ARRAY(pvalue) = vArray.Detach();
			vMatrixArray.SetAt(i, value);
			VariantClear(&value);
		}

		auto& _row_v = vMatrixArray.GetAt(i);
		_row_out_val = &_row_v;
		if ((V_VT(_row_out_val) & VT_ARRAY) != VT_ARRAY || (V_VT(_row_out_val) ^ VT_ARRAY) != VT_VARIANT) {
			hr = E_INVALIDARG;
			break;
		}

		typename ATL::template CComSafeArray<VARIANT> vRowArray;
		vRowArray.Attach(V_ARRAY(_row_out_val));
		vRowArray.Resize(nc);

		for (LONG j = 0; j < nc && SUCCEEDED(hr); j++) {
			VARIANT value = { VT_EMPTY };
			auto* pvalue = &value;
			hr = autoit_from(in_val(i, j), pvalue);

			if (SUCCEEDED(hr)) {
				vRowArray.SetAt(j, value);
			}

			VariantClear(&value);
		}

		vRowArray.Detach();
	}

	vMatrixArray.Detach();
	return hr;
}

PTR_BRIDGE_DECL(dlib::simple_structural_svm_problem::get_truth_joint_feature_vector_function)
PTR_BRIDGE_DECL(dlib::simple_structural_svm_problem::separation_oracle_function)
