/* My keymap */
#define KEYMAP 1

/*
 * THEMES
 * */
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

/* Focus on active tag */
#define FOCUSONNETACTIVE 1
// Move to another monitor while in Fullscreen mode
#define TAGMONFIXFS_PATCH 1

/* Systray */
#define SYSTRAY_PATCH 1

#define TAGICONS_PATCH 1

#define DWMBLOCKS_PATCH 1

/*
 * MISC
 */

/* DWMC
 * uncomment the following line in Makefile:
 *    #cp -f patch/dwmc ${DESTDIR}${PREFIX}/bin
 */
#define DWMC_PATCH 1
