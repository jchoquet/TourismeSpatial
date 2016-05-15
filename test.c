/** Author : Sandra MICHAUT
    Date : 22 April 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "structure_d.h"


int main(int argc, char** argv) {

  if (argc == 9) {
    
    char * nom = argv[1];
    char * prenom = argv[2];
    char * des1 = argv[3];
    char * des2 = argv[4];
    char * des3 = argv[5];
    char * des4 = argv[6];
    char * des5 = argv[7];
    char * des6 = argv[8];


    
    printf("\n----TEST POUR LA CREATION----\n");
    dataCliLibre* d = creer_dataCliLibre();
    setNom(d, nom);
    setPrenom(d, prenom);
    setDes1(d, des1);
    setDes2(d, des2);
    setDes3(d, des3);
    setDes4(d, des4);
    setDes5(d, des5);
    setDes6(d, des6);

    printf("Le nom est %s\n", getNom(d));
    printf("Le prenom est %s\n", getPrenom(d));
    printf("Les destinations sont %s, %s, %s, %s, %s, %s\n\n", getDes1(d), getDes2(d), getDes3(d), getDes4(d), getDes5(d), getDes6(d));


  
    printf("----TEST POUR L'IMPORTATION----\n");
    dataCliLibre* d2;
    d2 = importer_dataCliLibre(nom, prenom, des1,  des2, des3, des4, des5, des6);
    printf("Le nom est %s\n", getNom(d2));
    printf("Le prenom est %s\n", getPrenom(d2));
    printf("Les destinations sont %s, %s, %s, %s, %s, %s\n\n", getDes1(d2), getDes2(d2), getDes3(d2), getDes4(d2), getDes5(d2), getDes6(d2));



    free(d);
    free(d2);
  }
  else printf("usage : name firstName Des1 Des2 Des3 Des4 Des5 Des6\n");

  printf("----TEST AVEC DES TABLEAUX DE CARACTERES----\n");
  dataCliLibre* data = creer_dataCliLibre();
  char nom[4] = "Leo";
  char des1[13] = "sur la Terre";
  nom[13] = '\0';
  setNom(data, nom);
  setDes1(data, des1);

  printf("Le nom est %s\n", getNom(data));
  printf("La 1e destination est %s\n\n", getDes1(data));

  free(data);
  
  printf("----TEST DE LIBERATION DE LA MEMOIRE----\n");
  char * nom1 = calloc(5,sizeof(char));
  nom1[0] = 'F';
  nom1[1] = 'r';
  nom1[2] = 'o';
  nom1[3] = 's';
  nom1[4] = 't';
  nom1[5] = '\0';

  dataCliLibre* data2 = creer_dataCliLibre();
  setNom(data2, nom1);

  printf("Le nom est %s\n\n", getNom(data2));
  
  liberer_dataCliLibre(data2);
  return 0;
}
