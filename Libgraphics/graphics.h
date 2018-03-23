
/* Interface de la bibliothèque `graphics' */

#include <X11/Xlib.h>

/* Ouverture de la fenêtre, fermeture et fonctions associées. */

void gr_open_graph(char* arg);

void gr_close_graph(void);

void gr_clear_graph(void);

int gr_size_x(void);

int gr_size_y(void);

/* Primitives de dessin */

void gr_plot(int x, int y);

void gr_moveto(int x, int y);

void gr_current_point(int *x, int *y);

void gr_lineto(int x, int y);

void gr_draw_arc(int x, int y, int rx, int ry, int a1, int a2);
void gr_draw_ellispe(int x, int y, int rx, int ry);
void gr_draw_circle(int x, int y, int r);
void gr_draw_poly(int* array, int npoints);

void gr_set_line_width(int width);

/* Remplissage */

void gr_fill_rect(int x, int y, int w, int h);
void gr_fill_poly(int* array, int npoints);

void gr_fill_arc(int x, int y, int rx, int ry, int a1, int a2);
void gr_fill_ellipse(int x, int y, int rx, int ry);
void gr_fill_circle(int x, int y, int r);

/* Couleurs */

typedef unsigned long color;

#define RGB(r,g,b) (((r) << 16) + ((g) << 8) + b)

#define black   0x000000
#define white   0xFFFFFF
#define red     0xFF0000
#define green   0x00FF00
#define blue    0x0000FF
#define yellow  0xFFFF00
#define cyan    0x00FFFF
#define magenta 0xFF00FF

#define background white
#define foreground black

void gr_set_color(color c);

color gr_get_color(int x, int y);

/* Texte */

void gr_set_font(char *fontname);

void gr_draw_char(char chr);

void gr_draw_string(char *str);

void gr_text_size(char *str, int *w, int *h);

/* Images */

struct grimage {
  int width, height;            /* Dimensions de l'image */
  Pixmap data;                  /* Pixels */
  Pixmap mask;                  /* Masque pour les points transparent */
};

/* couleur pour les points transparents */
#define Transparent (-1)

struct grimage* gr_create_image(int w, int h);

void gr_blit_image(struct grimage *im, int x, int y);

/* static void gr_free_image(struct grimage *im); */

struct grimage* gr_make_image(color* m, int width, int height);

color* gr_dump_image(struct grimage* image);

struct grimage* gr_get_image(int x, int y, int w, int h);

/* Son */

void gr_sound(int freq, int dur);

/* Événements */

struct status {
  int mouse_x;
  int mouse_y;
  Bool button;
  Bool key_pressed;
  char key;
};

#define BUTTON_DOWN  0x00000001
#define BUTTON_UP    0x00000002
#define KEY_PRESSED  0x00000004
#define MOUSE_MOTION 0x00000008
#define POLL         0x00000010

struct status* gr_wait_event(int eventmask);

void gr_mouse_pos(int *x, int *y);
Bool gr_button_down(void);
Bool gr_key_pressed(void);
char gr_read_key(void);

