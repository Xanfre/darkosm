#if !defined(__SHOCKAI_H) && defined(SHOCK)
#define __SHOCKAI_H

#include "service.h"

/* ShockAI Service */
#undef INTERFACE
#define INTERFACE IShockAIService
DECLARE_SCRIPT_SERVICE(ShockAI, 0x21b)
{
	SERVICE_FUNCS()
	STDMETHOD_(BOOL, Stun)(THIS_ int who, String startTags, String loopTags,
		float sec) PURE;
	STDMETHOD_(BOOL, IsStunned)(THIS_ int who) PURE;
	STDMETHOD_(BOOL, UnStun)(THIS_ int who) PURE;
	STDMETHOD_(BOOL, Freeze)(THIS_ int who, float sec) PURE;
	STDMETHOD_(BOOL, IsFrozen)(THIS_ int who) PURE;
	STDMETHOD_(BOOL, UnFreeze)(THIS_ int who) PURE;
	STDMETHOD_(void, NotifyEnterTripwire)(THIS_ int who, int what) PURE;
	STDMETHOD_(void, NotifyExitTripwire)(THIS_ int who, int what) PURE;
	STDMETHOD_(BOOL, ObjectLocked)(THIS_ int obj) PURE;
	STDMETHOD_(void, ValidateSpawn)(THIS_ int creature, int spawnMarker) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_SHOCKAI
#undef SERVICE_DEF_SHOCKAI
#endif
#define SERVICE_DEF_SHOCKAI() interface IShockAIService *ShockAI = NULL;
#ifdef SERVICE_EXT_SHOCKAI
#undef SERVICE_EXT_SHOCKAI
#endif
#define SERVICE_EXT_SHOCKAI() extern IShockAIService *ShockAI;
#ifdef SERVICE_IMPL_SHOCKAI
#undef SERVICE_IMPL_SHOCKAI
#endif
#define SERVICE_IMPL_SHOCKAI(_m) IMPLEMENT_SERVICE(_m, ShockAI)

#endif
