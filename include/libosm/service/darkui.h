#if !defined(__DARKUI_H) && !defined(SHOCK)
#define __DARKUI_H

#include "service.h"

/* DarkUI Service */
#undef INTERFACE
#define INTERFACE IDarkUIService
DECLARE_SCRIPT_SERVICE(DarkUI, 0x19f)
{
	SERVICE_FUNCS()
	STDMETHOD(TextMessage)(THIS_ const char* message, int color DEF_ARG(0),
		int timeout DEF_ARG(-1001)) PURE;
	STDMETHOD(ReadBook)(THIS_ const char* text, const char* art) PURE;
	STDMETHOD_(int *, InvItem)(THIS_ int REF ret) PURE;
	STDMETHOD_(int *, InvWeapon)(THIS_ int REF ret) PURE;
	STDMETHOD(InvSelect)(THIS_ int obj) PURE;
	STDMETHOD_(BOOL *, IsCommandBound)(THIS_ BOOL REF ret, const String REF cmd)
		PURE;
	STDMETHOD_(String *, DescribeKeyBinding)(THIS_ String REF ret,
		const String REF cmd) PURE;
}; 

/* Populated Implementors */
#ifdef SERVICE_DEF_DARKUI
#undef SERVICE_DEF_DARKUI
#endif
#define SERVICE_DEF_DARKUI() interface IDarkUIService *DarkUI = NULL;
#ifdef SERVICE_EXT_DARKUI
#undef SERVICE_EXT_DARKUI
#endif
#define SERVICE_EXT_DARKUI() extern IDarkUIService *DarkUI;
#ifdef SERVICE_IMPL_DARKUI
#undef SERVICE_IMPL_DARKUI
#endif
#define SERVICE_IMPL_DARKUI(_m) IMPLEMENT_SERVICE(_m, DarkUI)

#endif
