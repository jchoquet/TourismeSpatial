#include <stdio.h>
#include <stdlib.h>
#include "structure_d.h"
#include "structure_c.h"
#include "structure_contraintes.h"
#include "affectation_destination_d.h"


int main(int argc, char ** argv) {
  
  if (argc != 2) {
    printf("ERROR: Usage = nom\n");
    return 1;
  }

  char * nom = argv[1];
  /*char * prenom = argv[2];
  char * des1 = argv[3];
  char * des2 = argv[4];
  char * des3 = argv[5];
  char * des4 = argv[6];
  char * des5 = argv[7];
  char * des6 = argv[8];*/

  
  int n = 150; /* Nb touristes */
  dataCliLibre* dataTotal = calloc(n,sizeof(dataCliLibre));
  dataTotal[0] = *creer_dataCliLibre();
  setNom_dataCliLibre(&dataTotal[0], nom);

  
  printf("Le nom est %s\n", getNom_dataCliLibre(&dataTotal[0]));

  char * nom2 = argv[2];
  setNom_dataCliLibre(&dataTotal[0], nom2);
  printf("Le nom est %s\n", getNom_dataCliLibre(&dataTotal[0]));
  
  
  free(dataTotal);
  
  printf("Done\n");

  return 0;
}
