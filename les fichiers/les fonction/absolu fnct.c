/**
*/
#include<stdio.h>

int absolue (int nombre);

int main() {
	int nombre;
	

	printf (" donnez un nombre");
	scanf ("%d",&nombre);
	
	printf(" la valeur absolue de %d est  : %d \n", nombre,absolue ( nombre));

}

int absolue (int nombre){

	if ( nombre<0)
	return nombre*-1;
	else 
	return nombre;
}
