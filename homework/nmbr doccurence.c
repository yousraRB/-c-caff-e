/**
*@rebai yousra
*29/07/2020
*/

#include<stdio.h>
#include<stdbool.h>
int main () {
	int A,C ,i,cpt,save, rest;
	
	printf ( "saisir un nombre entier A: \n");
	scanf ("%d",&A);
	
	 do {
	 printf (" donnez un chiffre C entre 1 et 10 : \n");
	 scanf ("%d",&C);
	} while ( C<0 || 9<C);
	
	cpt =0; save=A;
	while ( save!=0 ){
		rest= save %10 ;
		if ( rest ==C){
		cpt =cpt+1;}
		save=save/10;
	}
	printf (" le nombre d'occurence de chiffre  %d dans l'entier  %d est : %d fois ",C ,A , cpt );
	return 0;
}
	

