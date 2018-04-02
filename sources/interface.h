/*
 * Fichier : interface.h
 * Cree le 26/03/18 par benjamin-z
 */


#define JOUEUR 0
#define IA     1

// Interface de bienvenu en terminal
void initInterTXT();

// Interface de debut de tour en terminal
void interTour(int joueur, int nb_tour);

/*
* choix entre les modes ;
* JOUEUR vs JOUEUR
* JOUEUR vs IA
* IA vs IA
*/
void choixMode(int *j);

// partie manuelle du Joueur
void partJoueur(plateau p,int *xd, int *yd, int *xa, int *ya);

//Interface apres deplacement
void interDep(int xd, int yd, int xa, int ya, int nb_coups_restants);

// Interface de DEBUG
void interDEBUG(plateau p, int xd, int yd, int xa, int ya);

// Interface de fin de partie
void interFin(int scoreR, int scoreJ);
