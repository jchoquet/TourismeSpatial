
struct noeud{
  int Identifiant;
  char * Nom;
  char * Prenom;
  int Croisiere;
  struct noeud * suivant;
};

typedef struct noeud noeud;

struct file{
  struct noeud* debut;
};

typedef struct file file;


void supprimer(file *f);

void affichage( file *f);



/* Fonction qui permet de créer une file vide */

file* creer_file();


void ajouter(file *f ,int i ,char *n, char *p, int c);


void affichage( file *f);
/* Fonction qui fait pointer le dernier de b1 vers le premier de b2 */

void collage_file(file * b1,file * b2);