/*
 * colorANSI.h
 *
 *  Created on: 15 févr. 2018
 *      Author: ben
 */

#ifndef COLORANSI_H_
#define COLORANSI_H_



#endif /* COLORANSI_H_ */
#define RESET		"\x1b[0m"
#define NOIR		"\x1b[30m"
#define ROUGE		"\x1b[31m"
#define VERT		"\x1b[32m"
#define JAUNE		"\x1b[33m"
#define BLEU    	"\x1b[34m"
#define MAGENTA 	"\x1b[35m"
#define CYAN    	"\x1b[36m"
#define WHITE		"\x1b[37m"

#define NOIR_B		"\x1b[90m"
#define ROUGE_B		"\x1b[91m"
#define VERT_B		"\x1b[92m"
#define JAUNE_B		"\x1b[93m"
#define BLEU_B    	"\x1b[94m"
#define MAGENTA_B 	"\x1b[95m"
#define CYAN_B 		"\x1b[96m"
#define WHITE_B		"\x1b[97m"

/* Pour l'utiliser il faut faire :
* printf(ROUGE     "Le texte est rouge!"     RESET"\n");
* ou :
* printf(ROUGE);
* printf("Le texte est rouge!\n");
* printf(RESET);
*/
