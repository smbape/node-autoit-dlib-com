#pragma once

#include "autoit_bridge.h"

class CDlibModule : public ATL::CAtlDllModuleT< CDlibModule >
{
public:
	DECLARE_LIBID(LIBID_dlibCOM)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DLIB, "{a7599799-48f5-4569-b79e-7eff77460ede}")
};

extern class CDlibModule _AtlModule;

STDAPI_(BOOL) DllActivateManifest(_In_opt_ LPCWSTR pManifest);
STDAPI_(BOOL) DllActivateActCtx(_In_opt_ PCACTCTXW pActCtx);
STDAPI_(BOOL) DllDeactivateActCtx();
