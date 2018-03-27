/*
 * Fichier : alea.c
 * Cree le 16/02/18 par benjamin-z
 */

#include <time.h>
#include <stdlib.h>

//Initialise le temps pour les aléa
void initAlea(){
  srand(time(NULL));	// Initialise le temps pour générer des alea
}

//Tire un nb alea entre a et b
int randEntreBornes(int a, int b){
	return rand()%(b-a)+a;
}
