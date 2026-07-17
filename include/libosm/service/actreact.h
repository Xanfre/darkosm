#ifndef __ACTREACT_H
#define __ACTREACT_H

#include "service.h"

/* ActReact Service */
#undef INTERFACE
#define INTERFACE IActReactService
DECLARE_SCRIPT_SERVICE(ActReact, 0xF4)
{
	SERVICE_FUNCS()
	STDMETHOD(React)(THIS_ long what, float stim_intensity,
		int target DEF_ARG(0), int agent DEF_ARG(0),
		const MultiParm REF parm1 DEF_ARG(0),
		const MultiParm REF parm2 DEF_ARG(0),
		const MultiParm REF parm3 DEF_ARG(0),
		const MultiParm REF parm4 DEF_ARG(0),
		const MultiParm REF parm5 DEF_ARG(0),
		const MultiParm REF parm6 DEF_ARG(0),
		const MultiParm REF parm7 DEF_ARG(0),
		const MultiParm REF parm8 DEF_ARG(0))
		PURE;
#ifdef THIEF1
#ifdef NEWDARK
	STDMETHOD(StimulateLegacy)(THIS_ int who, int what, float how_much) PURE;
#else
	STDMETHOD(Stimulate)(THIS_ int who, int what, float how_much) PURE;
#endif
#else
	STDMETHOD(Stimulate)(THIS_ int who, int what, float how_much,
		int source DEF_ARG(0)) PURE;
#endif
	STDMETHOD_(int, GetReactionNamed)(THIS_ const char* name) PURE;
	STDMETHOD_(String *, GetReactionName)(THIS_ String REF ret, long id) PURE;
	STDMETHOD(SubscribeToStimulus)(THIS_ int obj, int what) PURE;
	STDMETHOD(UnsubscribeToStimulus)(THIS_ int obj, int what) PURE;
	STDMETHOD(BeginContact)(THIS_ int source, int sensor) PURE;
	STDMETHOD(EndContact)(THIS_ int source, int sensor) PURE;
	STDMETHOD(SetSingleSensorContact)(THIS_ int source, int sensor) PURE;

#ifdef NEWDARK
	/*
	** new functions in T2 v1.28 / SS2 v2.49:
	*/

#ifdef THIEF1
	/* this should replace the old T1/G interface method and should be
	 * preferred over the legacy method in new modules */
	STDMETHOD(Stimulate)(THIS_ int who, int what, float how_much,
		int source DEF_ARG(0)) PURE;
#endif
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_ACTREACT
#undef SERVICE_DEF_ACTREACT
#endif
#define SERVICE_DEF_ACTREACT() interface IActReactService *ActReact = NULL;
#ifdef SERVICE_EXT_ACTREACT
#undef SERVICE_EXT_ACTREACT
#endif
#define SERVICE_EXT_ACTREACT() extern IActReactService *ActReact;
#ifdef SERVICE_IMPL_ACTREACT
#undef SERVICE_IMPL_ACTREACT
#endif
#define SERVICE_IMPL_ACTREACT(_m) IMPLEMENT_SERVICE(_m, ActReact)

#endif
