#include <cstring>

#include "apiex.hpp"
#include "module.hpp"
#include "script.hpp"

#ifdef __GNUC__
extern "C" { const void *__dyn_tls_init_callback = NULL; }
#endif

IScriptMan *g_man = NULL;
fScrPrintFunc g_print = NULL;
IMalloc *g_alloc = NULL;

sScrClassDesc g_classes[SCR_NUM];

cScriptModule::cScriptModule(const char *s) : count(0)
{
	strncpy(name, s, sizeof(name) - 1);
	name[sizeof(name) - 1] = '\0';
}

STDMETHODIMP cScriptModule::QueryInterface(REFIID riid, void **ppv)
{
	if (!IsEqualIID(riid, IID_IScriptModule))
	{
		if (NULL != ppv)
			*ppv = 0;
		return E_NOINTERFACE;
	}
	if (NULL != ppv)
		*ppv = this;
	AddRef();
	return NOERROR;
}

STDMETHODIMP_(unsigned long) cScriptModule::AddRef()
{
	return ++count;
}

STDMETHODIMP_(unsigned long) cScriptModule::Release()
{
	if (0 == count)
		return 0;
	if (0 == --count)
	{
		delete this;
		return 0;
	}
	return count;
}

STDMETHODIMP_(const char*) cScriptModule::GetName()
{
	return name;
}

STDMETHODIMP_(const sScrClassDesc*)
cScriptModule::GetFirstClass(unsigned int *iter)
{
	if (NULL != iter)
		*iter = 0;
	return &g_classes[0];
}

STDMETHODIMP_(const sScrClassDesc*)
cScriptModule::GetNextClass(unsigned int *iter)
{
	return (NULL != iter && *iter + 1 < SCR_NUM) ? &g_classes[++(*iter)] : NULL;
}

STDMETHODIMP_(void) cScriptModule::EndClassIter(unsigned int *) { }

extern "C" BOOL __declspec(dllexport) __stdcall
ScriptModuleInit(const char *name, IScriptMan *man, fScrPrintFunc print,
	IUnknown *alloc, IScriptModule **outmod)
{
	cScriptModule *mod;

	if (NULL == name || NULL == man || NULL == alloc || NULL == outmod)
		return FALSE;
	*outmod = NULL;
	if (NOERROR != alloc->QueryInterface(IID_IMalloc, (void **) &g_alloc)
		|| NULL == (mod = new cScriptModule(name)))
		return FALSE;
	g_man = man;
	if (NULL != print)
		g_print = print;
	if (NOERROR != mod->QueryInterface(IID_IScriptModule, (void **) outmod))
		return FALSE;
	InitScripts(mod->GetName());
	return TRUE;
}

