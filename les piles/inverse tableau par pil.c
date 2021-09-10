#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "piles.h"
#include<time.h>
int main (){
	PILE *tete;
	int i,n;
	int *tab;
	do{
		printf(" taille t3 tableau  :\n");
		scanf("%d",&n);
	}while(n<0);
	tab=(int*)malloc(n*sizeof(int));
	srand(time(NULL));
	printf("{");
	for(i=0;i<n;i++){
		tab[i]=rand()%30;
		printf("%d |",tab[i]);
	}
	printf("}");
	init(&tete);
	for (i=0;i<n;i++){
		enpiler(&tete,tab[i]);
	}
	printf ("tableau ma9lob : \n [");
	while (!vide(tete)){
		depiler(&tete,&tab[i]);
		printf("%d |",tab[i]);
	}
	printf ("]");
	
}
