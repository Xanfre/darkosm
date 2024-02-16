#ifndef __PUPPET_H
#define __PUPPET_H

#include "service.h"

/* Puppet Service */
#undef INTERFACE
#define INTERFACE IPuppetService
DECLARE_SCRIPT_SERVICE(Puppet, 0xfd)
{
	SERVICE_FUNCS()
	STDMETHOD_(BOOL *, PlayMotion)(THIS_ BOOL REF ret, const int obj,
		const char *name) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_PUPPET
#undef SERVICE_DEF_PUPPET
#endif
#define SERVICE_DEF_PUPPET() interface IPuppetService *Puppet = NULL;
#ifdef SERVICE_EXT_PUPPET
#undef SERVICE_EXT_PUPPET
#endif
#define SERVICE_EXT_PUPPET() extern IPuppetService *Puppet;
#ifdef SERVICE_IMPL_PUPPET
#undef SERVICE_IMPL_PUPPET
#endif
#define SERVICE_IMPL_PUPPET(_m) IMPLEMENT_SERVICE(_m, Puppet)

#endif
