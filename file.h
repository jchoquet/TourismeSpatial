
struct noeud{
  int Identifiant;

  char Nom;

  char Prenom;

  int Croisiere;

  struct noeud *suivant;
};


typedef struct file{

  struct noeud *debut;

  int taille;

} file;

typedef struct noeud noeud;

typedef struct file file;

 file * initialiser();

void ajouter( file *f, int i, char n, char p, int c);

void supprimer(file *f);

void affichage( file *f);
