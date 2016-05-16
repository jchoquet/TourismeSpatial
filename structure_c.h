struct destination {
  char nom;
  int quota;
};

typedef struct destination destination;
 
struct croisiere{
  destination **c;
  int tailles[6]; /* Tableau de 6 cases contenant le nb de destinations dans la zone */
};

typedef struct croisiere croisiere;

croisiere* creer();

void incrementer(croisiere c, char * dest, int zone, int n);
