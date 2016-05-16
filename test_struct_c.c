#include <stdio.h>
#include <stdlib.h>
#include "structure_c.h"

int main () {

  printf("Creer croisiere\n");
  croisiere * crois = creer_croisiere();
  croisiere * crois2 = creer_croisiere();
  croisiere * crois3 = creer_croisiere();
  
  printf("Creer les destinations\n");
  int z;
  for (z=0; z<6; z++) {
    crois->c[z] = malloc(2*sizeof(destination));
    crois->tailles[z] = 2;
  }
  for (z=0; z<6; z++) {
    crois2->c[z] = malloc(2*sizeof(destination));
    crois2->tailles[z] = 2;
  }
  for (z=0; z<6; z++) {
    crois3->c[z] = malloc(3*sizeof(destination));
    crois3->tailles[z] = 3;
  }
  
  printf("Remplir les destinations\n");
  crois->c[0][0].nom = "Mercure";
  crois->c[0][0].quota = 25;
  crois->c[0][1].nom = "Venus";
  crois->c[0][1].quota = 10;
  crois->c[1][0].nom = "Terre";
  crois->c[1][0].quota = 35;
  crois->c[1][1].nom = "Mars";
  crois->c[1][1].quota = 20;
  crois->c[2][0].nom = "Jupiter";
  crois->c[2][0].quota = 25;
  crois->c[2][1].nom = "Uranus";
  crois->c[2][1].quota = 10;
  crois->c[3][0].nom = "Neptune";
  crois->c[3][0].quota = 35;  
  crois->c[3][1].nom = "Pluton";
  crois->c[3][1].quota = 20;
  crois->c[4][0].nom = "Titan";
  crois->c[4][0].quota = 25;  
  crois->c[4][1].nom = "Titania";
  crois->c[4][1].quota = 10;  
  crois->c[5][0].nom = "Soleil lol";
  crois->c[5][0].quota = 35;  
  crois->c[5][1].nom = "Lune";
  crois->c[5][1].quota = 20;

  crois2->c[0][0].nom = "Mercure";
  crois2->c[0][0].quota = 2;
  crois2->c[0][1].nom = "Venus";
  crois2->c[0][1].quota = 8;
  crois2->c[1][0].nom = "Terre";
  crois2->c[1][0].quota = 20;
  crois2->c[1][1].nom = "Mars";
  crois2->c[1][1].quota = 1;
  crois2->c[2][0].nom = "Jupiter";
  crois2->c[2][0].quota = 0;
  crois2->c[2][1].nom = "Uranus";
  crois2->c[2][1].quota = 3;
  crois2->c[3][0].nom = "Neptune";
  crois2->c[3][0].quota = 20;  
  crois2->c[3][1].nom = "Pluton";
  crois2->c[3][1].quota = 15;
  crois2->c[4][0].nom = "Titan";
  crois2->c[4][0].quota =2;  
  crois2->c[4][1].nom = "Titania";
  crois2->c[4][1].quota = 8;  
  crois2->c[5][0].nom = "Soleil lol";
  crois2->c[5][0].quota = 5;  
  crois2->c[5][1].nom = "Lune";
  crois2->c[5][1].quota = 4;

  crois3->c[0][0].nom = "Mercure";
  crois3->c[0][0].quota = 125;
  crois3->c[0][1].nom = "Venus";
  crois3->c[0][1].quota = 110;
  crois3->c[0][2].nom = "Autre";
  crois3->c[0][2].quota = 10;
  crois3->c[1][0].nom = "Terre";
  crois3->c[1][0].quota = 135;
  crois3->c[1][1].nom = "Mars";
  crois3->c[1][2].quota = 120;
  crois3->c[1][2].nom = "Pas d'idee";
  crois3->c[1][1].quota = 20;
  crois3->c[2][0].nom = "Jupiter";
  crois3->c[2][0].quota = 125;
  crois3->c[2][1].nom = "Uranus";
  crois3->c[2][1].quota = 110;
  crois3->c[2][2].nom = "Terfe";
  crois3->c[2][2].quota = 11;
  crois3->c[3][0].nom = "Neptune";
  crois3->c[3][0].quota = 135;  
  crois3->c[3][1].nom = "Pluton";
  crois3->c[3][1].quota = 120;
  crois3->c[3][1].nom = "Nouvel";
  crois3->c[3][1].quota = 28;
  crois3->c[4][0].nom = "Titan";
  crois3->c[4][0].quota = 125;  
  crois3->c[4][1].nom = "Titania";
  crois3->c[4][1].quota = 110;  
  crois3->c[4][1].nom = "Truc";
  crois3->c[4][1].quota = 14;  
  crois3->c[5][0].nom = "Soleil lol";
  crois3->c[5][0].quota = 135;  
  crois3->c[5][1].nom = "Lune";
  crois3->c[5][1].quota = 120;
  crois3->c[5][1].nom = "Solaris";
  crois3->c[5][1].quota = 25;

  printf("Affichage destinations\n");
  int i,j;
 
  for (i=0; i<6; i++) {
    for (j=0; j<2; j++) {
      printf("Destination : %s, quotas : %i\n", crois->c[i][j].nom, crois->c[i][j].quota);
    }
    printf("\n");
  }
  
  printf("Tests sur les fonctions de base\n\n");
  printf("Nom destination 2,1 : %s\n",get_Name_Desti(*crois, 2, 1));
  printf("Quota destination 2,1 : %i\n",get_Quota_Desti(*crois, 2, 1));
  
  moins_Quota_Desti(*crois, 2, 1);
  printf("Nouveau quota destination 2,1 : %i\n",get_Quota_Desti(*crois, 2, 1));

  
  printf("Quota destination Lune : %i\n",get_Quota_Desti(*crois, 5, 1));
  incrementer(*crois, "Lune", 5, 10);
  printf("Nouveau quota destination Lune : %i\n",get_Quota_Desti(*crois, 5, 1));

  printf("\nTest sur les soustractions\n\nAvant: \n");
  for (i=0; i<6; i++) {
    for (j=0; j<2; j++) {
      printf("Destination : %s, quotas : %i\n", crois->c[i][j].nom, crois->c[i][j].quota);
    }
    printf("\n");
  }

  soustraction_struc_c(crois, *crois2);
  
  printf("\n\nApres: \n");
  for (i=0; i<6; i++) {
    for (j=0; j<2; j++) {
      printf("Destination : %s, quotas : %i\n", crois->c[i][j].nom, crois->c[i][j].quota);
    }
    printf("\n");
  }


  printf("\nTest sur les soustractions non uniformes\n\nAvant: \n");
  for (i=0; i<6; i++) {
    for (j=0; j<2; j++) {
      printf("Destination : %s, quotas : %i\n", crois3->c[i][j].nom, crois3->c[i][j].quota);
    }
    printf("\n");
  }

  soustract(crois3, *crois, *crois2, *crois2);
  
  printf("\n\nApres: \n");
  for (i=0; i<6; i++) {
    for (j=0; j<2; j++) {
      printf("Destination : %s, quotas : %i\n", crois3->c[i][j].nom, crois3->c[i][j].quota);
    }
    printf("\n");
  }



  return 0;
}
