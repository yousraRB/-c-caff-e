/**
*@rebai yousra
*29/07/2020
*/

#include<stdio.h>
#include<stdbool.h>
int main () {
	int  i,nombre;
	bool trouve;
	printf ("dnnez un nombre : \n");
	scanf ("%d",&nombre);
	
	
	if (nombre ==1)	
	printf ("le nombre  n'est pas premier");
		else
	i=2; trouve =false;
		
	while (i<=nombre/2 && trouve== false) {
	
	if (nombre % i == 0) {
	printf ("le nombre n'est pas premier");
  	trouve= true;	}
    i++;
   } 
	
	if ( trouve==false)
	printf ("le nombre est  premier");
	
	return 0;
}

