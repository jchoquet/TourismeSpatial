/** Author : Sandra MICHAUT
    Date : 22 April 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "affectation_destination_d.h"
#include "structure_d.h"
#include "structure_c.h"
#include "structure_contraintes.h"

void importer_contraintes(contraintes ** contBi, int* nbBi, contraintes ** contUni, int* nbUni);
void setCrois(croisiere croisTot, croisiere croisDispo, croisiere croisPlan, croisiere croisSat, croisiere croisVie);
void importer_quotas_libre(croisiere* libre);

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
  croisiere libre = creer_croisiere();
  importer_quotas_libre(&croisiere); // On importe toutes les destinations possibles et leur quotas
  // A FINIR avec une fonction comme setCrois

  
  /* Creation des structures des contraintes et remplissage */
  contraintes ** contUni = NULL;
  contraintes ** contBi = NULL;
  int nbContUni = 0;
  int nbContBi = 0;

  importer_contraintes(contUni, &nbContUni, contBi, &nbContBi);
 
  
  /* Creation du tableau de structures dataCliLibre et remplissage */
  
  dataCliLibre* dataTotal = calloc(n,sizeof(dataCliLibre));
  for (i=0; i<n; i=i+1) {
    dataTotal[i] = *creer_dataCliLibre();
  }
  
  
  /* Creation du tableau de structures destination et remplissage */
  croisiere croisTot = creer_croisiere();
  setCrois(croisTot, croisDispo, croisPlan, croisSat, croisVie); // A voir
  
  
  char * destins[6]; /* Contiendra les destinations du touriste considere */
  
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
	incrementer(libre, destins[j], j+1, -1);
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
	// Decrementer la structure destination
	incrementer(libre, destins[j], j+1, -1);
      }
    } 
    
  }
  
  /* 3e parcours du tableau (ordre decroissant) : annulation des places en trop */
  /* On regarde le nombre de places au maximum qu'il faut enlever et on fait une boucle a partir de la fin jusqu'a arriver a ce nombre */
  int min = 0;
  for (j=0; j<6; j++) {
    for (i=0; i<libre.tailles[j]; i++) {
      if (libre.c[j][i].quotas < min) min = libre.c[j][i].quotas;
    }
  } 
  /* On enleve les places reservees en trop */
  if (min < 0) {
    for (i=0; i<-min; i++) { // Boucle sur le tableau de dataCliLibre
      for (j=0; j<6; j++) {
	// Regarder si le nombre de places restantes pour cette destination est < 0 et changer si oui
      
    }
  }
  /* 4e parcours du tableau : remplissage des cases vides par destinations */
  for (i=0; i<n; i++) { // Boucle sur le tableau de dataCliLibre
    
    /* Recuperation des destinations dans un tableau */
    destins[0] = getDes1_dataCliLibre(&dataTotal[i]);
    destins[1] = getDes2_dataCliLibre(&dataTotal[i]);
    destins[2] = getDes3_dataCliLibre(&dataTotal[i]);
    destins[3] = getDes4_dataCliLibre(&dataTotal[i]);
    destins[4] = getDes5_dataCliLibre(&dataTotal[i]);
    destins[5] = getDes6_dataCliLibre(&dataTotal[i]);
    
    if (destins[0] == NULL) {
      /* Remplir ici par la destination de la zone 1 ou il reste le + de places */
    }

    if (destins[1] == NULL) {
      /* Remplir ici par la destination de la zone 1 ou il reste le + de places */
    }

    if (destins[2] == NULL) {
      /* Remplir ici par la destination de la zone 1 ou il reste le + de places */
    }

    if (destins[3] == NULL) {
      /* Remplir ici par la destination de la zone 1 ou il reste le + de places */
    }

    if (destins[4] == NULL) {
      /* Remplir ici par la destination de la zone 1 ou il reste le + de places */
    }

    if (destins[5] == NULL) {
      /* Remplir ici par la destination de la zone 1 ou il reste le + de places */
    }
    
  }
  
  
  
  /* Exportation sous le format .csv */
  
  
  
  /* On libere les structures utilisees */
  free(dataTotal);
  printf("Done\n");
 
}




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
