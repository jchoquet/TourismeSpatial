struct destination {
  char * nom;
  int quota;
};

typedef struct destination destination;
 
 
struct croisiere {
  destination ** c; /* Tableau de 6 lignes (nombre de zones) et 2 colonnes (2 destinations par zone), tableau de destinations */
  int tailles[6]; /* Tableau de 6 cases contenant le nb de destinations dans la zone */
};

typedef struct croisiere croisiere;

/* Fonction qui crée une instance de croisiere vide */

croisiere * creer_croisiere();

void incrementer(croisiere c, char * dest, int zone, int n);


char * get_Name_Desti(croisiere crois, int i, int j);
int get_Quota_Desti(croisiere crois, int i, int j);
int get_Quota_by_Name_Desti(croisiere crois, char * nom, int zone);
void moins_Quota_Desti(croisiere crois, int i, int j);


/* A coder please : Fonctions qui créent les structures c0, c1 et c2 */

void get_c0(croisiere * c);
void get_c1(croisiere * c);
void get_c2(croisiere * c);

/* Fonction qui cree la structure croisiere pour la croisiere libre et l'autre qui enleve pour chaque destination le nombre de places indiquees dans les structures c0, c1 et c2 */

void get_c3(croisiere * c3);
void soustract(croisiere * c3, croisiere c0, croisiere c1, croisiere c2);

/* On soustrait les quotas de la croisière 2 à ceux de la croisière 1 */

void soustraction_struc_c(croisiere * crois1, croisiere crois2);
