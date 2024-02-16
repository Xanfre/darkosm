#ifndef __DEBUG_H
#define __DEBUG_H

#include "service.h"

/* Debug Service */
#undef INTERFACE
#define INTERFACE IDebugService
DECLARE_SCRIPT_SERVICE(Debug, 0xd7)
{
	SERVICE_FUNCS()
	STDMETHOD(MPrint)(THIS_ const String REF, const String REF DEF_ARG(""),
		const String REF DEF_ARG(""), const String REF DEF_ARG(""),
		const String REF DEF_ARG(""), const String REF DEF_ARG(""),
		const String REF DEF_ARG(""), const String REF DEF_ARG("")) PURE;
	STDMETHOD(Command)(THIS_ const String REF, const String REF DEF_ARG(""),
		const String REF DEF_ARG(""), const String REF DEF_ARG(""),
		const String REF DEF_ARG(""), const String REF DEF_ARG(""),
		const String REF DEF_ARG(""), const String REF DEF_ARG("")) PURE;
	STDMETHOD(Break)(THIS) PURE;

#ifdef NEWDARK
	/*
	** new functions in T2 v1.19 / SS2 v2.4:
	*/

	/* log file output (works in game exe too) */
	STDMETHOD(Log)(THIS_ const String REF, const String REF DEF_ARG(""),
		const String REF DEF_ARG(""), const String REF DEF_ARG(""),
		const String REF DEF_ARG(""), const String REF DEF_ARG(""),
		const String REF DEF_ARG(""), const String REF DEF_ARG("")) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_DEBUG
#undef SERVICE_DEF_DEBUG
#endif
#define SERVICE_DEF_DEBUG() interface IDebugService *Debug = NULL;
#ifdef SERVICE_EXT_DEBUG
#undef SERVICE_EXT_DEBUG
#endif
#define SERVICE_EXT_DEBUG() extern IDebugService *Debug;
#ifdef SERVICE_IMPL_DEBUG
#undef SERVICE_IMPL_DEBUG
#endif
#define SERVICE_IMPL_DEBUG(_m) IMPLEMENT_SERVICE(_m, Debug)

#endif
