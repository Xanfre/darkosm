#ifndef __KEY_H
#define __KEY_H

#include "service.h"

/* Key Service */
#undef INTERFACE
#define INTERFACE IKeyService
DECLARE_SCRIPT_SERVICE(Key, 0x10d)
{
	SERVICE_FUNCS()
	STDMETHOD_(BOOL, TryToUseKey)(THIS_ const int REF key_obj,
		const int REF lock_obj, eKeyUse how) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_KEY
#undef SERVICE_DEF_KEY
#endif
#define SERVICE_DEF_KEY() interface IKeyService *Key = NULL;
#ifdef SERVICE_EXT_KEY
#undef SERVICE_EXT_KEY
#endif
#define SERVICE_EXT_KEY() extern IKeyService *Key;
#ifdef SERVICE_IMPL_KEY
#undef SERVICE_IMPL_KEY
#endif
#define SERVICE_IMPL_KEY(_m) IMPLEMENT_SERVICE(_m, Key)

#endif
