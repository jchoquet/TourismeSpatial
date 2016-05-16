#include <stdio.h>
#include <stdlib.h>
#include "hafsa_file.h"


/* TO CHANGE : test pas sur taille mais sur != NULL */

int filevide(file *f){
  if (f == NULL )
    return 1;
  else
    return 0;
}


file* creer_file(void){  
  file* f = malloc (sizeof(file));
  f->debut = NULL;
  return f;
}


void ajouter_file(file *f ,int i ,char *n, char *p, int c){
  struct noeud *new= malloc(sizeof(*new));
  if(f==NULL || new==NULL){
    exit(EXIT_FAILURE);
    }
     new->Identifiant =(int) i;
     new->Nom= (char*)n;
     new->Prenom=(char *)p;
     new->Croisiere=(int )c;
     new->suivant=NULL;
    if (f->debut != NULL){
	noeud *courant = f->debut;
	while (courant ->suivant != NULL){
		courant = courant->suivant;
        }
	courant->suivant = new;
    }
    else{ f->debut = new ; }
}


void supprimer_file(file *f ){
  if(f==NULL){
     exit(EXIT_FAILURE);
  }
  if(f->debut != NULL){
    noeud* tmp = f->debut;
    f->debut = tmp->suivant;
    }
}


void affichage_file( file *f){
  struct noeud *courant;
  courant = f->debut;
  while(courant !=NULL ){     
     printf("(%d | %s | %s | %d -)->", courant->Identifiant, courant->Nom, courant->Prenom, courant->Croisiere);
     courant=courant->suivant;
     }
  printf ("\n");
}


void collage_file(file * b1,file * b2){
   if (b1->debut != NULL){
	noeud *courant = b1->debut;
	while (courant ->suivant != NULL){
		courant = courant->suivant;
        }
	courant->suivant = b2->debut;
   }
}

