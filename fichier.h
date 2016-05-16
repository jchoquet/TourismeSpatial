#include <stdio.h>
#include <string.h>


//fontion open file "filename"

FILE * open_file(const char * filename, const char * mode);

// fonction close file

int fclose(FILE* filename);
 
int importer_prio(const char * filename);

int importer_souh_voy(const char * filename);

int importer_contr(const char * filename);

int importer_dest(const char * filename)

/* Fonction qui retorune un tableau contenant [Nom, Prenom, souhait1, souhait2 ] */

char ** get_Infos_by_ID(int identifiant);