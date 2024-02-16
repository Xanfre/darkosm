#if !defined(__DARKGAME_H) && !defined(SHOCK)
#define __DARKGAME_H

#include "service.h"

/* DarkGame Service */
#undef INTERFACE
#define INTERFACE IDarkGameService
DECLARE_SCRIPT_SERVICE(DarkGame, 0x1b4)
{
	SERVICE_FUNCS()
	STDMETHOD(KillPlayer)(THIS) PURE;
	STDMETHOD(EndMission)(THIS) PURE;
	STDMETHOD(FadeToBlack)(THIS_ float time) PURE;
#if !defined(THIEF1) || defined(NEWDARK)
	STDMETHOD(FoundObject)(THIS_ int obj) PURE;
	STDMETHOD_(BOOL, ConfigIsDefined)(THIS_ const char *name) PURE;
	STDMETHOD_(BOOL, ConfigGetInt)(THIS_ const char *name, int REF value) PURE;
	STDMETHOD_(BOOL, ConfigGetFloat)(THIS_ const char *name, float REF value)
		PURE;
	STDMETHOD_(float, BindingGetFloat)(THIS_ const char *name) PURE;
	STDMETHOD_(BOOL, GetAutomapLocationVisited)(THIS_ int page, int location)
		PURE;
	STDMETHOD(SetAutomapLocationVisited)(THIS_ int page, int location) PURE;

#ifdef NEWDARK
	/*
	** new functions in v1.19:
	*/

	/* set/change the next mission that will follow current mission (normally
	 * the next mission is cur+1 or if "missflag.str" contains a miss_%d_next
	 * the next mission is defined by that) */
	STDMETHOD_(void, SetNextMission)(THIS_ int mission) PURE;
	/* get current mission number */
	STDMETHOD_(int, GetCurrentMission)(THIS) PURE;

	/*
	** new functions in v1.24:
	*/

	/* only does something in T2 multiplayer builds */
	STDMETHOD_(BOOL, RespawnPlayer)(THIS) PURE;
	/* only does something in T2 multiplayer builds */
	STDMETHOD(FadeIn)(THIS_ float time) PURE;
#endif
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_DARKGAME
#undef SERVICE_DEF_DARKGAME
#endif
#define SERVICE_DEF_DARKGAME() interface IDarkGameService *DarkGame = NULL;
#ifdef SERVICE_EXT_DARKGAME
#undef SERVICE_EXT_DARKGAME
#endif
#define SERVICE_EXT_DARKGAME() extern IDarkGameService *DarkGame;
#ifdef SERVICE_IMPL_DARKGAME
#undef SERVICE_IMPL_DARKGAME
#endif
#define SERVICE_IMPL_DARKGAME(_m) IMPLEMENT_SERVICE(_m, DarkGame)

#endif
