/*
 * IA.c
 *
 *  Created on: 12 mars. 2018
 *      Author: ben
 */

#include "plateau.h"
#include "IA.h"
#include "alea.h"
#include "partie.h"
#include "stdio.h"
#include "colorANSI.h"


// Les coordonnees sont purement alleatoires
void IAalea(plateau p, int *xd, int *yd, int *xa, int *ya, int nb_coups_restants){
  do{
    *xd = randEntreBornes(0,TAILLE);
    *yd = randEntreBornes(0,TAILLE);
    *xa = randEntreBornes(0,TAILLE);
    *ya = randEntreBornes(0,TAILLE);
  }while((testCoups(p,*xd,*yd,*xa,*ya,MUET)!=0)&&(nb_coups_restants!=0));  //TODO bloquant fin de partie
}

// partie manuelle du Joueur
void partJoueur(plateau p,int *xd, int *yd, int *xa, int *ya){
  int testDep;

  // entrer les coordonnees tant que l'entree n'est pas correct
  do {
    // Choix coordonnées
    printf("tour de départ ?\n");
    printf("x?\n");
    scanf("%d", xd);
    printf("y?\n");
    scanf("%d", yd);

    printf("Tour d'arrivée ?\n");
    printf("x?\n");
    scanf("%d", xa);
    printf("y?\n");
    scanf("%d", ya);
    // Test du coups a realiser
    testDep = testCoups(p,*xd,*yd,*xa,*ya,VERBOSE);
    printf("test Tour = %d\n", testDep);
  } while(testDep!=0);
}
