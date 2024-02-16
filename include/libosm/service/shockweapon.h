#if !defined(__SHOCKWEAPON_H) && defined(SHOCK)
#define __SHOCKWEAPON_H

#include "service.h"

/* ShockWeapon Service */
#undef INTERFACE
#define INTERFACE IShockWeaponService
DECLARE_SCRIPT_SERVICE(ShockWeapon, 0x213)
{
	SERVICE_FUNCS()
	STDMETHOD_(void, SetWeaponModel)(THIS_ const int REF obj) PURE;
	STDMETHOD_(int *, GetWeaponModel)(THIS_ int REF ret) PURE;
	STDMETHOD_(int *, TargetScan)(THIS_ int REF ret, int projectile) PURE;
	STDMETHOD_(void, Home)(THIS_ int projectile, int target) PURE;
	STDMETHOD_(void, DestroyMelee)(THIS_ const int REF obj) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_SHOCKWEAPON
#undef SERVICE_DEF_SHOCKWEAPON
#endif
#define SERVICE_DEF_SHOCKWEAPON() interface IShockWeaponService *ShockWeapon = NULL;
#ifdef SERVICE_EXT_SHOCKWEAPON
#undef SERVICE_EXT_SHOCKWEAPON
#endif
#define SERVICE_EXT_SHOCKWEAPON() extern IShockWeaponService *ShockWeapon;
#ifdef SERVICE_IMPL_SHOCKWEAPON
#undef SERVICE_IMPL_SHOCKWEAPON
#endif
#define SERVICE_IMPL_SHOCKWEAPON(_m) IMPLEMENT_SERVICE(_m, ShockWeapon)

#endif
