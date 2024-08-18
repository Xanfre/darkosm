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

static STDMETHODIMP QueryInterface(THIS_ REFIID riid, void **ppv)
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

static STDMETHODIMP_(unsigned long) AddRef(THIS)
{
	return ++((sScriptModule *) This)->count;
}

static STDMETHODIMP_(unsigned long) Release(THIS)
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

static STDMETHODIMP_(const char*) GetName(THIS)
{
	return ((sScriptModule *) This)->name;
}

static STDMETHODIMP_(const sScrClassDesc*) GetFirstClass(THIS_ unsigned int *iter)
{
	if (NULL != iter)
		*iter = 0;
	return &g_classes[0];
}

static STDMETHODIMP_(const sScrClassDesc*) GetNextClass(THIS_ unsigned int *iter)
{
	return (NULL != iter && *iter + 1 < SCR_NUM) ? &g_classes[++(*iter)] : NULL;
}

static STDMETHODIMP_(void) EndClassIter(THIS_ unsigned int *iter) { UNUSED(iter) }

static IScriptModuleVtbl g_modvtbl = { QueryInterface, AddRef, Release,
									GetName, GetFirstClass, GetNextClass,
									EndClassIter };

BOOL __declspec(dllexport) __stdcall
ScriptModuleInit(const char *name, IScriptMan *man, fScrPrintFunc print,
	IUnknown *alloc, IScriptModule **outmod)
{
	sScriptModule *mod;

	if (NULL == name || NULL == man || NULL == alloc || NULL == outmod)
		return FALSE;
	*outmod = NULL;
	if (NOERROR != COMCALL2(alloc, QueryInterface, &IID_IMalloc,
			(void **) &g_alloc)
		|| NULL == (mod = COMCALL1(g_alloc, Alloc, sizeof(sScriptModule))))
		return FALSE;
	strncpy(mod->name, name, sizeof(mod->name) - 1);
	mod->name[sizeof(mod->name) - 1] = '\0';
	g_man = man;
	if (NULL != print)
		g_print = print;
	mod->lpVtbl = &g_modvtbl;
	mod->count = 0;
	if (NOERROR != COMCALL2((IScriptModule *) mod, QueryInterface,
		&IID_IScriptModule, (void **) outmod))
		return FALSE;
	InitScripts(COMCALL0((IScriptModule *) mod, GetName));
	return TRUE;
}

