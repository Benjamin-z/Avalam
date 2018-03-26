/*
 * main.c
 *
 *  Created on: 15 févr. 2018
 *      Author: ben
 */
#include "plateau.h"
#include <stdio.h>
#include "partie.h"
#include "IA.h"
#include "colorANSI.h"
#include "interface.h"
//#include <unistd.h>		// pause()

int main(){
	// Creation du plateau
	plateau p;
  // Coordonnées pour mvt
  int xd, yd;
	int xa, ya;
	// Joueurs
	int joueur = 0;
	int nb_tour = 0;
	int nb_coups_restants = 48;

	int testDep;

	// Initialisation du plateau de jeu
	p = initPlateau();
	initInterTXT();
	affPlatTXT(p);
	while(1){
  //while(nb_coups_restants != 0){
		nb_tour++;
		interTour(joueur, nb_tour);
		printf("%d tours jouables\n",nb_coups_restants);

		do{
				partJoueur(p,&xd,&yd,&xa,&ya);
				testDep = testCoups(p,xd,yd,xa,ya);
				//Test de la tour de depart
				printf("test Tour = %d\n", testTour(p, xd, yd));
		}while(testDep!=0);
		//IAalea(p,&xd,&yd,&xa,&ya,nb_coups_restants);
		printf("Dep(%d,%d)\nArr(%d,%d)\n",xd,yd,xa,ya);

		// Deplace une tour
    dep(&p, xd, yd, xa, ya);
		affPlatTXT(p);
		//affPlatDEBUG(p);
		nb_coups_restants = testPlateau(p);
		joueur = !joueur; // 1 || 0
	}
	return 0;
}
