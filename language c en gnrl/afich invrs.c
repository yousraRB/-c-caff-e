#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include"piles.h"

typedef struct element element;
struct element {
	int val;
	element *svt;
};
void remplissage (element **tete,int n);
void affichage (PILE *tete);
void affiche (element *tete);
void creepil(element *tete,PILE **tet);
int main (){
	element *tete;
	PILE *tet;
	
	tete=NULL;
	

	int n,ind;
	
	do{
		printf(" list chhal fiha mn valeur ? \n");
		scanf("%d",&n);
	}while(n<=0);
	
	remplissage(&tete,n);
	affiche (tete);
	creepil(tete,&tet);
	affichage (tet);
}
void remplissage(element **tete,int n){
	int i,val;
	element *p,*q;
	
	for(i=0;i<n;i++){
		p=(element*)malloc(sizeof(element));
		printf("  entrer la valeur %d de la list : \n",i+1);
		scanf("%d",&val);
		p->val=val;
		p->svt=NULL;
		if(*tete==NULL){
			*tete=p;
		}
		else {
			q->svt=p;
		}
		q=p;	
	}
}
void affichage (PILE *tet){
	int val;
	printf(" [");
	
	while(!vide(tet)){
		depiler(&tet,&val);
		printf("%d |",val);
		
	}
	printf("]");
}
void affiche (element *tete){
	element *p;
	p=tete;
	printf("[ ");
	while (p!=NULL){
		printf("%d |",p->val);
		p=p->svt;
	}
	printf("]");
}
void creepil(element *tete,PILE **tet){
	int val;
	element *p;
	p=tete;
	init(&(*tet)); 
	
	while (p!=NULL){
		val=p->val;
		enpiler (&(*tet),val);
		p=p->svt;
	}
}
