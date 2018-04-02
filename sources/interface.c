/*
 * Fichier : interface.c
 * Cree le 26/03/18 par benjamin-z
 */

#include "plateau.h"
#include "partie.h"
#include "interface.h"
#include <stdio.h>
#include "colorANSI.h"
#include "config.h"


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

// partie manuelle du Joueur
void partJoueur(plateau p,int *xd, int *yd, int *xa, int *ya){
  // entrer les coordonnees tant que l'entree n'est pas correct
  do {
    // Choix coordonnees
    printf("tour de depart ?\n");
    printf("x?\n");
    scanf("%d", xd);
    printf("y?\n");
    scanf("%d", yd);

    printf("Tour d'arrivee ?\n");
    printf("x?\n");
    scanf("%d", xa);
    printf("y?\n");
    scanf("%d", ya);

    if(DEBUG) interDEBUG(p,*xd,*yd,*xa,*ya);
    //interDEBUG(p,*xd,*yd,*xa,*ya);
  } while(testCoups(p,*xd,*yd,*xa,*ya,VERBOSE)!=0);
}

//Interface apres deplacement
// Affiche le deplacement en cours ainsi que le nb de coups encore possibles
void interDep(int xd, int yd, int xa, int ya, int nb_coups_restants){
  printf("%d cases jouables\n",nb_coups_restants);
  printf("Tour %d,%d en %d,%d\n\n",xd,yd,xa,ya);
}

// Interface de DEBUG
void interDEBUG(plateau p, int xd, int yd, int xa, int ya){
  int x = xd;
  int y = yd;
  printf(ROUGE_B "\n---DEBUG---\n\n" RESET);
  printf("Info Tour depart %d,%d:\n", xd, yd);
  printf("---------------------\n");
  printf("taille = %d\n", p.pos[yd][xd].taille);
  printf("couleur = %c\n", p.pos[yd][xd].couleur);
  printf("testPos = %d\n", testPos(p,xd,yd));
  printf("testTour = %d\n", testTour(p,xd,yd));
  printf("testTaille = %d\n", testTaille(p,xd,yd));
  printf("testVoisin = %d\n\n", testVoisin(p,xd,yd));
  int x_prox[T_PROX] = {x+1,x+1,x+1,x,x-1,x-1,x-1,x};
	int y_prox[T_PROX] = {y-1,y,y+1,y+1,y+1,y,y-1,y-1};
	int i;
	for(i = 0; i < T_PROX; i++){
    if(testPos(p,x_prox[i],y_prox[i])) printf("testTaille(%d,%d) = %d\n", x_prox[i], y_prox[i], testTaille(p,x_prox[i],y_prox[i]));
  }
  printf("\n");

  printf("Info Tour Arrivee %d,%d:\n", xa, ya);
  printf("----------------------\n");
  printf("taille = %d\n", p.pos[ya][xa].taille);
  printf("couleur = %c\n", p.pos[ya][xa].couleur);
  printf("testPos = %d\n", testPos(p,xa,ya));
  printf("testTour = %d\n", testTour(p,xa,ya));
  printf("testTaille = %d\n", testTaille(p,xa,ya));
  printf("testVoisin = %d\n\n", testVoisin(p,xa,ya));

  printf("testCoups = %d\n", testCoups(p,xd,yd,xa,ya,!VERBOSE));

  printf(ROUGE_B "\n---FIN DEBUG\n\n" RESET);
}

// Interface de fin de partie
void interFin(int scoreR, int scoreJ){
  printf(BLEU);
  printf("Score rouge = %d\n", scoreR);
  printf("Score jaune = %d\n", scoreJ);
  printf("---\n");
  if(scoreR > scoreJ) printf("Le gagnant est le joueur rouge\n");
  else if(scoreJ > scoreR) printf("Le gagnant est le joueur jaune\n");
  else printf("C'est un match null\n");
  printf(RESET);
}
