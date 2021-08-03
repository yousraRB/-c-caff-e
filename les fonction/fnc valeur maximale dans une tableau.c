/**
*@rebai yousra
*02/08/2021
*yousrarebai886@gmail.com
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int fmax (int tab[100],int n);
int main(){
	int n,i,max ;
	int tab[100];
	do{
	printf (" donnez n le nombre des cases de tableau  (n>0): \n");
	scanf( "%d",&n);
    }while ( n<=0);
    
    for (i=0;i<n;i++){
    	printf ( " donnez la valeur de la case numéro %d : ",i);
    	scanf ("%d",&tab[i]);
    	printf ("\n");
	}
	
	printf (" voila votre tableau : \n");
	
	for (i=0;i<n;i++){
    	printf ("%d",tab[i]);
    	printf (" |");
	}
	max=fmax(tab,n);
	printf ( " \n la valeur maximale dans ce tableau est : %d",max);
}
int fmax (int tab[100],int n){
	int i,max;
	max=tab[0];
	for ( i=1;i<n;i++){
		if ( tab[i] >max){
		max = tab [i];
		;}
	}
	return max;
}
