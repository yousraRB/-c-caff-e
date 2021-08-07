#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "types.h"
#include "etudiant.h"
#include "section.h"

int main( ){
	int menu;
	tetudiant e1,e2;
	char mat [50];
	
	while (1){
		printf (" 1 ajouter etudiant \n");
		printf (" 2 modifier etudiant \n");
		printf (" 3 supprimer etudiant \n");
		printf (" 4 afficher les etudiant dune section \n");
		printf (" 5 afficher la moyenne dune sectin  \n");
		printf (" 6 afficher etudiants \n \n");
		printf(" veuilliez entrer votre choix \n ");
		scanf ("%d",&menu);
		switch (menu){
			case 1:
				ajouterEtudiant ();
				break;
			case 2:
				printf (" donnez le matricule : \n");
				scanf (" %s", e1.matricule);
				printf ( " donnez le nom  : \n");
				scanf (" %s", e1.nom);
				printf ( " donnez le prenom  : \n");
				scanf (" %s", e1.prenm);
				printf ( " donnez la moyenne   : \n");
				scanf ("%f", &e1.moy);
				printf ( " donnez le nom de la section  : \n");
				scanf (" %s", e1.sec.nom);
				printf ( " donnez la filiere  :  \n");
				scanf (" %s", e1.sec.filier);
				printf ( "\n \n  veuilliez entrier les nouvelles information \n \n");
				printf (" donnez le matricule : \n");
				scanf (" %s", e2.matricule);
				printf ( " donnez le nom  : \n");
				scanf (" %s", e2.nom);
				printf ( " donnez le prenom  : \n");
				scanf (" %s", e2.prenm);
				printf ( " donnez la moyenne   : \n");
				scanf ("%f", &e2.moy);
				printf ( " donnez le nom de la section  : \n");
				scanf (" %s", e2.sec.nom);
				printf ( " donnez la filiere  :  \n");
				scanf (" %s", e2.sec.filier);
				modifieEtudiants(e1,e2);
				break;
			case 3:
				printf ( " entrer le matricule detudiant que  vous voulez le supprime :\n");
				scanf(" %s",mat);
				supprimerEtudiants(mat);
				break;
			case 4:
				printf (" donnez le nom de la section: \n");
				scanf ( " %s",mat);
				afficherSEC(mat);
			break;
				
			case 5 : 
				printf (" donnez le nom de la section: \n");
				scanf ( " %s",mat);
				printf (" la moyenne est : %.2f \n",moysec(mat));
			break;
			case 6 :
				afficherEtudiants ();
				break;
			
			default : exit (1);
		
		}
	}
}
