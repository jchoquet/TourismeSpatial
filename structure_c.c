#include <stdio.h>
#include <stdlib.h>

#include "structure_c.h"

croisiere* creer_croisiere(){
  croisiere* new = malloc(sizeof(croisiere));
  new->c = malloc(6*sizeof(destination*));
  return new;
}

void incrementer(croisiere crois, char * dest, int zone, int n) {
  int i;

  for (i=0; i<crois.tailles[zone]; i++) {
    if (crois.c[zone][i].nom == dest) {
      crois.c[zone][i].quota += n;
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

  int i = 0;
  int j = 0;

  for(i =0; i < 6; i++)
  {

    taille_zone = crois2.tailles[i];

    for(j =0; j < taille_zone; j++)
    {

      temp = crois1->c[i][j].quota;
      temp = temp - crois2.c[i][j].quota;

      crois1->c[i][j].quota = temp;
      
    }

  }

}


void soustract(croisiere * c3, croisiere c0, croisiere c1, croisiere c2) {
int zone = 0;
	int j;	

	for (zone=0; zone <6; zone++) {
    	/* Pour chaque destination dans c3 on va decrementer le quota du nombre de places reservees dans c0, c1 et c2 */
      		for (j=0; j<c0.tailles[zone]; j++) {
			incrementer(*c3, c0.c[zone][j].nom, zone, -c0.c[zone][j].quota);
      		}   
		for (j=0; j<c1.tailles[zone]; j++) {
			incrementer(*c3, c1.c[zone][j].nom, zone, -c1.c[zone][j].quota);
      		} 	
		for (j=0; j<c2.tailles[zone]; j++) {
			incrementer(*c3, c2.c[zone][j].nom, zone, -c2.c[zone][j].quota);
      		} 
	}

}
