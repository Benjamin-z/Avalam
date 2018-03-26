/*
* Fichier : interface.h
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


//Interface apres deplacement
void interDep(int xd, int yd, int xa, int ya, int nb_coups_restants);
