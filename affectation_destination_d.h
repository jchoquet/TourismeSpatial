/** Author : Sandra MICHAUT
    Date : 22 April 2016
*/

/* Module qui permet d'affecter des destinations pour les touristes ayant choisi une croisiere libre */


void importer_contraintes(contraintes ** contBi, int* nbBi, contraintes ** contUni, int* nbUni);
void setCrois(croisiere croisTot, croisiere croisDispo, croisiere croisPlan, croisiere croisSat, croisiere croisVie);
void importer_quotas_libre(croisiere* libre);

void affectationCliLibre(dataCliLibre* touriste, croisiere* croisLibre);

