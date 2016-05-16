#include "hafsa_file.h"




int main () {


  printf("Début du test :\n");
  printf("Création de la file\n");
  file * f = creer_file();
  printf("Remplissage\n");
  ajouter(f,10, "abc", "def", 2);
  printf("Remplissage2\n");
  ajouter(f,1, "gjkh", "dqsdqsd", 45);
  printf("Affichage\n");
  affichage(f);
  printf("Suppression\n");
  supprimer(f);
  printf("Affichage\n");
  affichage(f);
  printf("Fin\n");

  return 0;
}
