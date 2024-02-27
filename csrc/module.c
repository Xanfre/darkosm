#include <string.h>

#include <libosm/api.h>

#include "common.h"
#include "module.h"
#include "script.h"

#undef INTERFACE
#define INTERFACE IScriptModule

#ifdef __GNUC__
const void *__dyn_tls_init_callback = NULL;
#endif

IScriptMan *g_man = NULL;
fScrPrintFunc g_print = NULL;
IMalloc *g_alloc = NULL;

sScrClassDesc g_classes[SCR_NUM];

STDMETHODIMP SMQueryInterface(THIS_ REFIID riid, void **ppv)
{
	if (!IsEqualIID(riid, &IID_IScriptModule))
	{
		if (NULL != ppv)
			*ppv = 0;
		return E_NOINTERFACE;
	}
	if (NULL != ppv)
		*ppv = This;
	COMCALL0(This, AddRef);
	return NOERROR;
}

STDMETHODIMP_(unsigned long) SMAddRef(THIS)
{
	return ++((sScriptModule *) This)->count;
}

STDMETHODIMP_(unsigned long) SMRelease(THIS)
{
	if (0 == ((sScriptModule *) This)->count)
		return 0;
	if (0 == --((sScriptModule *) This)->count && COMCALL1(g_alloc, DidAlloc, This))
	{
		COMCALL1(g_alloc, Free, This);
		return 0;
	}
	return ((sScriptModule *) This)->count;
}

STDMETHODIMP_(const char*) SMGetName(THIS)
{
	return ((sScriptModule *) This)->name;
}

STDMETHODIMP_(const sScrClassDesc*) SMGetFirstClass(THIS_ unsigned int *iter)
{
	if (NULL != iter)
		*iter = 0;
	return &g_classes[0];
}

STDMETHODIMP_(const sScrClassDesc*) SMGetNextClass(THIS_ unsigned int *iter)
{
	return (NULL == iter && *iter + 1 < SCR_NUM) ? &g_classes[++(*iter)] : NULL;
}

STDMETHODIMP_(void) SMEndClassIter(THIS_ unsigned int *iter) { UNUSED(iter) }

static IScriptModuleVtbl g_modvtbl = { SMQueryInterface, SMAddRef, SMRelease,
									SMGetName, SMGetFirstClass, SMGetNextClass,
									SMEndClassIter };

BOOL __declspec(dllexport) __stdcall
ScriptModuleInit(const char *name, IScriptMan *man, fScrPrintFunc print,
	IUnknown *alloc, IScriptModule **outmod)
{
	sScriptModule *mod;

	if (NULL == name || NULL == man || NULL == print || NULL == alloc
		|| NULL == outmod)
		return FALSE;

	*outmod = NULL;

	if (NOERROR != COMCALL2(alloc, QueryInterface, &IID_IMalloc,
			(void **) &g_alloc)
		|| NULL == (mod = COMCALL1(g_alloc, Alloc, sizeof(sScriptModule))))
		return FALSE;

	strncpy(mod->name, name, sizeof(mod->name) - 1);
	g_man = man;
	g_print = print;

	mod->lpVtbl = &g_modvtbl;
	mod->count = 0;
	if (NOERROR != COMCALL2((IScriptModule *) mod, QueryInterface,
		&IID_IScriptModule, (void **) outmod))
		return FALSE;

	InitScripts(COMCALL0((IScriptModule *) mod, GetName));

	return TRUE;
}

