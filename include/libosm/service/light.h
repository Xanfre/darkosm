#ifndef __LIGHT_H
#define __LIGHT_H

#include "service.h"

/* Light Service */
#undef INTERFACE
#define INTERFACE ILightService
DECLARE_SCRIPT_SERVICE(Light, 0x16c)
{
	SERVICE_FUNCS()
	STDMETHOD_(void, Set)(THIS_ const int REF obj, int mode,
		float min_brightness, float max_brightness) PURE;
	STDMETHOD_(void, SetMode)(THIS_ const int REF obj, int mode) PURE;
	STDMETHOD_(void, Activate)(THIS_ const int REF obj) PURE;
	STDMETHOD_(void, Deactivate)(THIS_ const int REF obj) PURE;
	STDMETHOD_(void, Subscribe)(THIS_ const int REF obj) PURE;
	STDMETHOD_(void, Unsubscribe)(THIS_ const int REF obj) PURE;
	STDMETHOD_(int, GetMode)(THIS_ const int REF obj) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_LIGHT
#undef SERVICE_DEF_LIGHT
#endif
#define SERVICE_DEF_LIGHT() interface ILightService *Light = NULL;
#ifdef SERVICE_EXT_LIGHT
#undef SERVICE_EXT_LIGHT
#endif
#define SERVICE_EXT_LIGHT() extern ILightService *Light;
#ifdef SERVICE_IMPL_LIGHT
#undef SERVICE_IMPL_LIGHT
#endif
#define SERVICE_IMPL_LIGHT(_m) IMPLEMENT_SERVICE(_m, Light)

#endif
