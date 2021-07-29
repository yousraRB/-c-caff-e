/**
*@rebai yousra
*29/07/2020
*/

#include<stdio.h>
#include<stdbool.h>
int main () {
	int nombre ,i,som;
	
	printf ( "saisir un nombre entier: \n");
	scanf ("%d",&nombre);
	
	    i=1; som=0;
	while (i<=nombre/2 ){
		if (nombre %i==0 ){
		som=som+i;}
		i++;
	}
	if (som==nombre)
		printf ("le nombre est parfait ");
	
	else
	
	printf (" le nombre est pas parfait");

	return 0;	

}

