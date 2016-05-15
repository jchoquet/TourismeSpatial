#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


//ouvrir un fichier 

FILE * open_file(const char * filename, const char * mode){
  FILE * fp;
  fp = fopen(filename, mode);
  if(fp == NULL){
    printf("Impossible d'ouvrir le fichier %s\n", filename);
    exit(1);
  }
  printf("Ouverture du fichier %s\n", filename);
  return 0;
}



//importer priorités 

char **str_split (char *s, const char *ct){
  char **tab = NULL;
  if (s != NULL && ct != NULL){
    int i;
    char *cs = NULL;
    size_t size = 1;
    for (i = 0; (cs = strtok (s, ct)); i++){
      if ((int)size <= i + 1){
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



char **str_split2 (char *s, const char *ct){
  char **tab = NULL;
  if (s != NULL && ct != NULL){
    int i;
    char *cs = NULL;
    size_t size = 1;
    for (i = 0; (cs = strtok (s, ct)); i++){
      if (cs == NULL) {
	printf("NULL");
      }
      printf("%s|", cs);
      if ((int)size <= i + 1){
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




int importer_prio(const char * filename){
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
      char **tab = str_split2(tampon, ",");
      printf ("%d,%s",cpt+1,tab[2]  );                        
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
  
  
  
int importer_dest(){
  FILE *fichier ;
  int cpt=0;
  char tampon[BUFSIZ];
  int actuel = 0;
  int c;
 
  fichier = fopen ("destinations.csv", "r");
  if (!fichier) {
    return EXIT_FAILURE;
  }
	
  while ((c = fgetc (fichier)) != EOF) {        
    if (c == ';' || c == '\n') {
      //printf ("%d",cpt );
      //printf ("%s", strtol(tampon, NULL, 2));
	    
      char **tab = str_split2(tampon, ",");
      printf ("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",tab[0],tab[1],tab[2],tab[3],tab[4],tab[5],tab[6],tab[7],tab[8],tab[9],tab[10],tab[11]);                        
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
  open_file("destinations.csv", "r");
  printf("ok\n");
  importer_dest();
  printf("Done\n");
  return 0;
}  
