#include <libosm/api.h>

#include "common.h"

#undef INTERFACE
#define INTERFACE IScript

/* Contants */
#define SCR_NUM 1

/* Script Setup Macros */
#define MAKE_SCR(_n,_a) \
	STDMETHODIMP_(const char*) _n##GetClassName(THIS) { return ((sScript *) This)->name; } \
	static IScriptVtbl _n##Vtbl = { SQueryInterface, SAddRef, SRelease, _n##GetClassName, _n##ReceiveMessage }; \
	IScript * _n##Factory(const char *msg, int obj) \
	{ \
		sScript *s; \
		IScript *script = NULL; \
		UNUSED(msg) \
		if (NULL == _a || NULL == (s = COMCALL1(_a, Alloc, sizeof(sScript)))) \
			return NULL; \
		s->lpVtbl = &_n##Vtbl; \
		s->count = 1; \
		s->name = #_n; \
		s->obj = obj; \
		_n##Vtbl.QueryInterface((void *) s, &IID_IScript, (void **) &script); \
		return 0 == _n##Vtbl.Release((void *) s) ? NULL : script; \
	}
#define SCR_DESC(_n,_r,_i) \
	g_classes[_i].mod = modname; \
	g_classes[_i].name = #_n; \
	g_classes[_i].base = #_r; \
	g_classes[_i].factory = _n##Factory;
#define SCR_DESC_DEF(_n,_i) SCR_DESC(_n, RootScript, _i)

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
STDMETHODIMP SQueryInterface(THIS_ REFIID, void **);
STDMETHODIMP_(unsigned long) SAddRef(THIS);
STDMETHODIMP_(unsigned long) SRelease(THIS);
STDMETHODIMP TestScriptReceiveMessage(THIS_ sScrMsg *, sMultiParm *, eScrTraceAction);
long TestScriptOnFrobWorldEnd(sScript *, sFrobMsg *, sMultiParm *);
void InitScripts(const char *modname);
