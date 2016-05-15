struct destination {
  char nom;
  int quota;
};

typedef struct destination destination;
 
struct croisiere{
  destination **c;
};

typedef struct croisiere croisiere;

croisiere* creer();

void incrementer( destination d, int n);
