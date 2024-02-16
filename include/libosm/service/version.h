#if !defined(__VERSION_H) && defined(NEWDARK)
#define __VERSION_H

#include "service.h"

/* Version Service */
#undef INTERFACE
#define INTERFACE IVersionService
DECLARE_SCRIPT_SERVICE(Version, 0x228)
{
	SERVICE_FUNCS()
	/* returns an app name-version string in the form of "Thief 2 Final 1.19" if
	 * title_only is FALSE  or an app name string in the form of
	 * "Thief 2"/"DromEd"/"System Shock 2" if title_only is TRUE */
	STDMETHOD_(void, GetAppName)(THIS_ BOOL title_only, String REF result) PURE;
	/* get version numbers */
	STDMETHOD_(void, GetVersion)(THIS_ int REF major, int REF minor) PURE;
	/* returns 0 if the running executable is NOT the editor, 1 if editor in
	 * edit mode, 2 if editor in game mode (due to a bug, the return values for
	 * 1 and 2 are reversed in T2 v1.22 / SS2 v2.43, this only affects the
	 * editor and not the game executables) */
	STDMETHOD_(int, IsEditor)(THIS) PURE;
	/* returns the "game" string (set in cam.cfg to select game, i.e.
	 * "dark"/"shock") */
	STDMETHOD_(void, GetGame)(THIS_ String REF result) PURE;
	/* returns the current gamesys filename (including ".gam" extension) */
	STDMETHOD_(void, GetGamsys)(THIS_ String REF result) PURE;
	/* returns the current map/mission filename (including ".mis" extension) */
	STDMETHOD_(void, GetMap)(THIS_ String REF result) PURE;

	/*
	** FM services
	*/

	/* get the current FM name, returns empty string and S_FALSE if none is
	 * active */
	STDMETHOD(GetCurrentFM)(THIS_ String REF result) PURE;
	/* get the current FM path name as "rootpath/name" (roopath can be relative
	 * to CWD), returns empty string and S_FALSE if none is active */
	STDMETHOD(GetCurrentFMPath)(THIS_ String REF result) PURE;
	/* returns the 'relpath' with the current FM path prefixed if an FM is
	 * active, otherwise the unmodified 'relpath' */
	STDMETHOD_(void, FMizeRelativePath)(THIS_ const char *relpath,
		String REF result) PURE;
	/* checks if path is absolute, if so returns it as-is, otherwise behaves the
	 * same as FMizeRelativePath */
	STDMETHOD_(void, FMizePath)(const char *path, String REF result) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_VERSION
#undef SERVICE_DEF_VERSION
#endif
#define SERVICE_DEF_VERSION() interface IVersionService *Version = NULL;
#ifdef SERVICE_EXT_VERSION
#undef SERVICE_EXT_VERSION
#endif
#define SERVICE_EXT_VERSION() extern IVersionService *Version;
#ifdef SERVICE_IMPL_VERSION
#undef SERVICE_IMPL_VERSION
#endif
#define SERVICE_IMPL_VERSION(_m) IMPLEMENT_SERVICE(_m, Version)

#endif
