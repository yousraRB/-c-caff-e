#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct element element;
struct element {
	int val;
	element *svt;
};
void remplissage (element **tete,int n);
void affichage (element *tete);
int indice (element *tete);
int main (){
	element *tete;
	tete=NULL;
	int n,ind;
	
	do{
		printf(" list chhal fiha mn valeur ? \n");
		scanf("%d",&n);
	}while(n<=0);
	
	remplissage(&tete,n);
	affichage (tete);
	ind =indice(tete);
	printf (" indice mxim est : %d \n",ind);
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
void affichage (element *tete){
	
	element *p;
	p=tete;
	printf("[ ");
	while (p!=NULL){
		printf("%d |",p->val);
		p=p->svt;
	}
	printf("]");
}
int indice (element *tete){
	int imx,i=1 ,max ;
	element *p;
	p=tete;
	imx=1;
	max=p->val;
	p=p->svt;
	while (p!=NULL){
		i=i+1;
		if ((p->val)>max){
			imx=i;
			max=p->val;
		}
		p=p->svt;
	}
	return imx;
}
