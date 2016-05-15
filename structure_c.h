struct destination {
  char nom;
  int quota;
};

typedef struct destination destination;
 
struct croisiere{
  destination **c;
};

typedef struct croisiere.c croisiere;

croisiere creer();
