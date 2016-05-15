#include <stdio.h>
#include <stdlib.h>
#include "structure_c.h"

croisiere* creer(){
  croisiere* new = malloc(sizeof(croisiere));
  new->c = NULL;
  return new;
}

void incrementer(destination d, int n){
  d.quota = d.quota + n;
}

int main(){
return 0;
}
