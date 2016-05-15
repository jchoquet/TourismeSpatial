/** Author : Sandra MICHAUT
    Date : 15 May 2016
*/

struct contraintes {
  char* nom;
  int zone;
};

typedef struct contraintes contraintes;

contraintes* creer_contrainte(char* nom, int zone);

char* getNom(contraintes cont);

int getZone (contraintes cont);
