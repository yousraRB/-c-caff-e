#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"file.h"
void remplissage(FILEs *tete,int n);
void affichage (FILEs tete);
bool rechercher(FILEs tete,int val);
void supprime (FILEs *tete,int val );
void inseri (FILEs *tete ,int pos,int val);
void fus(FILEs tete, FILEs you ,FILEs *fusi);
int main (){
	int n,pos;
	bool trouve;
	FILEs tete;
	FILEs you;
	FILEs fusi;
	
	init(&tete);
	do{

		printf("lfile dyalk chhal dir fiha mn valeur ? \n");
		scanf("%d",&n);
	}while (n<=0);
	remplissage(&tete,n);
	printf(" aywaah : \n");
	affichage(tete);
	printf("printf la valeur lirh tverifyiha \n");
	scanf("%d",&n);
	if (rechercher(tete,n)==true){
		printf("l9itha \n");
	}
	else{
		printf(" 7awil mojadadan \n");
	}
	do{
	printf("medli la valeur lirak hab tsuprimiha il faut tkon tgzizti \n");
	scanf("%d",&n);
	}while(rechercher(tete,n)==false);
	
	supprime(&tete,n);
	affichage(tete);
	printf("medli la valeur wlposition lihab dirha fiha : \n valeur: \n");
	scanf("%d",&n);
	printf ("pos : \n");
	scanf("%d",&pos);
	inseri(&tete,pos,n);
	affichage(tete);
	init(&you);
	do{

		printf("lfile 2em chhal dir fiha mn valeur ? \n");
		scanf("%d",&n);
	}while (n<=0);
	remplissage(&you,n);
	affichage (tete);
	affichage(you);
	printf(" mor lmix : \n");
	fus(tete,you,&fusi);
	affichage(fusi);

}
void remplissage (FILEs *tete,int n){
	int i,val;
	printf ("bismilah nebdaw n3mroha  b %d valeur \n",n);
	for(i=0;i<n;i++){
		printf("aktb la valeur  numero *%d* \n",i+1);
		scanf("%d",&val);
		enfiler(&(*tete),val);
	}
}
void affichage (FILEs tete){
	int val;
	FILEs r;
	init (&r);
	printf("[");
	while (!vide(tete)){
		defiler(&tete,&val);
		printf("%d |",val);
		enfiler(&r,val);
	}
	printf("] \n");
	init(&tete);
	while(!vide(r)){
		defiler(&r,&val);
		enfiler(&tete,val);
	}
}
bool rechercher(FILEs tete,int val){
	int val2;
	bool trouve=false;
	FILEs r;
	init(&r);
	while(!vide(tete)){
		defiler(&tete,&val2);
		enfiler(&r,val2);
		if(val==val2){
			trouve=true;
		}
	}
	init(&tete);
	while (!vide(r)){
		defiler(&r,&val2);
		enfiler(&tete,val2);
	}
	return trouve;
}
void supprime (FILEs *tete,int val){
	FILEs r;
	int val2;
	
	init(&r);
	while (!vide(*tete)){
		defiler(&(*tete),&val2);
		if (val2!=val){
			enfiler(&r,val2);
		}	
	}
	init(&(*tete));
	while (!vide(r)){
		defiler(&r,&val2);
		enfiler(&(*tete),val2);
	}
	
}
void inseri(FILEs *tete, int pos , int val){
	FILEs r;
	bool trv=false;
	int cpt=1;
	int vale;
	init(&r);
	while(!vide(*tete)){
		defiler(&(*tete),&vale);
		if (cpt!=pos){
			enfiler(&r,vale);
		}
		else{
			trv=true;
			enfiler(&r,val);
			enfiler(&r,vale);
		
		}
		cpt++;
	}
	if(trv==false ){
		enfiler(&r,val);
	}
	init(&(*tete));
		while (!vide(r)){
		defiler(&r,&vale);
		enfiler(&(*tete),vale);
	}
	
}
void fus(FILEs tete, FILEs you ,FILEs *fusi){
	FILEs r;
	int val, nbr;
	defiler(&tete,&val);
	defiler(&you,&nbr);
	init(&(*fusi));
	while(!vide(tete) || !vide(you)){
		if(nbr<val){
			enfiler(&(*fusi),nbr);
			defiler(&you,&nbr);
		}
		else{
			enfiler(&(*fusi),val);
			defiler(&tete,&val);
		}
		
	}
	if(nbr<val){
		enfiler(&(*fusi),nbr);
		enfiler(&(*fusi),val);
	}
	else{
		enfiler(&(*fusi),val);
		enfiler(&(*fusi),nbr);
	}
}
