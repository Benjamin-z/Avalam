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


// Les coordonnees sont purement alleatoires
void IAalea(plateau p, int *xd, int *yd, int *xa, int *ya){
  do{
    *xd = randEntreBornes(0,TAILLE);
    *yd = randEntreBornes(0,TAILLE);
    *xa = randEntreBornes(0,TAILLE);
    *ya = randEntreBornes(0,TAILLE);
  }while((testCoups(p,*xd,*yd,*xa,*ya)!=0)&&(testPlateau(p)!=0));  //TODO bloquant fin de partie
}
