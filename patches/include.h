#if ATTACHABOVE_PATCH || ATTACHASIDE_PATCH || ATTACHBELOW_PATCH || ATTACHBOTTOM_PATCH || ATTACHASIDEBELOW_PATCH
#include "attachx.h"
#endif
#if STICKY_PATCH
#include "sticky.h"
#endif
#if XRDB_PATCH
#include "xrdb.h"
#endif
#if SWALLOW_PATCH
#include "swallow.h"
#endif
#if FULLSCREEN_PATCH
#include "fullscreen.h"
#endif
#if FAKEFULLSCREEN_CLIENT_PATCH
#include "fakefullscreenclient.h"
#endif
#if SCRATCHPADS_PATCH
#include "scratchpads.h"
#endif
#if SYSTRAY_PATCH
#include "systray.h"
#endif
#if TAGICONS_PATCH
#include "tagicons.h"
#endif
#if DWMBLOCKS_PATCH
#include "dwmblocks.h"
#endif
#if DWMC_PATCH
#include "dwmc.h"
#endif
#if PERTAG_PATCH
#include "pertag.h"
#endif
#if VANITYGAPS_PATCH
#include "vanitygaps.h"
#endif
/* Layout */

#if CFACTS_PATCH
#include "cfacts.h"
#endif
#if CYCLELAYOUT_PATCH
#include "cyclelayout.h"
#endif
#if BSTACK_LAYOUT
#include "layout_bstack.h"
#endif
#if DECK_LAYOUT
#include "layout_deck.h"
#endif
#if CENTEREDMASTER_LAYOUT
#include "layout_centeredmaster.h"
#endif
#if CENTEREDFLOATINGMASTER_LAYOUT
#include "layout_centeredfloatingmaster.h"
#endif
#if HORIZGRID_LAYOUT
#include "layout_horizgrid.h"
#endif
#if NROWGRID_LAYOUT
#include "layout_nrowgrid.h"
#endif
#if BSTACKHORIZ_LAYOUT
#include "layout_bstackhoriz.h"
#endif
#if FIBONACCI_DWINDLE_LAYOUT || FIBONACCI_SPIRAL_LAYOUT
#include "layout_fibonacci.h"
#endif
#if GAPLESSGRID_LAYOUT
#include "layout_gapless.h"
#endif
#if TILE_LAYOUT
#include "layout_tile.h"
#endif
#if MONOCLE_LAYOUT
#include "layout_monocle.h"
#endif
#if FLEXTILE_DELUXE_LAYOUT
#include "layout_flextile-deluxe.h"
#endif

#if LAYOUTMENU_PATCH
#include "layoutmenu.h"
#endif
#if DRAGMFACT_PATCH
#include "dragmfact.h"
#endif
#if DRAGCFACT_PATCH
#include "dragcfact.h"
#endif
#if PLACEMOUSE_PATCH
#include "placemouse.h"
#endif

#if IPC_PATCH
#include "ipc.h"
#include "ipc/ipc.h"
#include "ipc/util.h"
#endif // IPC_PATCH
#if SHIFTVIEW_PATCH
#include "shiftview.h"
#endif
#if SHIFTVIEW_CLIENTS_PATCH
#include "shiftviewclients.h"
#endif
