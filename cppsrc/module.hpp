#ifndef __MODULE_H
#define __MODULE_H

#include "apiex.hpp"

/* Script Module Class */
class cScriptModule : public IScriptModule
{
public:
	cScriptModule(const char *);
	virtual ~cScriptModule() { }
	STDMETHOD(QueryInterface)(REFIID, void **);
	STDMETHOD_(unsigned long, AddRef)();
	STDMETHOD_(unsigned long, Release)();
	STDMETHOD_(const char*, GetName)();
	STDMETHOD_(const sScrClassDesc*, GetFirstClass)(unsigned int *);
	STDMETHOD_(const sScrClassDesc*, GetNextClass)(unsigned int *);
	STDMETHOD_(void, EndClassIter)(unsigned int *);

private:
	unsigned int count;
	char name[MAX_PATH];
};

#endif
