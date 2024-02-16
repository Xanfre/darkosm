#ifndef __PHYSICS_H
#define __PHYSICS_H

#include "service.h"

/* Physics Service */
#undef INTERFACE
#define INTERFACE IPhysicsService
DECLARE_SCRIPT_SERVICE(Physics, 0x141)
{
	SERVICE_FUNCS()
	STDMETHOD(SubscribeMsg)(THIS_ int phys_obj, int message_types) PURE;
	STDMETHOD(UnsubscribeMsg)(THIS_ int phys_obj, int message_types) PURE;
	STDMETHOD_(int *, LaunchProjectile)(THIS_ int REF ret, int launcher,
		int proj, float power, int flags, const sVector REF add_vel) PURE;
	STDMETHOD(SetVelocity)(THIS_ int obj, const sVector REF vel) PURE;
	STDMETHOD(GetVelocity)(THIS_ int obj, sVector REF vel) PURE;
#if !defined(SHOCK) && !defined(THIEF1)
	STDMETHOD(ControlVelocity)(THIS_ int obj, const sVector REF vel) PURE;
	STDMETHOD(StopControlVelocity)(THIS_ int obj) PURE;
#endif
	STDMETHOD(SetGravity)(THIS_ int obj, float gravity) PURE;
	STDMETHOD_(float, GetGravity)(THIS_ int obj) PURE;
	STDMETHOD_(BOOL, HasPhysics)(THIS_ int obj) PURE;
	STDMETHOD_(BOOL, IsSphere)(THIS_ int obj) PURE;
	STDMETHOD_(BOOL, IsOBB)(THIS_ int obj) PURE;
	STDMETHOD(ControlCurrentLocation)(THIS_ int obj) PURE;
	STDMETHOD(ControlCurrentRotation)(THIS_ int obj) PURE;
	STDMETHOD(ControlCurrentPosition)(THIS_ int obj) PURE;
	STDMETHOD(DeregisterModel)(THIS_ int obj) PURE;
	STDMETHOD_(void, PlayerMotionSetOffset)(THIS_ int subModel,
		sVector REF offset) PURE;
	STDMETHOD(Activate)(THIS_ const int obj) PURE;
	STDMETHOD_(BOOL, ValidPos)(THIS_ const int obj) PURE;

#ifdef NEWDARK
	/*
	** new functions in T2 v1.19 / SS2 v2.4:
	*/

	/* is object a rope */
	STDMETHOD_(BOOL, IsRope)(THIS_ const int REF obj) PURE;
	/* get climbable int that 'climber' is currently attached to, OBJ_NULL
	 * if none */
	STDMETHOD_(void, GetClimbingObject)(THIS const int REF climber,
		int REF climbobj) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_PHYSICS
#undef SERVICE_DEF_PHYSICS
#endif
#define SERVICE_DEF_PHYSICS() interface IPhysicsService *Physics = NULL;
#ifdef SERVICE_EXT_PHYSICS
#undef SERVICE_EXT_PHYSICS
#endif
#define SERVICE_EXT_PHYSICS() extern IPhysicsService *Physics;
#ifdef SERVICE_IMPL_PHYSICS
#undef SERVICE_IMPL_PHYSICS
#endif
#define SERVICE_IMPL_PHYSICS(_m) IMPLEMENT_SERVICE(_m, Physics)

#endif
