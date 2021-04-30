#include <fcntl.h>

#define TTEXTW(X)               (drw_fontset_getwidth(drw, (X)))
#define STATUSLENGTH            256
#define DWMBLOCKSLOCKFILE       "/tmp/dwmblocks.pid"
#define DELIMITERENDCHAR        20
#define LSPAD                   (lrpad / 2) /* padding on left side of status text */
#define RSPAD                   (lrpad / 2) /* padding on right side of status text */

static void sigdwmblocks(const Arg *arg);
static void updatedwmblockssig(int x);
static char stextc[STATUSLENGTH];
static char stexts[STATUSLENGTH];
static unsigned int dwmblockssig;
