/*
 * partie.c
 *
 *  Created on: 16 févr. 2018
 *      Author: ben
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

// Permet de déplacer une tour xDep, yDep en xArr, yArr
void dep(plateau* p, int xDep, int yDep, int xArr, int yArr){
	printf(ROUGE);
	switch (testCoups(*p, xDep, yDep, xArr, yArr)){
		case 0:
    	printf(RESET);
			// Changement des caractéristique de la tour d'arrivée
			p->pos[yArr][xArr].taille += p->pos[yDep][xDep].taille;
			p->pos[yArr][xArr].couleur = p->pos[yDep][xDep].couleur;
			// Mise à zéro de celle de départ
			p->pos[yDep][xDep].taille = 0;
			p->pos[yDep][xDep].couleur = 'z';
      affPlatTXT(*p);
		break;

    case 1:
			printf("Erreur taille tour de départ\n");
		break;

    case 2:
    	printf("Erreur taille tour d'arrivée\n");
    break;

    case 3:
    	printf("Erreur coordonnées tour de départ erronées\n");
    break;

    case 4:
    	printf("Erreur coordonnées tour d'arrivée erronées\n");
    break;

    case 5:
    	printf("Erreur coordonées tour de départ et arrivée identiques\n");
    break;

    case 6:
    	printf("Erreur taille total apres coups\n");
    break;

		case 7:
			printf("Erreur tour d'arrivée trop éloignée de la tour de départ\n");
		break;
  }
  printf(RESET);
}

// Test si le coups est jouable et renvoi un code d'Erreur
//0 = pas d'erreur
//1 = taille tour depart
//2 = taille tour d arrivee
//3 = TODO

int testCoups(plateau p, int xDep, int yDep, int xArr, int yArr){
	int err;
	int tDep = p.pos[yDep][xDep].taille;
  int tArr = p.pos[yArr][xArr].taille;

	//testTour(p, xDep,yDep);
	// err 1 si la taille de la tour de départ est inf à 0 ou sup à 5 inclus
	if((tDep <= 0) || (tDep >= 5)) err = 1;
	// err 2 pour idem tour arrivée
	else if((tArr <= 0) || (tArr >= 5)) err = 2;
	// err 3 si les coordonées se la tour de départs sont inf à 0 ou sup à 9 exclus
	else if((xArr < 0) || (yArr > 9)) err = 3;
	// err 4 idem coordonnées tour d'arrivée
	else if((xDep < 0) || (yDep > 9)) err = 4;
  // err 5 si tour départ = tour arrivée
  else if((xDep == xArr) && (yDep == yArr)) err = 5;
	// err 6 si taille tour apres coups < 5
	else if(tDep+tArr>5) err = 6;
	// Test si la tour est à proximité (test des 8 cases autour) err7 sinon
	else if((abs(yArr-yDep) <= 1) && (abs(xArr-xDep) <= 1)) err = 0;
  else err = 7;
	return err;
}


// Test la fin de partie
// Renvoi le nb de coups jouable
/*int finPartie(plateau p){
  int x, y,fp;
	//Test si la partie est finPartie
	testPlateau(p);
  for(y = 0; y < TAILLE; y++){
  	for(x = 0; x < TAILLE; x++){
    	fp = fp + p.pos[y][x].jouable;
    }
	}
  return fp;
}*/

// Test de la tour pour voir si on peu encore la jouer
void testTour(plateau p, int x, int y){	//TODO
	int jou;
  if(p.pos[y][x].jouable){
      // Test de la taille de la tour
      if((p.pos[y][x].taille <= 0) || (p.pos[y][x].taille >=5)) jou = 0;
      // Test d'isolement pour les 8 tours autour
      else if((x!=8) && (y!=0) && (p.pos[y-1][x+1].taille <= 0)) jou = 0;    	// tour 1
      else if((x!=8) && (p.pos[y][x+1].taille <= 0)) jou = 0;									// tour 2
  		else if((x!=8) && (y!=8) && (p.pos[y+1][x+1].taille <= 0)) jou = 0;			// tour 3
  		else if((y!=8) && (p.pos[y+1][x].taille <= 0)) jou = 0;									// tour 4
  		else if((x!=0) && (y!=8) && (p.pos[y+1][x-1].taille <= 0)) jou = 0;			// tour 5
  		else if((x!=0) && (p.pos[y][x-1].taille <= 0)) jou = 0;									// tour 6
  		else if((x!=0) && (y!=0) && (p.pos[y-1][x-1].taille <= 0)) jou = 0;			// tour 7
  		else if((y!=0) && (p.pos[y-1][x].taille <= 0)) jou = 0;									// tour 8
      else p.pos[y][x].jouable = 1;
			jou = p.pos[y][x].jouable;
  }
}

// Teste tous le plateau tour par tour et retourne le nb de tours jouables
int testPlateau(plateau p){
	int x,y,nb_tour;
	for(y = 0; y < TAILLE; y++){
		for(x = 0; x < TAILLE; x++){
			printf("tour.jou(%d,%d)=%d\n", x,y,p.pos[y][x].jouable);
			testTour(p,x,y);
			nb_tour += p.pos[y][x].jouable;
		}
	}
	return nb_tour;
}
