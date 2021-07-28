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
// Initialisation du compteur pour avoir un nombre aléatoire différent pour chaque exécutation 
 	ltime =time (NULL);
	
	srand(ltime);
//générer un  aléatoire entre 1 et 1000.
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
	 printf ("félicitation  vous avez trouve le nombre %d",random);
	 else 
	 printf ("  le nombre est : %d ,essayé une autre fois ,",random);
	
	return 0;
}
