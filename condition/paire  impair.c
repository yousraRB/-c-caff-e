/**
*@rebai yousra
*27/07/2021
*yousrarebai886@gmail.com
*/


#include<stdio.h>

int main () {
	
	int nombre;

	printf (" donnez un nombre entier ");
	scanf("%d",&nombre);
	
	if (nombre % 2 == 0)
		printf (" le nombre %d est : pair",nombre);
	else 
		printf("le nombre %d est impair", nombre);
		
	return 0;	
}
