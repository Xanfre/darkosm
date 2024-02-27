#ifndef __LINK_H
#define __LINK_H

#include "service.h"

/* Helper Macros */
#ifdef __cplusplus
#define AnyLinksLeft(_q) !_q->Done()
#define Link_(_q) _q->ID()
#define NextLink(_q) _q->Next()
#else
#define AnyLinksLeft(_q) !_q->lpVtbl->Done(_q)
#define Link_(_q) _q->lpVtbl->ID(_q)
#define NextLink(_q) _q->lpVtbl->Next(_q)
#endif

/* Link Query Interface */
DEFINE_GUID(IID_ILinkQuery, 0x83000083, 0x7b03, 0x1252, 0x83, 0x48, 0x00, 0xaa, 0x00, 0xa8, 0x2b, 0x51);
#undef INTERFACE
#define INTERFACE ILinkQuery
DECLARE_INTERFACE_(ILinkQuery, IUnknown)
{
	IUNKNOWN_FUNCS()
	STDMETHOD_(BOOL, Done)(THIS) PURE;
	STDMETHOD(Link)(THIS_ sLink*) PURE;
	STDMETHOD_(long, ID)(THIS) PURE;
	STDMETHOD_(void *, Data)(THIS) PURE;
	STDMETHOD(Next)(THIS) PURE;
	STDMETHOD_(ILinkQuery *, Inverse)(THIS) PURE;
};

/* Link Service */
#undef INTERFACE
#define INTERFACE ILinkService
DECLARE_SCRIPT_SERVICE(Link, 0xee)
{
	SERVICE_FUNCS()
	STDMETHOD_(long *, Create)(THIS_ long REF ret, long kind, int from, int to)
		PURE;
	STDMETHOD(Destroy)(THIS_ long destroy_me) PURE;
	STDMETHOD_(BOOL *, AnyExist)(THIS_ BOOL REF ret, long kind DEF_ARG(0),
		int from DEF_ARG(0), int to DEF_ARG(0)) PURE;
	STDMETHOD_(ILinkQuery **, GetAll)(THIS_ ILinkQuery * REF ret,
		long kind DEF_ARG(0), int from DEF_ARG(0), int to DEF_ARG(0)) PURE;
	STDMETHOD_(long *, GetOne)(THIS_ long REF ret, long kind DEF_ARG(0),
		int from DEF_ARG(0), int to DEF_ARG(0)) PURE;
	STDMETHOD(BroadcastOnAllLinks)(THIS_ const int REF SelfObj,
		const char *Message, long recipients) PURE;
	STDMETHOD(BroadcastOnAllLinksData)(THIS_ const int REF SelfObj,
		const char *Message, long recipients, const MultiParm REF intdata) PURE;
	STDMETHOD(CreateMany)(THIS_ long kind, const String REF FromSet,
		const String REF ToSet) PURE;
	STDMETHOD(DestroyMany)(THIS_ long kind, const String REF FromSet,
		const String REF ToSet) PURE;
	STDMETHOD_(ILinkQuery **, GetAllInherited)(THIS_ ILinkQuery * REF ret,
		long kind DEF_ARG(0), int from DEF_ARG(0), int to DEF_ARG(0)) PURE;
	STDMETHOD_(ILinkQuery **, GetAllInheritedSingle)(THIS_ ILinkQuery * REF ret,
		long kind DEF_ARG(0), int from DEF_ARG(0), int to DEF_ARG(0)) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_LINK
#undef SERVICE_DEF_LINK
#endif
#define SERVICE_DEF_LINK() interface ILinkService *Link = NULL;
#ifdef SERVICE_EXT_LINK
#undef SERVICE_EXT_LINK
#endif
#define SERVICE_EXT_LINK() extern ILinkService *Link;
#ifdef SERVICE_IMPL_LINK
#undef SERVICE_IMPL_LINK
#endif
#define SERVICE_IMPL_LINK(_m) IMPLEMENT_SERVICE(_m, Link)

#endif
