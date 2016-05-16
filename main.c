#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structure_c.h"
#include "affectation_destination_c.h"

int main{


	/******************** Partie affectation des croisières organisées *******************/

	/* On doit tout d'abord connaître le nombre de places disponibles dans chaque croisière pour chaque destination 
	On crée 6 structures : les structures c0, c1, c2 et les structures de mises en mémoire c0m, c1m, c2m */

	croisiere * c0 = creer_croisiere();
	croisiere * c1 = creer_croisiere();
	croisiere * c2 = creer_croisiere();

	croisiere * c0m = creer_croisiere();
	croisiere * c1m = creer_croisiere();
	croisiere * c2m = creer_croisiere();

	/* On remplit ces structures croisières avec les données correspondantes */

	get_c0(c0);
	get_c0(c0m);

	get_c1(c1);
	get_c1(c1m);

	get_c2(c2);
	get_c2(c2m);

	/* On lance l'affectation des destinations pour les croisières organisées : la file b ne contiendra plus que les clients avec une croisière libre et résultat.csv contiendra les données
	des clients avec croisières organisées. Les c0, c1, c3 contiendront le nombre de places pour chaque destination */

	destination_orga(&b, c0, c1, c2);


	return 0;
}