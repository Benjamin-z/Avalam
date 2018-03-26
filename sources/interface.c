/*
* Fichier : interface.c
*/

#include "interface.h"
#include <stdio.h>
#include "colorANSI.h"


// Interface de bienvenu en terminal
void initInterTXT(){
  printf(ROUGE_B);
	printf("\nAVALAM\n\n");
	printf(RESET);
}

// Interface de debut de tour en terminal
void interTour(int joueur, int nb_tour){
  printf(VERT);
  printf("Tour %d\n",nb_tour);
  // Affichage du joueur en cours
  printf("Joueur %d\n",joueur+1);
  printf("--------\n\n");
  printf(RESET);
}

/*
* choix entre les modes ;
* JOUEUR vs JOUEUR
* JOUEUR vs IA
* IA vs IA
*/
void choixMode(int *j){
  int choix;
  printf(JAUNE);
  printf("Choix du mode de jeux :\n");
  printf("-----------------------\n");
  printf("\t1-Joueur contre joueur\n");
  printf("\t2-Joueur contre IA\n");
  printf("\t3-IA contre IA\n");
  printf("Votre choix ? : ");

  do {
    scanf("%d", &choix);
  } while((choix<0)&&(choix>4));
  if(choix == 1){
    j[0] = JOUEUR;
    j[1] = JOUEUR;
  }else if(choix == 2){
    j[0] = JOUEUR;
    j[1] = IA;
  }else if(choix == 3){
    j[0] = IA;
    j[1] = IA;
  }
  printf("\n"RESET);
}

//Interface apres deplacement
// Affiche le deplacement en cours ainsi que le nb de coups encore possibles
void interDep(int xd, int yd, int xa, int ya, int nb_coups_restants){
  printf("%d coups jouables\n",nb_coups_restants);
  printf("Tour %d,%d en %d,%d\n\n",xd,yd,xa,ya);
}
