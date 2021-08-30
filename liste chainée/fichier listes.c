#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct moyenne moyenne ;

struct moyenne{
	float moy;
	moyenne *svt;
	
};
void creel(moyenne **tete);
void affichage(moyenne *tete);
void supprime (moyenne **tete,float val);
int main (){
	FILE *f;
	FILE *g;
	moyenne *tete;
	float val;
	
	creel(&tete);
	affichage (tete);
	printf("  \n veuillier entrer la valeur \n");
	scanf("%f",&val);
	supprime (&tete,val);
	affichage(tete);
}
void creel(moyenne **tete){
	FILE *f;
	FILE *g;
	char i[10],j[10];
	moyenne *p,*q;
	float moy,nb1,nb2;
	
	f=fopen("pair.txt","r");
	g=fopen("impair.txt","r");
	*tete=NULL;
	
	while (!feof(f)&&!feof(g)){
		fgets(i,10,f);
		strtok(i,"\n");
		fgets(j,10,g);
		strtok(j,"\n");
		nb1=atof(i);
		nb2=atof(j);
		printf ("%f | %f  \n",nb1,nb2);
		moy=(nb1+nb2)/2;
		p=(moyenne*)malloc(sizeof(moyenne));
		p->moy=moy;
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
void affichage(moyenne *tete){
	moyenne *p;
	p=tete;
	while(p!=NULL){
		printf ("%.2f",p->moy);
		printf ("\n");
		p=p->svt;
	}
}
void supprime (moyenne **tete,float val){
	moyenne *p,*pr;
	p=*tete;
	pr=NULL;
	while (p!=NULL){
		if (p->moy<val){
			if(p==*tete){
				*tete=(*tete)->svt;
				free(p);
				p=*tete;
			}
			else{
				pr->svt=p->svt;
				free(p);
				p=pr->svt;
			}
		}
		else{
			pr=p;
			p=p->svt;
		}
	}
}
