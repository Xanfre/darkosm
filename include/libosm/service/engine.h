#if !defined(__ENGINE_H) && defined(NEWDARK)
#define __ENGINE_H

#include "service.h"

/* Engine Service */
#undef INTERFACE
#define INTERFACE IEngineService
DECLARE_SCRIPT_SERVICE(Engine, 0x229)
{
	SERVICE_FUNCS()
	/* returns TRUE if config var is defined */
	STDMETHOD_(BOOL, ConfigIsDefined)(THIS_ const char *name) PURE;
	/* get config var as int value */
	STDMETHOD_(BOOL, ConfigGetInt)(THIS_ const char *name, int REF value) PURE;
	/* get config var as float value */
	STDMETHOD_(BOOL, ConfigGetFloat)(THIS_ const char *name, float REF value)
		PURE;
	/* get config var value as raw text */
	STDMETHOD_(BOOL, ConfigGetRaw)(THIS_ const char *name, String REF value)
		PURE;
	/* get bind variable as float */
	STDMETHOD_(float, BindingGetFloat)(THIS_ const char *name) PURE;
	/* search for a file in paths defined by a path config var (like
	 * "script_module_path"), 'fullname' is set if return value is TRUE */
	STDMETHOD_(BOOL, FindFileInPath)(THIS_ const char *path_config_var,
		const char *filename, String REF fullname) PURE;
	/* returns TRUE if running game in legacy DX6 mode */
	STDMETHOD_(BOOL, IsRunningDX6)(THIS) PURE;
	/* get display resolution (more specifically the main 2D surface, which is
	 * the only thing relevant as far as drawing concerns) */
	STDMETHOD_(void, GetCanvasSize)(THIS_ int REF width, int REF height) PURE;
	/* aspect ratio of current display mode (w/h) */
	STDMETHOD_(float, GetAspectRatio)(THIS) PURE;
	/* get global fog settings (dist 0 means fog disabled) */
	STDMETHOD_(void, GetFog)(THIS_ int REF r, int REF g, int REF b,
		float REF dist) PURE;
	/* set global fog settings (dist 0 means fog disabled) */
	STDMETHOD_(void, SetFog)(THIS_ int r, int g, int b, float dist) PURE;
	/* get fog settings for a fog zone (iZone must be a number 1 to 8 or
	 * function silently fails) */
	STDMETHOD_(void, GetFogZone)(THIS_ int iZone, int REF r, int REF g,
		int REF b, float REF dist) PURE;
	/* set fog settings for a fog zone (iZone must be a number 1 to 8 or
	 * function silently fails) */
	STDMETHOD_(void, SetFogZone)(THIS_ int iZone, int r, int g, int b,
		float dist) PURE;
	/* get weather parameters */
	STDMETHOD_(void, GetWeather)(THIS_ int REF precip_type,
		float REF precip_freq, float REF precip_speed, float REF vis_dist,
		float REF rend_radius, float REF alpha, float REF brightness,
		float REF snow_jitter, float REF rain_len, float REF splash_freq,
		float REF splash_radius, float REF splash_height,
		float REF splash_duration, String REF texture, sVector REF wind) PURE;
	/* set weather parameters */
	STDMETHOD_(void, SetWeather)(THIS_ int precip_type, float precip_freq,
		float precip_speed, float vis_dist, float rend_radius, float alpha,
		float brightness, float snow_jitter, float rain_len, float splash_freq,
		float splash_radius, float splash_height, float splash_duration,
		const char *texture, const sVector REF wind) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_ENGINE
#undef SERVICE_DEF_ENGINE
#endif
#define SERVICE_DEF_ENGINE() interface IEngineService *Engine = NULL;
#ifdef SERVICE_EXT_ENGINE
#undef SERVICE_EXT_ENGINE
#endif
#define SERVICE_EXT_ENGINE() extern IEngineService *Engine;
#ifdef SERVICE_IMPL_ENGINE
#undef SERVICE_IMPL_ENGINE
#endif
#define SERVICE_IMPL_ENGINE(_m) IMPLEMENT_SERVICE(_m, Engine)

#endif
