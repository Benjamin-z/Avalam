/*
 * Fichier : main.c
 * Cree le 15/02/18 par benjamin-z
 */
#include "config.h"
#include "plateau.h"
#include <stdio.h>
#include "partie.h"
#include "IA.h"
#include "colorANSI.h"
#include "interface.h"
#include "alea.h"
//#include <unistd.h>		// pause()

int main(){
  initAlea();
	// Creation du plateau
	plateau p;
  // Coordonnées pour mvt
  int xd, yd;
	int xa, ya;
	// Variable pour definir quel Joueur doit jouer (0 ou 1)
	int joueur = 0;
	// Definition du mode de jeu soit avec une IA soit avec un JOUEUR
	int j[2];
	int nb_tour = 0;
	int nb_coups_restants = 48;

	// Initialisation du plateau de jeu
	p = initPlateau();
	initInterTXT();
	affPlatTXT(p);
	// Choix du mode de jeux
	choixMode(j);
	while(1){
  //while(nb_coups_restants != 0){
		nb_tour++;
		// Interface de debut de tour
		interTour(joueur, nb_tour);
		// Diferenciation IA / JOUEUR pour les 2 joueurs
		if(j[joueur]==JOUEUR){	// joueur varie entre 0 et 1 a chq tour
			// Choix des coordonnes des cases de depart et d'arrivee par le joueur
			partJoueur(p,&xd,&yd,&xa,&ya);
		} else {
			IAalea(p,&xd,&yd,&xa,&ya,nb_coups_restants);
		}
		// Affichage de DEBUG
		if(DEBUG) interDEBUG(p,xd,yd,xa,ya);
		// Affiche le deplacement en cours ainsi que le nb de coups encore possibles
		interDep(xd,yd,xa,ya,nb_coups_restants);
		// Deplace une tour
    dep(&p, xd, yd, xa, ya);
		affPlatTXT(p);
		// Calcul du nombre de coups restants
		nb_coups_restants = testPlateau(p);
		// Changement de joueur
		joueur = !joueur; // 1 || 0
	}
	return 0;
}
