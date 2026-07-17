#ifndef __SOUND_H
#define __SOUND_H

#include "service.h"


/* Sound Service */
DECLARE_SCRIPT_SERVICE(Sound, 0xf1)
{
#undef INTERFACE
#define INTERFACE ISoundService
#ifdef THIEF1
#define SCR_SOUND_NETWORK
#define PlayAtLocation PlayAtLocationLegacy
#define PlayAtObject PlayAtObjectLegacy
#define Play PlayLegacy
#define PlayAmbient PlayAmbientLegacy
#define PlaySchemaAtLocation PlaySchemaAtLocationLegacy
#define PlaySchemaAtObject PlaySchemaAtObjectLegacy
#define PlaySchema PlaySchemaLegacy
#define PlaySchemaAmbient PlaySchemaAmbientLegacy
#define PlayEnvSchema PlayEnvSchemaLegacy
#else
#define SCR_SOUND_NETWORK , eSoundNetwork Network DEF_ARG(kSN_Default)
#endif
	SERVICE_FUNCS()
	STDMETHOD_(BOOL *, PlayAtLocation)(THIS_ BOOL REF ret, int CallbackObject, 
		const String REF SoundName, sVector REF Vector,
		eSoundSpecial Special DEF_ARG(kSS_Normal) SCR_SOUND_NETWORK) PURE;
	STDMETHOD_(BOOL *, PlayAtObject)(THIS_ BOOL REF ret, int CallbackObject, 
		const String REF SoundName, int TargetObject,
		eSoundSpecial Special DEF_ARG(kSS_Normal) SCR_SOUND_NETWORK) PURE;
	STDMETHOD_(BOOL *, Play)(THIS_ BOOL REF ret, int CallbackObject,
		const String REF SoundName, eSoundSpecial Special DEF_ARG(kSS_Normal)
		SCR_SOUND_NETWORK) PURE;
	STDMETHOD_(BOOL *, PlayAmbient)(THIS_ BOOL REF ret, int CallbackObject,
		const String REF SoundName, eSoundSpecial Special DEF_ARG(kSS_Normal)
		SCR_SOUND_NETWORK) PURE;
	STDMETHOD_(BOOL *, PlaySchemaAtLocation)(THIS_ BOOL REF ret,
		int CallbackObject, int Schema, sVector REF Vector SCR_SOUND_NETWORK)
		PURE;
	STDMETHOD_(BOOL *, PlaySchemaAtObject)(THIS_ BOOL REF ret,
		int CallbackObject, int Schema, int SourceObject SCR_SOUND_NETWORK)
		PURE;
	STDMETHOD_(BOOL *, PlaySchema)(THIS_ BOOL REF ret, int CallbackObject,
		int Schema SCR_SOUND_NETWORK) PURE;
	STDMETHOD_(BOOL *, PlaySchemaAmbient)(THIS_ BOOL REF ret,
		int CallbackObject, int Schema SCR_SOUND_NETWORK) PURE;
	STDMETHOD_(BOOL *, PlayEnvSchema)(THIS_ BOOL REF ret, int CallbackObject,
		const String REF Tags, int SourceObject DEF_ARG(0),
		int AgentObject DEF_ARG(0), eEnvSoundLoc loc DEF_ARG(kESL_OnObj)
		SCR_SOUND_NETWORK) PURE;
	STDMETHOD_(BOOL *,PlayVoiceOver)(THIS_ BOOL REF ret, int cb_obj, int Schema)
		PURE;
	STDMETHOD_(int, Halt)(THIS_ int TargetObject,
		const String REF SoundName DEF_ARG(""), int CallbackObject DEF_ARG(0))
		PURE;
	STDMETHOD_(BOOL *, HaltSchema)(THIS_ BOOL REF ret, int TargetObject,
		const String REF SoundName DEF_ARG(""),
		int CallbackObject DEF_ARG(0)) PURE;
	STDMETHOD(HaltSpeech)(THIS_ int speakerObj) PURE;
	STDMETHOD_(BOOL *, PreLoad)(THIS_ BOOL REF ret, const String REF SpeechName)
		PURE;
#undef SCR_SOUND_NETWORK
#ifdef THIEF1
#undef PlayAtLocation
#undef PlayAtObject
#undef Play
#undef PlayAmbient
#undef PlaySchemaAtLocation
#undef PlaySchemaAtObject
#undef PlaySchema
#undef PlaySchemaAmbient
#undef PlayEnvSchema
#endif

#ifdef NEWDARK
	/*
	** new functions in T2 v1.28 / SS2 v2.49:
	*/

#ifdef THIEF1
	/* these should replace the old T1/G interface methods and should be
	 * preferred over the legacy methods in new modules */
	STDMETHOD_(BOOL *, PlayAtLocation)(THIS_ BOOL REF ret, int CallbackObject, 
		const String REF SoundName, sVector REF Vector,
		eSoundSpecial Special DEF_ARG(kSS_Normal),
		eSoundNetwork Network DEF_ARG(kSN_Default)) PURE;
	STDMETHOD_(BOOL *, PlayAtObject)(THIS_ BOOL REF ret, int CallbackObject, 
		const String REF SoundName, int TargetObject,
		eSoundSpecial Special DEF_ARG(kSS_Normal),
		eSoundNetwork Network DEF_ARG(kSN_Default)) PURE;
	STDMETHOD_(BOOL *, Play)(THIS_ BOOL REF ret, int CallbackObject,
		const String REF SoundName, eSoundSpecial Special DEF_ARG(kSS_Normal),
		eSoundNetwork Network DEF_ARG(kSN_Default)) PURE;
	STDMETHOD_(BOOL *, PlayAmbient)(THIS_ BOOL REF ret, int CallbackObject,
		const String REF SoundName, eSoundSpecial Special DEF_ARG(kSS_Normal),
		eSoundNetwork Network DEF_ARG(kSN_Default)) PURE;
	STDMETHOD_(BOOL *, PlaySchemaAtLocation)(THIS_ BOOL REF ret,
		int CallbackObject, int Schema, sVector REF Vector,
		eSoundNetwork Network DEF_ARG(kSN_Default)) PURE;
	STDMETHOD_(BOOL *, PlaySchemaAtObject)(THIS_ BOOL REF ret,
		int CallbackObject, int Schema, int SourceObject,
		eSoundNetwork Network DEF_ARG(kSN_Default)) PURE;
	STDMETHOD_(BOOL *, PlaySchema)(THIS_ BOOL REF ret, int CallbackObject,
		int Schema , eSoundNetwork Network DEF_ARG(kSN_Default)) PURE;
	STDMETHOD_(BOOL *, PlaySchemaAmbient)(THIS_ BOOL REF ret,
		int CallbackObject, int Schema,
		eSoundNetwork Network DEF_ARG(kSN_Default)) PURE;
	STDMETHOD_(BOOL *, PlayEnvSchema)(THIS_ BOOL REF ret, int CallbackObject,
		const String REF Tags, int SourceObject DEF_ARG(0),
		int AgentObject DEF_ARG(0), eEnvSoundLoc loc DEF_ARG(kESL_OnObj),
		eSoundNetwork Network DEF_ARG(kSN_Default)) PURE;
#endif
	/* change the current song */
	STDMETHOD_(void, SongChange)(THIS_ const char *song) PURE;
	/* change active song theme */
	STDMETHOD_(void, SongSetTheme)(THIS_ const char *theme) PURE;
#endif
};

/* Populated Implementors */
#ifdef SERVICE_DEF_SOUND
#undef SERVICE_DEF_SOUND
#endif
#define SERVICE_DEF_SOUND() interface ISoundService *Sound = NULL;
#ifdef SERVICE_EXT_SOUND
#undef SERVICE_EXT_SOUND
#endif
#define SERVICE_EXT_SOUND() extern ISoundService *Sound;
#ifdef SERVICE_IMPL_SOUND
#undef SERVICE_IMPL_SOUND
#endif
#define SERVICE_IMPL_SOUND(_m) IMPLEMENT_SERVICE(_m, Sound)

#endif
