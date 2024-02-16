#if !defined(__PICKLOCK_H) && !defined(SHOCK)
#define __PICKLOCK_H

#include "service.h"

/* PickLock Service */
#undef INTERFACE
#define INTERFACE IPickLockService
DECLARE_SCRIPT_SERVICE(PickLock, 0x111)
{
	SERVICE_FUNCS()
	STDMETHOD_(BOOL, Ready)(THIS_ int picker, int pick_obj) PURE;
	STDMETHOD_(BOOL, UnReady)(THIS_ int picker, int pick_obj) PURE;
	STDMETHOD_(BOOL, StartPicking)(THIS_ int picker, int pick_obj,
		int locked_obj) PURE;
	STDMETHOD_(BOOL, FinishPicking)(THIS_ int pick_obj) PURE;
	STDMETHOD_(BOOL, CheckPick)(THIS_ int pick_obj, int locked_obj, int stage)
		PURE;
	STDMETHOD_(BOOL, DirectMotion)(THIS_ BOOL start) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_PICKLOCK
#undef SERVICE_DEF_PICKLOCK
#endif
#define SERVICE_DEF_PICKLOCK() interface IPickLockService *PickLock = NULL;
#ifdef SERVICE_EXT_PICKLOCK
#undef SERVICE_EXT_PICKLOCK
#endif
#define SERVICE_EXT_PICKLOCK() extern IPickLockService *PickLock;
#ifdef SERVICE_IMPL_PICKLOCK
#undef SERVICE_IMPL_PICKLOCK
#endif
#define SERVICE_IMPL_PICKLOCK(_m) IMPLEMENT_SERVICE(_m, PickLock)

#endif
