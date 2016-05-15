#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fichier.h"



//importer souhaits_voyageurs

char **str_split (char *s, const char *ct){
   char **tab = NULL;
   if (s != NULL && ct != NULL){
      int i;
      char *cs = NULL;
      size_t size = 1;
      for (i = 0; (cs = strtok (s, ct)); i++){
         if (size <= i + 1){
            void *tmp = NULL;
            size <<= 1;
            tmp = realloc (tab, sizeof (*tab) * size);
            if (tmp != NULL){
               tab = tmp;
            }
            else{
               fprintf (stderr, "Memoire insuffisante\n");
               free (tab);
               tab = NULL;
               exit (EXIT_FAILURE);
            }
         }
         tab[i] = cs;
         s = NULL;
      }
      tab[i] = NULL;
   }
   return tab;
}

int importer_souh_voy(const char * filename){
        FILE *fichier ;
        int cpt=0;
        
        char tampon[BUFSIZ];
        int actuel = 0;
        int c; 
        fichier = fopen (filename, "r");
        if (!fichier) {
                return EXIT_FAILURE;
        }
        while ((c = fgetc (fichier)) != EOF) {        
                if (c == ';' || c == '\n') {
                        //printf ("%d",cpt );
                        //printf ("%s", strtol(tampon, NULL, 2));						
						char **tab = str_split(tampon, ",");
                        printf ("%d,%s,%s,%s,%s",cpt+1,tab[1],tab[2],tab[3],tab[4]  );                        
                        actuel = 0;
                        memset (tampon, 0, sizeof tampon);
						            printf ("\n" );
                        cpt++;                           
                         
                } else {
                        tampon[actuel++] = c;
                
                }
        } 
        fclose (fichier);
    return EXIT_SUCCESS;
}
  
  
  
  
int main(void){
importer_souh_voy("souhaits_voyageurs.csv");
}  
