/* See LICENSE file for copyright and license details. */
#define TERM "st"
#define TERMC "St"
#define TERM1 "kitty"
#define TERMC1 "kitty"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
#if SWALLOW_PATCH
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
#endif // SWALLOW_PATCH
#if UNDERLINETAGS_PATCH
static const unsigned int ulinepad			= 0;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke		= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset		= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall					= 1;	/* 1 to show underline on all tags, 0 for just the active ones */
#endif // UNDERLINETAGS_PATCH
#if SYSTRAY_PATCH
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 1;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static int showsystray        = 0;     /* 0 means no systray */
#endif // SYSTRAY_PATCH
#if VANITYGAPS_PATCH
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps_fact     = 0;        /* 1 means no outer gap when there is only one window */
#endif // VANITYGAPS_PATCH
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10","Siji:size=10"};
static const char dmenufont[]       = "monospace:size=10";

#include "theme.h"
#if SCRATCHPADS_PATCH
const char *spcmd1[] = {TERM, "-n", "sptm", "-g", "144x41", "-e", "tmuc", NULL };
const char *spcmd2[] = {TERM, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd3[] = {TERM, "-n", "spemacs", "-g", "120x34", "-e", "emacs", NULL };
static Sp scratchpads[] = {
	/* Name        cmd */
	{"sptm",     spcmd1},
	{"spterm",   spcmd2},
	{"spemacs",   spcmd3},
};
#endif
#if TAGICONS_PATCH
/* tagging: refer to https://github.com/bakkeby/patches/wiki/tagicons */
static const char *tags[NUMTAGS] = { NULL };  /* left for compatibility reasons, i.e. code that checks LENGTH(tags) */
static char *tagicons[][NUMTAGS] = {
	[IconsDefault]        = { "", "", "", "", "", "<6>", "<7>", "<8>", "<9>" },
	[IconsVacant]         = { NULL },
	[IconsText]           = { "term", "mario", "web", "chat", "misc", "", "", "", "" },
	[IconsOccupied]       = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
};
#else
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
#endif

/* xprop(1):
 *	WM_CLASS(STRING) = instance, class
 *	WM_NAME(STRING) = title
 */
#if SWALLOW_PATCH
static const Rule rules[] = {
	/* class     	 instance    title            tags mask     isfloating  isterminal  noswallow   monitor */
	{ "Gimp",     	  NULL,       NULL,            0,            1,          0,			 0,           -1 },
	{ "Firefox",  	  NULL,       NULL,            3 << 8,       0,          0, 	    -1,			  -1 },
	{ TERMC,  		  NULL,    	  NULL,       	   0,       	 0,          1,			 0,			  -1 },
	{ TERMC1,  	  	  NULL,       NULL,            0,       	 0,          1,			 0,			  -1 },
	{ "Vieb",  	  	  NULL,       NULL,            1 << 4,       0,          0,			 0,			  -1 },
	#if SCRATCHPADS_PATCH
	{ NULL,		  	  "sptm",     NULL,		       SPTAG(0),	 1,			 1,      	 0,       	  -1 },
	{ NULL,		  	  "spterm",	  NULL,		  	   SPTAG(1),	 1,			 1,          0,       	  -1 },
	{ NULL,		  	  "spemacs",  NULL,		  	   SPTAG(2),	 1,			 1,          0,       	  -1 },
	#endif
	{ NULL,  	  	  NULL,       "Event Tester",  0,       	 0,          0,			 1,			  -1 },  /* xev */

};
#else
static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	#if SCRATCHPADS_PATCH
	{ NULL,		  "sptm",     NULL,		  SPTAG(0),	    1,			 -1 },
	{ NULL,		  "spterm",	  NULL,		  SPTAG(1),	    1,			 -1 },
	#endif
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};
#endif

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
#if FLEXTILE_DELUXE_LAYOUT
static const int nstack      = 0;    /* number of clients in primary stack area */
#endif // FLEXTILE_DELUXE_LAYOUT
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#if NROWGRID_LAYOUT
#define FORCE_VSPLIT 1
#endif

#if FLEXTILE_DELUXE_LAYOUT
static const Layout layouts[] = {
	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
	{ "f[]=",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // default tile layout
    { "f",      NULL,             {0} },    /* no layout function means floating behavior */
	{ "f[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
	{ "f|||",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // columns (col) layout
	{ "f>M>",      flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // floating master
	{ "f[D]",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
	{ "fTTT",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // bstack
	{ "f===",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // bstackhoriz
	{ "f|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
	{ "f-M-",      flextile,         { -1, -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, // centeredmaster horiz
	{ "f:::",      flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, // gappless grid
	{ "f[\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
	{ "f(@)",      flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, // fibonacci spiral
	{ "f[T]",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TATAMI, 0, NULL } }, // tatami mats
	#if TILE_LAYOUT
	{ "[]=",      tile,             {0} },
	#endif
	#if MONOCLE_LAYOUT
	{ "[M]",      monocle,          {2} },
	#endif
	#if BSTACK_LAYOUT
	{ "TTT",      bstack,           {0} },
	#endif
	#if BSTACKHORIZ_LAYOUT
	{ "===",      bstackhoriz,      {0} },
	#endif
	#if CENTEREDMASTER_LAYOUT
	{ "|M|",      centeredmaster,   {0} },
	#endif
	#if CENTEREDFLOATINGMASTER_LAYOUT
	{ ">M>",      centeredfloatingmaster, {0} },
	#endif
	#if COLUMNS_LAYOUT
	{ "|||",      col,              {0} },
	#endif
	#if DECK_LAYOUT
	{ "[D]",      deck,             {0} },
	#endif
	#if FIBONACCI_SPIRAL_LAYOUT
	{ "(@)",      spiral,           {0} },
	#endif
	#if FIBONACCI_DWINDLE_LAYOUT
	{ "[\\]",     dwindle,          {0} },
	#endif
	#if GRIDMODE_LAYOUT
	{ "HHH",      grid,             {0} },
	#endif
	#if HORIZGRID_LAYOUT
	{ "---",      horizgrid,        {0} },
	#endif
	#if GAPLESSGRID_LAYOUT
	{ ":::",      gaplessgrid,      {0} },
	#endif
	#if NROWGRID_LAYOUT
	{ "###",      nrowgrid,         {0} },
	#endif
	#if CYCLELAYOUTS_PATCH
	{ NULL,       NULL,             {0} },
	#endif
};
#else
static const Layout layouts[] = {
	/* symbol     arrange function */
	#if TILE_LAYOUT
	{ "",      tile },    /* first entry is default */
	#endif
	#if MONOCLE_LAYOUT
	{ "[M]",      monocle },
	#endif
	#if BSTACK_LAYOUT
	{ "TTT",      bstack },
	#endif
	#if BSTACKHORIZ_LAYOUT
	{ "===",      bstackhoriz },
	#endif
	#if CENTEREDMASTER_LAYOUT
	{ "|M|",      centeredmaster },
	#endif
	#if CENTEREDFLOATINGMASTER_LAYOUT
	{ ">M>",      centeredfloatingmaster },
	#endif
	#if DECK_LAYOUT
	{ "[D]",      deck },
	#endif
	#if FIBONACCI_SPIRAL_LAYOUT
	{ "(@)",      spiral },
	#endif
	#if FIBONACCI_DWINDLE_LAYOUT
	{ "[\\]",     dwindle },
	#endif
	#if NROWGRID_LAYOUT
	{ "###",      nrowgrid },
	#endif
	#if GAPLESSGRID_LAYOUT
	{ ":::",      gaplessgrid },
	#endif
	#if HORIZGRID_LAYOUT
	{ "---",      horizgrid },
	#endif
	{ "",      NULL },    /* no layout function means floating behavior */
	#if CYCLELAYOUT_PATCH
	{ NULL,       NULL },
	#endif
};
#endif // FLEXTILE_DELUXE_LAYOUT

#if KEYMAP
#include "keymap.h"
#else
/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
#if LAYOUTMENU_PATCH
static const char *layoutmenu_cmd = "layoutmenu.sh";
#endif // LAYOUTMENU_PATCH
static const char *termcmd[]  = { TERM, NULL };
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
#endif

#if DWMC_PATCH
/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum               function */
	{ "focusstack",           focusstack },
	{ "setmfact",             setmfact },
	{ "togglebar",            togglebar },
	{ "incnmaster",           incnmaster },
	{ "togglefloating",       togglefloating },
	{ "focusmon",             focusmon },
	{ "tagmon",               tagmon },
	{ "zoom",                 zoom },
	{ "view",                 view },
	{ "viewall",              viewallex },
	{ "viewex",               viewex },
	{ "toggleview",           view },
	{ "toggleviewex",         toggleviewex },
	#if STICKY_PATCH
	{ "togglesticky",         togglesticky },
	#endif // STICKY_PATCH
	#if FULLSCREEN_PATCH
	{ "togglefullscreen",     togglefullscreen },
	#endif // TOGGLEFULLSCREEN_PATCH
	#if !FAKEFULLSCREEN_PATCH && FAKEFULLSCREEN_CLIENT_PATCH
	{ "togglefakefullscreen", togglefakefullscreen },
	#endif // FAKEFULLSCREEN_CLIENT_PATCH
	#if SYSTRAY_PATCH
	{ "togglesystray",        togglesystray },
	#endif // TOGGLEFULLSCREEN_PATCH
	#if SCRATCHPADS_PATCH
	{ "togglescratch",        togglescratch },
	#endif // SCRATCHPADS_PATCH
	#if FLEXTILE_DELUXE_LAYOUT
	{ "incnstack",               incnstack },
	{ "rotatelayoutaxis",        rotatelayoutaxis },
	{ "setlayoutaxisex",         setlayoutaxisex },
	{ "mirrorlayout",            mirrorlayout },
	#endif // FLEXTILE_DELUXE_LAYOUT
	#if CFACTS_PATCH
	{ "setcfact",                setcfact },
	#endif // CFACTS_PATCH
	#if VANITYGAPS_PATCH
	{ "incrgaps",                incrgaps },
	{ "incrigaps",               incrigaps },
	{ "incrogaps",               incrogaps },
	{ "incrihgaps",              incrihgaps },
	{ "incrivgaps",              incrivgaps },
	{ "incrohgaps",              incrohgaps },
	{ "incrovgaps",              incrovgaps },
	{ "togglegaps",              togglegaps },
	{ "defaultgaps",             defaultgaps },
	{ "setgaps",                 setgapsex },
	#endif // VANITYGAPS_PATCH
	#if CYCLELAYOUTS_PATCH
	{ "cyclelayout",             cyclelayout },
	#endif // CYCLELAYOUTS_PATCH
	{ "tag",                  tag },
	{ "tagall",               tagallex },
	{ "tagex",                tagex },
	{ "toggletag",            tag },
	{ "toggletagex",          toggletagex },
	{ "killclient",           killclient },
	{ "quit",                 quit },
	{ "setlayout",            setlayout },
	{ "setlayoutex",          setlayoutex },
};
#endif

#if IPC_PATCH
static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
	IPCCOMMAND( focusmon, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( focusstack, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incnmaster, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( killclient, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( quit, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( setlayoutsafe, 1, {ARG_TYPE_PTR} ),
	IPCCOMMAND( setmfact, 1, {ARG_TYPE_FLOAT} ),
	IPCCOMMAND( tag, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( tagmon, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( togglebar, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( togglefloating, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( toggletag, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( toggleview, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( view, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( zoom, 1, {ARG_TYPE_NONE} ),
	#if CFACTS_PATCH
	IPCCOMMAND( setcfact, 1, {ARG_TYPE_FLOAT} ),
	#endif // CFACTS_PATCH
	#if CYCLELAYOUTS_PATCH
	IPCCOMMAND( cyclelayout, 1, {ARG_TYPE_SINT} ),
	#endif // CYCLELAYOUTS_PATCH
	#if !FAKEFULLSCREEN_PATCH && FAKEFULLSCREEN_CLIENT_PATCH
	IPCCOMMAND( togglefakefullscreen, 1, {ARG_TYPE_NONE} ),
	#endif // FAKEFULLSCREEN_CLIENT_PATCH
	#if FLEXTILE_DELUXE_LAYOUT
	IPCCOMMAND( incnstack, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( rotatelayoutaxis, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( setlayoutaxisex, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( mirrorlayout, 1, {ARG_TYPE_NONE} ),
	#endif // FLEXTILE_DELUXE_LAYOUT
	#if SCRATCHPADS_PATCH
	IPCCOMMAND( togglescratch, 1, {ARG_TYPE_UINT} ),
	#endif // SCRATCHPADS_PATCH
	#if SHIFTVIEW_PATCH
	IPCCOMMAND( shiftview, 1, {ARG_TYPE_SINT} ),
	#endif // SHIFTVIEW_PATCH
	#if SHIFTVIEW_CLIENTS_PATCH
	IPCCOMMAND( shiftviewclients, 1, {ARG_TYPE_SINT} ),
	#endif // SHIFTVIEW_CLIENTS_PATCH
	#if STICKY_PATCH
	IPCCOMMAND( togglesticky, 1, {ARG_TYPE_NONE} ),
	#endif // STICKY_PATCH
	#if FULLSCREEN_PATCH
	IPCCOMMAND( togglefullscreen, 1, {ARG_TYPE_NONE} ),
	#endif // TOGGLEFULLSCREEN_PATCH
	#if VANITYGAPS_PATCH
	IPCCOMMAND( incrgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrigaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrogaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrihgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrivgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrohgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrovgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( togglegaps, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( defaultgaps, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( setgapsex, 1, {ARG_TYPE_SINT} ),
	#endif // VANITYGAPS_PATCH
};
#endif // IPC_PATCH
