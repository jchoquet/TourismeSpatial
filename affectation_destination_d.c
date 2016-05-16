/** Author : Sandra MICHAUT
    Date : 22 April 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "structure_d.h"
#include "structure_c.h"
#include "structure_contraintes.h"
#include "affectation_destination_d.h"

/* Fonction necessaires et non encore implementees */
void affectationCliLibre(dataCliLibre* touriste, croisiere* croisLibre) {

  /* On a besoin en entree:
     Tableaux des contraintes => A approvisionner dans le pgm
     Tableau des destinations deja prises => A donner en parametres ?
     File des touristes => A donner en parametres ?
     Nombre de touristes => A donner en parametres 
     ......
  */
  int n = 150; /* Nb touristes */
  int i,j;
  
  
  /* Creation des structures des contraintes et remplissage */
  contraintes ** contUni = NULL;
  contraintes ** contBi = NULL;
  int nbContUni = 0;
  int nbContBi = 0;
  
  importer_contraintes(contUni, &nbContUni, contBi, &nbContBi);
  
  char * destins[6]; /* Contiendra les destinations du touriste considere */
  
  /* 1e parcours du tableau : verification des contraintes bidirectionnelles */
  for (i=0; i<n; i++) { /* Boucle sur le tableau de dataCliLibre */
    
    /* Recuperation des destinations dans un tableau */
    for (j=0; j<6; j++) { 
      destins[j] = getDes_dataCliLibre(&touriste[i],j);
    }
    
    for (j=0; j<nbContBi; j++) { /* Boucle sur les contraintes */
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
	/* Decrementer la structure destination pour chaque destination */
	incrementer(*croisLibre, destins[j], j+1, -1);
      }
      
    }
  }
  
  /* 2e parcours du tableau : verification des contraintes unidirectionnelles */
  for (i=0; i<n; i++) { /* Boucle sur le tableau de dataCliLibre */
    
    /* Recuperation des destinations dans un tableau */
    for (j=0; j<6; j++) { 
      destins[j] = getDes_dataCliLibre(&touriste[i],j);
    }
    
    
    for (j=0; j<nbContUni; j++) {
      char * nomCont1 = getNom(contBi[j][0]);
      char * nomCont2 = getNom(contBi[j][1]);
      int zoneCont1 = getZone(contBi[j][0]);
      int zoneCont2 = getZone(contBi[j][1]);
      
      if (destins[zoneCont2] == nomCont2 && destins[zoneCont1] != nomCont1) {
	/* La contrainte n'est pas respectee */
	destins[zoneCont1] = nomCont1;
	/* Decrementer la structure destination */
	incrementer(*croisLibre, destins[j], j+1, -1);
      }
    } 
    
  }
  
  /* 3e parcours du tableau (ordre decroissant) : annulation des places en trop */
  /* On regarde le nombre de places au maximum qu'il faut enlever et on fait une boucle a partir de la fin jusqu'a arriver a ce nombre */
  int min = 0;
  for (j=0; j<6; j++) {
    for (i=0; i<croisLibre->tailles[j]; i++) {
      if (croisLibre->c[j][i].quota < min) min = croisLibre->c[j][i].quota;
    }
  } 
  /* On enleve les places reservees en trop */
  if (min < 0) {
    for (i=0; i<-min; i++) { /* Boucle sur le tableau de dataCliLibre */
      
      /* Recuperation des destinations dans un tableau */
      for (j=0; j<6; j++) { 
	destins[j] = getDes_dataCliLibre(&touriste[i],j);
      }
      
      int quota = 0;
      
      for (j=0; j<6; j++) {
	/* Regarder si le nombre de places restantes pour cette destination est < 0 et changer si oui */
	quota = get_Quota_by_Name_Desti(*croisLibre,destins[j], j);
	if (quota < 0) {
	  setDes_dataCliLibre(&touriste[i],j, NULL);
	}
      }
    }
  }
  /* 4e parcours du tableau : remplissage des cases vides par destinations */
  for (i=0; i<n; i++) { /* Boucle sur le tableau de dataCliLibre */
    
    /* Recuperation des destinations dans un tableau */
    for (j=0; j<6; j++) { 
      destins[j] = getDes_dataCliLibre(&touriste[i],j);
      
      /* Si la destination est NULL, on remplace par la destination de la meme zone ou il reste le + de places */
      if (destins[j] == NULL) {
	setDes_dataCliLibre(&touriste[i],j, get_Max_Quota(croisLibre, j));
      }
    }   
  }
  
  printf("Done\n");
 
}



