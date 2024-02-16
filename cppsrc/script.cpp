#include <cstdio>

#include "api.hpp"
#include "script.hpp"

#include <libosm/service/debug.h>
#include <libosm/service/implement.h>

extern IScriptMan *g_man;
extern fScrPrintFunc g_print;
extern IMalloc *g_alloc;

extern sScrClassDesc g_classes[SCR_NUM];

DEF_SERVICES()

STDMETHODIMP cScript::QueryInterface(REFIID riid, void **ppv)
{
	if (!IsEqualIID(riid, IID_IScript))
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

STDMETHODIMP_(unsigned long) cScript::AddRef()
{
	return ++count;
}

STDMETHODIMP_(unsigned long) cScript::Release()
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

STDMETHODIMP_(const char*) cScript::GetClassName()
{
	return name;
}

STDMETHODIMP cScript::ReceiveMessage(sScrMsg *, sMultiParm *, eScrTraceAction)
{
	return 0;
}

MAKE_SCR(TestScript)

STDMETHODIMP TestScript::ReceiveMessage(sScrMsg *msg, sMultiParm *data,
	eScrTraceAction act)
{
	SCR_HANDLE_MSG(FrobWorldEnd, sFrobMsg, msg, data)
	return cScript::ReceiveMessage(msg, data, act);
}

long TestScript::OnFrobWorldEnd(sFrobMsg *msg, sMultiParm *)
{
	char srcobj[33] = { 0 };
	char frobber[33] = { 0 };
	sprintf(srcobj, "%d", msg->srcobj);
	sprintf(frobber, "%d", msg->frobber);
	Debug->MPrint("FrobWorldEnd on ", srcobj, " from ", frobber);
	return 0;
}

void InitScripts(const char *modname)
{
	unsigned int i = 0;
	INIT_SERVICES(g_man)
	SCR_DESC_DEF(TestScript, i);
}
