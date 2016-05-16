#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "file.h"
#include "affectation_choix.h"

#include "fichier.h"
#include "tri_priorite.h"


File *  affectation_choix ()
{

	/* On r�cup�re le tableau 2D comportant dans la premi�re colonne l'identifiant (num�ro de ligne du client)
	et dans la deuxi�me l'ordre de priorit�, les lignes du tableau sont ordonn�es par ordre de priorit� d�croissante */

	int * tab_prio = get_tab_prio_tri();

	/* On r�cup�re la taille du tableau */

	int n = taille_tableau();
	int i = 0;

	/* On cr�e deux Files : la premi�re b1 contienda les voyageurs ayant obtenu une croisi�re organis�e
	la deuxi�me b2 contiendra les voyageurs ayant obtenu une croisi�re libre */

	File * b1 = creer_file();
	File * b2 = creer_file();

	/* On identifie les croisi�res par des num�ros : 
	 0 pour la croisi�re les plan�tes, 1 pour satellites naturels, 2 pour traces de vies, 3 pour croisi�re libre.
	 On va donc cr�er les variables indiquant le nombre de places dispos par croisi�re */

	 int place_0 = 35;
	 int place_1 = 35;
	 int place_2 = 35;

	/* Pour chaque ligne du tableau, on va attribuer le souhait 1 ou 2 et cr�er une File qui contient Identifiant, Nom, Pr�nom, Croisi�re, suivant 
	On initialise donc les variables n�cessaires. */

	int identifiant = 0;
	char * nom = NULL;
	char * prenom = NULL;
	char * souhait1 = NULL;
	char * souhait2 = NULL;
	int croisiere = 0;

	int choix_done = 0;

	/* Tableau temporaire qui permet d'obtenir les informations correspondant � un identifiant */
	char ** tab_infos = NULL;

	for(i=0; i < n; i++)
	{

		choix_done = 0;

		/* On r�cup�re l'identifiant dans le tableau des priorit�s */
		identifiant = tab_prio[i];

		/* On r�cup�re les informations correspondant � l'identifiant */
		tab_infos = get_Infos_by_ID(identifiant);

		/* On affecte les diff�rentes variables avec ce que l'on a r�cup�r� */
		nom = tab_infos[0];
		prenom = tab_infos[1];
		souhait1 = tab_infos[2];
		souhait2 = tab_infos[3];

		/* On affecte le num�ro de croisi�re en fonction des places et des souhaits effectu�s */

		/* On regarde d'abord si souhait1 est possible, si oui on affecte la croisi�re et on indique que le choix est fait */
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

		/* Si le souhait 1 n'a pas �t� attribu�, on consid�re le souhait 2 */
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

		/* Si la croisi�re est libre, on ajoute un noeud � la File b2 sinon on ajoute � la File b1 */
		if ( croisiere == 3)
		{
			ajouter_file(b2, identifiant, nom, prenom, croisiere);
		}
		else 
		{
			ajouter_file(b1, identifiant, nom, prenom, croisiere);
		}

	}

	/* On a attribu� une croisi�re � chaque client, on fait pointer le dernier �l�ment de b1 vers le premier �l�ment de b2 */

	collage_file(b1,b2);


	return b1;
}

