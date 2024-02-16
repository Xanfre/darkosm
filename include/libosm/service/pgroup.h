#ifndef __PGROUP_H
#define __PGROUP_H

#include "service.h"

/* PGroup Service */
#undef INTERFACE
#define INTERFACE IPGroupService
DECLARE_SCRIPT_SERVICE(PGroup, 0x1f8)
{
	SERVICE_FUNCS()
	STDMETHOD(SetActive)(THIS_ int PGroupObjID, BOOL active) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_PGROUP
#undef SERVICE_DEF_PGROUP
#endif
#define SERVICE_DEF_PGROUP() interface IPGroupService *PGroup = NULL;
#ifdef SERVICE_EXT_PGROUP
#undef SERVICE_EXT_PGROUP
#endif
#define SERVICE_EXT_PGROUP() extern IPGroupService *PGroup;
#ifdef SERVICE_IMPL_PGROUP
#undef SERVICE_IMPL_PGROUP
#endif
#define SERVICE_IMPL_PGROUP(_m) IMPLEMENT_SERVICE(_m, PGroup)

#endif
