/**
*@rebai yousra
*28/07/2021
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int main () {
	int random;
	int stime;
	long ltime;
	int nombre,cpt;
	bool bol;
// Initialisation du compteur pour avoir un nombre al�atoire diff�rent pour chaque ex�cutation 
 	ltime =time (NULL);
	
	srand(ltime);
//g�n�rer un  al�atoire entre 1 et 1000.
	random = rand () % 1000;
	
	
	cpt=1; bol =false;
	
	while (cpt<=3 && bol==false) {
		printf(" devener un nombre ");
		scanf ("%d",&nombre);
		if (nombre == random){
			bol=true;
		}
		cpt=cpt+1;
	}
	 
	 if ( bol ==true )
	 printf ("f�licitation  vous avez trouve le nombre %d",random);
	 else 
	 printf ("  le nombre est : %d ,essay� une autre fois ,",random);
	
	return 0;
}
