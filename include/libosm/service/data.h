#ifndef __DATA_H
#define __DATA_H

#include "service.h"

/* Data Service */
#undef INTERFACE
#define INTERFACE IDataService
DECLARE_SCRIPT_SERVICE(Data, 0x1a0)
{
	SERVICE_FUNCS()
	STDMETHOD_(String *, GetString)(THIS_ String REF ret, const char* table,
		const char* name, const char* def DEF_ARG(""),
		const char* relpath DEF_ARG("strings")) PURE;
	STDMETHOD_(String *, GetObjString)(THIS_ String REF ret, int obj,
		const char* table) PURE;
	STDMETHOD_(int, DirectRand)(THIS) PURE;
	STDMETHOD_(int, RandInt)(THIS_ int low, int high) PURE;
	STDMETHOD_(float, RandFlt0to1)(THIS) PURE;
	STDMETHOD_(float, RandFltNeg1to1)(THIS) PURE;
}; 

/* Populated Implementors */
#ifdef SERVICE_DEF_DATA
#undef SERVICE_DEF_DATA
#endif
#define SERVICE_DEF_DATA() interface IDataService *Data = NULL;
#ifdef SERVICE_EXT_DATA
#undef SERVICE_EXT_DATA
#endif
#define SERVICE_EXT_DATA() extern IDataService *Data;
#ifdef SERVICE_IMPL_DATA
#undef SERVICE_IMPL_DATA
#endif
#define SERVICE_IMPL_DATA(_m) IMPLEMENT_SERVICE(_m, Data)

#endif
