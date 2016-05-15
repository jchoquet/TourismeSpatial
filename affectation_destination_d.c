/** Author : Sandra MICHAUT
    Date : 22 April 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "affectation_destination_d.h"
#include "structure_d.h"
#include "structure_c.h"
#include "structure_contraintes.h"

contraintes ** importer_contraintes();

void affectationCliLibre(croisiere croisPlan, croisiere croisSat,croisiere croisVie, croisiere croisDispo) {

  /* On a besoin en entree:
     Tableaux des contraintes => A approvisionner dans le pgm
     Tableau des destinations deja prises => A donner en parametres ?
     File des touristes => A donner en parametres ?
     Nombre de touristes => A donner en parametres 
     ......
  */
  int n = 150; /* Nb touristes */
  int i,j;

  /* Calcul des nouveaux quotas */
  

  
  /* Creation des structures des contraintes et remplissage */
  contraintes ** cont = importer_contraintes();
  contraintes ** contUni = NULL;
  contraintes ** contBi = NULL;

  int nbContUni = 0;
  int nbContBi = 0;
  
  
  /* Creation du tableau de structures dataCliLibre et remplissage */
  
  dataCliLibre* dataTotal = calloc(n,sizeof(dataCliLibre));
  for (i=0; i<n; i=i+1) {
    dataTotal[i] = *creer_dataCliLibre();
  }
  
  
  /* Creation du tableau de structures destination et remplissage */
  croisiere croisTot = creer_croisiere();
  setCrois(croisTot, croisDispo, croisPlan, croisSat, croisVie); // A voir
  
  
  char ** destins = malloc(sizeof(char*));
  
  /* 1e parcours du tableau : verification des contraintes bidirectionnelles */
  for (i=0; i<n; i++) { // Boucle sur le tableau de dataCliLibre
    
    /* Recuperation des destinations dans un tableau */
    destins[0] = getDes1_dataCliLibre(&dataTotal[i]);
    destins[1] = getDes2_dataCliLibre(&dataTotal[i]);
    destins[2] = getDes3_dataCliLibre(&dataTotal[i]);
    destins[3] = getDes4_dataCliLibre(&dataTotal[i]);
    destins[4] = getDes5_dataCliLibre(&dataTotal[i]);
    destins[5] = getDes6_dataCliLibre(&dataTotal[i]);
    
    
    for (j=0; j<nbContBi; j++) { // Boucle sur les contraintes
      char * nomCont1 = getNom(contBi[j][0]);
      char * nomCont2 = getNom(contBi[j][1]);
      int zoneCont1 = getZone(contBi[j][0]);
      int zoneCont2 = getZone(contBi[j][1]);
      if (destins[zoneCont1] == nomCont1 && destins[zoneCont2] != nomCont2) {
	/* La contrainte n'est pas respectee */
	destins[zoneCont1] = NULL;
      }
      else if (destins[zoneCont2] == nomCont2 && destins[zoneCont1] != nomCont1) {
	/* La contrainte n'est pas respectee */
	destins[zoneCont2] = NULL;
      }
    }
    
    for (j=0; j<6; j++) {
      if (destins[j] != NULL) {
	// Decrementer la structure destination pour chaque destination
      }
      
    }
  }
  
  /* 2e parcours du tableau : verification des contraintes unidirectionnelles */
  for (i=0; i<n; i++) { // Boucle sur le tableau de dataCliLibre
    
    /* Recuperation des destinations dans un tableau */
    destins[0] = getDes1_dataCliLibre(&dataTotal[i]);
    destins[1] = getDes2_dataCliLibre(&dataTotal[i]);
    destins[2] = getDes3_dataCliLibre(&dataTotal[i]);
    destins[3] = getDes4_dataCliLibre(&dataTotal[i]);
    destins[4] = getDes5_dataCliLibre(&dataTotal[i]);
    destins[5] = getDes6_dataCliLibre(&dataTotal[i]);
    
    
    for (j=0; j<nbContUni; j++) {
      char * nomCont1 = getNom(contBi[j][0]);
      char * nomCont2 = getNom(contBi[j][1]);
      int zoneCont1 = getZone(contBi[j][0]);
      int zoneCont2 = getZone(contBi[j][1]);
      if (destins[zoneCont2] == nomCont2 && destins[zoneCont1] != nomCont1) {
	/* La contrainte n'est pas respectee */
	destins[zoneCont1] = nomCont1;
      }
    }
    
    for (j=0; j<6; j++) {
      if (destins[j] != NULL) {
	// Decrementer la structure destination
      }
      
    }
  }
  
  /* 3e parcours du tableau (ordre decroissant) : annulation des places en trop */
  /* On regarde le nombre de places au maximum qu'il faut enlever et on fait une boucle a partir de la fin jusqu'a arriver a ce nombre */

  for (i=n-1; i>=0; i--) { // Boucle sur le tableau de dataCliLibre
    
    
  }
  
  /* 4e parcours du tableau : remplissage des cases vides par destinations */
  
  
  
  
  /* Exportation sous le format .csv */
  
  
  
  /* On libere les structures utilisees */
  free(destins);
  free(dataTotal);
  printf("Done\n");
 
}




int main(int argc, char ** argv) {
  
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
