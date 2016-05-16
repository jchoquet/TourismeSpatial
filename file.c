#include <stdio.h>
#include <stdlib.h>
#include "File.h"



int filevide(File *f){
  if (f == NULL )
    return 1;
  else
    return 0;
}


File * creer_file()
{
    File * f = malloc(sizeof(File));
    f->debut = NULL;

    return f;
}

void ajouter_File(File *f ,int i ,char *n, char *p, int c){
  
  Noeud *new= malloc(sizeof(*new));

  if(f == NULL || new == NULL){
    exit(EXIT_FAILURE);
  }
  new->identifiant=i;
  new->nom=n;
  new->prenom=p;
  new->croisiere=c;
  new->suivant=NULL;

  if (f->debut != NULL){
    
    Noeud *courant = f->debut;
    while (courant ->suivant != NULL){
      courant = courant->suivant;
    }
    courant->suivant = new;
    
  }
  else
  { 
    f->debut = new ;
  }
}


void supprimer_file(File *f ){
  if(f == NULL){
     exit(EXIT_FAILURE);
  }
  if(f->debut != NULL){
    Noeud * tmp = f->debut;
    f->debut = tmp->suivant;
    free(tmp);
  }
}


void affichage_File( File *f){
  struct Noeud *courant;
  courant = f->debut;
  while(courant !=NULL ){     
     printf("(%d | %s | %s | %d -)->", courant->identifiant, courant->nom, courant->prenom, courant->croisiere);
     courant=courant->suivant;
     }
  printf ("\n");
}


void collage_File(File * b1,File * b2){
   if (b1->debut != NULL){
  Noeud *courant = b1->debut;
  while (courant->suivant != NULL){
    courant = courant->suivant;
        }
  courant->suivant = b2->debut;
   }
}