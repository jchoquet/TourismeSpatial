/** Author : Sandra MICHAUT
    Date : 22 April 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "structure_d.h"



/* @ requires : 
   @ assigns :
   @ ensures : renvoie une nouvelle structure de donnees initialisees a NULL
   @ */
dataCliLibre* creer_dataCliLibre() {

  dataCliLibre* d = malloc(sizeof(struct dataCliLibre));
  d->nom = NULL;
  d->prenom = NULL;
  d->des1 = NULL;
  d->des2 = NULL;
  d->des3 = NULL;
  d->des4 = NULL;
  d->des5 = NULL;
  d->des6 = NULL;
  
  return d;

}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ nom dans *d par *nom
   @ */
void setNom_dataCliLibre(dataCliLibre* d, char *nom){
  d->nom = nom;
}

/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans nom
   @ */
char* getNom_dataCliLibre(struct dataCliLibre* d) {
  return d->nom;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ prenom dans *d par *prenom
   @ */
void setPrenom_dataCliLibre(dataCliLibre* d, char *prenom){
  d->prenom = prenom;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans prenom
   @ */
char* getPrenom_dataCliLibre(struct dataCliLibre* d) {
  return d->prenom;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des1 dans *d par *des1
   @ */
void setDes1_dataCliLibre(dataCliLibre* d, char *des1){
  d->des1 = des1;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des1
   @ */
char* getDes1_dataCliLibre(struct dataCliLibre* d) {
  return d->des1;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des2 dans *d par *des2
   @ */
void setDes2_dataCliLibre(dataCliLibre* d, char *des2){
  d->des2 = des2;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des2
   @ */
char* getDes2_dataCliLibre(struct dataCliLibre* d) {
  return d->des2;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des3 dans *d par *des3
   @ */
void setDes3_dataCliLibre(dataCliLibre* d, char *des3){
  d->des3 = des3;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des3
   @ */
char* getDes3_dataCliLibre(struct dataCliLibre* d) {
  return d->des3;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des4 dans *d par *des4
   @ */
void setDes4_dataCliLibre(dataCliLibre* d, char *des4){
  d->des4 = des4;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des4
   @ */
char* getDes4_dataCliLibre(struct dataCliLibre* d) {
  return d->des4;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des5 dans *d par *des5
   @ */
void setDes5_dataCliLibre(dataCliLibre* d, char *des5){
  d->des5 = des5;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des5
   @ */
char* getDes5_dataCliLibre(struct dataCliLibre* d) {
  return d->des5;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des6 dans *d par *des6
   @ */
void setDes6_dataCliLibre(dataCliLibre* d, char *des6){
  d->des6 = des6;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des6
   @ */
char* getDes6_dataCliLibre(struct dataCliLibre* d) {
  return d->des6;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : cree une structure dataCliLibre et la remplit par les donnees passees en arguments
   @ */
dataCliLibre* importer_dataCliLibre(char* nom, char* prenom, char* des1, char* des2, char* des3, char* des4, char* des5, char* des6){
  
  dataCliLibre* d = creer_dataCliLibre();
  d->nom = nom;
  d->prenom = prenom;
  d->des1 = des1;
  d->des2 = des2;
  d->des3 = des3;
  d->des4 = des4;
  d->des5 = des5;
  d->des6 = des6;
  return d;

}


/* @ requires : *d est valide et ses elements ont ete alloues dynamiquement
   @ assigns : *d
   @ ensures : libere la structure passee en argument
   @ */
void liberer_dataCliLibre(dataCliLibre* d){
  free(d->nom);
  free(d->prenom);
  free(d->des1);
  free(d->des2);
  free(d->des3);
  free(d->des4);
  free(d->des5);
  free(d->des6);

  free(d);
}


