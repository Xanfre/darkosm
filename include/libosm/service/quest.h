#ifndef __QUEST_H
#define __QUEST_H

#include "service.h"

/* Quest Service */
#undef INTERFACE
#define INTERFACE IQuestService
DECLARE_SCRIPT_SERVICE(Quest, 0x152)
{
	SERVICE_FUNCS()
	/* new for T2 v1.26 / SS2 v2.47 is that you can subscribe to name "*" in
	 * order to get QuestChange messages for all qvars (unsubscribe "*" to
	 * remove it again) */
	STDMETHOD_(BOOL, SubscribeMsg)(THIS_ int obj, const char *pName,
		eQuestDataType type DEF_ARG(kQDT_Unknown)) PURE;
	STDMETHOD_(BOOL, UnsubscribeMsg)(THIS_ int obj, const char *pName) PURE;
	STDMETHOD(Set)(THIS_ const char *pName, int value,
		eQuestDataType type DEF_ARG(kQDT_Mission)) PURE;
	STDMETHOD_(int, Get)(THIS_ const char *pName) PURE;
	STDMETHOD_(BOOL, Exists)(THIS_ const char* pName) PURE;
	/* Note that unlike Set, Delete events are not broadcast over network in MP,
	 * if there are scripts that depend on a qvar delete being broadcast the
	 * script has to handle broadcasting itself */
	STDMETHOD_(BOOL, Delete)(THIS_ const char *pName) PURE;

#ifdef NEWDARK
	/*
	** new functions in T2 v1.26 / SS2 v2.47:
	*/

	/* These functions provide script access to a campaign quest data binary
	 * store. Useful when campaign qvars consisting only of single int values
	 * isn't enough.
	 *
	 * The binary data stores allows storage of arbitrary data chunks up to
	 * 65000 bytes in size. BinSet will fail if max length is exceeded or length
	 * is <= 0.
	 *
	 * The interface is similar to regular qvars but has no interaction with the
	 * qvar database. Bin data entries could have the same name as regular qvars
	 * without causing any interference, since they're two separate databases.
	 * SubscribeMsg or any other of the above funtions do NOT work with bin
	 * data. Any other engine features that interact with qvars will also NOT
	 * work with bin data. Only scripts specifically made for using bin data
	 * have access to it.
	 *
	 * The data chunks are stored as named chunks, like qvars, but make sure
	 * you use unique enough names that guarantee there won't be any name
	 * collisions with other scripts. Otherwise another script, with differently
	 * formatted data, could cause all kinds of trouble if they accidentally
	 * used the same name. */

	/* Set existing bin data chunk, creates it if necessary */
	STDMETHOD(BinSet)(THIS_ const char *pName, const void *pData, int iLen)
		PURE;
	/* Get bin data, returns NULL if undefined */
	STDMETHOD_(const void*, BinGet)(THIS_ const char *pName, int REF iLen) PURE;
	/* determine whether a quest bin data chunk exists */
	STDMETHOD_(BOOL, BinExists)(THIS_ const char* pName) PURE;
	/* Delete quest bin data chunk */
	STDMETHOD_(BOOL, BinDelete)(THIS_ const char *pName) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_QUEST
#undef SERVICE_DEF_QUEST
#endif
#define SERVICE_DEF_QUEST() interface IQuestService *Quest = NULL;
#ifdef SERVICE_EXT_QUEST
#undef SERVICE_EXT_QUEST
#endif
#define SERVICE_EXT_QUEST() extern IQuestService *Quest;
#ifdef SERVICE_IMPL_QUEST
#undef SERVICE_IMPL_QUEST
#endif
#define SERVICE_IMPL_QUEST(_m) IMPLEMENT_SERVICE(_m, Quest)

#endif
