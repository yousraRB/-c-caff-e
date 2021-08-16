/**
*yousra rebai
*yousrarebai886@gmail.com
*12/08/2021
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"ecol.h"
#include"fncecol.h"

int main (){
	int choix,choixe;
	char nom[50],code [50];
	
	
	while (1){
	printf ("|-1 pour ajouter un condidat \n");
	printf ("|-2 pour verfie si le condidat a le droit de passer un examen \n");
	printf ("|-3 pour supprimer les condidats qui ont termine   \n");
	printf ("|-4 pour modifie le montant restant de condidat \n");
	printf ("|-5 pour mettre à jours le status d’ un examen\n ");
	printf ("|-6 pour afficher les condidats \n");
	printf ("|-7 exit\n");
	printf ("\n veuillez entrer votre choix : \n");
	scanf  ( "%d",&choix);

	switch (choix){

		case 1: 
			ajouter ();
			break;
		case 2:
			printf ("1 POUR EXAMEN CODE \n");
			printf ("2 POUR EXAMEN CRENEAU \n");
			printf ("3 POUR EXAMEN CONDUIT \n");
			printf ("\n veuilliez entrer votre choix \n\n");
			scanf("%d",&choixe);
			printf (" maintenant etrer le nom de ce condidat :\n");
			scanf (" %s",nom);
			printf("entrer le numero de dossier de ce condidat :\n");
			scanf (" %s",code);
			passer(nom,code,choixe);
			break;
		case 3:
			supprime ();
			break;
		case 4:
			printf ("donnez le nom de condidat que vous voulez modifie:\n");
			scanf (" %s",nom);
			printf ("donnez le numero dossier de condidat que vous voulez modifie : \n");
			scanf (" %s",code);
			printf ("saisissez le montant ajouté par le condidat \n");
			scanf ("%d",&choixe);
			modifie ( nom,code,choixe);
			break;
		case 5:
			printf ("*mettre à jours le status d’ un examen*\n");
			printf ("|1 POUR EXAMEN CODE \n");
			printf ("|2 POUR EXAMEN CRENEAU \n");
			printf ("|3 POUR EXAMEN CONDUIT \n");
			printf ("\n veuilliez entrer votre choix \n\n");
			scanf("%d",&choixe);
			printf (" maintenant etrer le nom de ce condidat :\n");
			scanf (" %s",nom);
			printf("entrer le numero de dossier de ce condidat :\n");
			scanf (" %s",code);
			misajour(nom,code,choixe);
			break;
		case 6:
			printf ("\n*la liste des condidats*\n");
			affichage ();
			break;
	default :exit (1);
}
}
}
