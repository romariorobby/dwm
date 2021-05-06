#if ATTACHABOVE_PATCH || ATTACHASIDE_PATCH || ATTACHBELOW_PATCH || ATTACHBOTTOM_PATCH || ATTACHASIDEBELOW_PATCH
#include "attachx.c"
#endif
#if STICKY_PATCH
#include "sticky.c"
#endif
#if XRDB_PATCH
#include "xrdb.c"
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
#if TAGICONS_PATCH
#include "tagicons.c"
#endif
#if DWMBLOCKS_PATCH
#include "dwmblocks.c"
#endif
#if DWMC_PATCH
#include "dwmc.c"
#endif
#if PERTAG_PATCH
#include "pertag.c"
#endif
#if VANITYGAPS_PATCH
#include "vanitygaps.c"
#endif
/* 
 * LAYOUT
 *
 * */

#if CYCLELAYOUT_PATCH
#include "cyclelayout.c"
#endif
#if BSTACK_LAYOUT || BSTACKHORIZ_LAYOUT || CENTEREDMASTER_LAYOUT || CENTEREDFLOATINGMASTER_LAYOUT || COLUMNS_LAYOUT || DECK_LAYOUT || TILE_LAYOUT
#include "layout_facts.c"
#endif
#if CFACTS_PATCH
#include "cfacts.c"
#endif
#if BSTACK_LAYOUT
#include "layout_bstack.c"
#endif
#if DECK_LAYOUT
#include "layout_deck.c"
#endif
#if CENTEREDMASTER_LAYOUT
#include "layout_centeredmaster.c"
#endif
#if CENTEREDFLOATINGMASTER_LAYOUT
#include "layout_centeredfloatingmaster.c"
#endif
#if HORIZGRID_LAYOUT
#include "layout_horizgrid.c"
#endif
#if NROWGRID_LAYOUT
#include "layout_nrowgrid.c"
#endif
#if BSTACKHORIZ_LAYOUT
#include "layout_bstackhoriz.c"
#endif
#if FIBONACCI_DWINDLE_LAYOUT || FIBONACCI_SPIRAL_LAYOUT
#include "layout_fibonacci.c"
#endif
#if GAPLESSGRID_LAYOUT
#include "layout_gapless.c"
#endif
#if TILE_LAYOUT
#include "layout_tile.c"
#endif
#if MONOCLE_LAYOUT
#include "layout_monocle.c"
#endif
#if FLEXTILE_DELUXE_LAYOUT
#include "layout_flextile-deluxe.c"
#endif

#if LAYOUTMENU_PATCH
#include "layoutmenu.c"
#endif
#if DRAGMFACT_PATCH
#include "dragmfact.c"
#endif
#if DRAGCFACT_PATCH
#include "dragcfact.c"
#endif
#if PLACEMOUSE_PATCH
#include "placemouse.c"
#endif

#if IPC_PATCH
#include "ipc.c"
#ifdef VERSION
#include "ipc/IPCClient.c"
#include "ipc/yajl_dumps.c"
#include "ipc/ipc.c"
#include "ipc/util.c"
#endif
#endif // IPC_PATCH
#if SHIFTVIEW_PATCH
#include "shiftview.c"
#endif
#if SHIFTVIEW_CLIENTS_PATCH
#include "shiftviewclients.c"
#endif
