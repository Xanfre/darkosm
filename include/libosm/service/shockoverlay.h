#if !defined(__SHOCKOVERLAY_H) && defined(SHOCK) && defined(NEWDARK)
#define __SHOCKOVERLAY_H

#include "service.h"

/* IShockOverlayHandler Interface */
#undef INTERFACE
#define INTERFACE IShockOverlayHandler
DECLARE_INTERFACE(IShockOverlayHandler)
{
	STDMETHOD_(void, DrawHUD)(THIS) PURE;
	STDMETHOD_(void, DrawTOverlay)(THIS) PURE;
	STDMETHOD_(void, OnUIEnterMode)(THIS) PURE;
	STDMETHOD_(BOOL, CanEnableElement)(THIS_ int which) PURE;
	STDMETHOD_(BOOL, IsMouseOver)(THIS_ int x, int y) PURE;
	STDMETHOD_(BOOL, MouseClick)(THIS_ int x, int y) PURE;
	STDMETHOD_(BOOL, MouseDblClick)(THIS_ int x, int y) PURE;
	STDMETHOD_(BOOL, MouseDragDrop)(THIS_ int x, int y, BOOL start_drag,
		int cursor_mode) PURE;
	STDMETHOD_(BOOL, HandleKey)(THIS_ int ch, int keycode) PURE;
};

/* ShockOverlay Service */
#undef INTERFACE
#define INTERFACE IShockOverlayService
DECLARE_SCRIPT_SERVICE(ShockOverlay, 0x22a)
{
	SERVICE_FUNCS()
	STDMETHOD_(void, SetHandler)(THIS_ IShockOverlayHandler *pHandler) PURE;
	STDMETHOD_(void, SetKeyboardInputCapture)(THIS_ BOOL bCapture) PURE;
	STDMETHOD_(int, GetBitmap)(THIS_ const char *name, const char *path) PURE;
	STDMETHOD_(void, FlushBitmap)(THIS_ int handle) PURE;
	STDMETHOD_(void, GetBitmapSize)(THIS_ int handle, int REF width,
		int REF height) PURE;
	STDMETHOD_(BOOL, SetCustomFont)(THIS_ int index, const char *name,
		const char *path) PURE;
	STDMETHOD_(void, GetOverlayRect)(THIS_ int which, int REF left, int REF top,
		int REF right, int REF bottom) PURE;
	STDMETHOD_(int, GetCursorMode)(THIS) PURE;
	STDMETHOD_(void, ClearCursorMode)(THIS) PURE;
	STDMETHOD_(BOOL, SetCursorBitmap)(THIS_ const char *name, const char *path)
		PURE;
	STDMETHOD_(void, SetInterfaceMouseOverObject)(THIS_ const int REF obj) PURE;
	STDMETHOD_(void, GetInterfaceFocusObject)(THIS_ int REF obj) PURE;
	STDMETHOD_(void, OpenLookPopup)(THIS_ const int REF obj) PURE;
	STDMETHOD_(void, ToggleLookCursor)(THIS) PURE;
	STDMETHOD_(BOOL, StartObjectDragDrop)(THIS_ const int REF obj) PURE;
	STDMETHOD_(void, PlaySound)(THIS_ const char *schema_name) PURE;
	STDMETHOD_(BOOL, WorldToScreen)(THIS_ const vector REF pos, int REF x,
		int REF y) PURE;
	STDMETHOD_(BOOL, GetObjectScreenBounds)(THIS_ const int REF obj, int REF x1,
		int REF y1, int REF x2, int REF y2) PURE;
	STDMETHOD_(int, CreateTOverlayItem)(THIS_ int x, int y, int width,
		int height, int alpha, BOOL trans_bg) PURE;
	STDMETHOD_(int, CreateTOverlayItemFromBitmap)(THIS_ int x, int y, int alpha,
		int bm_handle, BOOL trans_bg) PURE;
	STDMETHOD_(void, DestroyTOverlayItem)(THIS_ int handle) PURE;
	STDMETHOD_(void, UpdateTOverlayAlpha)(THIS_ int handle, int alpha) PURE;
	STDMETHOD_(void, UpdateTOverlayPosition)(THIS_ int handle, int x, int y)
		PURE;
	STDMETHOD_(void, UpdateTOverlaySize)(THIS_ int handle, int width,
		int height) PURE;
	STDMETHOD_(void, DrawBitmap)(THIS_ int handle, int x, int y) PURE;
	STDMETHOD_(void, DrawSubBitmap)(THIS_ int handle, int x, int y, int src_x,
		int src_y, int src_width, int src_height) PURE;
	STDMETHOD_(void, DrawObjectIcon)(THIS_ const int REF obj, int x, int y)
		PURE;
	STDMETHOD_(void, SetFont)(THIS_ int font_type) PURE;
	STDMETHOD_(void, SetTextColor)(THIS_ int r, int g, int b) PURE;
	STDMETHOD_(void, GetStringSize)(THIS_ const char *text, int REF width,
		int REF height) PURE;
	STDMETHOD_(void, DrawString)(THIS_ const char *text, int x, int y) PURE;
	STDMETHOD_(void, DrawLine)(THIS_ int x1, int y1, int x2, int y2) PURE;
	STDMETHOD_(void, FillTOverlay)(THIS_ int color_idx, int alpha) PURE;
	STDMETHOD_(BOOL, BeginTOverlayUpdate)(THIS_ int handle) PURE;
	STDMETHOD_(void, EndTOverlayUpdate)(THIS) PURE;
	STDMETHOD_(void, DrawTOverlayItem)(THIS_ int handle) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_SHOCKOVERLAY
#undef SERVICE_DEF_SHOCKOVERLAY
#endif
#define SERVICE_DEF_SHOCKOVERLAY() interface IShockOverlayService *ShockOverlay = NULL;
#ifdef SERVICE_EXT_SHOCKOVERLAY
#undef SERVICE_EXT_SHOCKOVERLAY
#endif
#define SERVICE_EXT_SHOCKOVERLAY() extern IShockOverlayService *ShockOverlay;
#ifdef SERVICE_IMPL_SHOCKOVERLAY
#undef SERVICE_IMPL_SHOCKOVERLAY
#endif
#define SERVICE_IMPL_SHOCKOVERLAY(_m) IMPLEMENT_SERVICE(_m, ShockOverlay)

#endif
