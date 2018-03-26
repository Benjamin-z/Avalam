/*
 * partie.h
 *
 *  Created on: 16 févr. 2018
 *      Author: ben
 */

#ifndef PARTIE_H_
#define PARTIE_H_

#endif /* PARTIE_H_ */

// Permet de modifier la taille et la couleur d'une tour x,y
void modTour(plateau *p, int x, int y, char c, int tal, int jou);

// Permet de deplacer une tour xDep, yDep en xArr,Yarr
void dep(plateau *p, int xDep, int yDep, int xArr, int yArr);

// Teste si le coups est jouable et renvoi un booleen
int testCoups(plateau p, int xDeb, int yDeb, int xArr, int yArr);

// Test la fin de partie
int finPartie(plateau p);

// Test de la tour pour voir si on peu encore la jouer
int testTour(plateau p, int x, int y);

// Test tous le plateau tour par tour et retourne le nb de tour jouables
int testPlateau(plateau p);

// Test la position de la tour. les coordonnee doivent etre entre 0 et TAILLE-1
int testPosTour(int x, int y,plateau p);
