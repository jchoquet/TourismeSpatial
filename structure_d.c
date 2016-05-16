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
   @ ensures : remplace la destination de la zone zone dans d* par *des
   @ */
void setDes_dataCliLibre(dataCliLibre* d, int zone, char *des){
  
  if (zone == 0) d->des1 = des;
  else if (zone == 1) d->des2 = des;
  else if (zone == 2) d->des3 = des;
  else if (zone == 3) d->des4 = des;
  else if (zone == 4) d->des5 = des;
  else return d->des6 = des;
}


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des1
   @ */
char* getDes_dataCliLibre(struct dataCliLibre* d, int zone) {
  if (zone == 0) return d->des1;
  else if (zone == 1) return d->des2;
  else if (zone == 2) return d->des3;
  else if (zone == 3) return d->des4;
  else if (zone == 4) return d->des5;
  else return d->des6;
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


