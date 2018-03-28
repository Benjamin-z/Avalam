/*
 * Fichier : partie.c
 * Cree le 16/02/18 par benjamin-z
 */

#include "plateau.h"
#include "partie.h"
#include "colorANSI.h"
#include <stdio.h>
#include <stdlib.h> //abs()

// Permet de modifier la taille et la couleur d'une tour x,y
void modTour(plateau *p, int x, int y, char c, int tal, int jou){
	p->pos[y][x].couleur = c;
	p->pos[y][x].taille  = tal;
  p->pos[y][x].jouable = jou;
}

// Permet de deplacer une tour xDep, yDep en xArr, yArr
void dep(plateau* p, int xDep, int yDep, int xArr, int yArr){
			// Changement des caracteristique de la tour d'arrivee
			p->pos[yArr][xArr].taille += p->pos[yDep][xDep].taille;
			p->pos[yArr][xArr].couleur = p->pos[yDep][xDep].couleur;
			// Mise à zero de celle de depart
			p->pos[yDep][xDep].taille = 0;
			p->pos[yDep][xDep].couleur = 'z';
}

// Test si le coups est jouable et renvoi un code d'Erreur
//0 = pas d'erreur
//1 = taille tour depart
//2 = taille tour d arrivee
//3 = ... TODO

int testCoups(plateau p, int xDep, int yDep, int xArr, int yArr, int verbose){
	int err;
	int tDep = p.pos[yDep][xDep].taille;
  int tArr = p.pos[yArr][xArr].taille;

	if(verbose) printf(ROUGE);

	//testTour(p, xDep,yDep);
	// err 1 si la taille de la tour de depart est inf à 0 ou sup à 5 inclus
	if((tDep <= 0) || (tDep >= 5)){
		if(verbose) printf("\n> Erreur taille tour de depart\n\n");
		err = 1;
	}
	// err 2 pour idem tour arrivee
	else if((tArr <= 0) || (tArr >= 5)){
		if(verbose) printf("\n> Erreur taille tour d'arrivee\n\n");
		err = 2;
	}
	// err 3 si les coordonees se la tour de departs sont inf à 0 ou sup à 9 exclus
	else if((xArr < 0) || (yArr > 9)){
		if(verbose) printf("\n> Erreur coordonnees tour de depart erronees\n\n");
		err = 3;
	}
	// err 4 idem coordonnees tour d'arrivee
	else if((xDep < 0) || (yDep > 9)){
		if(verbose) printf("\n> Erreur coordonnees tour d'arrivee erronees\n\n");
		err = 4;
	}
  // err 5 si tour depart = tour arrivee
  else if((xDep == xArr) && (yDep == yArr)){
		if(verbose) printf("\n> Erreur coordonees tour de depart et arrivee identiques\n\n");
		err = 5;
	}
	// err 6 si taille tour apres coups > 5
	else if(tDep+tArr>5){
		if(verbose) printf("\n> Erreur taille total apres coups\n\n");
		err = 6;
	}
	// Test si la tour est à proximite (test des 8 cases autour) err7 sinon
	else if((abs(yArr-yDep) <= 1) && (abs(xArr-xDep) <= 1)) err = 0;
  else{
		if(verbose) printf("\n> Erreur tour d'arrivee trop eloignee de la tour de depart\n\n");
		err = 7;
	}
	if(verbose) printf(RESET);
	return err;
}

// Test de la tour pour voir si on peu encore la jouer
int testTour(plateau *p, int x, int y, int verbose){	//TODO
	int jou, cmp;
	// Definition de toutes les cases aux alentours
	int x_prox[T_PROX] = {x+1,x+1,x+1,x,x-1,x-1,x};
	int y_prox[T_PROX] = {y-1,y,y+1,y+1,y+1,y,y-1,y-1};

	// Fait le test que si la tour est marquee "jouable"
  if(testPosTour(*p,x,y,!VERBOSE) && p->pos[y][x].jouable){
      // Test de la taille de la tour
      if((p->pos[y][x].taille <= 0) || (p->pos[y][x].taille >=5)) jou = 0;
      // Test d'isolement pour les 8 tours autour
			for (cmp  = 0; cmp < T_PROX; cmp++) {
					if(testPosTour(*p,x_prox[cmp],y_prox[cmp],!VERBOSE) && p->pos[y_prox[cmp]][x_prox[cmp]].taille < 1) jou = 0;
					else jou = 1;
			}
			p->pos[y][x].jouable = jou;
  }
	return jou;
}

// Teste tous le plateau tour par tour et retourne le nb de tours jouables entre 0 et 48
int testPlateau(plateau p){
	int x,y,nb_tour;
	for(y = 0; y < TAILLE; y++){
		for(x = 0; x < TAILLE; x++){
			//printf("tour.jou(%d,%d)=%d\n", x,y,p.pos[y][x].jouable);
			testTour(&p,x,y,MUET);
			nb_tour += p.pos[y][x].jouable;	// Comptage du nb de tours jouables
		}
	}
	return nb_tour;
}

// Test la position de la tour. les coordonnee doivent etre entre 0 et TAILLE-1
int testPosTour(plateau p, int x, int y, int verbose){
	int test;
	printf(ROUGE);
	if((x<0)||(x>TAILLE-1)||(y<0)||(y>TAILLE-1)){
		if(verbose) printf("\n> Erreur coordonnes non comprises entre %d,%d\n\n", 0, TAILLE);
		test = 0;
	}
	else test = 1;
	printf(RESET);
	return test;
}
