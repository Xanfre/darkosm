#ifndef __SERVICE_H
#define __SERVICE_H

#include "../api.h"

/* Helper macros */
#define SERVICE_FUNCS() \
	IUNKNOWN_FUNCS() \
	STDMETHOD_(void, Init)() PURE; \
	STDMETHOD_(void, End)() PURE;
#define DECLARE_SCRIPT_SERVICE_(_n, _i) \
	GUID IID_I##_n##Service = { \
		((((unsigned long)(_i) & 0xff) << 24) \
			| (((unsigned long)(_i) & 0xff00) << 16) \
			| ((unsigned long)(_i) & 0xffff)), \
		0x7a80+(_i), 0x11cf+(_i), \
		{ 0x83, 0x48, 0x00, 0xaa, 0x00, 0xa8, 0x2b, 0x51 } \
	};
#define DECLARE_SCRIPT_SERVICE(_n, _i) \
	DECLARE_SCRIPT_SERVICE_(_n, _i) \
	DECLARE_INTERFACE_(I##_n##Service, IUnknown)
#ifdef __cplusplus
#define IMPLEMENT_SERVICE(_m,_s) \
	_s = (interface I##_s##Service *) _m->GetService(&IID_I##_s##Service);
#else
#define IMPLEMENT_SERVICE(_m,_s) \
	_s = (interface I##_s##Service *) _m->lpVtbl->GetService(_m, &IID_I##_s##Service);
#endif

/* Null Service GUID */
#undef INTERFACE
#define INTERFACE INullService
DECLARE_SCRIPT_SERVICE_(Null, 0xf2)

/* Empty Implementors */
#define SERVICE_IMPL_AI(_m)
#define SERVICE_DEF_AI()
#define SERVICE_EXT_AI()
#define SERVICE_IMPL_PHYSICS(_m)
#define SERVICE_DEF_PHYSICS()
#define SERVICE_EXT_PHYSICS()
#define SERVICE_IMPL_ANIMTEXTURE(_m)
#define SERVICE_DEF_ANIMTEXTURE()
#define SERVICE_EXT_ANIMTEXTURE()
#define SERVICE_IMPL_PROPERTY(_m)
#define SERVICE_DEF_PROPERTY()
#define SERVICE_EXT_PROPERTY()
#define SERVICE_IMPL_DEBUG(_m)
#define SERVICE_DEF_DEBUG()
#define SERVICE_EXT_DEBUG()
#define SERVICE_IMPL_OBJECT(_m)
#define SERVICE_DEF_OBJECT()
#define SERVICE_EXT_OBJECT()
#define SERVICE_IMPL_LINK(_m)
#define SERVICE_DEF_LINK()
#define SERVICE_EXT_LINK()
#define SERVICE_IMPL_LINKTOOLS(_m)
#define SERVICE_DEF_LINKTOOLS()
#define SERVICE_EXT_LINKTOOLS()
#define SERVICE_IMPL_SOUND(_m)
#define SERVICE_DEF_SOUND()
#define SERVICE_EXT_SOUND()
#define SERVICE_IMPL_ACTREACT(_m)
#define SERVICE_DEF_ACTREACT()
#define SERVICE_EXT_ACTREACT()
#define SERVICE_IMPL_DOOR(_m)
#define SERVICE_DEF_DOOR()
#define SERVICE_EXT_DOOR()
#define SERVICE_IMPL_LOCKED(_m)
#define SERVICE_DEF_LOCKED()
#define SERVICE_EXT_LOCKED()
#define SERVICE_IMPL_PUPPET(_m)
#define SERVICE_DEF_PUPPET()
#define SERVICE_EXT_PUPPET()
#define SERVICE_IMPL_DAMAGE(_m)
#define SERVICE_DEF_DAMAGE()
#define SERVICE_EXT_DAMAGE()
#define SERVICE_IMPL_KEY(_m)
#define SERVICE_DEF_KEY()
#define SERVICE_EXT_KEY()
#define SERVICE_IMPL_CAMERA(_m)
#define SERVICE_DEF_CAMERA()
#define SERVICE_EXT_CAMERA()
#define SERVICE_IMPL_QUEST(_m)
#define SERVICE_DEF_QUEST()
#define SERVICE_EXT_QUEST()
#define SERVICE_IMPL_LIGHT(_m)
#define SERVICE_DEF_LIGHT()
#define SERVICE_EXT_LIGHT()
#define SERVICE_IMPL_CONTAINER(_m)
#define SERVICE_DEF_CONTAINER()
#define SERVICE_EXT_CONTAINER()
#define SERVICE_IMPL_DATA(_m)
#define SERVICE_DEF_DATA()
#define SERVICE_EXT_DATA()
#define SERVICE_IMPL_PGROUP(_m)
#define SERVICE_DEF_PGROUP()
#define SERVICE_EXT_PGROUP()
#define SERVICE_IMPL_NETWORKING(_m)
#define SERVICE_DEF_NETWORKING()
#define SERVICE_EXT_NETWORKING()
#define SERVICE_IMPL_CD(_m)
#define SERVICE_DEF_CD()
#define SERVICE_EXT_CD()
#define SERVICE_IMPL_VERSION(_m)
#define SERVICE_DEF_VERSION()
#define SERVICE_EXT_VERSION()
#define SERVICE_IMPL_ENGINE(_m)
#define SERVICE_DEF_ENGINE()
#define SERVICE_EXT_ENGINE()
#define SERVICE_IMPL_WEAPON(_m)
#define SERVICE_DEF_WEAPON()
#define SERVICE_EXT_WEAPON()
#define SERVICE_IMPL_PICKLOCK(_m)
#define SERVICE_DEF_PICKLOCK()
#define SERVICE_EXT_PICKLOCK()
#define SERVICE_IMPL_BOW(_m)
#define SERVICE_DEF_BOW()
#define SERVICE_EXT_BOW()
#define SERVICE_IMPL_DRKINV(_m)
#define SERVICE_DEF_DRKINV()
#define SERVICE_EXT_DRKINV()
#define SERVICE_IMPL_DRKPOWERUPS(_m)
#define SERVICE_DEF_DRKPOWERUPS()
#define SERVICE_EXT_DRKPOWERUPS()
#define SERVICE_IMPL_PLAYERLIMBS(_m)
#define SERVICE_DEF_PLAYERLIMBS()
#define SERVICE_EXT_PLAYERLIMBS()
#define SERVICE_IMPL_DARKUI(_m)
#define SERVICE_DEF_DARKUI()
#define SERVICE_EXT_DARKUI()
#define SERVICE_IMPL_DARKGAME(_m)
#define SERVICE_DEF_DARKGAME()
#define SERVICE_EXT_DARKGAME()
#define SERVICE_IMPL_DARKOVERLAY(_m)
#define SERVICE_DEF_DARKOVERLAY()
#define SERVICE_EXT_DARKOVERLAY()
#define SERVICE_IMPL_SHOCKGAME(_m)
#define SERVICE_DEF_SHOCKGAME()
#define SERVICE_EXT_SHOCKGAME()
#define SERVICE_IMPL_SHOCKPSI(_m)
#define SERVICE_DEF_SHOCKPSI()
#define SERVICE_EXT_SHOCKPSI()
#define SERVICE_IMPL_SHOCKOBJ(_m)
#define SERVICE_DEF_SHOCKOBJ()
#define SERVICE_EXT_SHOCKOBJ()
#define SERVICE_IMPL_SHOCKWEAPON(_m)
#define SERVICE_DEF_SHOCKWEAPON()
#define SERVICE_EXT_SHOCKWEAPON()
#define SERVICE_IMPL_SHOCKAI(_m)
#define SERVICE_DEF_SHOCKAI()
#define SERVICE_EXT_SHOCKAI()
#define SERVICE_IMPL_SHOCKOVERLAY(_m)
#define SERVICE_DEF_SHOCKOVERLAY()
#define SERVICE_EXT_SHOCKOVERLAY()

#endif
