#ifndef __CAMERA_H
#define __CAMERA_H

#include "service.h"

/* Camera Service */
#undef INTERFACE
#define INTERFACE ICameraService
DECLARE_SCRIPT_SERVICE(Camera, 0x140)
{
	SERVICE_FUNCS()
	STDMETHOD(StaticAttach)(THIS_ int attachee) PURE;
	STDMETHOD(DynamicAttach)(THIS_ int attachee) PURE;
	STDMETHOD(CameraReturn)(THIS_ int attachee) PURE;
	STDMETHOD(ForceCameraReturn)(THIS) PURE;

#ifdef NEWDARK
	/*
	** new functions in T2 v1.22 / SS2 v2.43:
	*/

	/* get the int the camera is currently attached to */
	STDMETHOD_(int *, GetCameraParent)(THIS int REF ret) PURE;
	/* returns true if GetCameraParent() != PlayerObject() */
	STDMETHOD_(BOOL *, IsRemote)(THIS_ BOOL ret) PURE;
	/* get location/rotation for the camera */
	STDMETHOD_(sVector *, GetPosition)(THIS_ sVector REF ret) PURE;
	STDMETHOD_(sVector *, GetFacing)(THIS_ sVector REF ret) PURE;

	/*
	** new functions in T2 v1.23 / SS2 v2.44:
	*/

	/* transform a pos from camera space to world space,
	 * WorldToCamera(vector(0,0,0)) would be the same as GetPosition() */
	STDMETHOD_(sVector *, CameraToWorld)(THIS_ sVector REF ret,
		const sVector REF local_pos) PURE;
	/* transform a pos from world space to camera space,
	 * WorldToCamera(GetPosition()) would be the same as vector(0,0,0) */
	STDMETHOD_(sVector *, WorldToCamera)(THIS_ sVector REF ret,
		const sVector REF world_pos) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_CAMERA
#undef SERVICE_DEF_CAMERA
#endif
#define SERVICE_DEF_CAMERA() interface ICameraService *Camera = NULL;
#ifdef SERVICE_EXT_CAMERA
#undef SERVICE_EXT_CAMERA
#endif
#define SERVICE_EXT_CAMERA() extern ICameraService *Camera;
#ifdef SERVICE_IMPL_CAMERA
#undef SERVICE_IMPL_CAMERA
#endif
#define SERVICE_IMPL_CAMERA(_m) IMPLEMENT_SERVICE(_m, Camera)

#endif
