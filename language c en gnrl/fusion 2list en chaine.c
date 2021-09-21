#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct element element ;
struct element {
	int val;
	element *svt;
	
};
void affichage(element *tete);
int main (){
	FILE *f;
	int var ,var2;
	element *tete,*q,*p1;
	FILE *p;
	bool trv;
	
	f=fopen("fichier1.txt","r");
	char val[20];
	tete=NULL;
	while (fgets(val,20,f)){
		strtok(val,"\n");
		
		var=atoi(val);
		p1=(element*)malloc(sizeof(element));
		p1->val=var;
		p1->svt=NULL;
		if(tete==NULL){
			tete=p1;
		}
		else {
			q->svt=p1;
		}
		q=p1;
	}
	fclose(f);
	p=fopen("fichier2.txt","r");
	while (fgets(val,20,p)){
		strtok(val,"\n");
		var=atoi(val);
		trv=false;
		f=fopen("fichier1.txt","r");
		while(fgets(val,20,f)&& trv==false){
			strtok (val,"\n");
			var2 =atoi(val);
			if(var==var2){
				trv=true;
			}
		}
		fclose(f);
		if(trv==false){
			p1=(element*)malloc(sizeof(element));
			p1->val=var;
			p1->svt=NULL;
			q->svt=p1;
			q=p1;
		}
	}
	fclose(p);
	affichage(tete);
}
void affichage(element *tete){
	element *p;
	p=tete;
	printf("[ ");
	while (p!=NULL){
		printf("%d |",p->val);
		p=p->svt;
	}
	printf("]");
}
