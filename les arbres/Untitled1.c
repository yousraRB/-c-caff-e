#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node node ;
struct node {
	int val;
	node *fgch;
	node *fdrt;
};
void recherche (node **prec,node **p,int val);
void remplissage (node **racine ,int n);
void affichage (node *racine);
int main (){
	node *racine=NULL;
	int n;
	do{
		printf (" chal kyyn mn valeur : \n");
		scanf("%d",&n);
	}while(n<=0);
	remplissage(&racine,n);
	affichage (racine);
	
	
		
}
void recherche (node **prec,node **p,int val){
	while (*p!=NULL && (*p)->val!=val){
		*prec=*p;
		if ((*p)->val <val)
			*p=(*p)->fdrt;
		else 
			*p=(*p)->fgch;
	
	}
}
void remplissage (node **racine ,int n){
	int i,val;
	node *p,*prec;
	
	for (i=0;i<n;i++){
		printf (" medli la valeur *%d* :\n",i+1);
		scanf ("%d",&val);
		p=*racine;
		prec=NULL;
		recherche(&prec,&p,val);
		if (p!=NULL)
			printf (" la valeur tgzizti deja !");
		else{
			p=(node*)malloc(sizeof(node));
			p->val=val;
			p->fdrt=NULL;
			p->fgch=NULL;
			if(prec==NULL)
				*racine=p;
			else if (prec->val>val)
				prec->fgch=p;
			
			else 
				prec->fdrt=p;
		}		
		 
	}
}
void affichage (node *racine){
	
	
	if (racine!=NULL){
		affichage(racine->fgch);
		printf("%d|",racine->val);
		affichage(racine->fdrt);
	}

}
