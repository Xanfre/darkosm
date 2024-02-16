#ifndef __AI_H
#define __AI_H

#include "service.h"

/* AI Service */
#undef INTERFACE
#define INTERFACE IAIService
DECLARE_SCRIPT_SERVICE(AI, 0xe5)
{
	SERVICE_FUNCS()
	STDMETHOD_(BOOL *, MakeGotoObjLoc)(THIS_ BOOL REF ret, int objIdAI,
		const int *objIdTarget, eAIScriptSpeed speed DEF_ARG(kAISS_Normal),
		eAIActionPriority DEF_ARG(kAIAP_Normal),
		const MultiParm REF dataToSendOnReach DEF_ARG(MultiParm())) PURE;
	STDMETHOD_(BOOL *, MakeFrobObj)(THIS_ BOOL REF ret, int objIdAI,
		const int *objIdTarget, eAIActionPriority DEF_ARG(kAIAP_Normal),
		const MultiParm REF dataToSendOnReach DEF_ARG(MultiParm())) PURE;
	STDMETHOD_(BOOL *, MakeFrobObjWith)(THIS_ BOOL REF ret, int objIdAI,
		const int *objIdTarget, const int *objWith,
		eAIActionPriority DEF_ARG(kAIAP_Normal),
		const MultiParm REF dataToSendOnReach DEF_ARG(MultiParm())) PURE;
	STDMETHOD_(eAIScriptAlertLevel, GetAlertLevel)(THIS_ int objIdAI) PURE;
	STDMETHOD_(void, SetMinimumAlert)(THIS_ int objIdAI,
		eAIScriptAlertLevel level) PURE;
	STDMETHOD_(void, ClearGoals)(THIS_ int objIdAI) PURE;
	STDMETHOD_(void, SetScriptFlags)(THIS_ int objIdAI, int iFlags) PURE;
	STDMETHOD_(void, ClearAlertness)(THIS_ int objIdAI) PURE;
	STDMETHOD_(void, Signal)(THIS_ int objIdAI, String REF signal) PURE;
	STDMETHOD_(BOOL *, StartConversation)(THIS_ BOOL REF ret,
		int conversationID) PURE;

#ifdef NEWDARK
	/*
	** new functions in T2 v1.27 / SS2 v2.48:
	*/

	/* stun-related functions previously only available through the ShockAI
	 * script service are now available to all games here */
	STDMETHOD_(BOOL, Stun)(THIS_ int who, String REF startTags,
		String REF loopTags, float sec) PURE;
	STDMETHOD_(BOOL, IsStunned)(THIS_ int who) PURE;
	STDMETHOD_(BOOL, UnStun)(THIS_ int who) PURE;
	/* freeze-related functions previously only available through the ShockAI
	 * script service are now available to all games here */
	STDMETHOD_(BOOL, Freeze)(THIS_ int who, float sec) PURE;
	STDMETHOD_(BOOL, IsFrozen)(THIS_ int who) PURE;
	STDMETHOD_(BOOL, UnFreeze)(THIS_ int who) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_AI
#undef SERVICE_DEF_AI
#endif
#define SERVICE_DEF_AI() interface IAIService *AI = NULL;
#ifdef SERVICE_EXT_AI
#undef SERVICE_EXT_AI
#endif
#define SERVICE_EXT_AI() extern IAIService *AI;
#ifdef SERVICE_IMPL_AI
#undef SERVICE_IMPL_AI
#endif
#define SERVICE_IMPL_AI(_m) IMPLEMENT_SERVICE(_m, AI)

#endif
