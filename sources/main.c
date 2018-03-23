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

int main(){
	// Creation du plateau
	plateau p;
  // Coordonnées pour mvt
  int xDep, yDep;
	int xArr, yArr;
	// Joueurs
	int joueur = 0;
	int nb_tour = 0;
	//int nb_coups_restants;

	// Initialisation du plateau de jeu
	p = initPlateau();
	printf("Initialisation\n");
	affPlatTXT(p);

  while(nb_coups_restants != 0){
		nb_tour++;
		printf("Tour %d\n",nb_tour);
		// Affichage du joueur en cours
		printf("Joueur %d\n",joueur+1);
		printf("%d coups restants\n",testPlateau(p));
		joueur = !joueur; // 1 || 0


    // Choix coordonnées
    /*printf("tour de départ ?\n");
    printf("x?\n");
    scanf("%d", &xDep);
    printf("y?\n");
    scanf("%d", &yDep);

    printf("Tour d'arrivée ?\n");
    printf("x?\n");
    scanf("%d", &xArr);
    printf("y?\n");
    scanf("%d", &yArr);*/
		IAalea(p,&xDep,&yDep,&xArr,&yArr);
		printf("Dep(%d,%d)\nArr(%d,%d)\n",xDep,yDep,xArr,yArr);

		//Test de la tour de depart
		testTour(p, xDep, yDep);
		// Deplace une tour
    dep(&p, xDep, yDep, xArr, yArr);
		affPlatDEBUG(p);
		//nb_coups_restants = testPlateau(p);
	}
	return 0;
}
