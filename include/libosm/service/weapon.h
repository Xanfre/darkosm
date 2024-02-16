#if !defined(__WEAPON_H) && !defined(SHOCK)
#define __WEAPON_H

#include "service.h"

/* Weapon Service */
#undef INTERFACE
#define INTERFACE IWeaponService
DECLARE_SCRIPT_SERVICE(Weapon, 0x10e)
{
	SERVICE_FUNCS()
	STDMETHOD(Equip)(THIS_ int weapon, int type DEF_ARG(kDWT_Sword)) PURE;
	STDMETHOD(UnEquip)(THIS_ int weapon) PURE;
	STDMETHOD_(BOOL, IsEquipped)(THIS_ int owner, int weapon) PURE;
	STDMETHOD(StartAttack)(THIS_ int owner, int weapon) PURE;
	STDMETHOD(FinishAttack)(THIS_ int owner, int weapon) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_WEAPON
#undef SERVICE_DEF_WEAPON
#endif
#define SERVICE_DEF_WEAPON() interface IWeaponService *Weapon = NULL;
#ifdef SERVICE_EXT_WEAPON
#undef SERVICE_EXT_WEAPON
#endif
#define SERVICE_EXT_WEAPON() extern IWeaponService *Weapon;
#ifdef SERVICE_IMPL_WEAPON
#undef SERVICE_IMPL_WEAPON
#endif
#define SERVICE_IMPL_WEAPON(_m) IMPLEMENT_SERVICE(_m, Weapon)

#endif
