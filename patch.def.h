/* My keymap */
#define KEYMAP 1

/*
 * THEMES
 * */

#define XRDB_PATCH 1

// if none selected fallback to default
// GRUVBOX 
#define GRUVBOX_DARK 1
#define GRUVBOX_MEDIUM 0
#define GRUVBOX_LIGHT 0

// NORD
#define NORD 0
// SOLARIZED
#define SOLARIZED_DARK 0
#define SOLARIZED_LIGHT 0

/*
 * WINDOW
 */

#define VANITYGAPS_PATCH 1

/* ATTACHDIR */
// 1 or another
#define ATTACHABOVE_PATCH 0
#define ATTACHASIDE_PATCH 0
#define ATTACHBELOW_PATCH 0
#define ATTACHBOTTOM_PATCH 0
#define ATTACHASIDEBELOW_PATCH 1

/* Sticky */
#define STICKY_PATCH 1

#define NOBORDER_PATCH 1
/* Swallow */
// You have to uncomment xcb from config.mk
#define SWALLOW_PATCH 1

/* Scratchpads */
#define SCRATCHPADS_PATCH 1

/* Fake Fullscreen */
// 1 or another
// Global Fakefullscreen
#define FAKEFULLSCREEN_PATCH 0
// Toggle fake fullscreen
#define FAKEFULLSCREEN_CLIENT_PATCH 1


/* Fullscreen */
// Toggle fullscreen (actualfullscreen)
#define FULLSCREEN_PATCH 1
/* #define FULLSCREENALIKE_PATCH 0 */
// Prevent Focus to another window when fullscreen
#define LOSEFULLSCREEN_PATCH 1

/* 
 * TAG
 */

#define UNDERLINETAGS_PATCH 1
#define TAGSCOLORS_PATCH 1
#define LITTLEBOXTAGS_PATCH 1
#define HIDEVACANTTAGS_PATCH 1

#define SHIFTVIEW_PATCH 0
#define SHIFTVIEW_CLIENTS_PATCH 1
/* Focus on active tag */
#define FOCUSONNETACTIVE 1
// Move to another monitor while in Fullscreen mode
#define TAGMONFIXFS_PATCH 1

/* Systray */
#define SYSTRAY_PATCH 1

#define TAGICONS_PATCH 1

#define DWMBLOCKS_PATCH 1

#define PERTAG_PATCH 1
#define PERTAGBAR_PATCH 1
#define PERTAG_VANITYGAPS_PATCH 1

/*
 * LAYOUT
 */
#define FLEXTILE_DELUXE_LAYOUT 0

#define CFACTS_PATCH 1
#define CYCLELAYOUT_PATCH 1
#define CENTEREDMASTER_LAYOUT 1
#define CENTEREDFLOATINGMASTER_LAYOUT 1
#define BSTACKHORIZ_LAYOUT 1
#define BSTACK_LAYOUT 1
#define FIBONACCI_DWINDLE_LAYOUT 1
#define FIBONACCI_SPIRAL_LAYOUT 1
#define TILE_LAYOUT 1
#define MONOCLE_LAYOUT 1
#define MONOCLECOUNT_PATCH 1
#define NROWGRID_LAYOUT 1

#define DRAGMFACT_PATCH 1
#define DRAGCFACT_PATCH 1
#define PLACEMOUSE_PATCH 1

/* Layoutmenu (XMENU)
 * uncomment the following line in Makefile:
 *    #cp -f patch/layoutmenu.sh ${DESTDIR}${PREFIX}/bin
 */
#define LAYOUTMENU_PATCH 0

/*
 * MISC
 */

/* DWMC
 * uncomment the following line in Makefile:
 *    #cp -f patch/dwmc ${DESTDIR}${PREFIX}/bin
 */
#define DWMC_PATCH 1
#define IPC_PATCH 0 

