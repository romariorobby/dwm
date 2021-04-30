void
cycleiconset(const Arg *arg)
{
	Monitor *m = selmon;
	if (arg->i == 0)
		return;
	if (arg->i > 0) {
		for (++m->iconset; m->iconset < IconsLast && tagicons[m->iconset][0] == NULL; ++m->iconset);
		if (m->iconset >= IconsLast)
			m->iconset = 0;
	} else if (arg->i < 0) {
		for (--m->iconset; m->iconset > 0 && tagicons[m->iconset][0] == NULL; --m->iconset);
		if (m->iconset < 0)
			for (m->iconset = IconsLast - 1; m->iconset > 0 && tagicons[m->iconset][0] == NULL; --m->iconset);
	}
	drawbar(m);
}

char *
geticon(Monitor *m, int tag, int iconset)
{
	int i;
	int tagindex = tag + NUMTAGS * m->num;
	for (i = 0; i < LENGTH(tagicons[iconset]) && tagicons[iconset][i] != NULL; ++i);
	if (i == 0)
		tagindex = 0;
	else if (tagindex >= i)
		tagindex = tagindex % i;

	return tagicons[iconset][tagindex];
}

void
seticonset(const Arg *arg)
{
	if (arg->i >= 0 && arg->i < IconsLast) {
		selmon->iconset = arg->i;
		drawbar(selmon);
	}
}

char *
tagicon(Monitor *m, int tag)
{
	Client *c;
	char *icon;
	for (c = m->clients; c && (!(c->tags & 1 << tag)); c = c->next);
	// for (c = m->clients; c && (!(c->tags & 1 << tag) || HIDDEN(c)); c = c->next); // awesomebar / wintitleactions compatibility
	if (c && tagicons[IconsOccupied][0] != NULL)
		icon = geticon(m, tag, IconsOccupied);
	else {
		icon = geticon(m, tag, m->iconset);
		if (TEXTW(icon) <= lrpad && m->tagset[m->seltags] & 1 << tag)
			icon = geticon(m, tag, IconsVacant);
	}

	return icon;
}

