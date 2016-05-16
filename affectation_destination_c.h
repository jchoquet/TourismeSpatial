/* Ce module permet d'affecter les destinations des croisières organisées
Fonction principale : prend en argument la file b : [identifiant, nom, prenom, crosiere -]> ...
chaque personne a été affectée à une croisière représentée par un numéro 
0 pour la croisière les planètes, 1 pour satellites naturels, 2 pour traces de vies, 3 pour croisière libre.  
Renvoie la file contenant uniquement les clients avec croisières libres et écrit directement dans le fichier resultat.csv */

void destination_orga (File * b, croisiere * c0, croisiere * c1, croisiere * c2);