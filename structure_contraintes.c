#include <stdio.h>
#include <stdlib.h>
#include "structure_contraintes.h"


contraintes* creer_contrainte(char* nom, int zone) {
  contraintes* cont = malloc (sizeof (contraintes));
  cont->nom = nom;
  cont->zone = zone;

  return cont;  
}


char* getNom(contraintes cont) {
  return cont.nom;
}


int getZone (contraintes cont) {
  return cont.zone;
}
