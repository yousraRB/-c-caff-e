#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "file.h"

void remplissage (FILEs *tete,int n);
void mode(FILEs tete);

int main  (){
	FILEs tete;
	int n;
	init (&tete);
	do{
		
		printf(" chhal kyn mn valeur hbb : \n");
		scanf("%d",&n);
	}while (n<=0);
	remplissage (&tete,n);
	mode(tete);
	
}
void remplissage (FILEs *tete,int n){
	int i,x;
	for (i=0;i<n;i++){
		printf (" la valeur %d : \n",i);
		scanf("%d",&x);
		enfiler(&(*tete),x);
	}
}
void mode(FILEs tete){
	FILEs r;
	FILEs k;
	int mod,val,nbmod ,nbocr,i=1,val2;
	mod=sommet(tete);
	val=mod;
	nbocr=1;
	nbmod=1;
	init (&k);
	
	while(!vide(tete)){
		
	
		defiler (&tete,&val);
		if (i==1)
			enfiler(&k,val);
			
		init(&r);
		nbocr=1	;;
	
		while(!vide(tete)){
			defiler(&tete,&val2);
			if(i==1)
				enfiler (&k,val2);
				
			if (val==val2){
				nbocr++;
			}
			else {
				enfiler(&r,val2);
			}
		}
		i++;
		if (nbocr>nbmod){
			nbmod=nbocr ;
			mod=val;
		}
		
		init (&tete);
	
		while (!vide(r)){
			
			defiler (&r,&val);
			enfiler (&tete,val);
			
		}
		
	}
	if (nbmod==1)
		printf(" pas de mod");
	else {
		while(!vide(k)){
	
			defiler (&k,&val);
			init(&r);
			nbocr=1;
	
			while(!vide(k)){
				defiler(&k,&val2);
				if (val==val2){
					nbocr++;
				}
				else {
				enfiler(&r,val2);
				}
			}
			if (nbocr==nbmod){
				printf("%d",val);
			}
		
			init (&k);
			while (!vide(r)){
				defiler (&r,&val);
				enfiler (&k,val);
			}
		}
	}

	
	
}
