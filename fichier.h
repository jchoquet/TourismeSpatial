#include <stdio.h>
#include <string.h>


//fontion open file "filename"

FILE * open_file(const char * filename, const char * mode);

// fonction close file

int fclose(FILE* filename);
 
int importer_prio(const char * filename);

int importer_souh_voy(const char * filename);

int importer_contr(const char * filename);

int importer_dest(const char * filename);

/*TODO*/

/* Fonction qui retourne un tableau contenant [Nom, Prenom, souhait1, souhait2 ] */

char ** get_Infos_by_ID(int identifiant);


/* Fonction qui retourne un tableau contenant les 6 destinations souhaitées par l'utilisateur ligne id pour la croisiere num_croisiere */
char ** get_Destinations_Client_Orga(int id, int num_croisiere);

/* Fonction qui écrit dans le fichier resultat.csv le contenu de tab_res */
void print_resultat_csv(char ** tab_res);

