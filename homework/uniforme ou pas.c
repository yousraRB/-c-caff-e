/**
*@rebai yousra
*29/07/2020
*/

#include<stdio.h>
#include<stdbool.h>
int main () {
	int A,rest ,i,chif1;
	bool trouve;
	printf ( "saisir un nombre entier A: \n");
	scanf ("%d",&A);
	
	; trouve = false;

     rest =A %10;  A = A/10; 
     
	while ( A !=0 && trouve==false){
		chif = rest;
		rest= A %10; 
		if ( chif != rest){
		printf (" le nombre est pas uniforme");
		trouve =true;	}
		A = A/10;
	}
	
	if (trouve==false )
	printf (" le nombre est uniforme");
	return 0;
}
