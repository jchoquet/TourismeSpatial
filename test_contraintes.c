#include <stdio.h>
#include <stdlib.h>

#include "structure_contraintes.h"



int main (int argc, char** argv) {

  int i;
  contraintes* contraintes = malloc(3*sizeof(contraintes));

  if (argc != 4) {
    printf("ERROR : Usage = contrainte1 contrainte2 contrainte3\n");
    return 1;
  }

  for (i=0; i<3; i++){
    contraintes[i] = *creer_contrainte(argv[i+1], i+1);
  }

  for (i=0; i<3; i++){
    printf("%s -> %i\n", getNom(contraintes[i]), getZone(contraintes[i]));
  }
  


  return 0;
}
