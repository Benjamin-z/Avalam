#include <stdio.h>
#include <stdlib.h>
#include "outil.h"
#include "param.h"

main(int argc, char *argv[])
{
FILE * fp = NULL;
FILE * fp_res = NULL;
val * lcval; 
float * res;
int nb_calc = 0;


if(argc == 3) //au moins un argument + le nom de la commande	
{	
	fp = ouvrir_fichier(argv[1],"r");
	fp_res = ouvrir_fichier(argv[2],"w");
}
else
{
	printf("aucun fichier passé en paramètre de la commande %s\n", argv[0]);
	abort();
}

lcval = lecture_fichier(fp,&nb_calc);

res = creer_liste_resultat(nb_calc);

calcul(res, lcval, nb_calc);

ecrire_resultat(res, fp_res, nb_calc);

close(fp);
close(fp_res);

}
	
