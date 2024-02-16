#ifndef __SHOCKOBJ_H
#define __SHOCKOBJ_H

#include "service.h"

/* ShockObj Service */
#undef INTERFACE
#define INTERFACE IShockObjService
DECLARE_SCRIPT_SERVICE(ShockObj, 0x1d9)
{
	SERVICE_FUNCS()
	STDMETHOD_(int, FindScriptDonor)(int objID, String name) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_SHOCKOBJ
#undef SERVICE_DEF_SHOCKOBJ
#endif
#define SERVICE_DEF_SHOCKOBJ() interface IShockObjService *ShockObj = NULL;
#ifdef SERVICE_EXT_SHOCKOBJ
#undef SERVICE_EXT_SHOCKOBJ
#endif
#define SERVICE_EXT_SHOCKOBJ() extern IShockObjService *ShockObj;
#ifdef SERVICE_IMPL_SHOCKOBJ
#undef SERVICE_IMPL_SHOCKOBJ
#endif
#define SERVICE_IMPL_SHOCKOBJ(_m) IMPLEMENT_SERVICE(_m, ShockObj)

#endif
