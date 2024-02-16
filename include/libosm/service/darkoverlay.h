#if !defined(__DARKOVERLAY_H) && !defined(SHOCK) && defined(NEWDARK)
#define __DARKOVERLAY_H

#include "service.h"

/*
** IDarkOverlayHandler interface
**
** implemented by script module that wishes to have custom HUD elements,
** registered with DarkOverlay::SetHandler
*/

#undef INTERFACE
#define INTERFACE IDarkOverlayHandler
DECLARE_INTERFACE(IDarkOverlayHandler)
{
	/* handler called by the engine so script implementation of
	 * IDarkOverlayHandler can draw HUD elements */
	STDMETHOD_(void, DrawHUD)(THIS) PURE;
	/* handler called by the engine so script implementation of
	 * IDarkOverlayHandler can update and draw transparent overlay elements
	 * (transparent overlay elements are bitmaps drawn directly to the 3D buffer
	 * with alpha blending, like the security icon in shock) */
	STDMETHOD_(void, DrawTOverlay)(THIS) PURE;
	/* handler called by the engine when dark initializes UI components, this is
	 * also called when resuming game after in-game menu and other UI screens
	 * and is a good place to update positioning of HUD elements in case display
	 * resolution changed */
	STDMETHOD_(void, OnUIEnterMode)(THIS) PURE;
};

/*
** DarkOverlay script service
*/

#undef INTERFACE
#define INTERFACE IDarkOverlayService
DECLARE_SCRIPT_SERVICE(DarkOverlay, 0x22b)
{
	SERVICE_FUNCS()
	/* set the current overlay handler, there can only be one handler set at any
	 * given time, NULL clears handler */
	STDMETHOD_(void, SetHandler)(THIS_ IDarkOverlayHandler *pHandler) PURE;
	/* get/load a bitmap that can be used for HUD drawing (max 128 bitmaps can
	 * be loaded, cleared when db resets)
	 * returns a handle that can be used in subsequent bitmap functions or -1 if
	 * failed to load */
	STDMETHOD_(int, GetBitmap)(THIS_ const char *name,
		const char *path /*= "intrface\\"*/) PURE;
	/* discard a no longer used bitmap handle, only needs to be called when
	 * using a lot of bitmaps to stay below 128 */
	STDMETHOD_(void, FlushBitmap)(THIS_ int handle) PURE;
	/* get size of a loaded bitmap */
	STDMETHOD_(void, GetBitmapSize)(THIS_ int handle, int REF width,
		int REF height) PURE;

	/*
	** coordinate mapping (may ONLY be called inside the
	** DarkOverlayHandler::DrawHUD and DrawTOverlay handlers)
	*/

	/* map a 3D position in the world to a screen coordinate, returns FALSE if
	 * off-screen */
	STDMETHOD_(BOOL, WorldToScreen)(THIS_ const sVector REF pos, int REF x,
		int REF y) PURE;
	/* get the screen space bounding rect of an object, returns FALSE if
	 * entirely off-screen */
	STDMETHOD_(BOOL, GetObjectScreenBounds)(THIS_ const int REF obj, int REF x1,
		int REF y1, int REF x2, int REF y2) PURE;

	/*
	** transparent overlay management
	*/

	/* create a transparent overlay item (like the security icon in shock),
	 * alpha is 0 to 255 its contents have to be updated using
	 * Begin/EndTOverlayUpdate and draw calls, note that constant updating isn't
	 * too optimal, so it should only be done when necessary and avoided on
	 * larger items
	 * returns an overlay handle, or -1 if failed */
	STDMETHOD_(int, CreateTOverlayItem)(THIS_ int x, int y, int width,
		int height, int alpha, BOOL trans_bg) PURE;
	/* create a transparent overlay item from a bitmap, does not require its
	 * contents to be updated (max 64 overlays can be created, cleared when db
	 * resets)
	 * returns an overlay handle, or -1 if failed (will fail if
	 * bm_handle isn't a valid bitmap) */
	STDMETHOD_(int, CreateTOverlayItemFromBitmap)(THIS_ int x, int y, int alpha,
		int bm_handle, BOOL trans_bg) PURE;
	/* destroy a transparent overlay item, not necessary to call but frees
	 * resources and overlay slot before a db reset */
	STDMETHOD_(void, DestroyTOverlayItem)(THIS_ int handle) PURE;
	/* change alpha of a transparent overlay */
	STDMETHOD_(void, UpdateTOverlayAlpha)(THIS_ int handle, int alpha) PURE;
	/* change position of a transparent overlay */
	STDMETHOD_(void, UpdateTOverlayPosition)(THIS_ int handle, int x, int y)
		PURE;
	/* change display size of a transparent overlay (for scaled overlay
	 * items) */
	STDMETHOD_(void, UpdateTOverlaySize)(THIS_ int handle, int width,
		int height) PURE;

	/*
	** methods that may ONLY be called inside the DarkOverlayHandler::DrawHUD
	** handler or inside a DarkOverlayHandler::Begin/EndTOverlayUpdate pair
	*/

	/* draw a loaded bitmap at the given position, bitmap will be drawn
	 * unscaled */
	STDMETHOD_(void, DrawBitmap)(THIS_ int handle, int x, int y) PURE;
	/* draw a sub-rect of a loaded bitmap at the given position
	 * src_x/src_y are relative to the bitmap (0,0 would be the upper left of
	 * the bitmap) */
	STDMETHOD_(void, DrawSubBitmap)(THIS_ int handle, int x, int y, int src_x,
		int src_y, int src_width, int src_height) PURE;
	/* set current text color from a eStyleColorKind
	 * not all font types support custom colors, FONTT_FLAT8 font type has color
	 * native in font and is unaffected */
	STDMETHOD_(void, SetTextColorFromStyle)(THIS_ eStyleColorKind style_color)
		PURE;
	/* set current text color with explicit RGB values
	 * not all font types support custom colors, FONTT_FLAT8 font type has color
	 * native in font and is unaffected */
	STDMETHOD_(void, SetTextColor)(THIS_ int r, int g, int b) PURE;
	/* get string extents (with current font) */
	STDMETHOD_(void, GetStringSize)(THIS_ const char *text, int REF width,
		int REF height) PURE;
	/* draw text string (with current font and text color) */
	STDMETHOD_(void, DrawString)(THIS_ const char *text, int x, int y) PURE;
	/* draw line (with current text color) */
	STDMETHOD_(void, DrawLine)(THIS_ int x1, int y1, int x2, int y2) PURE;

	/*
	** methods that may ONLY be called inside a
	** DarkOverlayHandler::Begin/EndTOverlayUpdate pair
	*/

	/* fill contents of a transparent overlay item to palette index color (0 is
	 * black), 'alpha' sets alpha component of the image data and should not be
	 * confused with the alpha specified in the CreateOverlayItem functions,
	 * which is applied on top of the alpha in image data (normally it's set to
	 * 255) */
	STDMETHOD_(void, FillTOverlay)(THIS_ int color_idx /*= 0*/,
		int alpha /*= 255*/) PURE;

	/*
	** methods that may ONLY be called inside the
	** DarkOverlayHandler::DrawTOverlay handler
	*/

	/* must be called before updating a transparent overlay item contents with
	 * draw calls make sure the return value is TRUE before drawing anything */
	STDMETHOD_(BOOL, BeginTOverlayUpdate)(THIS_ int handle) PURE;
	/* end update of a transparent overlay item, may only be called after a
	 * successful BeginTOverlayUpdate */
	STDMETHOD_(void, EndTOverlayUpdate)(THIS) PURE;
	/* draw a transparent overlay item, handle is an overlay item handle
	 * returned by one of the CreateTOverlayItem functions */
	STDMETHOD_(void, DrawTOverlayItem)(THIS_ int handle) PURE;
};

/* Populated Implementors */
#ifdef SERVICE_DEF_DARKOVERLAY
#undef SERVICE_DEF_DARKOVERLAY
#endif
#define SERVICE_DEF_DARKOVERLAY() interface IDarkOverlayService *DarkOverlay = NULL;
#ifdef SERVICE_EXT_DARKOVERLAY
#undef SERVICE_EXT_DARKOVERLAY
#endif
#define SERVICE_EXT_DARKOVERLAY() extern IDarkOverlayService *DarkOverlay;
#ifdef SERVICE_IMPL_DARKOVERLAY
#undef SERVICE_IMPL_DARKOVERLAY
#endif
#define SERVICE_IMPL_DARKOVERLAY(_m) IMPLEMENT_SERVICE(_m, DarkOverlay)

#endif
