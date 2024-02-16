#ifndef __MODULE_H
#define __MODULE_H

#include "api.hpp"

/* Script Module Class */
class cScriptModule : public IScriptModule
{
public:
	cScriptModule(const char *s) { modname = s; }
	virtual ~cScriptModule() { }
	STDMETHODIMP QueryInterface(REFIID, void **);
	STDMETHODIMP_(unsigned long) AddRef();
	STDMETHODIMP_(unsigned long) Release();
	STDMETHODIMP_(const char*) GetName();
	STDMETHODIMP_(const sScrClassDesc*) GetFirstClass(unsigned int *);
	STDMETHODIMP_(const sScrClassDesc*) GetNextClass(unsigned int *);
	STDMETHODIMP_(void) EndClassIter(unsigned int *);

private:
	unsigned int count;
	const char *modname;
};

#endif
