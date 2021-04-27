#if SOLARIZED_DARK
static const char *colors[][17]      = {
    /* fg    bg         border */
    { "#286e75", "#002b36", "#286e75"},        /* [0]  01 - Client normal */
    { "#268bd2", "#002b36", "#af8700"},        /* [1]  02 - Client selected */
    { "#dc322f", "#002b36", "#286e75"},        /* [2]  03 - Client urgent */
    { "#286e75", "#002b36", "#286e75"},        /* [3]  04 - Client occupied */
    { "#dc322f", "#002b36", "#002b36"},        /* [4]  05 - Red */
    { "#af8700", "#002b36", "#002b36"},        /* [5]  06 - Yellow */
    { "#859900", "#002b36", "#002b36"},        /* [6]  07 - Green */
    { "#666666", "#002b36", "#002b36"},        /* [7]  08 - Dark grey */
    { "#DCDCDC", "#002b36", "#002b36"},        /* [8]  09 - Light grey */
    { "#286e75", "#002b36", "#286e75"},        /* [9]  0A - Bar normal*/
    { "#268bd2", "#002b36", "#268bd2"},        /* [10] 0B - Bar selected*/
    { "#dc322f", "#002b36", "#286e75"},        /* [11] 0C - Bar urgent*/
    { "#268bd2", "#002b36", "#286e75"},        /* [12] 0D - Bar occupied*/
    { "#286e75", "#002b36", "#286e75"},        /* [13] 0E - Tag normal*/
    { "#268bd2", "#002b36", "#268bd2"},        /* [14] 0F - Tag selected*/
    { "#dc322f", "#002b36", "#dc322f"},        /* [15] 10 - Tag urgent*/
    { "#268bd2", "#002b36", "#286e75"},        /* [16] 11 - Tag occupied*/
};
#elif SOLARIZED_LIGHT
static const char *colors[][17]      = {
    /* fg    bg         border */
    { "#93a1a1", "#fdf6e3", "#93a1a1"},        /* [0]  01 - Client normal */
    { "#268bd2", "#fdf6e3", "#268bd2"},        /* [1]  02 - Client selected */
    { "#dc322f", "#fdf6e3", "#93a1a1"},        /* [2]  03 - Client urgent */
    { "#93a1a1", "#fdf6e3", "#93a1a1"},        /* [3]  04 - Client occupied */
    { "#dc322f", "#fdf6e3", "#fdf6e3"},        /* [4]  05 - Red */
    { "#af8700", "#fdf6e3", "#fdf6e3"},        /* [5]  06 - Yellow */
    { "#859900", "#fdf6e3", "#fdf6e3"},        /* [6]  07 - Green */
    { "#666666", "#fdf6e3", "#fdf6e3"},        /* [7]  08 - Dark grey */
    { "#DCDCDC", "#fdf6e3", "#fdf6e3"},        /* [8]  09 - Light grey */
    { "#93a1a1", "#fdf6e3", "#93a1a1"},        /* [9]  0A - Bar normal*/
    { "#268bd2", "#fdf6e3", "#268bd2"},        /* [10] 0B - Bar selected*/
    { "#dc322f", "#fdf6e3", "#93a1a1"},        /* [11] 0C - Bar urgent*/
    { "#268bd2", "#fdf6e3", "#93a1a1"},        /* [12] 0D - Bar occupied*/
    { "#93a1a1", "#fdf6e3", "#93a1a1"},        /* [13] 0E - Tag normal*/
    { "#268bd2", "#fdf6e3", "#268bd2"},        /* [14] 0F - Tag selected*/
    { "#dc322f", "#fdf6e3", "#dc322f"},        /* [15] 10 - Tag urgent*/
    { "#268bd2", "#fdf6e3", "#93a1a1"},        /* [16] 11 - Tag occupied*/
};
#endif
