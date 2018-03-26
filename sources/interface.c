/*
*interface.c
*/

#include "interface.h"
#include <stdio.h>
#include "colorANSI.h"

void initInterTXT(){
  printf(ROUGE_B);
	printf("\nAVALAM\n\n");
	printf(RESET);
}

void interTour(int joueur, int nb_tour){
  printf(VERT);
  printf("Tour %d\n",nb_tour);
  // Affichage du joueur en cours
  printf("Joueur %d\n",joueur+1);
  printf("--------\n\n");
  printf(RESET);
}
