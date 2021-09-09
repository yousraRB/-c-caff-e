#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "piles.h"
int compteur (PILE *tete);
int max (PILE *tete);
PILE* supprime(PILE *tete,int val);
int main (){
	
	PILE *tete;
	int i=0,val,choix=1,nbr;
	
	
	init (&tete);
	while (choix==1){
		printf (" dekhel la valeur %d \n",i);
		scanf ("%d",&val);
		enpiler(&tete,val);
		do{
			printf (" habit tzid valeur aktb 1 sinon kteb 0 \n");
			scanf("%d",&choix);
		}while (choix!=0 &&choix!=1);
		i++;
	}
	nbr=compteur(tete);
	printf ("lpile fiha %d valeur \n",nbr);
	
	nbr=max(tete);

	printf("lmaximum t3 lpile is %d \n",nbr);
	printf (" give me number lihabit tsuprimih \n");
	scanf ("%d",&nbr);
	tete=supprime (tete,nbr);
	printf (" kisuprimito : \n");
	while (!vide(tete)){
		depiler(&tete,&nbr);
		printf ("%d -|",nbr);
	}
}
int compteur (PILE *tete){
	int i=0;
	PILE *p;
	int val;
	p=tete;
	init (&tete);
	while (!vide(p)){
		i++;
		depiler(&p,&val);
		enpiler(&tete,val);
		
		
	}
	return i;
}
int max (PILE *tete){
	int max,val;
	PILE *p;
	p=tete;
	init(&tete);
	depiler(&p,&max);
	enpiler(&tete,max);
	
	while(!vide(p)){
		depiler(&p,&val);
		enpiler(&tete,val);
		if(val>max)
			max=val;
		printf("%d |%d \n",max,val);
	}
	return max;
}
PILE * supprime(PILE *tete,int val){
	int x;
	PILE *r;
	init (&r);
	while (!vide(tete)){
		depiler(&tete,&x);
		if(x!=val){
			enpiler(&r,x);
		}
	}
	init(&tete);
	while (!vide(r)){
		depiler(&r,&x);
		enpiler(&tete,x);
	}
	return tete;
}
