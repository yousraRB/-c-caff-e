#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct client client;
struct client {
	int chmbr;
	int pens;
	bool pcn;
	client *svt;
};
void remplissage(client **tete);
void affichage (client *tete);
int facture ( client *tete,int num);
int main (){
	int choix ;
	client *tete;
	int f,num;
	
	while (1){
		printf("1- pour sauvgarder les information des clients \n");
		printf("2- pour affichier les information des clients \n");
		printf("3- pour afficher la facture d un client \n");
		printf("0- POUR EXIT \n");
		scanf("%d",&choix);
		switch (choix){
			case 1: 
				remplissage (&tete);
			break;
			case 2:
				affichage(tete);
			break;
			case 3 : 
				printf (" entrer le numero de la chambre pour calcule la facture : \n ");
				scanf("%d",&num);
				f=facture (tete,num);
				printf (" paiment totale est : %d \n",f);
			break;
			default : (exit);
		}
	
	}


}
void remplissage(client **tete){
	client *p;
	client *q;
	int i=1;
	*tete=NULL;
	while (i==1 ){
		p=(client*)malloc(sizeof(client));
		printf("veuillier entrer le numéro de la chmabre : \n");
		scanf("%d",&p->chmbr);
		printf(" veuillier entrer votre type de pension : \n");
		printf(" pour petit-déjeuner ==>1 \n");
		printf(" pour demi-pension ==>2 \n ");
		printf(" pour all-inclusif ==>3 \n");
		scanf("%d",&p->pens);
		printf (" entrer  *1 pour oui* ou * 0 pour non* pour le supplément accès piscine \n");
		scanf("%d",&i);
		p->pcn=i;
		p->svt=NULL;
		if (*tete==NULL){
			*tete=p;
			
		}
		else{
			q->svt=p;
			
		}
		q=p;
		printf ("tzid wla la chriki  ida hab tzid dakhal 1 machi hab 0 wlah ysahhel: \n");
		scanf("%d",&i);
	}
}
void affichage (client *tete){
	client *p;

	p=tete;
	while (p!=NULL){
		printf ("chambre : %d |type de pension : ",p->chmbr);
		
		if (p->pens==1)
			printf ("petit-déjeuner|");
		else if (p->pens==2)
			printf("demi-pension|");
		else
			printf ("all-inclusif|");
			
		if (p->pcn==1)
			printf("acces piscine : oui \n");
		else
			printf("acces piscine : non \n");
		
		p=p->svt;
	}	
}
int facture ( client *tete, int num){
	client *p;
	int f=0;
	bool trouve=false;
	p=tete;
	while (p!=NULL&& trouve==false){
		if(p->chmbr==num){
			trouve =true ;
			if (p->pens==1)
				f=f+3300;
			else if (p->pens==2)
				f=f+4500;
			else 
				f=f+6500;
			
			if (p->pcn==1)
				f=f+1500;	

		}
		p=p->svt;
	}
	return f;
}
