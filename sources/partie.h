/*
 * partie.h
 * Cree le 16/02/18 par benjamin-z
 */

// Definition pour le niveau d'affichage
#define VERBOSE 1

// Permet de modifier la taille et la couleur d'une tour x,y
void modTour(plateau *p, int x, int y, char c, int tal);

// Permet de deplacer une tour xd, yd en xa,ya
void dep(plateau *p, int xd, int yd, int xa, int ya);

// Teste si le coups est jouable et renvoi un booleen
int testCoups(plateau p, int xd, int yd, int xa, int ya, int verbose);

// Test la fin de partie
int finPartie(plateau p);

// Test de la tour pour voir si on peu encore la jouer
int testTour(plateau p, int x, int y);

// Test tous le plateau tour par tour et retourne le nb de tour jouables
int testPlateau(plateau p);

// Test la position de la tour. les coordonnee doivent etre entre 0 et TAILLE-1
int testPos(plateau p, int x, int y);

// Test la taille de la tour quoi doir etre entre 1 et 4
int testTaille(plateau p, int x, int y);

// Test les tours voisines. La tour est jouable tant qu'une des tour voisine a une taille sup a 0
int testVoisin(plateau p, int x, int y);
