#if !defined(__SHOCKGAME_H) && defined(SHOCK)
#define __SHOCKGAME_H

#include "service.h"

/* ShockGame Service */
#undef INTERFACE
#define INTERFACE IShockGameService
DECLARE_SCRIPT_SERVICE(ShockGame, 0x108)
{
	SERVICE_FUNCS()
	STDMETHOD(DestroyCursorObj)(THIS) PURE;
	STDMETHOD(DestroyInvObj)(THIS_ const int REF DestroyObj) PURE;
	STDMETHOD(HideInvObj)(THIS_ const int REF DestroyObj) PURE;
	STDMETHOD(SetPlayerPsiPoints)(THIS_ int power) PURE;
	STDMETHOD_(int, GetPlayerPsiPoints)(THIS) PURE;
	STDMETHOD(AttachCamera)(THIS_ const String REF s) PURE;
	STDMETHOD(CutSceneModeOn)(THIS_ const String REF sceneName) PURE;
	STDMETHOD(CutSceneModeOff)(THIS) PURE;
	STDMETHOD_(int, CreatePlayerPuppet)(THIS) PURE;
	STDMETHOD_(int, CreatePlayerPuppet)(THIS_ const String REF modelName) PURE;
	STDMETHOD(DestroyPlayerPuppet)(THIS) PURE;
	STDMETHOD(Replicator)(THIS_ const int REF RepObj) PURE;
	STDMETHOD(Container)(THIS_ const int REF ContainObj) PURE;
	STDMETHOD(YorN)(THIS_ const int REF BaseObj, const String REF s) PURE;
	STDMETHOD(Keypad)(THIS_ const int REF BaseObj) PURE;
	STDMETHOD(HRM)(THIS_ int hacktype, const int REF Obj, BOOL frompsi) PURE;
	STDMETHOD(TechTool)(THIS_ const int REF Obj) PURE;
	STDMETHOD(UseLog)(THIS_ const int REF LogObj, BOOL PickedUpByMe) PURE;
	STDMETHOD_(BOOL, TriggerLog)(THIS_ int usetype, int uselevel, int which,
		BOOL show_mfd) PURE;
	STDMETHOD(FindLogData)(THIS_ const int REF LogObj, int usetype, int *level,
		int *which) PURE;
	STDMETHOD(PayNanites)(THIS_ int quan) PURE;
	STDMETHOD(OverlayChange)(THIS_ int which, int mode) PURE;
	STDMETHOD_(int *, Equipped)(THIS_ int REF ret, int slot) PURE;
	STDMETHOD(LevelTransport)(THIS_ const char *newlevel, int marker,
		unsigned int flags) PURE;
	STDMETHOD_(BOOL, CheckLocked)(THIS_ const int REF CheckObj, BOOL verbose,
		const int REF player) PURE;
	STDMETHOD(AddText)(THIS_ const char *msg, const int REF player,
		int time DEF_ARG(5000)) PURE;
	STDMETHOD(AddTranslatableText)(THIS_ const char *msg, const char *table,
		const int REF player, int time DEF_ARG(5000)) PURE;
	STDMETHOD(AmmoLoad)(THIS_ const int REF GunObj, const int REF AmmoObj) PURE;
	STDMETHOD_(int, GetClip)(THIS_ const int REF GunObj) PURE;
	STDMETHOD(AddExp)(THIS_ const int REF Who, int amount, BOOL verbose ) PURE;
	STDMETHOD_(BOOL, HasTrait)(THIS_ const int REF Who, int trait) PURE;
	STDMETHOD_(BOOL, HasImplant)(THIS_ const int REF Who, int implant) PURE;
	STDMETHOD(HealObj)(THIS_ const int REF Who, int amt) PURE;
	STDMETHOD(OverlaySetObj)(THIS_ int which, const int REF Obj) PURE;
	STDMETHOD(Research)(THIS) PURE;
	STDMETHOD_(String *, GetArchetypeName)(THIS_ String REF ret,
		const int REF Obj) PURE;
	STDMETHOD_(BOOL, OverlayOn)(THIS_ int which) PURE;
	STDMETHOD_(int *,FindSpawnPoint)(THIS_ int REF ret, const int REF Obj,
		unsigned int flags) PURE;
	STDMETHOD_(int, CountEcoMatching)(THSI_ int val) PURE;
	STDMETHOD_(int, GetStat)(THIS_ const int REF who, int which) PURE;
	STDMETHOD_(int *, GetSelectedObj)(THIS_ int REF ret) PURE;
	STDMETHOD_(BOOL, AddInvObj)(THIS_ const int REF obj) PURE;
	STDMETHOD(RecalcStats)(THIS_ const int REF who) PURE;
	STDMETHOD(PlayVideo)(THIS_ const char *vidname) PURE;
	STDMETHOD(ClearRadiation)(THIS) PURE;
	STDMETHOD_(void, SetPlayerVolume)(THIS_ float volume) PURE;
	STDMETHOD_(int, RandRange)(THIS_ int low, int high) PURE;
	STDMETHOD_(BOOL, LoadCursor)(THIS_ const int REF obj) PURE;
	STDMETHOD_(void, AddSpeedControl)(THIS_ const char *name, float speed_fac,
		float rot_fac) PURE;
	STDMETHOD_(void, RemoveSpeedControl)(THIS_ const char *name) PURE;
	STDMETHOD(PreventSwap)(THIS) PURE;
	STDMETHOD_(int *, GetDistantSelectedObj)(THIS_ int REF ret) PURE;
	STDMETHOD(Equip)(THIS_ int slot, const int REF Obj) PURE;
	STDMETHOD(OverlayChangeObj)(THIS_ int which, int mode, const int REF Obj)
		PURE;
	STDMETHOD(SetObjState)(THIS_ const int REF Obj, int state) PURE;
	STDMETHOD(RadiationHack)(THIS) PURE;
	STDMETHOD(DestroyAllByName)(THIS_ const char *name) PURE;
	STDMETHOD(AddTextObjProp)(THIS_ const int REF Obj, const char *propname,
		const int REF player, int time DEF_ARG(5000)) PURE;
	STDMETHOD(DisableAlarmGlobal)(THIS) PURE;
	STDMETHOD_(void, Frob)(THIS_ BOOL in_inv DEF_ARG(FALSE)) PURE;
	STDMETHOD(TweqAllByName)(THIS_ const char *name, BOOL state) PURE;
	STDMETHOD(SetExplored)(THIS_ int maploc, char val DEF_ARG(1)) PURE;
	STDMETHOD(RemoveFromContainer)(THIS_ const int REF Obj,
		const int REF Container) PURE;
	STDMETHOD(ActivateMap)(THIS) PURE;
	STDMETHOD_(int, SimTime)(THIS) PURE;
	STDMETHOD_(void, StartFadeIn)(THIS_ int time, unsigned char red,
		unsigned char green, unsigned char blue) PURE;
	STDMETHOD_(void, StartFadeOut)(THIS_ int time, unsigned char red,
		unsigned char green, unsigned char blue) PURE;
	STDMETHOD(GrantPsiPower)(THIS_ const int REF who, int which) PURE;
	STDMETHOD_(BOOL, ResearchConsume)(THIS_ const int REF Obj) PURE;
	STDMETHOD(PlayerMode)(THIS_ int mode) PURE;
	STDMETHOD(EndGame)(THIS) PURE;
	STDMETHOD_(BOOL, AllowDeath)(THIS) PURE;
	STDMETHOD(AddAlarm)(THIS_ int time) PURE;
	STDMETHOD(RemoveAlarm)(THIS) PURE;
	STDMETHOD_(float, GetHazardResistance)(THIS_ int endur) PURE;
	STDMETHOD_(int,GetBurnDmg)(THIS) PURE;
	STDMETHOD_(int *, PlayerGun)(THIS_ int REF ret) PURE;
	STDMETHOD_(BOOL, IsPsiActive)(THIS_ int power) PURE;
	STDMETHOD(PsiRadarScan)(THIS) PURE;
	STDMETHOD_(int *, PseudoProjectile)(THIS_ int REF ret, const int REF source,
		const int REF emittype) PURE;
	STDMETHOD(WearArmor)(THIS_ const int REF Obj) PURE;
	STDMETHOD(SetModify)(THIS_ const int REF Obj, int modlevel) PURE;
	STDMETHOD_(BOOL, Censored)(THIS) PURE;
	STDMETHOD(DebriefMode)(THIS_ int mission) PURE;
	STDMETHOD(TlucTextAdd)(THIS_ char *name, char *table, int offset) PURE;
	STDMETHOD(Mouse)(THIS_ BOOL mode, BOOL clear) PURE;
	STDMETHOD(RefreshInv)(THIS) PURE;
	STDMETHOD(TreasureTable)(THIS_ const int REF Obj) PURE;
	STDMETHOD_(int *, OverlayGetObj)(THIS_ int REF ret) PURE;
	STDMETHOD(VaporizeInv)(THIS) PURE;
	STDMETHOD(ShutoffPsi)(THIS) PURE;
	STDMETHOD(SetQBHacked)(THIS_ const String REF qbname, int qbval) PURE;
	STDMETHOD_(int, GetPlayerMaxPsiPoints)(THIS) PURE;
	STDMETHOD(SetLogTime)(THIS_ int level, int logtype, int which) PURE;
	STDMETHOD(AddTranslatableTextInt)(THIS_ const char *msg, const char *table,
		const int REF player, int val, int time DEF_ARG(5000)) PURE;
	STDMETHOD(ZeroControls)(THIS_ const int REF Obj, BOOL poll) PURE;
	STDMETHOD(SetSelectedPsiPower)(THIS_ int which) PURE;
	STDMETHOD_(BOOL, ValidGun)(THIS_ const int REF Obj) PURE;
	STDMETHOD(AddTranslatableTextIndexInt)(THIS_ const char *msg,
		const char *table, const int REF player, int index, int val,
		int time DEF_ARG(5000)) PURE;
	STDMETHOD_(BOOL, IsAlarmActive)(THIS) PURE;
	STDMETHOD(SlayAllByName)(THIS_ const char *name) PURE;
	STDMETHOD(NoMove)(THIS_ BOOL jump_allowed) PURE;
	STDMETHOD(PlayerModeSimple)(THIS_ int mode) PURE;
	STDMETHOD(UpdateMovingTerrainVelocity)(THIS_ const int objID,
		const int next_node, float speed) PURE;
	STDMETHOD_(BOOL, MouseCursor)(THIS) PURE;
	STDMETHOD_(BOOL, ConfigIsDefined)(THIS_ const char *name) PURE;
	STDMETHOD_(BOOL, ConfigGetInt)(THIS_ const char *name, int REF value) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_SHOCKGAME
#undef SERVICE_DEF_SHOCKGAME
#endif
#define SERVICE_DEF_SHOCKGAME() interface IShockGameService *ShockGame = NULL;
#ifdef SERVICE_EXT_SHOCKGAME
#undef SERVICE_EXT_SHOCKGAME
#endif
#define SERVICE_EXT_SHOCKGAME() extern IShockGameService *ShockGame;
#ifdef SERVICE_IMPL_SHOCKGAME
#undef SERVICE_IMPL_SHOCKGAME
#endif
#define SERVICE_IMPL_SHOCKGAME(_m) IMPLEMENT_SERVICE(_m, ShockGame)

#endif
