#ifndef __API_H
#define __API_H

#include <initguid.h>
#include <objbase.h>

/* Helper macros */
#define IUNKNOWN_FUNCS() \
	STDMETHOD(QueryInterface)(THIS_ REFIID, void **) PURE; \
	STDMETHOD_(unsigned long, AddRef)(THIS)  PURE; \
	STDMETHOD_(unsigned long, Release)(THIS) PURE;
#define INIT_SERVICES()
#ifdef __cplusplus
#define DEF_ARG(_x) = _x
#else
#define DEF_ARG(_x)
#endif

/* Definitions */
#ifndef MultiParm
#define MultiParm sMultiParm
#endif
#ifndef String
#define String char *
#endif
#ifdef __cplusplus
#define REF &
#else
#define REF *
#endif

/* Forward Declarations */
typedef struct sMultiParm sMultiParm;
typedef struct sScrMsg sScrMsg;

/* GUID Definitions */
DEFINE_GUID(IID_IScript, 0xd00000d0, 0x7b50, 0x129f, 0x83, 0x48, 0x00, 0xaa, 0x00, 0xa8, 0x2b, 0x51);
DEFINE_GUID(IID_IScriptMan, 0xcf0000cf, 0x7b4f, 0x129e, 0x83, 0x48, 0x00, 0xaa, 0x00, 0xa8, 0x2b, 0x51);
DEFINE_GUID(IID_IScriptModule, 0xd40000d4, 0x7b54, 0x12a3, 0x83, 0x48, 0x00, 0xaa, 0x00, 0xa8, 0x2b, 0x51);

/* Functions */
typedef int (*fScrPrintFunc)(const char *, ...);
typedef interface IScript * (*fScrFactoryFunc)(const char *, int);
typedef void (*fScrMsgCallback)(const sScrMsg *, const sMultiParm *, void *);
typedef int (*fPersistIOFunc)(void *, void *, size_t);

/* Enumerations */
typedef enum eAIAction
{
	kAIA_NoAction,
	kAIA_GoTo,
	kAIA_Frob,
	kAIA_Maneuver
} eAIAction;
typedef enum eAIActionPriority
{
	kAIAP_Low,
	kAIAP_Normal,
	kAIAP_High
} eAIActionPriority;
typedef enum eAIActionResult
{
	kAIAR_Done,
	kAIAR_Failed,
	kAIAR_NotAttempted
} eAIActionResult;
typedef enum eAIMode
{
	kAIM_Asleep,
	kAIM_SuperEfficient,
	kAIM_Efficient,
	kAIM_Normal,
	kAIM_Combat,
	kAIM_Dead,
	kAIM_Num
} eAIMode;
typedef enum eAIScriptAlertLevel
{
	kAIAL_None,
	kAIAL_Low,
	kAIAL_Moderate,
	kAIAL_High
} eAIScriptAlertLevel;
typedef enum eAIScriptSpeed
{
	kAISS_Slow,
	kAISS_Normal,
	kAISS_Fast
} eAIScriptSpeed;
typedef enum eBodyAction
{
	kBA_MotionStart,
	kBA_MotionEnd,
	kBA_MotionFlagReached
} eBodyAction;
typedef enum eDarkWeaponType
{
	kDWT_Sword,
	kDWT_Blackjack
} eDarkWeaponType;
typedef enum eDoorAction
{
	kDA_Open,
	kDA_Close,
	kDA_Opening,
	kDA_Closing,
	kDA_Halt
} eDoorAction;
typedef enum eDrkInvCap
{
	kDIC_Cycle,
	kDIC_WorldFrob,
	kDIC_WorldFocus,
	kDIC_InvFrob
} eDrkInvCap;
typedef enum eDrkInvControl
{
	kDICL_On,
	kDICL_Off,
	kDICL_Toggle
} eDrkInvControl;
typedef enum eEnvSoundLoc
{
	kESL_OnObj,
	kESL_AtObjLoc,
	kESL_Ambient
} eEnvSoundLoc;
typedef enum eFrobLoc
{
	kFL_World,
	kFL_Inv,
	kFL_Tool,
	kFL_None,
	kFL_NumActions = kFL_None
} eFrobLoc;
typedef enum eKeyUse
{
	kKU_Default,
	kKU_Open,
	kKU_Close,
	kKU_Check
} eKeyUse;
typedef enum eMultiParmType
{
	kMT_Undefined,
	kMT_Integer,
	kMT_Float,
	kMT_String,
	kMT_Vector,
	kMT_Object
} eMultiParmType;
typedef enum eObjType
{
	kOT_Player,
	kOT_RemotePlayer,
	kOT_Creature,
	kOT_Object,
	kOT_None
} eObjType;
typedef enum ePhysCollisionType
{
	kPCT_CollNone,
	kPCT_CollTerrain,
	kPCT_CollObject
} ePhysCollisionType;
typedef enum ePhysContactType
{
	kPCT_ConNone,
	kPCT_ConFace,
	kPCT_ConEdge,
	kPCT_ConVertex,
	kPCT_ConSphere,
	kPCT_ConSphereHat,
	kPCT_ConOBB
} ePhysContactType;
typedef enum ePhysMsgResult
{
	kPMR_Default,
	kPMR_DoNothing,
	kPMR_Bounce,
	kPMR_Slay,
	kPMR_Remove
} ePhysMsgResult;
typedef enum ePsiPowers
{
	kPP_Level1,
	kPP_PsiScreen,
	kPP_StillHand,
	kPP_Pull,
	kPP_Quickness,
	kPP_Cyber,
	kPP_Cryokinesis,
	kPP_Codebreaker,
	kPP_Level2,
	kPP_Stability,
	kPP_Berserk,
	kPP_RadShield,
	kPP_Heal,
	kPP_Might,
	kPP_Psi,
	kPP_Immolate,
	kPP_Level3,
	kPP_Fabricate,
	kPP_Electro,
	kPP_AntiPsi,
	kPP_ToxinShield,
	kPP_Radar,
	kPP_Pyrokinesis,
	kPP_Terror,
	kPP_Level4,
	kPP_Invisibility,
	kPP_Seeker,
	kPP_Dampen,
	kPP_Vitality,
	kPP_Alchemy,
	kPP_CyberHack,
	kPP_Sword,
	kPP_Level5,
	kPP_MajorHealing,
	kPP_SomaDrain,
	kPP_Teleport,
	kPP_Enrage,
	kPP_ForceWall,
	kPP_Mines,
	kPP_Shield,
	kPP_Max,
	kPP_None = kPP_Max
} ePsiPowers;
typedef enum eQuestDataType
{
	kQDT_Mission,
	kQDT_Campaign,
	kQDT_Unknown
} eQuestDataType;
typedef enum eRelTransformType
{
	kRTT_Object,
	kRTT_Joint,
	kRTT_VHot,
	kRTT_SubObject,
	kRTT_SubPhysModel
} eRelTransformType;
typedef enum eScrTimedMsgKind
{
	kSTM_OneShot,
	kSTM_Periodic
} eScrTimedMsgKind;
typedef enum eScrTraceAction
{
	kSTA_NoAction,
	kSTA_Break,
	kSTA_Spew,
	kSTA_Pad = 65536
} eScrTraceAction;
typedef enum eSoundNetwork
{
	kSN_Default,
	kSN_NetworkAmbient,
	kSN_NoNetworkSpatial
} eSoundNetwork;
typedef enum eSoundSpecial
{
	kSS_Normal,
	kSS_Loop
} eSoundSpecial;
typedef enum eStyleColorKind
{
	kSCK_FG,
	kSCK_BG,
	kSCK_Text,
	kSCK_Hilite,
	kSCK_Bright,
	kSCK_Dim,
	kSCK_FG2,
	kSCK_BG2,
	kSCK_Border,
	kSCK_White,
	kSCK_Black,
	kSCK_XOR,
	kSCK_BevelLight,
	kSCK_BevelDark
} eStyleColorKind;
typedef enum eTransType
{
	kTT_Enter,
	kTT_Exit,
	kTT_RoomTransit
} eTransType;
typedef enum eTweqDirection
{
	kTD_Forward,
	kTD_Reverse
} eTweqDirection;
typedef enum eTweqOperation
{
	kTO_KillAll,
	kTO_RemoveTweq,
	kTO_HaltTweq,
	kTO_StatusQuo,
	kTO_SlayAll,
	kTO_FrameEvent
} eTweqOperation;
typedef enum eTweqType
{
	kTT_Scale,
	kTT_Rotate,
	kTT_Joints,
	kTT_Models,
	kTT_Delete,
	kTT_Emitter,
	kTT_Flicker,
	kTT_Lock,
	kTT_All,
	kTT_Null
} eTweqType;

/* Types */
typedef struct sDatapath
{
	unsigned char num;
	unsigned char last;
	BOOL nocurrent;
	char *datapath[16];
	int findflags;
} sDatapath;
typedef struct sLink
{
	int source;
	int dest;
	int flavor;
} sLink;
struct sMultiParm
{
	union
	{
		int i;
		int o;
		float f;
		char *s;
		union sVector *v;
	} val;
	eMultiParmType type;
};
typedef struct sScrClassDesc
{
	const char *mod;
	const char *name;
	const char *base;
	fScrFactoryFunc factory;
} sScrClassDesc;
typedef struct sScrDatumTag
{
	int objId;
	const char *_class;
	const char *name;
} sScrDatumTag;
typedef struct sScrSrvDesc
{
	IUnknown **iface;
	GUID *guid;
} sScrSrvDesc;
typedef struct sScrTraceHashKey
{
	unsigned char combo[40];
} sScrTraceHashKey;
typedef struct sScrTrace
{
	int hostobj;
	eScrTraceAction action;
	int line;
	sScrTraceHashKey hashkey;
} sScrTrace;
typedef struct sVector
{
	float x, y, z;
} sVector;

/* Script Message Types */
#ifdef __cplusplus
#define SCR_MSG_NAME(_s) virtual const char * __thiscall GetName() { return _s; };
typedef struct sPersistent
{
	virtual ~sPersistent() { }
	virtual BOOL __thiscall Persistence() { return FALSE; }
	SCR_MSG_NAME("No Factory")
} sPersistent;
typedef struct sScrMsgBase : IUnknown
{
	virtual ~sScrMsgBase() { }
	STDMETHODIMP QueryInterface(REFIID, void **);
	STDMETHODIMP_(unsigned long) AddRef() { return ++count; }
	STDMETHODIMP_(unsigned long) Release()
	{
		if (0 == count)
			return 0;
		if (0 == --count)
			delete this;
		return count;
	}
	unsigned int count;
} sScrMsgBase;
#define SCR_MSG_GEN()
struct sScrMsg : sScrMsgBase, sPersistent
{
	SCR_MSG_NAME("sScrMsg")
	int from;
	int to;
	const char *message;
	unsigned long time;
	int flags;
	sMultiParm data;
	sMultiParm data2;
	sMultiParm data3;
};
#define SCR_MSG_TYPE(_s) struct _s : sScrMsg
#else
#define SCR_MSG_NAME(_s)
typedef struct sPersistentVtbl
{
	void (*Destruct)(void *); /* destructor */
	BOOL (*Persistence)(struct sPersistentVtbl *); /* __thiscall */
	const char * (*GetName)(struct sPersistentVtbl *); /* __thiscall */
} sPersistentVtbl;
#define SCR_MSG_GEN() \
	IUnknownVtbl *lpVtbl; /* manually populated */ \
	unsigned int count; \
	sPersistentVtbl *lpPersistentVtbl; /* manually populated */ \
	int from; \
	int to; \
	const char *message; \
	unsigned long time; \
	int flags; \
	sMultiParm data; \
	sMultiParm data2; \
	sMultiParm data3;
struct sScrMsg
{
	SCR_MSG_GEN()
};
#define SCR_MSG_TYPE(_s) struct _s
#endif
typedef SCR_MSG_TYPE(sSimMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sSimMsg")
	BOOL starting;
} sSimMsg;
typedef SCR_MSG_TYPE(sDarkGameModeScrMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sDarkGameModeScrMsg")
	BOOL resuming;
	BOOL suspending;
} sDarkGameModeScrMsg;
typedef SCR_MSG_TYPE(sAIModeChangeMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sAIModeChangeMsg")
	eAIMode mode;
	eAIMode prevmode;
} sAIModeChangeMsg;
typedef SCR_MSG_TYPE(sAIAlertnessMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sAIAlertnessMsg")
	eAIScriptAlertLevel level;
	eAIScriptAlertLevel oldlevel;
} sAIAlertnessMsg;
typedef SCR_MSG_TYPE(sAIHighAlertMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sAIHighAlertMsg")
	eAIScriptAlertLevel level;
	eAIScriptAlertLevel oldlevel;
} sAIHighAlertMsg;
typedef SCR_MSG_TYPE(sAIResultMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sAIResultMsg")
	eAIAction action;
	eAIActionResult result;
	sMultiParm resultdata;
} sAIResultMsg;
typedef SCR_MSG_TYPE(sAIObjActResultMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sAIObjActResultMsg")
	int target;
} sAIObjActResultMsg;
typedef SCR_MSG_TYPE(sAIPatrolPointMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sAIPatrolPointMsg")
	int targetobj;
} sAIPatrolPointMsg;
typedef SCR_MSG_TYPE(sAISignalMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sAISignalMsg")
	const char *signal;
} sAISignalMsg;
typedef SCR_MSG_TYPE(sAttackMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sAttackMsg")
	int weapon;
} sAttackMsg;
typedef SCR_MSG_TYPE(sCombineScrMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sCombinScrMsg")
	int combiner;
} sCombineScrMsg;
typedef SCR_MSG_TYPE(sContainedScrMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sContainedScrMsg")
	int container;
} sContainedScrMsg;
typedef SCR_MSG_TYPE(sContainerScrMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sContainerScrMsg")
	int containee;
} sContainerScrMsg;
typedef SCR_MSG_TYPE(sDamageScrMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sDamageScrMSg")
	int kind;
	int damage;
	int culprit;
} sDamageScrMsg;
typedef SCR_MSG_TYPE(sDiffScrMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sDiffScrMsg")
	int difficulty;
} sDiffScrMsg;
typedef SCR_MSG_TYPE(sDoorMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sDoorMsg")
	eDoorAction action;
	eDoorAction prevaction;
#ifndef THIEF1
	BOOL proxy;
#endif
} sDoorMsg;
typedef SCR_MSG_TYPE(sFrobMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sFrobMsg")
	int srcobj;
	int destobj;
	int frobber;
	eFrobLoc srcloc;
	eFrobLoc destloc;
	float sec;
	BOOL abort;
} sFrobMsg;
typedef SCR_MSG_TYPE(sBodyMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sBodyMsg")
	eBodyAction actiontype;
	const char *motionname;
	int flagvalue;
} sBodyMsg;
typedef SCR_MSG_TYPE(sPickStateMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sPickStateMsg")
	int prevstate;
	int newstate;
} sPickStateMsg;
typedef SCR_MSG_TYPE(sPressurePlateMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sPressurePlateMsg")
} sPressurePlateMsg;
typedef SCR_MSG_TYPE(sPhysMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sPhysMsg")
	int submod;
	ePhysCollisionType colltype;
	int collobj;
	int collsubmod;
	float collmomentum;
	sVector collnormal;
	sVector collpoint;
	ePhysContactType contacttype;
	int contactobj;
	int contactsubmod;
	int transobj;
	int transsubmod;
} sPhysMsg;
typedef SCR_MSG_TYPE(sReportMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sReportMsg")
	int warnlevel;
	int reportflags;
	int types;
	char *textbuf;
} sReportMsg;
typedef SCR_MSG_TYPE(sRoomMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sRoomMsg")
	int fromobj;
	int toobj;
	int moveobj;
	eObjType objtype;
	eTransType transtype;
} sRoomMsg;
typedef SCR_MSG_TYPE(sSlayMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sSlayMsg")
	int culprit;
	int kind;
} sSlayMsg;
typedef SCR_MSG_TYPE(sSchemaDoneMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sSchemaDoneMsg")
	sVector coordinates;
	int targetobj;
	const char *name;
} sSchemaDoneMsg;
typedef SCR_MSG_TYPE(sSoundDoneMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sSoundDoneMsg")
	sVector coordinates;
	int targetobj;
	const char *name;
} sSoundDoneMsg;
typedef SCR_MSG_TYPE(sStimMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sStimMsg")
	int stimulus;
	float intensity;
	int sensor;
	int source;
} sStimMsg;
typedef SCR_MSG_TYPE(sScrTimerMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sScrTimerMsg")
	const char *name;
} sScrTimerMsg;
typedef SCR_MSG_TYPE(sTweqMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sTweqMsg")
	eTweqType type;
	eTweqOperation op;
	eTweqDirection dir;
} sTweqMsg;
typedef SCR_MSG_TYPE(sWaypointMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sWaypointMsg")
	int movingterrain;
} sWaypoingMsg;
typedef SCR_MSG_TYPE(sQuestMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sQuestMsg")
	const char *name;
	int oldvalue;
	int newvalue;
} sQuestMsg;
typedef SCR_MSG_TYPE(sMediumTransMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sMediumTransMsg")
	int fromtype;
	int totype;
} sMediumTransMsg;
#ifdef SHOCK2
typedef SCR_MSG_TYPE(sYorNMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sYorNMsg")
	int yorn;
} sYorNMsg;
typedef SCR_MSG_TYPE(sKeypadMsg)
{
	SCR_MSG_GEN()
	SCR_MSG_NAME("sKeypadMsg")
	int code;
} sKeypadMsg;
#endif
#undef SCR_MSG_NAME
#undef SCR_MSG_GEN
#undef SCR_MSG_TYPE

/* Interface Definitions */
#undef INTERFACE
#define INTERFACE IScript
DECLARE_INTERFACE_(IScript, IUnknown)
{
	IUNKNOWN_FUNCS()
	STDMETHOD_(const char *, GetClassName)(THIS) PURE;
	STDMETHOD (ReceiveMessage)(THIS_ sScrMsg *, sMultiParm *,
		eScrTraceAction) PURE;

};
#undef INTERFACE
#define INTERFACE IScriptMan
DECLARE_INTERFACE_(IScriptMan, IUnknown)
{
	IUNKNOWN_FUNCS()
	STDMETHOD (GameInit)(THIS) PURE;
	STDMETHOD (GameEnd)(THIS) PURE;
	STDMETHOD(BeginScripts)(THIS) PURE;
	STDMETHOD(EndScripts)(THIS) PURE;
	STDMETHOD (SetModuleDatapath)(THIS_ const sDatapath *) PURE;
	STDMETHOD (AddModule)(THIS_ const char *) PURE;
	STDMETHOD (RemoveModule)(THIS_ const char *) PURE;
	STDMETHOD (ClearModules)(THIS) PURE;
	STDMETHOD (ExposeService)(THIS_ IUnknown *, const GUID *) PURE;
	STDMETHOD_(IUnknown *, GetService)(THIS_ const GUID *) PURE;
	STDMETHOD_(const sScrClassDesc *, GetFirstClass)(THIS_ unsigned int *) PURE;
	STDMETHOD_(const sScrClassDesc *, GetNextClass)(THIS_ unsigned int *) PURE;
	STDMETHOD_(void, EndClassIter)(THIS_ unsigned int *) PURE;
	STDMETHOD_(const sScrClassDesc *, GetClass)(THIS_ const char *) PURE;
	STDMETHOD (SetObjScripts)(THIS_ int, const char **, unsigned n) PURE;
	STDMETHOD (ForgetObj)(THIS_ int) PURE;
	STDMETHOD (ForgetAllObjs)(THIS) PURE;
	STDMETHOD_(BOOL, WantsMessage)(THIS_ int, const char *) PURE;
	STDMETHOD (SendMessage)(THIS_ sScrMsg *, sMultiParm *) PURE;
	STDMETHOD_(void, KillTimedMessage)(THIS_ void *) PURE;
	STDMETHOD_(int, PumpMessages)(THIS) PURE;
	STDMETHOD_(void, PostMessage)(THIS_ sScrMsg *) PURE;
	STDMETHOD_(void *, SetTimedMessage)(THIS_ sScrMsg *, unsigned long,
		eScrTimedMsgKind) PURE;
	STDMETHOD_ (sMultiParm, SendMessage2)(int, int, const char *,
		const MultiParm REF, const MultiParm REF, const MultiParm REF) PURE;
#ifdef THIEF1
	STDMETHOD_(void, PostMessage2)(int, int, const char *, const MultiParm REF,
		const MultiParm REF, const MultiParm REF) PURE;
#else
	STDMETHOD_(void, PostMessage2)(int, int, const char *, const MultiParm REF,
		const MultiParm REF, const MultiParm REF, unsigned long flags) PURE;
#endif
	STDMETHOD_(void *, SetTimedMessage2)(int, const char *, unsigned long,
		eScrTimedMsgKind, const MultiParm REF) PURE;
	STDMETHOD_(BOOL, IsScriptDataSet)(THIS_ const sScrDatumTag *) PURE;
	STDMETHOD (GetScriptData)(THIS_ const sScrDatumTag *, sMultiParm *) PURE;
	STDMETHOD (SetScriptData)(THIS_ const sScrDatumTag *,
		const sMultiParm *) PURE;
	STDMETHOD (ClearScriptData)(THIS_ const sScrDatumTag *, sMultiParm *) PURE;
	STDMETHOD (AddTrace)(int Object, char *, eScrTraceAction, int) PURE;
	STDMETHOD (RemoveTrace)(int, char *) PURE;
	STDMETHOD_ (BOOL, GetTraceLine)(int) PURE;
	STDMETHOD_ (void, SetTraceLine)(int, BOOL) PURE;
	STDMETHOD_ (int, GetTraceLineMask)() PURE;
	STDMETHOD_ (void, SetTraceLineMask)(int) PURE;
	STDMETHOD_(const sScrTrace *, GetFirstTrace)(unsigned int *) PURE;
	STDMETHOD_(const sScrTrace *, GetNextTrace)(unsigned int *) PURE;
	STDMETHOD_(void, EndTraceIter)(unsigned int *) PURE;
	STDMETHOD (SaveLoad)(THIS_ fPersistIOFunc, void *, BOOL) PURE;
	STDMETHOD_(void, PostLoad)() PURE;
};
#undef INTERFACE
#define INTERFACE IScriptModule
DECLARE_INTERFACE_(IScriptModule, IUnknown)
{
	IUNKNOWN_FUNCS()
	STDMETHOD_(const char *, GetName)(THIS) PURE;
	STDMETHOD_(const sScrClassDesc *, GetFirstClass)(THIS_ unsigned int *) PURE;
	STDMETHOD_(const sScrClassDesc *, GetNextClass)(THIS_ unsigned int *) PURE;
	STDMETHOD_(void, EndClassIter)(THIS_ unsigned int *) PURE;
};

#endif
