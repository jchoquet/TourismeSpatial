#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#define H_tab   120      /* la hauteur du tableau */ 
#define L_tab   2     /* la largeur du tableau */ 



char **create_tab(){
char **tab;
tab = (char **)malloc(sizeof(char*) * H_tab);
int i ; 
for (i = 0 ; i < H_tab ; i=i+1){
    tab[i]=(char *)malloc(sizeof(char)*L_tab);
    }
 return tab;
}

/* initialiser le tableau pas 0 */ 

void init_tab( char **tab ){
    int i ;
    int j ;
      
    for( i=0 ; i<L_tab ; i++){
        for(j=0 ; j<H_tab ; j++){
           tab[i][j]= 0 ;           
        }
    }
}


//int gener_aleat(int **tab,int val )   
//{
//   /* Generation des deux premieres cases*/
//   int nb,b1;
//   do
//   {
//   srand(time(NULL));
//   nb=rand()%(H_tab*L_tab );
//   b1=(nb/H_tab);
//   }while(tab[b1][nb%H_tab]!=0) ;
//   
//   tab[b1][nb%H_tab]=val;
//   return nb ;
//   
//}


void afficheSep()
{
    printf("\t ");
    int i;
    for(i=0; i<L_tab-1; i++)
    {
        printf(" ");
    }
    printf("\n");
}
/* fonction affichage du tableau */


void affichage(char **tab){
     int i,j;
      for (i=0;i<H_tab; i++)
   {     
       afficheSep();
       printf("\t|");
       for (j=0;j<L_tab;j++)
       {   
               printf("%5d|", tab[i][j]);
       }
   }printf("\n");
   afficheSep();
}    
   


/* remplir le tableau */
char* remplir( char **tab ,char n , char m , int i ){
    tab[i-1][0]=n;
    tab[i-1][1]=m;
//  int o = H_tab;
//  tab[o][0]=n;
//  tab[o][1]=m;
//  o ++;
  }


   
/* fonction main */

//int main(){
//
///*initialisation du tableau */     
//char **tab;
//tab=create_tab();
//int i ; 
//for (i =0 ; i<H_tab ; i++){
//remplir(tab , i+1 , 1 , i+1);
////remplir(tab , 2 , 3 , 2);
////remplir(tab , 3 , 4 , 3);
////remplir(tab , 4 , 5 , 4);
////remplir(tab , 5 , 6 , 5);
//}
//
////init_tab(tab);
////nb=gener_aleat(tab,1 );
//affichage(tab);
//
//}
//
//
//    
