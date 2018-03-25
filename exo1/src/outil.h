
typedef struct val{
	
	float x;
	float y;
	struct val * suiv;
	
} val;


FILE * ouvrir_fichier(char * nomfich, char * mode);
val* lecture_fichier(FILE * fp, int *cpt);
float* creer_liste_resultat(int nb_calc);
void calcul(float *res, val *input, int nb_calc);
void ecrire_resultat(float *res, FILE *fp, int cpt);
