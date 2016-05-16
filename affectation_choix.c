#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "file.h"
#include "affectation_choix.h"

#include "fichier.h"
#include "tri_priorite.h"


File *  affectation_choix ()
{

	/* On récupère le tableau 2D comportant dans la première colonne l'identifiant (numéro de ligne du client)
	et dans la deuxième l'ordre de priorité, les lignes du tableau sont ordonnées par ordre de priorité décroissante */

	int * tab_prio = get_tab_prio_tri();

	/* On récupère la taille du tableau */

	int n = taille_tableau();
	int i = 0;

	/* On crée deux Files : la première b1 contienda les voyageurs ayant obtenu une croisière organisée
	la deuxième b2 contiendra les voyageurs ayant obtenu une croisière libre */

	File * b1 = creer_file();
	File * b2 = creer_file();

	/* On identifie les croisières par des numéros : 
	 0 pour la croisière les planètes, 1 pour satellites naturels, 2 pour traces de vies, 3 pour croisière libre.
	 On va donc créer les variables indiquant le nombre de places dispos par croisière */

	 int place_0 = 35;
	 int place_1 = 35;
	 int place_2 = 35;

	/* Pour chaque ligne du tableau, on va attribuer le souhait 1 ou 2 et créer une File qui contient Identifiant, Nom, Prénom, Croisière, suivant 
	On initialise donc les variables nécessaires. */

	int identifiant = 0;
	char * nom = NULL;
	char * prenom = NULL;
	char * souhait1 = NULL;
	char * souhait2 = NULL;
	int croisiere = 0;

	int choix_done = 0;

	/* Tableau temporaire qui permet d'obtenir les informations correspondant à un identifiant */
	char ** tab_infos = NULL;

	for(i=0; i < n; i++)
	{

		choix_done = 0;

		/* On récupère l'identifiant dans le tableau des priorités */
		identifiant = tab_prio[i];

		/* On récupère les informations correspondant à l'identifiant */
		tab_infos = get_Infos_by_ID(identifiant);

		/* On affecte les différentes variables avec ce que l'on a récupéré */
		nom = tab_infos[0];
		prenom = tab_infos[1];
		souhait1 = tab_infos[2];
		souhait2 = tab_infos[3];

		/* On affecte le numéro de croisière en fonction des places et des souhaits effectués */

		/* On regarde d'abord si souhait1 est possible, si oui on affecte la croisière et on indique que le choix est fait */
		if (strcmp(souhait1, "planetes") == 0 && (place_0 != 0) )
		{
			croisiere = 0;
			place_0--;
			choix_done = 1;
		}
		else if (strcmp(souhait1, "satellites") == 0 && (place_1 != 0) )
		{
			croisiere = 1;
			place_1--;
			choix_done = 1;
		}
		else if (strcmp(souhait1, "vie") == 0 && (place_2 != 0) )
		{
			croisiere = 2;
			place_2--;
			choix_done = 1;
		}
		else if( strcmp(souhait1, "libre") == 0)
		{
			croisiere = 3;
			choix_done = 1;
		}

		/* Si le souhait 1 n'a pas été attribué, on considère le souhait 2 */
		if(choix_done == 0)
		{
			if (strcmp(souhait2, "planetes") == 0 && (place_0 != 0) )
			{
				croisiere = 0;
				place_0--;
			}
			else if (strcmp(souhait2, "satellites") == 0 && (place_1 != 0) )
			{
				croisiere = 1;
				place_1--;
			}
			else if (strcmp(souhait2, "vie") == 0 && (place_2 != 0) )
			{
				croisiere = 2;
				place_2--;
			}
			else
			{
				croisiere = 3;
			}
		}

		/* Si la croisière est libre, on ajoute un noeud à la File b2 sinon on ajoute à la File b1 */
		if ( croisiere == 3)
		{
			ajouter_file(b2, identifiant, nom, prenom, croisiere);
		}
		else 
		{
			ajouter_file(b1, identifiant, nom, prenom, croisiere);
		}

	}

	/* On a attribué une croisière à chaque client, on fait pointer le dernier élèment de b1 vers le premier élèment de b2 */

	collage_file(b1,b2);


	return b1;
}

