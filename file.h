
struct Noeud{
  int identifiant;
  char * nom;
  char * prenom;
  int croisiere;
  struct Noeud * suivant;
};


struct File{
  struct Noeud* debut;
};


typedef struct File File;
typedef struct Noeud Noeud;


void supprimer_file(File *f);

void affichage_file(File *f);



/* Fonction qui permet de créer une file vide */

File* creer_file();


void ajouter_file(File *f ,int i ,char *n, char *p, int c);

/* Fonction qui fait pointer le dernier de b1 vers le premier de b2 */

void collage_file(File * b1,File * b2);
