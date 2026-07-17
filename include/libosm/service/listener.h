#ifndef __LISTENER_H
#define __LISTENER_H

#include "service.h"

/* Listener Service */
#undef INTERFACE
#define INTERFACE IListenerService
DECLARE_SCRIPT_SERVICE(Listener, 0x22c)
{
	SERVICE_FUNCS()
	/* listen to a property */
	STDMETHOD(SubscribeProperty)(THIS_ const int REF watcher, const int REF obj,
		const char *propname,
		ePropertyListenMsg interests
			DEF_ARG(kListenPropModify|kListenPropSet|kListenPropUnset),
		BOOL async DEF_ARG(FALSE)) PURE;
	STDMETHOD(UnubscribeProperty)(THIS_ const int REF watcher,
		const int REF obj, const char *propname) PURE;
	/* listen to an int */
	STDMETHOD(SubscribeObject)(THIS_ const int REF watcher, const int REF obj,
		BOOL dbmsgs DEF_ARG(FALSE), BOOL async DEF_ARG(FALSE)) PURE;
	STDMETHOD(UnubscribeObject)(THIS_ const int REF watcher, const int REF obj)
		PURE;
	/* listen to a link flavor */
	STDMETHOD(SubscribeLink)(THIS_ const int REF watcher, const int REF obj,
		long kind,
		eRelationListenMsg interests
			DEF_ARG(kListenLinkModify|kListenLinkBirth|kListenLinkDeath),
		BOOL async DEF_ARG(FALSE)) PURE;
	STDMETHOD(UnubscribeLink)(THIS_ const int REF watcher, const int REF obj,
		long kind) PURE;
	/* listen to hierarchy changes */
	STDMETHOD(SubscribeHierarchy)(THIS_ const int REF watcher,
		const int REF obj, BOOL async DEF_ARG(FALSE)) PURE;
	STDMETHOD(UnsubscribeHierarchy)(THIS_ const int REF watcher,
		const int REF obj) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_LISTENER
#undef SERVICE_DEF_LISTENER
#endif
#define SERVICE_DEF_LISTENER() interface IListenerService *Listener = NULL;
#ifdef SERVICE_EXT_LISTENER
#undef SERVICE_EXT_LISTENER
#endif
#define SERVICE_EXT_LISTENER() extern IListenerService *Listener;
#ifdef SERVICE_IMPL_LISTENER
#undef SERVICE_IMPL_LISTENER
#endif
#define SERVICE_IMPL_LISTENER(_m) IMPLEMENT_SERVICE(_m, Listener)

#endif
