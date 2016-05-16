#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fichier.h"
#include "file.h"
#include "structure_c.h"
#include "affectation_destination_c.h"


/* FOnction utilisées non codées :
	get_Destinations_Client_Orga(id, num_croisiere);
	print_resultat_csv(tab_res);

	get_Name_Desti(crois, i, j);
	get_Quota_Desti(crois, i, j);
	moins_Quota_Desti(crois, i, j);

*/

void reset_tab (char ** * tab, int taille);
char * set_Destination (croisiere * crois, char * choix_dest, int i);
	 

void destination_orga (file * b, croisiere * c0, croisiere * c1, croisiere * c2)
{

	/* Initialisation des variables temporaires */

	int num_croisiere = 0;

	char * choix_dest;
	int nombre_destinations = 0;

	int id = 0;
	

	char ** tab_des;
	tab_des = (char **)malloc(sizeof(char*) * 6);
	
	char ** tab_res;
	tab_res = (char **)malloc(sizeof(char*) * 8);

	/* On va parcourir la file contenant l'affectation croisiere des différents voyageurs tant que la croisiere attribuée est organisée */

	while (b->croisiere != 3)
	{

		/* On récupère le numéro = nom de la croisière du client */

		num_croisiere = b->croisiere;

		/* On récupère son identifiant */

		id = b->Identifiant;

		/* On écrit le nom et prénom dans le tableau résultat */

		tab_res[0] = b->Nom;
		tab_res[1] = b->Prenom;

		/* On récupère les 6 destinations associées à ce souhait de croisière du client */

		tab_des = get_Destinations_Client_Orga(id, num_croisiere);

		/* On va maitenant attribuer une destination par zone selon les places dispo et le souhait du client */

		for(int i=0; i < 6; i++)
		{
			/* On récupère la destination voulue par le client pour la zone i */

			choix_dest = tab_des[i];

			/* On se place dans la croisière du client */

			switch (num_croisiere)
			{
				case 0:
					/* Croisière planètes */
					tab_res[i]=set_Destination(c0, choix_dest, i);
				break;
				case 1:
					/* Croisière satellites naturels */
					tab_res[i]=set_Destination(c1, choix_dest, i);
				break;
				default :
					/* Croisière traces de vie */
					tab_res[i]=set_Destination(c2, choix_dest, i);
				break;
			}


		}
		
		/* On écrit dans le fichier resultat.csv les données du tableau résultat */

		print_resultat_csv(tab_res);

		/* On reset les tableaux destinations et résultat */

		reset_tab(&tab_res, 8);
		reset_tab(&tab_des, 6);

		/* On supprime le client traité de la file */

		supprimer_file(&b);
	}

	/* On libère les tableaux alloués */

	free(tab_res);
	free(tab_des);
}

char * set_Destination (croisiere * crois, char * choix_dest, int i){


	nombre_destinations = crois->tailles[i];

	for(int j =0; j < nombre_destinations; j++)
	{

		/* On récupère le nom de la destination */
		char * nom_dest = get_Name_Desti(*crois, i, j);

		/* Si ce nom est celui de la destination souhaitée on regarde le nombre de places restantes */
		if(strcmp(nom_dest, choix_dest) == 0)
		{
			quota_dest = get_Quota_Desti(*crois, i, j);

			/* S'il reste une place, on donne cette destination au client et on supprime une place */
			if(quota_dest != 0)
			{
				moins_Quota_Desti(*crois, i, j);
				return nom_dest;
			}
		}
	}

	/* Cas où il n'y avait pas assez de places dans la destination souhaité : on attribue la première disponible */
	for(int j =0; j < nombre_destinations; j++)
	{
		/* On récupère le nom de la destination */
		nom_dest = get_Name_Desti(*crois, i, j);
		quota_dest = get_Quota_Desti(*crois, i, j);

		if(quota_dest != 0)
		{
			moins_Quota_Desti(*crois, i, j);
			return nom_dest;
		}

	}
}

void reset_tab (char ** * tab, int taille)
{
	for(int i=0; i < taille; i++)
	{
		*tab[i] = "";
	}
}