#if !defined(__BOW_H) && !defined(SHOCK)
#define __BOW_H

#include "service.h"

/* Bow Service */
#undef INTERFACE
#define INTERFACE IBowService
DECLARE_SCRIPT_SERVICE(Bow, 0x115)
{
	SERVICE_FUNCS()
	STDMETHOD(Equip)(THIS) PURE;
	STDMETHOD(UnEquip)(THIS) PURE;
	STDMETHOD_(BOOL, IsEquipped)(THIS) PURE;
	STDMETHOD(StartAttack)(THIS) PURE;
	STDMETHOD(FinishAttack)(THIS) PURE;
	STDMETHOD(AbortAttack)(THIS) PURE;
	STDMETHOD_(BOOL, SetArrow)(THIS_ int arrow) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_BOW
#undef SERVICE_DEF_BOW
#endif
#define SERVICE_DEF_BOW() interface IBowService *Bow = NULL;
#ifdef SERVICE_EXT_BOW
#undef SERVICE_EXT_BOW
#endif
#define SERVICE_EXT_BOW() extern IBowService *Bow;
#ifdef SERVICE_IMPL_BOW
#undef SERVICE_IMPL_BOW
#endif
#define SERVICE_IMPL_BOW(_m) IMPLEMENT_SERVICE(_m, Bow)

#endif
