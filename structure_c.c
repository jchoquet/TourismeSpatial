#include <stdio.h>
#include <stdlib.h>
#include "structure_c.h"

croisiere* creer_croisiere(){
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

char * get_Name_Desti(croisiere crois, int i, int j) {
    return crois.c[i][j].nom;
}


int get_Quota_Desti(croisiere crois, int i, int j) {
  return crois.c[i][j].quota ;
}


void moins_Quota_Desti(croisiere crois, int i, int j) {
    int temp = crois.c[i][j].quota;
    if (temp != 0)
    {
      crois.c[i][j].quota = temp - 1;
    }
}

/* On soustrait les quotas de la croisière 2 à ceux de la croisière 1 */

void soustraction_struc_c(croisiere * crois1, croisiere crois2) {

  int taille_zone = 0;
  int temp = 0;

  for( int i =0; i < 6; i++)
  {

    taille_zone = crois2.tailles[i];

    for(int j =0; j < taille_zone; j++)
    {

      temp = crois1->c[i][j].quota;
      temp = temp - crois2.c[i][j].quota;

      crois1->c[i][j].quota = temp;
      
    }

  }

}