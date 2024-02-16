#ifndef __MODULE_H
#define __MODULE_H

#include <libosm/api.h>

#undef INTERFACE
#define INTERFACE IScriptModule

/* Script Module Type */
typedef struct sScriptModule
{
	IScriptModuleVtbl *lpVtbl;
	unsigned int count;
} sScriptModule;

/* Script Module Functions */
STDMETHODIMP SMQueryInterface(THIS_ REFIID, void **);
STDMETHODIMP_(unsigned long) SMAddRef(THIS);
STDMETHODIMP_(unsigned long) SMRelease(THIS);
STDMETHODIMP_(const char*) SMGetName(THIS);
STDMETHODIMP_(const sScrClassDesc*) SMGetFirstClass(THIS_ unsigned int *);
STDMETHODIMP_(const sScrClassDesc*) SMGetNextClass(THIS_ unsigned int *);
STDMETHODIMP_(void) SMEndClassIter(THIS_ unsigned int *);

#endif
