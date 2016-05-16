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
void setNom_dataCliLibre(dataCliLibre* d, char *nom);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans nom
   @ */
char* getNom_dataCliLibre(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace le champ prenom dans *d par *prenom
   @ */
void setPrenom_dataCliLibre(dataCliLibre* d, char *prenom);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans prenom
   @ */
char* getPrenom_dataCliLibre(dataCliLibre* d);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : remplace la destination de la zone zone dans d* par *des
   @ */
void setDes_dataCliLibre(dataCliLibre* d, int zone, char *des);


/* @ requires : *d est valide
   @ assigns : *d
   @ ensures : renvoie l'element contenu dans des1
   @ */
  char* getDes_dataCliLibre(struct dataCliLibre* d, int zone);


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


