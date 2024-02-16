#if !defined(__DRKINV_H) && !defined(SHOCK)
#define __DRKINV_H

#include "service.h"

/* DrkInv Service */
#undef INTERFACE
#define INTERFACE IDrkInvService
DECLARE_SCRIPT_SERVICE(DrkInv, 0x150)
{
	SERVICE_FUNCS()
	STDMETHOD_(void, CapabilityControl)(THIS_ eDrkInvCap cap_change,
		eDrkInvControl control) PURE;
	STDMETHOD_(void, AddSpeedControl)(THIS_ const char *name, float speed_fac,
		float rot_fac) PURE;
	STDMETHOD_(void, RemoveSpeedControl)(THIS_ const char *name) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_DRKINV
#undef SERVICE_DEF_DRKINV
#endif
#define SERVICE_DEF_DRKINV() interface IDrkInvService *DrkInv = NULL;
#ifdef SERVICE_EXT_DRKINV
#undef SERVICE_EXT_DRKINV
#endif
#define SERVICE_EXT_DRKINV() extern IDrkInvService *DrkInv;
#ifdef SERVICE_IMPL_DRKINV
#undef SERVICE_IMPL_DRKINV
#endif
#define SERVICE_IMPL_DRKINV(_m) IMPLEMENT_SERVICE(_m, DrkInv)

#endif
