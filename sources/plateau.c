/*
 * plateau.c
 * Cree le 15/02/18 par benjamin-z
 */

#include "plateau.h"
#include "colorANSI.h"
#include <stdio.h>

// Calcul de la couleur des cases en debut de partie
// Pour faire l alternance des couleurs de cases
// Fonctionne en fonction de la partité se la somme des coordonnees
// parité paire = jaune
// parité impaire = rouge
char initCoul(int x, int y){
	char car;
	if((x+y)%2 == 0) car = 'r';
	else car = 'j';
	return car;
}

// Initialisation des cases du plateau
plateau initPlateau(){
	plateau p;
	int x, y;
	// Constante de placement des pions
	const int placement[TAILLE][TAILLE] = {
			{0,0,1,1,0,0,0,0,0},
			{0,1,1,1,1,0,0,0,0},
			{0,1,1,1,1,1,1,0,0},
			{0,1,1,1,1,1,1,1,1},
			{1,1,1,1,0,1,1,1,1},
			{1,1,1,1,1,1,1,1,0},
			{0,0,1,1,1,1,1,1,0},
			{0,0,0,0,1,1,1,1,0},
			{0,0,0,0,0,1,1,0,0},
	};
	for(y = 0; y < TAILLE; y++){
		for(x = 0; x < TAILLE; x++){
			if(placement[y][x] == 1){ // Si la case est jouable
				// Définition de la taille à 1
				p.pos[y][x].taille = 1;
				// Def de la case en rouge ou en jaune
				p.pos[y][x].couleur = initCoul(x, y);
			}else{
				// Def de la taille à 0
				p.pos[y][x].taille = 0;
				// Def de la couleur à autre -> z
				p.pos[y][x].couleur = 'z';
			}
		}
	}
	return p;
}

void affPlatTXT(plateau p){
	int x, y, tal;
	char coul;
	for(y = 0; y < TAILLE; y++){
		for(x = 0; x < TAILLE; x++){
			coul = p.pos[y][x].couleur;
			tal = p.pos[y][x].taille;
			// Mod de la coul de la tour en texte
			if(coul == 'r') printf(ROUGE);	// Change la couleur du txt en rouge
			else if(coul == 'j') printf(JAUNE);	// idem en jaune
			else if(coul == 'g') printf(VERT_B);	//idem en vert brillant
			printf("%d", tal);
			printf(RESET);
		}
		// Retour à la ligne
		printf("\n");
	}
    printf("\n");
}

// Affichage ligne par ligne
void affPlatDEBUG(plateau p){
	int x, y, tal;
	char coul;
	for(y = 0; y < TAILLE; y++){
		for(x = 0; x < TAILLE; x++){
			coul = p.pos[y][x].couleur;
			tal = p.pos[y][x].taille;
			printf("(%d , %d) : taille=%d, coul=%c\n", x, y, tal, coul);
		}
		printf("\n");
	}
    printf("\n");
}
