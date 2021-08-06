/**
*@rebai yousra
*02/08/2021
*yousrarebai886@gmail.com
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void  supprime (int tab[100],int n);
int main(){
	int n,i;
	int tab[100];
	do{
	printf (" donnez n le nombre des cases de tableau  (n>0): \n");
	scanf( "%d",&n);
    }while ( n<=0 || n>100);
    
    for (i=0;i<n;i++){
    	printf ( " donnez la valeur de la case numéro %d : ",i);
    	scanf ("%d",&tab[i]);
    	printf ("\n");
	}
	
	printf (" voila votre tableau : \n");
	printf (" [");
	for (i=0;i<n;i++){
    	printf ("%d",tab[i]);
    	printf (" |");
	}
	printf (" ]");
	printf(" \n this is the new bord : \n");
	 supprime (tab,n);
}
void supprime  (int tab[100],int n){
	int i,j,k;
	
	for ( i=0;i<n;i++){
		j=i+1;
		while(j<n){
			if ( tab[i]==tab[j]){
				for (k=j;k<n;k++){
					tab[k]=tab[k+1];
				}
				n=n-1;
			}else {
				j++;
			}
			
		}	
	}
	printf (" [");
	for (i=0;i<n;i++){
    	printf ("%d",tab[i]);
    	printf (" |");
	}
	printf (" ]");
}
