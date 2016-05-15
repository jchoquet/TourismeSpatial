
struct noeud{
  int Identifiant;
  char * Nom;
  char * Prenom;
  int Croisiere;
  struct noeud * suivant;
};

struct file{
  struct noeud* debut;
};

typedef struct file file;


void supprimer(file *f);

void affichage( file *f);



/* Fonction qui permet de créer une file vide */

file creer_file();


void ajouter_file(file * f, int identifiant, char * nom, char * prenom, int croisiere);


void affichage( file *f);
/* Fonction qui fait pointer le dernier de b1 vers le premier de b2 */

void collage_file(file * b1,file * b2);
