#ifndef __PROPERTY_H
#define __PROPERTY_H

#include "service.h"

/* Property Service */
#undef INTERFACE
#define INTERFACE IPropertyService
DECLARE_SCRIPT_SERVICE(Property, 0xda)
{
	SERVICE_FUNCS()
	STDMETHOD_(MultiParm *, Get)(THIS_ MultiParm REF ret, int obj,
		const char * prop, const char * field DEF_ARG(NULL)) PURE;
	STDMETHOD(Set)(THIS_ int obj, const char * prop, const char * field,
		const MultiParm REF) PURE;
	STDMETHOD(SetSimple)(THIS_ int obj, const char * prop, const MultiParm REF)
		PURE;
#ifndef THIEF1
	STDMETHOD(SetLocal)(THIS_ int obj, const char * prop, const char * field,
		const MultiParm REF) PURE;
#endif
	STDMETHOD(Add)(THIS_ int obj, const char* prop) PURE;
	STDMETHOD(Remove)(THIS_ int obj, const char* prop) PURE;
	STDMETHOD(CopyFrom)(THIS_ int targ, const char* prop, int src) PURE;
	STDMETHOD_(BOOL, Possessed)(THIS_ int obj, const char* prop) PURE;

#ifdef NEWDARK
	/*
	** new functions in T2 v1.27 / SS2 v2.48:
	*/

#ifdef THIEF1
	STDMETHOD(SetLocal)(THIS_ int obj, const char * prop, const char * field,
		const MultiParm REF) PURE;
#endif
	/* query if int has a property set locally, ignoring inheritance from
	 * archetypes and metaproperties */
	STDMETHOD_(BOOL, PossessedSimple)(THIS_ int obj, const char* prop) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_PROPERTY
#undef SERVICE_DEF_PROPERTY
#endif
#define SERVICE_DEF_PROPERTY() interface IPropertyService *Property = NULL;
#ifdef SERVICE_EXT_PROPERTY
#undef SERVICE_EXT_PROPERTY
#endif
#define SERVICE_EXT_PROPERTY() extern IPropertyService *Property;
#ifdef SERVICE_IMPL_PROPERTY
#undef SERVICE_IMPL_PROPERTY
#endif
#define SERVICE_IMPL_PROPERTY(_m) IMPLEMENT_SERVICE(_m, Property)

#endif
