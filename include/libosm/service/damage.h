#ifndef __DAMAGE_H
#define __DAMAGE_H

#include "service.h"

/* Damage Service */
#undef INTERFACE
#define INTERFACE IDamageService
DECLARE_SCRIPT_SERVICE(Damage, 0xFE)
{
	SERVICE_FUNCS()
	STDMETHOD(Damage)(THIS_ int victim, int culprit, int how_much, int what_kind DEF_ARG(0)) PURE; 
	STDMETHOD(Slay)(THIS_ int victim, int culprit) PURE; 
	STDMETHOD(Resurrect)(THIS_ int victim, int culprit DEF_ARG(0)) PURE; 
};

/* Populated Implementors */
#ifdef SERVICE_DEF_DAMAGE
#undef SERVICE_DEF_DAMAGE
#endif
#define SERVICE_DEF_DAMAGE() interface IDamageService *Damage = NULL;
#ifdef SERVICE_EXT_DAMAGE
#undef SERVICE_EXT_DAMAGE
#endif
#define SERVICE_EXT_DAMAGE() extern IDamageService *Damage;
#ifdef SERVICE_IMPL_DAMAGE
#undef SERVICE_IMPL_DAMAGE
#endif
#define SERVICE_IMPL_DAMAGE(_m) IMPLEMENT_SERVICE(_m, Damage)

#endif
