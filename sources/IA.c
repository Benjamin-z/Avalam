/*
 * Fichier : IA.c
 * Cree le 12/03/18 par benjamin-z
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
  }while((testCoups(p,*xd,*yd,*xa,*ya,!VERBOSE)!=0)&&(nb_coups_restants!=0));  //TODO bloquant fin de partie
}
