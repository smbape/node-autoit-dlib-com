#pragma once

#include "autoit_bridge_common.h"

template<typename _Tp, long nr>
const bool is_assignable_from(matrix<_Tp, nr, 1>& out_val, VARIANT const* const& in_val, bool is_optional) {
	if (V_VT(in_val) == VT_ERROR) {
		return V_ERROR(in_val) == DISP_E_PARAMNOTFOUND && is_optional;
	}

	if (V_VT(in_val) == VT_EMPTY) {
		return is_optional;
	}

	if ((V_VT(in_val) & VT_ARRAY) != VT_ARRAY || (V_VT(in_val) ^ VT_ARRAY) != VT_VARIANT) {
		return false;
	}

	typename ATL::template CComSafeArray<VARIANT> vArray;
	vArray.Attach(V_ARRAY(in_val));

	LONG lLower = vArray.GetLowerBound();
	LONG lUpper = vArray.GetUpperBound();

	if (lUpper - lLower + 1 < nr) {
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
const HRESULT autoit_to(VARIANT const* const& in_val, matrix<_Tp, nr, 1>& out_val) {
	if (V_VT(in_val) == VT_ERROR) {
		return V_ERROR(in_val) == DISP_E_PARAMNOTFOUND ? S_OK : E_INVALIDARG;
	}

	if (V_VT(in_val) == VT_EMPTY) {
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
const HRESULT autoit_from(const std::shared_ptr<matrix<_Tp, nr, 1>>& in_val, VARIANT*& out_val) {
	return autoit_from(*in_val.get(), out_val);
}

template<typename _Tp, long nr>
const HRESULT autoit_from(const matrix<_Tp, nr, 1>& in_val, VARIANT*& out_val) {
	if (V_VT(out_val) == VT_EMPTY || V_VT(out_val) == VT_ERROR && V_ERROR(out_val) == DISP_E_PARAMNOTFOUND) {
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

PTR_BRIDGE_DECL(dlib::simple_structural_svm_problem::get_truth_joint_feature_vector_function)
PTR_BRIDGE_DECL(dlib::simple_structural_svm_problem::separation_oracle_function)
