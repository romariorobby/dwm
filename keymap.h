/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
/* static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL }; */
static const char *termcmd[]  = { TERM, NULL };
#if LAYOUTMENU_PATCH
static const char *layoutmenu_cmd = "layoutmenu.sh";
#endif // LAYOUTMENU_PATCH
static Key keys[] = {
	/* modifier                     key        function        argument */
	/* { MODKEY,             			XK_Return, 		spawn,          		{.v = termcmd } }, */
	{ MODKEY,                       XK_b,      		togglebar,      		{0} },
	{ MODKEY,                       XK_j,      		focusstack,     		{.i = -1 } },
	{ MODKEY,                       XK_k,      		focusstack,     		{.i = +1 } },
	#if SYSTRAY_PATCH
	{ MODKEY|ShiftMask,             XK_b,      		togglesystray,     		{0} },
	#endif
	#if STICKY_PATCH
	{ MODKEY,                       XK_s,      		togglesticky,   		{0} },
	#endif
	#if FULLSCREEN_PATCH
	{ MODKEY,                       XK_f,      		togglefullscreen, 		{0} },
	#endif
	#if !FAKEFULLSCREEN_PATCH && FAKEFULLSCREEN_CLIENT_PATCH
	{ MODKEY|ShiftMask,             XK_f,      		togglefakefullscreen, 	{0} },
	#endif
	#if SCRATCHPADS_PATCH
	{ MODKEY,             			XK_grave,   	togglescratch, 			{.ui = 0 } },
	{ MODKEY,             			XK_slash,  		togglescratch, 			{.ui = 1 } },
	{ MODKEY|ShiftMask,             XK_slash, 		togglescratch, 			{.ui = 2 } },
	#endif
	#if TAGICONS_PATCH
	{ MODKEY|ControlMask|ShiftMask, XK_a,      		seticonset,     		{.i = 0 } },
	{ MODKEY|ControlMask,           XK_a,      		seticonset,     		{.i = 1 } },
	{ MODKEY,                       XK_a,      		cycleiconset,     		{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_a,      		cycleiconset,     		{.i = -1 } },
	#endif
	#if CFACTS_PATCH
	{ MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_BackSpace,  setcfact,               {0} },
	#endif // CFACTS_PATCH
	#if VANITYGAPS_PATCH
	{ Mod3Mask,                     XK_BackSpace,   defaultgaps,            {0} },
	{ Mod3Mask,           			XK_g,           togglegaps,     		{0} },
    /* All */
	{ Mod3Mask,                     XK_comma,       incrgaps,				{.i = +1 } },
	{ Mod3Mask,                     XK_period,      incrgaps,           	{.i = -1 } },
    /* Inner */
	/* { MODKEY|Mod1Mask,              XK_,            incrigaps,				{.i = +1 } }, */
	/* { MODKEY|Mod1Mask|ShiftMask,    XK_,            incrigaps,           	{.i = -1 } }, */
    /* Outer */
	/* { MODKEY,                       XK_,            incrogaps,				{.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_,            incrogaps,           	{.i = -1 } }, */
    /* Horizontal Inner */
	/* { MODKEY,                       XK_,            incrihgaps,             {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_,            incrihgaps,             {.i = -1 } }, */
    /* Horizontal Outer */
	/* { MODKEY,                       XK_,            incrohgaps,             {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_,            incrohgaps,             {.i = -1 } }, */
    /* Vertical Inner */
	/* { MODKEY,                       XK_,            incrivgaps,             {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_,            incrivgaps,             {.i = -1 } }, */
    /* Vertical Outer */
	/* { MODKEY,                       XK_,            incrovgaps,             {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_,            incrovgaps,             {.i = -1 } }, */
    //
	#endif
	{ MODKEY|ShiftMask,             XK_space,  		togglefloating, 		{0} },
	{ MODKEY,                       XK_o,      		incnmaster,     		{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      		incnmaster,     		{.i = -1 } },
	{ MODKEY,                       XK_h,      		setmfact,       		{.f = -0.05} },
	{ MODKEY,                       XK_l,      		setmfact,       		{.f = +0.05} },
	{ MODKEY,                       XK_space, 		zoom,           		{0} },
	{ MODKEY,                       XK_Tab,    		view,           		{0} },
	{ MODKEY,             			XK_q,      		killclient,     		{0} },
	/* { MODKEY,                       XK_space,  		setlayout,  		    {0} }, */
	#if SCRATCHPADS_PATCH
	{ MODKEY,                       XK_0,      		view,           		{.ui = ~SPTAGMASK } },
	#else
	{ MODKEY,                       XK_0,      		view,           		{.ui = ~0 } },
	#endif
	{ MODKEY|ShiftMask,             XK_0,      		tag,            		{.ui = ~0 } },
	{ MODKEY|ControlMask|ShiftMask, XK_comma,  		focusmon,       		{.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_period, 		focusmon,       		{.i = +1 } },
	{ MODKEY|ControlMask,           XK_comma,  		tagmon,         		{.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, 		tagmon,         		{.i = +1 } },
    // LAYOUT
	#if FLEXTILE_DELUXE_LAYOUT
	{ MODKEY|ControlMask,           XK_i,          incnstack,              {.i = +1 } },
	{ MODKEY|ControlMask,           XK_u,          incnstack,              {.i = -1 } },
	#endif // FLEXTILE_DELUXE_LAYOUT
	#if FLEXTILE_DELUXE_LAYOUT
	{ MODKEY|ControlMask,           XK_t,          rotatelayoutaxis,       {.i = +1 } },   /* flextile, 1 = layout axis */
	{ MODKEY|ControlMask,           XK_Tab,        rotatelayoutaxis,       {.i = +2 } },   /* flextile, 2 = master axis */
	{ MODKEY|ControlMask|ShiftMask, XK_Tab,        rotatelayoutaxis,       {.i = +3 } },   /* flextile, 3 = stack axis */
	{ MODKEY|ControlMask|Mod1Mask,  XK_Tab,        rotatelayoutaxis,       {.i = +4 } },   /* flextile, 4 = secondary stack axis */
	{ MODKEY|Mod3Mask,              XK_t,          rotatelayoutaxis,       {.i = -1 } },   /* flextile, 1 = layout axis */
	{ MODKEY|Mod3Mask,              XK_Tab,        rotatelayoutaxis,       {.i = -2 } },   /* flextile, 2 = master axis */
	{ MODKEY|Mod3Mask|ShiftMask,    XK_Tab,        rotatelayoutaxis,       {.i = -3 } },   /* flextile, 3 = stack axis */
	{ MODKEY|Mod3Mask|Mod1Mask,     XK_Tab,        rotatelayoutaxis,       {.i = -4 } },   /* flextile, 4 = secondary stack axis */
	{ Mod3Mask,                     XK_space,      mirrorlayout,           {0} },          /* flextile, flip master and stack areas */
	#endif // FLEXTILE_DELUXE_LAYOUT
	#if CYCLELAYOUT_PATCH
	{ Mod3Mask,           			XK_Tab,        cyclelayout,            {.i = +1 } },
	{ Mod3Mask|ShiftMask,           XK_Tab,        cyclelayout,            {.i = -1 } },
	#endif // CYCLELAYOUTS_PATCH
	#if SHIFTVIEW_PATCH
	{ MODKEY|ShiftMask,             XK_Tab,        shiftview,              { .i = -1 } },
	{ MODKEY|ShiftMask,             XK_backslash,  shiftview,              { .i = +1 } },
  	#endif // SHIFTVIEW_PATCH
  	#if SHIFTVIEW_CLIENTS_PATCH
	{ MODKEY|Mod3Mask,              XK_Tab,        shiftviewclients,       { .i = -1 } },
	{ MODKEY|Mod3Mask,              XK_backslash,  shiftviewclients,       { .i = +1 } },
  	#endif // SHIFTVIEW_CLIENTS_PATCH
	{ Mod3Mask,                     XK_t,      	   setlayout,      		   {.v = &layouts[0]} },
	{ Mod3Mask,                     XK_y,      	   setlayout,      		   {.v = &layouts[1]} },
	{ Mod3Mask,                     XK_u,      	   setlayout,      		   {.v = &layouts[2]} },
	{ Mod3Mask,                     XK_i,      	   setlayout,      		   {.v = &layouts[3]} },
	{ Mod3Mask|ShiftMask,           XK_i,      	   setlayout,      		   {.v = &layouts[4]} },
	{ Mod3Mask,                     XK_f,  	       togglefloating, 		   {0} },
	TAGKEYS(                        XK_1,                      				0)
	TAGKEYS(                        XK_2,                      				1)
	TAGKEYS(                        XK_3,                      				2)
	TAGKEYS(                        XK_4,                      				3)
	TAGKEYS(                        XK_5,                      				4)
	TAGKEYS(                        XK_6,                      				5)
	TAGKEYS(                        XK_7,                      				6)
	TAGKEYS(                        XK_8,                      				7)
	TAGKEYS(                        XK_9,                      				8)
	{ MODKEY|ShiftMask,             XK_Escape, 		quit,           		{0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */

/* placemouse options, choose which feels more natural:
 *    0 - tiled position is relative to mouse cursor
 *    1 - tiled postiion is relative to window center
 *    2 - mouse pointer warps to window center
 *
 * The moveorplace uses movemouse or placemouse depending on the floating state
 * of the selected client. Set up individual keybindings for the two if you want
 * to control these separately (i.e. to retain the feature to move a tiled window
 * into a floating position).
 */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,                  Button1,        setlayout,      {0} },
	#if LAYOUTMENU_PATCH
	{ ClkLtSymbol,          0,                  Button3,        layoutmenu,     {0} },
	#else
	{ ClkLtSymbol,          0,                  Button3,        setlayout,      {.v = &layouts[2]} },
	#endif // BAR_LAYOUTMENU_PATCH
	{ ClkWinTitle,          0,                  Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                  Button2,        spawn,          {.v = termcmd } },
	#if DRAGCFACT_PATCH && CFACTS_PATCH
	{ ClkClientWin,         MODKEY|ShiftMask,   Button3,        dragcfact,      {0} },
	#endif // DRAGCFACT_PATCH
	#if DRAGMFACT_PATCH
	{ ClkClientWin,         MODKEY|ShiftMask,   Button1,      	dragmfact,      {0} },
	#endif
	#if PLACEMOUSE_PATCH
	{ ClkClientWin,         MODKEY,             Button1,        moveorplace,    {.i = 0} },
	#else
	{ ClkClientWin,         MODKEY,             Button1,        movemouse,      {0} },
	#endif
	{ ClkClientWin,         MODKEY,             Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,             Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                  Button1,        view,           {0} },
	{ ClkTagBar,            0,                  Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,             Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,             Button3,        toggletag,      {0} },
	#if TAGICONS_PATCH
	{ ClkTagBar,            0,                  Button4,        cycleiconset,   {.i = +1 } },
	{ ClkTagBar,            0,                  Button5,        cycleiconset,   {.i = -1 } },
	#endif
	#if DWMBLOCKS_PATCH
	{ ClkStatusText,        0,                  Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,                  Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,                  Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,                  Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,                  Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,          Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkStatusText,        ShiftMask,          Button2,        sigdwmblocks,   {.i = 7} },
	{ ClkStatusText,        ShiftMask,          Button3,        sigdwmblocks,   {.i = 8} },
	#endif // DWMBLOCKS_PATCH
};

