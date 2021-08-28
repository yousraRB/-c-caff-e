#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
typedef struct element element;
struct element{
	int val;
	element *svt;
};

void remplissage( element **tete,int n  );
void affichage (element *tete );
bool verifie (element *tete);
bool trouve( element * tete,int val);
void inserer (element **tete,int val);
bool suppression (element **tete , int val);
int main (){
	int n,val;
	element *tete;
	bool vid;
	
	do{
	printf("donnez le nombre des valeur n :\n");
	scanf("%d",&n);
	}while (n<=0);
	remplissage(&tete,n);
	affichage (tete);
	vid=verifie(tete);
	if (vid==true)
		printf("la liste est vide \n");
	else
		printf("la liste n est pas vide \n");
	
	printf ("donnez la valeur n :\n");
	scanf("%d",&val);
	
	vid=trouve(tete,val);
	if (vid==true)
		printf("la valeur est existe \n");
	else
		printf("la valeur n existe pas \n");
	
	printf ("donnez la valeur  que vus voulez l inserer  :\n");
	scanf("%d",&val);
	inserer(&tete,val);
	affichage (tete);
	
	printf ("donnez la valeur  que vus voulez supprimer :\n");
	scanf("%d",&val);
	vid=suppression(&tete,val);
	if (vid==false)
		printf ("cette valeur n exsiste pas : \n");
	else 
		affichage(tete);
	return 0;
}
void remplissage(element **tete ,int n){
	element *p,*q;
	int i;
	
	*tete=NULL;
	
	for (i=0;i<n;i++){
		p=(element*)malloc (sizeof (element));
		printf("donnez une valeur : \n ");
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
void affichage (element *tete){
	element *p;
	
	p=tete;
	while (p!=NULL){
		printf("%d | ",p->val);
		p=p->svt;
	}
	
}
bool verifie (element *tete){
	
	return  (tete==NULL);
}
bool trouve( element * tete,int val){
	bool tro=false;
	
	while (tete!=NULL&&tro==false){
		if (tete->val==val)
			tro=true;
		
		tete=tete->svt;
	}
	return tro;
}
void inserer (element **tete,int val){
	element *p,*pr,*q;
	bool trouve=false;
	
	p=*tete;
	pr=NULL;
	
	while (p!=NULL&&trouve==false) {
		if (p->val<val){
			pr=p;
			p=p->svt;
		}
		else {
			trouve=true;
		}
	}
	q=(element*)malloc (sizeof(element));
	q->val=val;
	if(p==*tete){
		q->svt=*tete;
		*tete=q;
	}
	else {
		q->svt=p;
		pr->svt=q;
	}
}
bool suppression (element **tete , int val){
	bool trouve=false;
	element *p ,*pr;
	
	p=*tete;
	while (p!=NULL&& trouve ==false){
		if (p->val==val){
			trouve=true;
		}
		else {
			pr=p;
			p=p->svt;
		}
			
	}	
	if (p==*tete){
		*tete=p->svt;
		free(p);
	}
	else {
		pr->svt=p->svt;
		free(p);
	}
	return trouve;
}
	

	
	
	

