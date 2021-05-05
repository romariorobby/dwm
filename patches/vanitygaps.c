#if !PERTAG_VANITYGAPS_PATCH || !PERTAG_PATCH
static int enablegaps = 1;   /* enables gaps, used by togglegaps */
#endif //!PERTAG_VANITYGAPS_PATCH || !PERTAG_PATCH


void
setgaps(int oh, int ov, int ih, int iv)
{
	if (oh < 0) oh = 0;
	if (ov < 0) ov = 0;
	if (ih < 0) ih = 0;
	if (iv < 0) iv = 0;

	selmon->gappoh = oh;
	selmon->gappov = ov;
	selmon->gappih = ih;
	selmon->gappiv = iv;

	#if PERTAG_VANITYGAPS_PATCH && PERTAG_PATCH
	selmon->pertag->gaps[selmon->pertag->curtag] =
		((oh & 0xFF) << 0) | ((ov & 0xFF) << 8) | ((ih & 0xFF) << 16) | ((iv & 0xFF) << 24);
	#endif // PERTAG_VANITYGAPS_PATCH | PERTAG_PATCH

	arrange(selmon);

}

#if IPC_PATCH || DWMC_PATCH
/* External function that takes one integer and splits it
 * into four gap values:
 *    - outer horizontal (oh)
 *    - outer vertical (ov)
 *    - inner horizontal (ih)
 *    - inner vertical (iv)
 *
 * Each value is represented as one byte with the uppermost
 * bit of each byte indicating whether or not to keep the
 * current value.
 *
 * Example:
 *
 *   10000000   10000000   00001111   00001111
 *   |          |          |          |
 *   + keep oh  + keep ov  + ih 15px  + iv 15px
 *
 * This gives an int of:
 *   10000000100000000000111100001111 = 2155876111
 *
 * Thus this command should set inner gaps to 15:
 *   xsetroot -name "fsignal:setgaps i 2155876111"
 */
static void
setgapsex(const Arg *arg)
{
	int oh = selmon->gappoh;
	int ov = selmon->gappov;
	int ih = selmon->gappih;
	int iv = selmon->gappiv;

	if (!(arg->i & (1 << 31)))
		oh = (arg->i & 0x7f000000) >> 24;
	if (!(arg->i & (1 << 23)))
		ov = (arg->i & 0x7f0000) >> 16;
	if (!(arg->i & (1 << 15)))
		ih = (arg->i & 0x7f00) >> 8;
	if (!(arg->i & (1 << 7)))
		iv = (arg->i & 0x7f);

	/* Auto enable gaps if disabled */
	#if PERTAG_VANITYGAPS_PATCH && PERTAG_PATCH
	if (!selmon->pertag->enablegaps[selmon->pertag->curtag])
		selmon->pertag->enablegaps[selmon->pertag->curtag] = 1;
	#else
	if (!enablegaps)
		enablegaps = 1;
	#endif // PERTAG_VANITYGAPS_PATCH | PERTAG_PATCH

	setgaps(oh, ov, ih, iv);
}
#endif // IPC_PATCH | DWMC_PATCH
void
togglegaps(const Arg *arg)
{
	#if PERTAG_VANITYGAPS_PATCH && PERTAG_PATCH
	selmon->pertag->enablegaps[selmon->pertag->curtag] = !selmon->pertag->enablegaps[selmon->pertag->curtag];
	#else
	enablegaps = !enablegaps;
	#endif
	arrange(selmon);
}

void
defaultgaps(const Arg *arg)
{
	setgaps(gappoh, gappov, gappih, gappiv);
}

void
incrgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov + arg->i,
		selmon->gappih + arg->i,
		selmon->gappiv + arg->i
	);
}

void
incrigaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih + arg->i,
		selmon->gappiv + arg->i
	);
}

void
incrogaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov + arg->i,
		selmon->gappih,
		selmon->gappiv
	);
}

void
incrohgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov,
		selmon->gappih,
		selmon->gappiv
	);
}

void
incrovgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov + arg->i,
		selmon->gappih,
		selmon->gappiv
	);
}

void
incrihgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih + arg->i,
		selmon->gappiv
	);
}

void
incrivgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih,
		selmon->gappiv + arg->i
	);
}

#if DRAGMFACT_PATCH || CENTEREDMASTER_LAYOUT || CENTEREDFLOATINGMASTER_LAYOUT || COLUMNS_LAYOUT || DECK_LAYOUT || FIBONACCI_DWINDLE_LAYOUT || FIBONACCI_SPIRAL_LAYOUT || GAPLESSGRID_LAYOUT || NROWGRID_LAYOUT || HORIZGRID_LAYOUT || BSTACK_LAYOUT || BSTACKHORIZ_LAYOUT || GRIDMODE_LAYOUT || FLEXTILE_DELUXE_LAYOUT || TILE_LAYOUT || (VANITYGAPS_MONOCLE_PATCH && MONOCLE_LAYOUT)
void
getgaps(Monitor *m, int *oh, int *ov, int *ih, int *iv, unsigned int *nc)
{
	unsigned int n, oe, ie;
	#if PERTAG_PATCH
	oe = ie = selmon->pertag->enablegaps[selmon->pertag->curtag];
	#else
	oe = ie = enablegaps;
	#endif // PERTAG_PATCH
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 1) {
		oe *= smartgaps_fact; // outer gaps disabled or multiplied when only one client
	}

	*oh = m->gappoh*oe; // outer horizontal gap
	*ov = m->gappov*oe; // outer vertical gap
	*ih = m->gappih*ie; // inner horizontal gap
	*iv = m->gappiv*ie; // inner vertical gap
	*nc = n;            // number of clients
}
#endif
