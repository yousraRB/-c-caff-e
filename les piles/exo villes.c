#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"lespiles.h"
void affichage (PILE *tete);
void supprime(PILE **tete);
void supprimeall(PILE **tete);
int main () {
	ville inf,info;
	char nom[30];
	float super;
	int habitant;
	int i=1,choix=1;
	PILE *tete;
	init (&tete);
	while (choix==1){

		printf (" med les information t3 la ville num  : %d\n",i);
		printf (" -1 nom : \n");
		scanf(" %s",nom);
		printf("-2 la superficie de la ville \n");
		scanf("%f",&super);
		printf("-3 le nombre d’habitants \n");
		scanf("%d",&habitant);
		i++;
		strcpy(inf.nom,nom);
		inf.super=super;
		inf.habitant=habitant;
		enpiler(&tete,inf);
		do {
			printf("tzid dkhel ville wahdokhra wla nn ? si oui aktb 1 sinon aktb 0 \n");
			scanf("%d",&choix);
		}while (choix!=1 && choix!=0);
	}
	
	affichage (tete);
	printf (" rah nzido corso semaa give me les info 3liha \n");
	printf("-2 la superficie de la ville \n");
	scanf("%f",&inf.super);
	printf("-3 le nombre d’habitants \n");
	scanf("%d",&inf.habitant);
	strcpy(inf.nom,"corso");
	printf("mchaw");
	enpiler(&tete,inf);
	printf (" annnnddd kizedna corso haylik kifch welat sayidati : \n");
	affichage(tete);
	printf("mor mana7ina la 3em ville sayidati :  \n ");
	supprime(&tete);
	affichage(tete);
	printf(" wdok suprimina g3 liybdw bel 'b' anisatii : \n");
	supprimeall(&tete);
	affichage(tete);
}
void affichage (PILE *tete){
	PILE *r;
	ville inf;
	init(&r);
	int i=1;
	while(!vide(tete)){
		depiler(&tete,&inf);
		printf ("-%d) la ville : %s |superficie: %.2f |nombre d'habitant :%d \n",i,inf.nom,inf.super,inf.habitant);
		enpiler(&r,inf);
		i++;
	}
	init(&tete);
	while (!vide(r)){
		depiler(&r,&inf);
		enpiler(&tete,inf);
	}
	
}
void supprime(PILE **tete){
	int i=1;
	PILE *r;
	ville inf;
	
	init(&r);
	while(!vide(*tete)){
		depiler(&(*tete),&inf);
		if (i!=3){
			
			enpiler(&r,inf);
		}
		i++;
		
	}
	init(&(*tete));
	while (!vide(r)){
		depiler(&r,&inf);
		enpiler(&(*tete),inf);
	}
}
void supprimeall(PILE **tete){
	
	PILE *r;
	ville inf;
	
	init(&r);
	while(!vide(*tete)){
		depiler(&(*tete),&inf);
		strlen(inf.nom);
		if ((inf.nom[0])!='b' && (inf.nom[0]!='B'))
			enpiler(&r,inf);
		
	}
	init(&(*tete));
	while (!vide(r)){
		depiler(&r,&inf);
		enpiler(&(*tete),inf);
	}
}
