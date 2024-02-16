#ifndef __LINKTOOLS_H
#define __LINKTOOLS_H

#include "service.h"

/* LinkTools Service */
#undef INTERFACE
#define INTERFACE ILinkToolsService
DECLARE_SCRIPT_SERVICE(LinkTools, 0xef)
{
	SERVICE_FUNCS()
	STDMETHOD_(long, LinkKindNamed)(THIS_ const char* name) PURE;
	STDMETHOD_(String *, LinkKindName)(THIS_ String REF ret, long id) PURE;
	STDMETHOD(LinkGet)(THIS_ long id, sLink REF l) PURE;
	STDMETHOD_(MultiParm *, LinkGetData)(THIS_ MultiParm REF ret, long id,
		const char* field) PURE;
	STDMETHOD(LinkSetData)(THIS_ long id, const char* field,
		const MultiParm REF val) PURE;
}; 

/* Populated Implementors */
#ifdef SERVICE_DEF_LINKTOOLS
#undef SERVICE_DEF_LINKTOOLS
#endif
#define SERVICE_DEF_LINKTOOLS() interface ILinkToolsService *LinkTools = NULL;
#ifdef SERVICE_EXT_LINKTOOLS
#undef SERVICE_EXT_LINKTOOLS
#endif
#define SERVICE_EXT_LINKTOOLS() extern ILinkToolsService *LinkTools;
#ifdef SERVICE_IMPL_LINKTOOLS
#undef SERVICE_IMPL_LINKTOOLS
#endif
#define SERVICE_IMPL_LINKTOOLS(_m) IMPLEMENT_SERVICE(_m, LinkTools)

#endif
