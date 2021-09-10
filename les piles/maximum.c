#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "piles.h"
#include<time.h>
void affichage (PILE *tete);
void supprime (PILE **tete,int val);
int max (PILE *tete);
int min (PILE *tete);
int main (){
	int i,nbr;
	PILE *tete;
	
	srand(time(NULL));
	init(&tete);
	
	for(i=0;i<5;i++){
		nbr=rand()%30;
		enpiler(&tete,nbr);
	}
	affichage (tete);
	printf("la valeur lihab tsuprimiha : \n");
	scanf("%d",&nbr);
	supprime(&tete,nbr);
	printf ("hawlik suprisentk \n");
	affichage (tete);
	nbr=max(tete);
	printf (" lmaximum f hed la pile is %d \n",nbr);
	printf("*lisatatk* \n");
	affichage (tete);
	nbr=min(tete);
	printf("hwlik sghayarr fihom : %d \n",nbr);
	printf("*lisatatk* \n");
	affichage (tete);
	
}
void affichage (PILE *tete){
	PILE *r;
	int val;
	
	init(&r);
	while (!vide(tete)){
		depiler(&tete,&val);
		printf("%d \n",val);
		enpiler (&r,val);
	}
	init(&tete);

	while (!vide(r)){
		depiler(&r,&val);
		enpiler (&tete,val);
	}
	
}
void supprime (PILE **tete,int val){
	PILE *r;
	int sup;
	
	init (&r);
	while (!vide(*tete)){
		depiler(&(*tete),&sup);
		if (sup!=val){
			enpiler(&r,sup);
		
		}
	}
	init (&(*tete));
	while(!vide(r)){
		depiler(&r,&sup);
		enpiler(&(*tete),sup);
	}
}
int max (PILE *tete){
	PILE *r;
	int val , max;
	init (&r);
	depiler(&(tete),&max);
	enpiler(&r,max);
	while (!vide(tete)){
		depiler(&(tete),&val);
		enpiler (&r,val);
		if (val >max)
			max=val;
	}
	init (&tete);
	while (!vide(r)){
		depiler(&r,&val);
		enpiler(&tete,val);
	}
	return max;
}
int min (PILE *tete){
	PILE *r;
	int val,min;
	init(&r);
	depiler(&tete,&min);
	enpiler(&r,min);
	while(!vide(tete)){
		depiler(&tete,&val);
		enpiler(&r,val);
		if(val<min)
			min=val;
	}
	init (&tete);
	while(!vide(r)){
		depiler(&r,&val);
		enpiler(&tete,val);
	}
	return min;
}
