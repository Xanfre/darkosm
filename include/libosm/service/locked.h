#ifndef __LOCKED_H
#define __LOCKED_H

#include "service.h"

/* Locked Service */
#undef INTERFACE
#define INTERFACE ILockedService
DECLARE_SCRIPT_SERVICE(Locked, 0xfb)
{
	SERVICE_FUNCS()
	STDMETHOD_(BOOL, IsLocked)(THIS_ const int REF obj) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_LOCKED
#undef SERVICE_DEF_LOCKED
#endif
#define SERVICE_DEF_LOCKED() interface ILockedService *Locked = NULL;
#ifdef SERVICE_EXT_LOCKED
#undef SERVICE_EXT_LOCKED
#endif
#define SERVICE_EXT_LOCKED() extern ILockedService *Locked;
#ifdef SERVICE_IMPL_LOCKED
#undef SERVICE_IMPL_LOCKED
#endif
#define SERVICE_IMPL_LOCKED(_m) IMPLEMENT_SERVICE(_m, Locked)

#endif
