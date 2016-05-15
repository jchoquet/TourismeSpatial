/** Author : Sandra MICHAUT
    Date : 22 April 2016
*/

/* Definition de la structure d, qui contiendra les donnees sur un client qui a choisi une croisere libre */
struct dataCliLibre {
  char* nom;
  char* prenom;
  char* des1;
  char* des2;
  char* des3;
  char* des4;
  char* des5;
  char* des6;
};


typedef struct dataCliLibre dataCliLibre;

/* @ requires : 
   @ assigns :
   @ ensures : renvoie une nouvelle structure de donnees initialisees a NULL
   @ */
dataCliLibre* creer_dataCliLibre(void);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ nom dans *d par *nom
   @ */
void setNom(dataCliLibre* d, char *nom);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans nom
   @ */
char* getNom(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ prenom dans *d par *prenom
   @ */
void setPrenom(dataCliLibre* d, char *prenom);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans prenom
   @ */
char* getPrenom(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des1 dans *d par *des1
   @ */
void setDes1(dataCliLibre* d, char *des1);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des1
   @ */
char* getDes1(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des2 dans *d par *des2
   @ */
void setDes2(dataCliLibre* d, char *des2);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des2
   @ */
char* getDes2(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des3 dans *d par *des3
   @ */
void setDes3(dataCliLibre* d, char *des3);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des3
   @ */
char* getDes3(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des4 dans *d par *des4
   @ */
void setDes4(dataCliLibre* d, char *des4);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des4
   @ */
char* getDes4(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des5 dans *d par *des5
   @ */
void setDes5(dataCliLibre* d, char *des5);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des5
   @ */
char* getDes5(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ des6 dans *d par *des6
   @ */
void setDes6(dataCliLibre* d, char *des6);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des6
   @ */
char* getDes6(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : cree une structure dataCliLibre et la remplit par les donnees passees en arguments
   @ */
dataCliLibre* importer_dataCliLibre(char* nom, char* prenom, char* des1, char* des2, char* des3, char* des4, char* des5, char* des6);


/* @ requires : *d est valide et ses elements ont ete alloues dynamiquement
   @ assigns : *d
   @ ensures : libere la structure passee en argument
   @ */
void liberer_dataCliLibre(dataCliLibre* d);


