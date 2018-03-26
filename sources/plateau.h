/*
 * plateau.h
 *
 *  Created on: 15 févr. 2018
 *      Author: ben
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_



#endif /* PLATEAU_H_ */

// Le plateau fait TAILLE par TAILLE
#define TAILLE 9

// Nb de tours a proximite
#define T_PROX 8

// Def de la structure tour définie par sa couleur et sa taille
typedef struct {
	char couleur;
	int taille;
    int jouable;
}tour;

// Def de la structure plateau définie comme un tableau de tours
typedef struct {
	tour pos[TAILLE][TAILLE];
}plateau;
// Pour utiliser la tour x,y on ecrit : plateau.pos[y][x]

// Calcul de la couleur d'une case à l'initialisation
// Pour faire l alternance des couleurs de cases
char initCoul(int x, int y);

// Initialisation des cases du plateau
plateau initPlateau();

// Affichage le plus simple du plateau de jeu
void affPlatTXT(plateau p);

// Affichage ligne par ligne
void affPlatDEBUG(plateau p);
