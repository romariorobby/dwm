
void
sigdwmblocks(const Arg *arg)
{
        static int fd = -1;
        struct flock fl;
        union sigval sv;

        if (!dwmblockssig)
                return;
        fl.l_type = F_WRLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        if (fd == -1) {
                if ((fd = open(DWMBLOCKSLOCKFILE, O_RDONLY)) == -1)
                        return;
                if (fcntl(fd, F_GETLK, &fl) == -1 || fl.l_type == F_UNLCK)
                        return;
        } else {
                if (fcntl(fd, F_GETLK, &fl) == -1)
                        return;
                if (fl.l_type == F_UNLCK) {
                        close(fd);
                        if ((fd = open(DWMBLOCKSLOCKFILE, O_RDONLY)) == -1)
                                return;
                        fl.l_type = F_WRLCK;
                        if (fcntl(fd, F_GETLK, &fl) == -1 || fl.l_type == F_UNLCK)
                                return;
                }
        }
        sv.sival_int = (dwmblockssig << 8) | arg->i;
        sigqueue(fl.l_pid, SIGRTMIN, sv);
}

void
updatedwmblockssig(int x)
{
        char *sts = stexts;
        char *stp = stexts;
        char tmp;

        while (*sts != '\0') {
                if ((unsigned char)*sts >= ' ') {
                        sts++;
                        continue;
                }
                tmp = *sts;
                *sts = '\0';
                x += TTEXTW(stp);
                *sts = tmp;
                if (x > 0) {
                        if (tmp == DELIMITERENDCHAR)
                                break;
                        if (!selmon->statushandcursor) {
                                selmon->statushandcursor = 1;
                                XDefineCursor(dpy, selmon->barwin, cursor[CurHand]->cursor);
                        }
                        dwmblockssig = tmp;
                        return;
                }
                stp = ++sts;
        }
        if (selmon->statushandcursor) {
                selmon->statushandcursor = 0;
                XDefineCursor(dpy, selmon->barwin, cursor[CurNormal]->cursor);
        }
        dwmblockssig = 0;
}

