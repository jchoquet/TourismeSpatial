/** Author : Sandra MICHAUT
    Date : 22 April 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "affectation_destination_d.h"
#include "structure_d.h"

void affectationCliLibre(destination ** croisPlan, destination ** croisSat, destination ** croisVie, destination ** croisDispo) {

  /* On a besoin en entree:
     Tableaux des contraintes => A approvisionner dans le pgm
     Tableau des destinations deja prises => A donner en parametres ?
     File des touristes => A donner en parametres ?
     Nombre de touristes => A donner en parametres 
     ......
  */
  int n = 150; /* Nb touristes */
  int i;

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
  destination ** croisTot = creer_destination();
  setCrois(croisTot, croisDispo, croisPlan, croisSat, croisVie); // A voir
  
  
  
  /* 1e parcours du tableau : verification des contraintes bidirectionnelles */
  for (i=0; i<n; i++) { // Boucle sur le tableau de dataCliLibre
    char ** destins = malloc(sizeof(char*));

    /* Recuperation des destinations dans un tableau */
    destins[0] = getDes1(dataTotal[i]);
    destins[1] = getDes2(dataTotal[i]);
    destins[2] = getDes3(dataTotal[i]);
    destins[3] = getDes4(dataTotal[i]);
    destins[4] = getDes5(dataTotal[i]);
    destins[5] = getDes6(dataTotal[i]);
    
    
    for (j=0; j<nbContBi; j++) {
      if (destins[ContBi[0].zone] == ContBi[0].nom && destins[ContBi[1].zone] != ContBi[1].nom) {
	/* La contrainte n'est pas respectee */
	destins[ContBi[0].zone] = NULL;
      }
      else if (destins[ContBi[1].zone] == ContBi[1].nom && destins[ContBi[0].zone] != ContBi[0].nom) {
	/* La contrainte n'est pas respectee */
	destins[ContBi[1].zone] = NULL;
      }
    }
    
    for (j=0; j<6; j++) {
      if (destins[j] != NULL) {
	// Decrementer la structure destination
      }
    
  }


  /* 2e parcours du tableau : verification des contraintes unidirectionnelles */
 for (i=0; i<n; i++) { // Boucle sur le tableau de dataCliLibre

    /* Recuperation des destinations dans un tableau */
    destins[0] = getDes1(dataTotal[i]);
    destins[1] = getDes2(dataTotal[i]);
    destins[2] = getDes3(dataTotal[i]);
    destins[3] = getDes4(dataTotal[i]);
    destins[4] = getDes5(dataTotal[i]);
    destins[5] = getDes6(dataTotal[i]);
    
    
    for (j=0; j<nbContUni; j++) {
      if (destins[ContUni[1].zone] == ContUni[1].nom && destins[ContUni[0].zone] != ContUni[0].nom) {
	/* La contrainte n'est pas respectee */
	destins[ContUni[0].zone] = ContUni[0];
      }
    }
    
    for (j=0; j<6; j++) {
      if (destins[j] != NULL) {
	// Decrementer la structure destination
      }
    
  }


  /* 3e parcours du tableau (ordre decroissant) : annulation des places en trop */
 for (i=n-1; i>=0; i--) { // Boucle sur le tableau de dataCliLibre

    /* Recuperation des destinations dans un tableau */
    destins[0] = getDes1(dataTotal[i]);
    destins[1] = getDes2(dataTotal[i]);
    destins[2] = getDes3(dataTotal[i]);
    destins[3] = getDes4(dataTotal[i]);
    destins[4] = getDes5(dataTotal[i]);
    destins[5] = getDes6(dataTotal[i]);
    
    
    for (j=0; j<nbContUni; j++) {
      if (destins[ContUni[1].zone] == ContUni[1].nom && destins[ContUni[0].zone] != ContUni[0].nom) {
	/* La contrainte n'est pas respectee */
	destins[ContUni[0].zone] = ContUni[0];
      }
    }
    
    for (j=0; j<6; j++) {
      if (destins[j] != NULL) {
	// Decrementer la structure destination
      }
    
  }


  /* 4e parcours du tableau : remplissage des cases vides par destinations */



  
  /* Exportation sous le format .csv */



  /* On libere les structures utilisees */
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
  setNom(&dataTotal[0], nom);

  
  printf("Le nom est %s\n", getNom(&dataTotal[0]));

  char * nom2 = argv[2];
  setNom(&dataTotal[0], nom2);
  printf("Le nom est %s\n", getNom(&dataTotal[0]));
  
  affectationCliLibre();
  
  free(dataTotal);
  
  printf("Done\n");

  return 0;
}
