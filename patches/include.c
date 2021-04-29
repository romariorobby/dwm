#if ATTACHABOVE_PATCH || ATTACHASIDE_PATCH || ATTACHBELOW_PATCH || ATTACHBOTTOM_PATCH || ATTACHASIDEBELOW_PATCH
#include "attachx.c"
#endif
#if STICKY_PATCH
#include "sticky.c"
#endif
#if SWALLOW_PATCH
#include "swallow.c"
#endif
#if FULLSCREEN_PATCH
#include "fullscreen.c"
#endif
#if FAKEFULLSCREEN_CLIENT_PATCH
#include "fakefullscreenclient.c"
#endif
#if SCRATCHPADS_PATCH
#include "scratchpads.c"
#endif
#if SYSTRAY_PATCH
#include "systray.c"
#endif
