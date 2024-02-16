#if !defined(__PLAYERLIMBS_H) && !defined(SHOCK)
#define __PLAYERLIMBS_H

#include "service.h"

/* PlayerLimbs Service */
#undef INTERFACE
#define INTERFACE IPlayerLimbsService
DECLARE_SCRIPT_SERVICE(PlayerLimbs, 0x15d)
{
	SERVICE_FUNCS()
	STDMETHOD(Equip)(THIS_ int item) PURE;
	STDMETHOD(UnEquip)(THIS_ int item) PURE;
	STDMETHOD(StartUse)(THIS_ int item) PURE;
	STDMETHOD(FinishUse)(THIS_ int item) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_PLAYERLIMBS
#undef SERVICE_DEF_PLAYERLIMBS
#endif
#define SERVICE_DEF_PLAYERLIMBS() interface IPlayerLimbsService *PlayerLimbs = NULL;
#ifdef SERVICE_EXT_PLAYERLIMBS
#undef SERVICE_EXT_PLAYERLIMBS
#endif
#define SERVICE_EXT_PLAYERLIMBS() extern IPlayerLimbsService *PlayerLimbs;
#ifdef SERVICE_IMPL_PLAYERLIMBS
#undef SERVICE_IMPL_PLAYERLIMBS
#endif
#define SERVICE_IMPL_PLAYERLIMBS(_m) IMPLEMENT_SERVICE(_m, PlayerLimbs)

#endif
