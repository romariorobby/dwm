static const char col_bg[]   	= "#141414";
static const char col_bg0[]   	= "#282828";
static const char col_bg1[]   	= "#3c3836";
static const char col_bg2[]   	= "#504945";
static const char col_bg3[]   	= "#665c54";
static const char col_bg4[]   	= "#7c6f64";

static const char col_fg[]   	= "#ebdbb2";
static const char col_fg0[]   	= "#d5c4a1";
static const char col_fg1[]   	= "#bdae93";
static const char col_fg2[]   	= "#a89984";

static const char col_red[]     = "#cc241d";
static const char col_green[]   = "#98971a";
static const char col_yellow[]  = "#d79921";
static const char col_blue[]    = "#458588";
static const char col_magenta[] = "#b16286";
static const char col_cyan[]    = "#689d6a";

static const char col_red2[]     = "#fb4934";
static const char col_green2[]   = "#b8bb26";
static const char col_yellow2[]  = "#fabd2f";
static const char col_blue2[]    = "#83a598";
static const char col_magenta2[] = "#d3869b";
static const char col_cyan2[]    = "#8ec07c";

static const char col_blue3[]    = "#376a6c";
static const char col_blue4[]    = "#305d5f";
static const char col_blue5[]    = "#1B3536";
#if GRUVBOX_DARK
static const char *colors[][29]      = {
// GRUVBOX DARK
//          fg         bg        border
    [SchemeNorm] = { col_fg2, col_bg, col_bg0},        /* [0] 15 - Client Normal */
    [SchemeSel]  = { col_blue, col_bg, col_blue},        /* [0] 15 - Client Normal */
    [SchemeUrg]  = { "#cc241d", "#141414", "#cc241d" },        /* [2] 17 - Client urgent */
    [SchemeOcc]  = { "#d65d0e", "#141414", "#d65d0e" },        /* [3] 18 - Client Occupied */
    // FG
    { "#cc241d", "#141414", "#cc241d" },        /* [4] 19 - FG_Red*/
    { "#458588", "#141414", "#458588" },        /* [5] 1a - FG_Blue */
    { "#98971a", "#141414", "#141414" },        /* [6] 1a - FG_Green */
    { "#fabd2f", "#141414", "#141414" },        /* [7] 1b - FG_Yellow */
    { "#d65d0e", "#141414", "#d65d0e" },        /* [8] 1c - FG_Orange */
    { "#689d6a", "#141414", "#689d6a" },        /* [9] 1d - FG_Aqua */
    { "#b16286", "#141414", "#b16286" },        /* [10] 1e - FG_Purple */
    { "#ebdbb2", "#141414", "#ebdbb2" },        /* [11] 1f - FG_White */
    { "#282828", "#141414", "#282828" },        /* [12] 2f - FG_Black */
    { "#a89984", "#141414", "#a89984" },        /* [13] 19 - BG_Grey */
    // BG
    { "#141414", "#cc241d", "#cc241d" },        /* [14] 17 - BG_Red*/
    { "#141414", "#458588", "#458588" },        /* [15] 16 -  BG_Blue*/
    { "#141414", "#98971a", "#141414" },        /* [16] 19 - BG_Green */
    { "#141414", "#fabd2f", "#141414" },        /* [17] 18 - BG_Yellow */
    { "#141414", "#d65d0e", "#d65d0e" },        /* [18] 20 - BG_Orange */
    { "#141414", "#689d6a", "#689d6a" },        /* [19] 19 - BG_Aqua */
    { "#141414", "#b16286", "#b16286" },        /* [20] 19 - BG_Purple */
    { "#141414", "#ebdbb2", "#ebdbb2" },        /* [21] 1f - FG_White */
    { "#141414", "#282828", "#282828" },        /* [22] 1f - FG_Black */
    { "#141414", "#a89984", "#a89984" },        /* [23] 19 - BG_Grey */
    // TAG
	[TagNorm] = { col_bg1, col_bg, col_bg0 },        /* [24] 0E - Tag Normal*/
    [TagSel]  = { col_blue, col_bg, col_blue },        /* [25] 0E - Tag Selected*/
    [TagUrg]  = { col_red, col_bg, col_red },        /* [26] 0E - Tag Urgent*/
    [TagOcc]  = { col_blue4, col_bg, "#3c3836" },        /* [27] 0E - Tag occupied*/
    // BAR
    [BarNorm] = { "#141414", "#ebdbb2", "#282828" },        /* [29]  1f - Bar Normal */
    [BarSel]  = { "#141414", "#ebdbb2", "#282828" },        /* [30]  1f - Bar Selected */
    [BarUrg]  = { "#141414", "#cc241d", "#458588" },        /* [31]  17 - Bar Urgent */
    [BarOcc]  = { "#141414", "#d65d0e", "#d65d0e" },        /* [32]  17 - Bar Occupied */
};
#elif GRUVBOX_LIGHT
static const char *colors[][3]      = {
// GRUVBOX_LIGHT
//          fg         bg        border
    { "#3c3836", "#fbf1c7",  "#fbf1c7" },        /* [0]  01 - Client normal */
    { "#458588", "#282828",  "#ebdbb2" },        /* [1]  02 - Client selected */
    { "#fb4934", "#282828",  "#83a598" },        /* [2]  03 - Client urgent */
    { "#83a598", "#282828",  "#83a598" },        /* [3]  04 - Client occupied */
    { "#fb4934", "#282828",  "#282828" },        /* [4]  05 - Red */
    { "#fabd2f", "#282828",  "#282828" },        /* [5]  06 - Yellow */
    { "#b8bb26", "#282828",  "#282828" },        /* [6]  07 - Green */
    { "#928374", "#282828",  "#282828" },        /* [7]  08 - Dark grey */
    { "#d5c4a1", "#282828",  "#282828" },        /* [8]  09 - Light grey */
    { "#928374", "#282828",  "#928374" },        /* [9]  0A - Bar normal*/
    { "#a89985", "#282828",  "#3c3836" },        /* [10] 0B - Bar selected*/
    { "#fb4934", "#282828",  "#fb4934" },        /* [11] 0C - Bar urgent*/
    { "#458588", "#282828",  "#928374" },        /* [12] 0D - Bar occupied*/
    { "#3c3836", "#282828",  "#3c3836" },        /* [13] 0E - Tag normal*/
    { "#83a598", "#282828",  "#83a598" },        /* [14] 0F - Tag selected*/
    { "#fb4934", "#282828",  "#fb4934" },        /* [15] 10 - Tag urgent*/
    { "#928374", "#282828",  "#3c3836" },        /* [16] 11 - Tag occupied*/
};
#elif GRUVBOX_MEDIUM
static const char *colors[][3]      = {
// MEDIUM
//          fg         bg        border
    { "#928374", "#282828",  "#282828" },        /* [0]  01 - Client normal */
    { "#458588", "#282828",  "#ebdbb2" },        /* [1]  02 - Client selected */
    { "#fb4934", "#282828",  "#83a598" },        /* [2]  03 - Client urgent */
    { "#83a598", "#282828",  "#83a598" },        /* [3]  04 - Client occupied */
    { "#fb4934", "#282828",  "#282828" },        /* [4]  05 - Red */
    { "#fabd2f", "#282828",  "#282828" },        /* [5]  06 - Yellow */
    { "#b8bb26", "#282828",  "#282828" },        /* [6]  07 - Green */
    { "#928374", "#282828",  "#282828" },        /* [7]  08 - Dark grey */
    { "#d5c4a1", "#282828",  "#282828" },        /* [8]  09 - Light grey */
    { "#928374", "#282828",  "#928374" },        /* [9]  0A - Bar normal*/
    { "#a89985", "#282828",  "#3c3836" },        /* [10] 0B - Bar selected*/
    { "#fb4934", "#282828",  "#fb4934" },        /* [11] 0C - Bar urgent*/
    { "#458588", "#282828",  "#928374" },        /* [12] 0D - Bar occupied*/
    { "#3c3836", "#282828",  "#3c3836" },        /* [13] 0E - Tag normal*/
    { "#83a598", "#282828",  "#83a598" },        /* [14] 0F - Tag selected*/
    { "#fb4934", "#282828",  "#fb4934" },        /* [15] 10 - Tag urgent*/
    { "#928374", "#282828",  "#3c3836" },        /* [16] 11 - Tag occupied*/
};
#endif
