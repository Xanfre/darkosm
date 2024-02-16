#if !defined(__NETWORKING_H) && (!defined(THIEF1) || defined(NEWDARK))
#define __NETWORKING_H

#include "service.h"

/* Networking Service */
#undef INTERFACE
#define INTERFACE INetworkingService
DECLARE_SCRIPT_SERVICE(Networking, 0x225)
{
	SERVICE_FUNCS()
	STDMETHOD(Broadcast)(THIS_ const int REF obj, const char *msg,
		BOOL sendFromProxy DEF_ARG(FALSE),
		const MultiParm REF data DEF_ARG(NULL)) PURE;
	STDMETHOD(SendToProxy)(THIS_ const int REF toPlayer, const int REF obj,
		const char *msg, const MultiParm REF data DEF_ARG(NULL)) PURE;
	STDMETHOD(TakeOver)(THIS_ const int REF obj) PURE;
	STDMETHOD(GiveTo)(THIS_ const int REF obj, const int REF toPlayer) PURE;
	STDMETHOD_(BOOL, IsPlayer)(THIS_ const int REF obj) PURE;
	STDMETHOD_(BOOL, IsMultiplayer)(THIS) PURE;
	STDMETHOD_(int, SetProxyOneShotTimer)(THIS_ const int REF toObj,
		const char *msg, float time, const MultiParm REF DEF_ARG(MultiParm()))
		PURE;
	STDMETHOD_(int *, FirstPlayer)(THIS_ int REF ret) PURE;
	STDMETHOD_(int *, NextPlayer)(THIS_ int REF ret) PURE;
	STDMETHOD(Suspend)(THIS) PURE;
	STDMETHOD(Resume)(THIS) PURE;
	STDMETHOD_(BOOL, HostedHere)(THIS_ const int REF obj) PURE;
	STDMETHOD_(BOOL, IsProxy)(THIS_ const int REF obj) PURE;
	STDMETHOD_(BOOL, LocalOnly)(THIS_ const int REF obj) PURE;
	STDMETHOD_(BOOL, IsNetworking)(THIS) PURE;
	STDMETHOD_(int *, Owner)(THIS_ int REF ret, const int REF obj) PURE;

#ifdef NEWDARK
	/*
	** new functions in T2 v1.27 / SS2 v2.48:
	*/

	/* only does something in T2 multiplayer builds */
	STDMETHOD(CreateContentProxy)(THIS_ const int REF player,
		const int REF content) PURE;
	/* only does something in T2 multiplayer builds */
	STDMETHOD_(BOOL, AmHost)(THIS) PURE;
	/* current number of players, including yourself */
	STDMETHOD_(int, NumPlayers)(THIS) PURE;
	/* in multiplayer this returns the local player's player number
	 * the player number is a number from 1 and up, unique for each player in a
	 * session and is consistent across loads (1 is the host player) */
	STDMETHOD_(int, MyPlayerNum)(THIS) PURE;
	/* get the player number from a player object */
	STDMETHOD_(int, ObjToPlayerNum)(THIS_ const int REF player) PURE;
	/* get the player object from a player number */
	STDMETHOD_(int *, PlayerNumToObj)(THIS_ int player) PURE;
	/* get the name of a player, returns a 0-len string if player was not
	 * found */
	STDMETHOD_(String *, GetPlayerName)(THIS_ String REF ret,
		const int REF player) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_NETWORKING
#undef SERVICE_DEF_NETWORKING
#endif
#define SERVICE_DEF_NETWORKING() interface INetworkingService *Networking = NULL;
#ifdef SERVICE_EXT_NETWORKING
#undef SERVICE_EXT_NETWORKING
#endif
#define SERVICE_EXT_NETWORKING() extern INetworkingService *Networking;
#ifdef SERVICE_IMPL_NETWORKING
#undef SERVICE_IMPL_NETWORKING
#endif
#define SERVICE_IMPL_NETWORKING(_m) IMPLEMENT_SERVICE(_m, Networking)

#endif
