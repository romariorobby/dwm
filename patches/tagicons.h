enum {
	IconsDefault,
	IconsVacant,
	IconsText,
	IconsOccupied,
	IconsLast
}; /* icon sets */

static void cycleiconset(const Arg *arg);
static char * geticon(Monitor *m, int tag, int iconset);
static void seticonset(const Arg *arg);
static char * tagicon(Monitor *m, int tag);
