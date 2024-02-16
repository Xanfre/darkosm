#if !defined(__DRKPOWERUPS_H) && !defined(SHOCK)
#define __DRKPOWERUPS_H

#include "service.h"

/* DrkPowerups Service*/
#undef INTERFACE
#define INTERFACE IDrkPowerupsService
DECLARE_SCRIPT_SERVICE(DrkPowerups, 0x153)
{
	SERVICE_FUNCS()
	STDMETHOD_(void, TriggerWorldFlash)(THIS_ int obj) PURE;
	STDMETHOD_(BOOL, ObjTryDeploy)(THIS_ int src_object, int deploy_arch) PURE;
	STDMETHOD_(void, CleanseBlood)(THIS_ int water_src_object, float rad) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_DRKPOWERUPS
#undef SERVICE_DEF_DRKPOWERUPS
#endif
#define SERVICE_DEF_DRKPOWERUPS() interface IDrkPowerupsService *DrkPowerups = NULL;
#ifdef SERVICE_EXT_DRKPOWERUPS
#undef SERVICE_EXT_DRKPOWERUPS
#endif
#define SERVICE_EXT_DRKPOWERUPS() extern IDrkPowerupsService *DrkPowerups;
#ifdef SERVICE_IMPL_DRKPOWERUPS
#undef SERVICE_IMPL_DRKPOWERUPS
#endif
#define SERVICE_IMPL_DRKPOWERUPS(_m) IMPLEMENT_SERVICE(_m, DrkPowerups)

#endif
