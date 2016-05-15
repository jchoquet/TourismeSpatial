#include <stdio.h>

#include <stdlib.h>

#include "file.h"




int filevide( file *f){

if (f->taille == 0 )
    return 1;

else
    return 0;

}



file* initialiser(void){
  
  file* f = malloc (sizeof(file));
  f->debut = NULL;
  f->taille = 0;
  return f;
}


void ajouter(file *f ,int i ,char n, char p, int c){

struct noeud *new= malloc(sizeof(*new));

if(f==NULL || new==NULL){

    exit(EXIT_FAILURE);

    }

else{

     new->Identifiant = i;

     new->Nom= n;

     new->Prenom= p;

     new->Croisiere= c;

     new->suivant= (f->debut);

     f->debut= new;

     f->taille = f->taille + 1;

    }

}


void supprimer(file *f ){

if(f==NULL){

     exit(EXIT_FAILURE);
}

else{

     struct noeud *tmp = f->debut;

     (f->debut)->suivant = NULL;

     f->debut = tmp->suivant ;

     f->taille = f->taille -1;

     free(tmp);

    }

}


void affichage( file *f){

struct noeud *courant;

int i;

courant = f->debut;

for( i=0 ; i< f->taille ; i++){

     printf("(%d | %c | %c | %d -)->", courant->Identifiant, courant->Nom, courant->Prenom, courant->Croisiere);

     courant=courant->suivant;

     }
 printf ("\n");
 
}

