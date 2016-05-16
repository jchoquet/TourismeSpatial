struct destination {
  char * nom;
  int quota;
};

typedef struct destination destination;
 
 
struct croisiere {
  destination **c; /* Tableau de 6 lignes (nombre de zones) et 2 colonnes (2 destinations par zone), tableau de destinations */
  int tailles[6]; /* Tableau de 6 cases contenant le nb de destinations dans la zone */
};

typedef struct croisiere croisiere;

/* Fonction qui crée une instance c vide */

croisiere * creer_croisiere();


/* A coder please : Fonctions qui créent les structures c0, c1 et c2 */

void get_c0(croisiere * c);
void get_c1(croisiere * c);
void get_c2(croisiere * c);

void incrementer(croisiere c, char * dest, int zone, int n);
