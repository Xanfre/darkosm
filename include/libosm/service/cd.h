#ifndef __CD_H
#define __CD_H

#include "service.h"

/* CD Service */
#undef INTERFACE
#define INTERFACE ICDService
DECLARE_SCRIPT_SERVICE(CD, 0x226)
{
	SERVICE_FUNCS()
	STDMETHOD(SetBGM)(THIS_ int track) PURE;
	STDMETHOD(SetTrack)(THIS_ int track, unsigned int flags) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_CD
#undef SERVICE_DEF_CD
#endif
#define SERVICE_DEF_CD() interface ICDService *CD = NULL;
#ifdef SERVICE_EXT_CD
#undef SERVICE_EXT_CD
#endif
#define SERVICE_EXT_CD() extern ICDService *CD;
#ifdef SERVICE_IMPL_CD
#undef SERVICE_IMPL_CD
#endif
#define SERVICE_IMPL_CD(_m) IMPLEMENT_SERVICE(_m, CD)

#endif
