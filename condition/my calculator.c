/**
*@rebai yousra 
* 27/07/2021
*/

#include<stdio.h>
 
int main () {
	 
	int choix , nbr1 ,nbr2 ;
	
	

	printf (" welcom in my calculator \n");
	
	printf ("| 1- addition       |\n");
	printf ("| 2- multiplication |\n");
    printf ("| 3- soustraction   |\n");
    printf ("| 4- division       |\n");
    printf ("| 5- modulo         |\n");
   
	
	printf ("donnez votre choix: \n");
	scanf ("%d",&choix);
	
	printf ("donnez le primier nombre : \n"); 
	scanf ("%d",&nbr1);
	printf ("donnez le deusieme nombre : \n");
	scanf ("%d",&nbr2);
	
	switch (choix ) {
		case 1 : printf ( "%d + %d = %d" , nbr1, nbr2, nbr1+nbr2 );
		break;
	
		case  2 : printf ( "%d * %d = %d" , nbr1, nbr2, nbr1*nbr2 );
		break;
	
		case 3 : printf ( "%d - %d = %d" , nbr1, nbr2, nbr1- nbr2 );
		break;
	
		case  4 : if (nbr2!=0)   
		             printf ( "%d / %d = %d" , nbr1, nbr2, nbr1/nbr2 );
		             else printf ("division impossible");
	   	break;
    	
		case 5   : printf ( "%d % %d = %d" , nbr1, nbr2, nbr1 % nbr2 );
    	break;
    	
    	default : printf (" veulliez choisir un choix qui contien dans la liste");
   	
}
	return 0;
}
