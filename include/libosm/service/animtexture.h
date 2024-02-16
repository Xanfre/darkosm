#ifndef __ANIMTEXTURE_H
#define __ANIMTEXTURE_H

#include "service.h"

/* AnimTexture Service */
#undef INTERFACE
#define INTERFACE IAnimTextureService
DECLARE_SCRIPT_SERVICE(AnimTexture, 0x16a)
{
	SERVICE_FUNCS()
	STDMETHOD(ChangeTexture)(THIS_ int refobj, const char *fam1,
		const char *tx1, const char *fam2, const char *tx2) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_ANIMTEXTURE
#undef SERVICE_DEF_ANIMTEXTURE
#endif
#define SERVICE_DEF_ANIMTEXTURE() interface IAnimTextureService *AnimTexture = NULL;
#ifdef SERVICE_EXT_ANIMTEXTURE
#undef SERVICE_EXT_ANIMTEXTURE
#endif
#define SERVICE_EXT_ANIMTEXTURE() extern IAnimTextureService *AnimTexture;
#ifdef SERVICE_IMPL_ANIMTEXTURE
#undef SERVICE_IMPL_ANIMTEXTURE
#endif
#define SERVICE_IMPL_ANIMTEXTURE(_m) IMPLEMENT_SERVICE(_m, AnimTexture)

#endif
