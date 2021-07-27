/**
*@rebai yousra 
* 27/07/2021
*/

#include<stdio.h>
 
int main () {
	 
	char caractere;
	
	printf ("donnez un caractere: \n");
	scanf ("%c",&caractere);
	
	switch (caractere) {
		case 'a' : 
		case 'e' :
		case 'y' :
		case 'i' :
    	case 'o' :
    	case 'u' :	printf ( " voyel ");
    	break;
    	default : printf ("constante");
    	
}
	return 0;
}
