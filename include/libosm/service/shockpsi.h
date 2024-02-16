#if !defined(__SHOCKPSI_H) && defined(SHOCK)
#define __SHOCKPSI_H

#include "service.h"

/* ShockPsi Service */
#undef INTERFACE
#define INTERFACE IShockPsiService
DECLARE_SCRIPT_SERVICE(ShockPsi, 0x1d7)
{
	SERVICE_FUNCS()
	STDMETHOD(OnDeactivate)(THIS_ ePsiPowers power) PURE;
	STDMETHOD_(unsigned long, GetActiveTime)(THIS_ ePsiPowers power) PURE;
	STDMETHOD_(BOOL, IsOverloaded)(THIS_ ePsiPowers power) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_SHOCKPSI
#undef SERVICE_DEF_SHOCKPSI
#endif
#define SERVICE_DEF_SHOCKPSI() interface IShockPsiService *ShockPsi = NULL;
#ifdef SERVICE_EXT_SHOCKPSI
#undef SERVICE_EXT_SHOCKPSI
#endif
#define SERVICE_EXT_SHOCKPSI() extern IShockPsiService *ShockPsi;
#ifdef SERVICE_IMPL_SHOCKPSI
#undef SERVICE_IMPL_SHOCKPSI
#endif
#define SERVICE_IMPL_SHOCKPSI(_m) IMPLEMENT_SERVICE(_m, ShockPsi)

#endif
