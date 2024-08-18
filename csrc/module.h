#ifndef __MODULE_H
#define __MODULE_H

#include <libosm/api.h>

#undef INTERFACE
#define INTERFACE IScriptModule

/* Script Module Type */
typedef struct sScriptModule
{
	IScriptModuleVtbl *lpVtbl;
	unsigned int count;
	char name[MAX_PATH];
} sScriptModule;

#endif
