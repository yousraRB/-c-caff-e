#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include"files.h"

int main (){
	FILEs tete;
	
	int i,nbr;
	
	srand(time(NULL));
	init (&tete);
	for(i=0;i<5;i++){
		nbr=rand()%30;
		enfiler(&tete,nbr);
	}
	while(!vide(tete)){
		defiler(&tete,&nbr);
		printf ("%d |",nbr);
	}
}
