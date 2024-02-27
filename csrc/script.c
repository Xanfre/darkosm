#include <stdio.h>

#include <libosm/api.h>
#include <libosm/service/debug.h>
#include <libosm/service/implement.h>

#include "common.h"
#include "script.h"

#undef INTERFACE
#define INTERFACE IScript

extern IScriptMan *g_man;
extern fScrPrintFunc g_print;
extern IMalloc *g_alloc;

extern sScrClassDesc g_classes[SCR_NUM];

DEF_SERVICES()

STDMETHODIMP SQueryInterface(THIS_ REFIID riid, void **ppv)
{
	if (!IsEqualIID(riid, &IID_IScript))
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

STDMETHODIMP_(unsigned long) SAddRef(THIS)
{
	return NULL == This ? 0 : ++((sScript *) This)->count;
}

STDMETHODIMP_(unsigned long) SRelease(THIS)
{
	if (NULL == This || 0 == ((sScript *) This)->count)
		return 0;
	if (0 == --((sScript *) This)->count && COMCALL1(g_alloc, DidAlloc, This))
	{
		COMCALL1(g_alloc, Free, This);
		return 0;
	}
	return ((sScript *) This)->count;
}

MAKE_SCR(TestScript, g_alloc)

STDMETHODIMP TestScriptReceiveMessage(THIS_ sScrMsg *msg, sMultiParm *data,
	eScrTraceAction act)
{
	UNUSED(act)

	SCR_HANDLE_MSG(TestScript, FrobWorldEnd, sFrobMsg, msg, data)
	return 0;
}

long TestScriptOnFrobWorldEnd(sScript *scr, sFrobMsg *msg, sMultiParm *data)
{
	char srcobj[33] = { 0 };
	char frobber[33] = { 0 };
	const char *m[8] = { "FrobWorldEnd on ", NULL, " from ", NULL, "", "", "",
		"" };

	UNUSED(scr)
	UNUSED(data)

	m[1] = &srcobj[0];
	m[3] = &frobber[0];
	sprintf(srcobj, "%d", msg->srcobj);
	sprintf(frobber, "%d", msg->frobber);
	COMCALL8(Debug, MPrint, &m[0], &m[1], &m[2], &m[3], &m[4], &m[5], &m[6],
		&m[7]);
	return 0;
}

void InitScripts(const char *modname)
{
	INIT_SERVICES(g_man)
	SCR_DESC_DEF(modname, TestScript, 0)
}
