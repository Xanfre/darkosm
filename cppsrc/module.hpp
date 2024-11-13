#ifndef __MODULE_H
#define __MODULE_H

#include "apiex.hpp"

/* Script Module Class */
class cScriptModule : public IScriptModule
{
public:
	cScriptModule(const char *);
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
	char name[MAX_PATH];
};

#endif
