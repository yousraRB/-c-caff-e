/**
*@rebai yousra 
* 27/07/2021
*/

#include<stdio.h>
#include<math.h>

int main (){
	int nombre, puiss;
	
	printf (" saisir un nombre entier ");
	scanf("%d",&nombre);
	
	printf(" donnez la puissence de ce nombre");
	scanf("%d",&puiss);
	
	printf (" la résultat est : %.2f", pow(nombre,puiss));
	
	return 0 ;
}

