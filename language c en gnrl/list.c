#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef  struct element element;
struct element {
	int val;
	element *svt;
};


void remplissage (element **tete,int n);
void affichage (element *tete);
void lnlp(element *tete,element **ln ,element **lp);
int main (){
	
	element *tete;
	element *ln,*lp ,*p;
	
	int n;
	tete=NULL;
	do{
		printf(" aktb le nombre t3 les valeur lihab dkhlhm svp : \n");
		scanf("%d",&n);
	}while (n<=0);
	remplissage(&tete,n);
	affichage(tete);
	printf("\n");
	lnlp(tete,&ln,&lp);
	p=ln;
	printf(" [ ");
	while (p!=NULL){
		printf("%d |",p->val);
		p=p->svt;
	}
	p=lp;
	while (p!=NULL){
		printf("%d |",p->val);
		p=p->svt;
	}
	printf("]");

}
void remplissage (element **tete,int n){
	element *p,*q;
	int i;
	
	for(i=0;i<n;i++){
		p=(element*)malloc (sizeof(element));
		printf(" entrer la %d valeur \n",i+1);
		scanf("%d",&p->val);
		p->svt=NULL;
		if(*tete==NULL){
			*tete=p;
		}
		else{
			q->svt=p;
		}
		q=p;
	}
}
void affichage(element *tete){
	
	element *p;
	p=tete;
	printf(" haylik la liste : \n [");
	while (p!=NULL){
		printf("%d |",p->val);
		p=p->svt;
	}
	printf("]");
}
void lnlp(element *tete,element **ln,element **lp){
	element *p;
	element *lnp,*lpp,*lnq,*lpq;
	*ln=NULL;
	*lp=NULL;
	p=tete;
	while (p!=NULL){
		if(p->val>0){
			lpp=(element*)malloc(sizeof(element));
			lpp->val=p->val;
			lpp->svt=NULL;
			if (*lp==NULL){
				*lp=lpp;
			}
			else{
				lpq->svt=lpp;
			}
			lpq=lpp;
		}
		else if(p->val<0){
			lnp=(element*)malloc(sizeof(element));
			lnp->val=p->val;
			lnp->svt=NULL;
			if (*ln==NULL){
				*ln=lnp;
			}
			else{
				lnq->svt=lnp;
			}
			lnq=lnp;
		}
		p=p->svt;
	}
		

}
