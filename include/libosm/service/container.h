#ifndef __CONTAINER_H
#define __CONTAINER_H

#include "service.h"

/* Container Service */
#undef INTERFACE
#define INTERFACE IContainerService
DECLARE_SCRIPT_SERVICE(Container, 0x17d)
{
	SERVICE_FUNCS()
	STDMETHOD(Add)(THIS_ int obj, int container, int type DEF_ARG(0),
		int flags DEF_ARG(1)) PURE;
	STDMETHOD(Remove)(THIS_ int obj, int container DEF_ARG(0)) PURE;
	STDMETHOD(MoveAllContents)(THIS_ int src, int targ, int flags DEF_ARG(1))
		PURE;
#if !defined(THIEF1) || defined(NEWDARK)
	STDMETHOD(StackAdd)(THIS_ int src, int quantity) PURE;
	STDMETHOD_(eContainType, IsHeld)(THIS_ int container, int containee) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_CONTAINER
#undef SERVICE_DEF_CONTAINER
#endif
#define SERVICE_DEF_CONTAINER() interface IContainerService *Container = NULL;
#ifdef SERVICE_EXT_CONTAINER
#undef SERVICE_EXT_CONTAINER
#endif
#define SERVICE_EXT_CONTAINER() extern IContainerService *Container;
#ifdef SERVICE_IMPL_CONTAINER
#undef SERVICE_IMPL_CONTAINER
#endif
#define SERVICE_IMPL_CONTAINER(_m) IMPLEMENT_SERVICE(_m, Container)

#endif
