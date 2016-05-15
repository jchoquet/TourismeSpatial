/** Author : Sandra MICHAUT
    Date : 22 April 2016
*/

/* Module qui permet d'affecter des destinations pour les touristes ayant choisi une croisiere libre */

struct contraintes {
  char* nom;
  int zone;
};

typedef struct contraintes contraintes;

void affectationCliLibre();
