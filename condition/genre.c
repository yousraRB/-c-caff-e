/**
*@rebai yousra 
* 27/07/2021
*/

#include<stdio.h>
 
int main () {
	 char genre; 
	 
	printf ("saisir ton genre ");
	scanf ("%c",&genre);
	
	switch (genre) {
		case 'M' : printf ("%c correspend a masculin",genre);
		break;
		case 'F' : printf ( " %c correspend a fumin ", genre);
		break;
		default : printf ( " u r not human");
	}
	return 0;
}
