#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "piles.h"


void remplissage (PILE **tete,int n,int j);
void affichage (PILE *tete);
float moy (PILE *tete,PILE *cof);
int main (){
	PILE *tete,*cof;
	int n,j;
	float moye;
	tete=NULL;
	do{
	printf(" chhal kyn mn valeur f la liste \n");
	scanf("%d",&n);
	}while(n<=0);
	j=1;
	remplissage (&tete,n,j);
	affichage (tete);
	j=2;
	cof=NULL;
	remplissage (&cof,n,j);
	affichage(cof);
	moye=moy(tete,cof);
	printf (" la moyenne is : %.2f",moye);
	
	
	
}
void remplissage (PILE **tete ,int n,int j){
	int x,cof,i;
	for(i=0;i<n;i++){
		printf(" la valeur *%d* de la liste %d : \n ",i+1,j);
		scanf ("%d",&x);
		enpiler(&(*tete),x);
	}
}
void affichage (PILE *tete){
	int val;
	PILE *r;
	
	init(&r);
	printf(" [");
	while (!vide(tete)){
		depiler(&tete,&val);
		printf("%d |",val);
		enpiler (&r,val);
	}
	printf("]\n");
	init(&tete);

	while (!vide(r)){
		depiler(&r,&val);
		enpiler (&tete,val);
	}
	
}
float moy (PILE *tete,PILE *cof){
	PILE *r ,*cofr;
	int val,cofe,cpt=0;
	float som=0;
	init(&cofr);
	init (&r);
	while (!vide(tete)){
		depiler(&tete,&val);
		depiler(&cof,&cofe);
		cpt=cpt+cofe;
		som=som+val*cofe;
		enpiler(&r,val);
		enpiler(&cofr,cofe);
	}
	init(&tete);
	init(&cof);
	
	while (!vide(r)){
		depiler(&r,&val);
		enpiler(&tete,val);
		depiler(&cofr,&cofe);
		enpiler(&cof,cofe);
	}
	return som/cpt;
}
