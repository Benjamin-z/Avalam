#include <stdio.h>
#include <stdlib.h>
#include "outil.h"


FILE * ouvrir_fichier(char * nomfich, char *mode)
{
	FILE * fp = NULL;
        if ((fp=fopen(nomfich, mode)) == NULL)
	{
		printf("erreur d'ouverture du fichier %s\n",nomfich); 
		abort();
	}
	else
		return(fp);
}				  

val * lecture_fichier(FILE *fp, int *cpt)
{
float val1, val2;
val *tete = NULL;
val *lc = NULL;


	while(fscanf(fp,"%f %f", &val1,&val2) != EOF)
	{
		lc = (val*) malloc(sizeof(val));
		lc->x = val1;
		lc->y = val2;
		lc->suiv = tete;
		tete = lc;
		(*cpt)++;
	}
	lc = tete;
	return lc;
}

float* creer_liste_resultat(int nb_calc)
{
float *res;

	res = (float *) calloc(nb_calc, sizeof(float));
	return res;
}

void calcul(float *res, val *input, int nb_calc)
{
int i = 0;

while(input != NULL)
{	
	res[i] = input->x + input->y;
	input = input->suiv;
	i++;
}

}


void ecrire_resultat(float *res, FILE *fp, int cpt)
{
int i;
for(i=cpt-1;i>=0;i--)
	fprintf(fp,"%f\n",res[i]);
}
