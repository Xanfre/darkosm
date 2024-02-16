#ifndef __DOOR_H
#define __DOOR_H

#include "service.h"

/* Door Service */
#undef INTERFACE
#define INTERFACE IDoorService
DECLARE_SCRIPT_SERVICE(Door, 0xf6)
{
	SERVICE_FUNCS()
	STDMETHOD_(BOOL, CloseDoor)(THIS_ int door_obj) PURE;
	STDMETHOD_(BOOL, OpenDoor)(THIS_ int door_obj) PURE;
	STDMETHOD_(int, GetDoorState)(THIS_ int door_obj) PURE;
	STDMETHOD(ToggleDoor)(THIS_ int door_obj) PURE;
#if (!defined(THIEF1) || defined(SHOCK)) || defined(NEWDARK)
	STDMETHOD(SetBlocking)(THIS_ int door_obj, BOOL state) PURE;
	STDMETHOD_(BOOL, GetSoundBlocking)(THIS_ int door_obj) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_DOOR
#undef SERVICE_DEF_DOOR
#endif
#define SERVICE_DEF_DOOR() interface IDoorService *Door = NULL;
#ifdef SERVICE_EXT_DOOR
#undef SERVICE_EXT_DOOR
#endif
#define SERVICE_EXT_DOOR() extern IDoorService *Door;
#ifdef SERVICE_IMPL_DOOR
#undef SERVICE_IMPL_DOOR
#endif
#define SERVICE_IMPL_DOOR(_m) IMPLEMENT_SERVICE(_m, Door)

#endif
