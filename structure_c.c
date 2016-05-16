#include <stdio.h>
#include <stdlib.h>
#include "structure_c.h"

croisiere* creer(){
  croisiere* new = malloc(sizeof(croisiere));
  new->c = NULL;
  return new;
}

void incrementer(croisiere crois, char * dest, int zone, int n) {
  int i;

  for (i=0; i<crois.tailles[zone]; i++) {
    if (crois.c[zone-1][i].nom == dest) {
      crois.c[zone-1][i].quota = crois.c[zone-1][i].quota + n;
      return;
    }
  }
}
