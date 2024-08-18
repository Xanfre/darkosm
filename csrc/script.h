#include <libosm/api.h>

#include "common.h"

#undef INTERFACE
#define INTERFACE IScript

/* Contants */
#define SCR_NUM 1

/* Script Setup Macros */
#define MAKE_SCR(_n,_a) \
	static STDMETHODIMP_(const char*) _n##GetClassName(THIS) \
	{ \
		return ((sScript *) This)->name; \
	} \
	static STDMETHODIMP _n##ReceiveMessage(THIS_ sScrMsg *, sMultiParm *, \
		eScrTraceAction); \
	static IScriptVtbl _n##Vtbl = { QueryInterface, AddRef, Release, \
		_n##GetClassName, _n##ReceiveMessage }; \
	IScript * _n##Factory(const char *s, int obj) \
	{ \
		sScript *scr; \
		IScript *ret = NULL; \
		\
		UNUSED(s) \
		\
		if (NULL == (scr = COMCALL1(_a, Alloc, sizeof(sScript)))) \
			return NULL; \
		scr->lpVtbl = &_n##Vtbl; \
		scr->count = 0; \
		scr->name = #_n; \
		scr->obj = obj; \
		COMCALL2((IScript *) scr, QueryInterface, &IID_IScript, \
			(void **) &ret); \
		return ret; \
	}
#define SCR_DESC(_m,_n,_r,_i) \
	g_classes[_i].mod = _m; \
	g_classes[_i].name = #_n; \
	g_classes[_i].base = #_r; \
	g_classes[_i].factory = _n##Factory;
#define SCR_DESC_DEF(_m,_n,_i) SCR_DESC(_m, _n, RootScript, _i)

/* Message Macros */
#define SCR_HANDLE_MSG(_n,_m,_t,_p1,_p2) \
	if (!strcmp(_p1->message, #_m)) \
		return _n##On##_m((sScript *) This, (_t *) _p1, _p2);
#define SCR_HANDLE_MSG_(_n,_m,_t,_p1,_p2) \
	else SCR_HANDLE_MSG(_n, _m, _t, _p1, _p2)

/* Script Helper Macros */
#define MESSAGE_IS(_m,_s) !strcmp(_m->message, #_s)

/* Script Type */
typedef struct sScript
{
	IScriptVtbl *lpVtbl;
	unsigned int count;
	const char *name;
	int obj;
} sScript;

/* Prototypes */
long TestScriptOnFrobWorldEnd(sScript *, sFrobMsg *, sMultiParm *);
void InitScripts(const char *modname);
