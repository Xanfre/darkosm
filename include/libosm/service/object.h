#ifndef __OBJECT_H
#define __OBJECT_H

#include "service.h"

/* Object Service */
#undef INTERFACE
#define INTERFACE IObjectService
DECLARE_SCRIPT_SERVICE(Object, 0xdf)
{
	SERVICE_FUNCS()
	STDMETHOD_(int *, BeginCreate)(THIS_ int REF ret, int archetype_or_clone)
		PURE;
	STDMETHOD(EndCreate)(THIS_ int obj) PURE;
	STDMETHOD_(int *, Create)(THIS_ int REF ret, int archetype_or_clone) PURE;
	STDMETHOD(Destroy)(THIS_ int obj) PURE;
	STDMETHOD_(BOOL *, Exists)(THIS_ BOOL REF ret, int obj) PURE;
	STDMETHOD(SetName)(THIS_ int obj, const char* name) PURE;
	STDMETHOD_(String *, GetName)(THIS_ String REF ret, int obj) PURE;
	STDMETHOD_(int *, Named)(THIS_ int REF ret, const char* name) PURE;
	STDMETHOD(AddMetaProperty)(THIS_ int obj, int metaprop) PURE;
	STDMETHOD(RemoveMetaProperty)(THIS_ int obj, int metaprop) PURE;
	STDMETHOD_(BOOL *,HasMetaProperty)(THIS_ BOOL REF ret, int obj,
		int metaprop) PURE;
	STDMETHOD_(BOOL *,InheritsFrom)(THIS_ BOOL REF ret, int obj,
		int archetype_or_metaprop) PURE;
	STDMETHOD_(BOOL *,IsTransient)(THIS_ BOOL REF ret, int obj) PURE;
	STDMETHOD(SetTransience)(THIS_ int obj, boolean is_transient) PURE;
	STDMETHOD_(sVector,Position)(THIS_ int obj) PURE;
	STDMETHOD_(sVector,Facing)(THIS_ int obj) PURE;
	STDMETHOD(Teleport)(THIS_ int obj, const sVector REF position,
		const sVector REF facing, int ref_frame DEF_ARG(0)) PURE;
#ifndef THIEF1
	STDMETHOD_(BOOL *, IsPositionValid)(THIS_ BOOL REF ret, int obj) PURE;
#ifndef SHOCK
	STDMETHOD_(int *,FindClosestObjectNamed)(THIS_ int REF ret, int objId,
		const char* name) PURE;
#endif
#endif
	STDMETHOD_(int, AddMetaPropertyToMany)(THIS_ int metaprop,
		const string REF ToSet) PURE;
	STDMETHOD_(int, RemoveMetaPropertyFromMany)(THIS_ int metaprop,
		const string REF ToSet) PURE;
	STDMETHOD_(BOOL *, RenderedThisFrame)(THIS_ BOOL REF ret, int scr_obj)
		PURE;

#ifdef NEWDARK
	/*
	** new functions in T2 v1.19 / SS2 v2.4:
	*/

#ifdef SHOCK
	STDMETHOD_(int *, FindClosestObjectNamed)(THIS_ int REF ret, int objId,
		const char* name) PURE;
#endif
	/* transform a pos from object space to world space,
	 * ObjectToWorld(vector(0,0,0)) would be the same as Position() */
	STDMETHOD_(sVector *, ObjectToWorld)(THIS_ sVector REF ret, int obj,
		const sVector REF obj_pos) PURE;

	/*
	** new functions in T2 v1.23 / SS2 v2.44:
	*/

	/* transform a pos from world space to object space,
	 * WorldToObject(Position()) would be the same as vector(0,0,0) */
	STDMETHOD_(sVector *, WorldToObject)(THIS_ sVector REF ret, int obj,
		const sVector REF world_pos) PURE;
	/* calculate the relative transform between two objects, returning the
	 * relative transform for the hypothetical child object
	 * rel_type is a eRelTransformType value and selects what on the parent the
	 * child should be relative to
	 * for joint/vhot/subobj/submodel types the sub_or_vhot_or_joint value has
	 * to be set to the desired joint/vhot/subobj/submodel index */
	STDMETHOD_(BOOL *, CalcRelTransform)(THIS_ BOOL REF ret, int parent_obj,
		int child_obj, sVector REF rel_pos, sVector REF rel_facing,
		eRelTransformType rel_type, int sub_or_vhot_or_joint) PURE;

	/*
	** new functions in T2 v1.24 / SS2 v2.45:
	*/

	/* get the archetype of an object */
	STDMETHOD_(int *, Archetype)(THIS_ int REF ret, int scr_obj) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_OBJECT
#undef SERVICE_DEF_OBJECT
#endif
#define SERVICE_DEF_OBJECT() interface IObjectService *Object = NULL;
#ifdef SERVICE_EXT_OBJECT
#undef SERVICE_EXT_OBJECT
#endif
#define SERVICE_EXT_OBJECT() extern IObjectService *Object;
#ifdef SERVICE_IMPL_OBJECT
#undef SERVICE_IMPL_OBJECT
#endif
#define SERVICE_IMPL_OBJECT(_m) IMPLEMENT_SERVICE(_m, Object)

#endif
