#include <math.h>
#include "graphics.h"

#define GEOMETRIE " 500x500"
#define LARGEUR 500
#define HAUTEUR 500
#define RAYON 200

/* Dessin d'un hexagone r�gulier de centre (cx, cy) inscrit dans un
   cercle de rayon r, avec deux c�t�s horizontaux. */
void hexagone (int cx, int cy, int r) {
    int g; /* abscisse des points un peu � gauche */
    int d; /* abscisse des points un peu � droite */
    int haut; /* ordonn�e des points du haut */
    int bas; /* ordonn�e des points du bas */
    int t;

    t = r * sqrt(3) / 2;
    haut = cy + t;
    bas = cy - t;
    g = cx - r / 2;
    d = cx + r / 2;

    gr_moveto(cx - r, cy);
    gr_lineto(g, haut);
    gr_lineto(d, haut);
    gr_lineto(cx + r, cy);
    gr_lineto(d, bas);
    gr_lineto(g, bas);
    gr_lineto(cx - r, cy);
}

int main () {
    /* Ouverture de la fen�tre graphique */
    gr_open_graph(GEOMETRIE);
    /* Dessin d'un hexagone au centre de la fen�tre */
    hexagone(LARGEUR/2, HAUTEUR/2, RAYON);
    /* On attend que l'utilisateur appuie sur une touche */
    (void) gr_wait_event(KEY_PRESSED);
    /* On nettoie et on s'en va */
    gr_close_graph();
    return 0;
}
