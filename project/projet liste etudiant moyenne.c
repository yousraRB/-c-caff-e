#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct element element;
struct element{
	float note;
	int coe;
};
typedef struct etudiant etudiant;
struct etudiant{
	char nom[50];
	char prenom[50];
	char mat[20];
	float moy;
	int nb;
	element *eval;
	etudiant *svt;
	
};
struct etudiante {
	char nom[50];
	char prenom[50];
	char mat[20];
	float moy;
};
typedef struct etudiante etudiante ;
void remplissage (int n,etudiant **tete);
void affichage (etudiant *tete);
void calcule(etudiant **tete);
void cree(etudiant *tete,FILE *f);
void triee (FILE *f);
void nouveau (FILE *f,FILE *g);
int main (){
	int n,choix;
	etudiant *tete ;
	FILE *f;
	FILE *g;
	printf ("*welcom:)*");
	while (1){
		printf("1-remplissage \n");
		printf("2-affichage \n");
		printf("3-calculer et mettre à jour le champ moy de chque etudiant :\n");
		printf("4-créer un fichier contenant que les étudiants \n");
		printf("5-trier le fichier en ordre décroissant avec affichage\n");
		printf("6-créer un nouveau fichier contenant que les 50% premiers étudiants\n \n");
		printf("0-exit");
		printf("veuilliez entrer votre choix :\n");
		switch (choix){
			case 1:
				printf("veuilliez entrer le nombre des etudiants : \n");
				scanf("%d",&n);
				remplissage (n,&tete);
			break;
			case 2:
				affichage (tete);
			break;
			case 3: 
				calcule(&tete);
			break;
			case 4:
				cree(tete,f);
			break;
			case 5: 
				triee (f);
			break;
			case 6:
				nouveau (f,g);
				
			break;
			default :(exit);
		}
		
		
	}
	
	
	
	

	
	
}
void remplissage (int n,etudiant **tete){
	int i,j;
	etudiant *p,*q ;

	tete =NULL;
	
	for (i=0;i<n;i++){
		p=(etudiant*)malloc (sizeof(etudiant));
		printf ("veuilliez entrer les information d etudiant %d : \n",i+1);
		printf ("le nom : \n");
		scanf(" %s",p->nom);
		printf (" le prenom : \n");
		scanf (" %s",p->prenom);
		printf (" le matricule : \n");
		scanf(" %s",p->mat);
		printf ("la moyenne : \n");
		scanf(" %f",&p->moy);
		printf (" donner le nombre de module d etudiant %d : \n");
		scanf("%d",&p->nb);
		for(j=0;j<p->nb;j++){
			printf(" la note de  module %d : \n",i+1);
			scanf("%f",&p->eval->note);
			printf (" coefficient de ce module : \n");
			scanf("%d",&p->eval->coe);
		
		}
		p->svt=NULL;
		if (*tete==NULL){
			*tete=p;
		}
		else {
			q->svt=p;
		}
		p=q;
	}
	
}
void affichage (etudiant *tete){
	etudiant *p;
	int i,j=1;
	tete=p;
	while (p!=NULL){
		printf(" %d)-|nom:%s|preom:%s|mat:%s|moy:%.2f| ______",j,p->nom,p->prenom,p->mat,p->moy);
		for (i=0;i<(p->nb);i++){
			printf (" note %d :%.2f|coefficent : %d __",i+1,p->eval->note,p->eval->coe);
		}
		printf("\n");
		p=p->svt;
		j=j+1;
		
	}
}
void calcule(etudiant **tete){
	etudiant *p;
	float s;
	p=*tete;
	int cof;
	int i;
	
	while(p!=NULL){
		s=0;cof=0;
		printf ("mise a jour la moyenne de * %s  %s * \n",p->nom,p->prenom);
		for (i=0;i<p->nb;i++){
			printf ("donnez la nouvelle note de module %d :\n",i+1);
			scanf("%d",&p->eval->note);
			s=s+p->eval->note;
			cof=p->eval->coe;
		}
		p->moy=s/cof;
		p=p->svt;
	}
}
void cree(etudiant *tete,FILE **f){
	etudiant *p;
	etudiante e;
	
	f=fopen("etudiant.txt","a");
	p=tete;
	while (p!=NULL){
		strcpy (e.nom,p->nom);
		strcpy(e.prenom,p->prenom);
		strcpy(e.mat,p->mat);
		e.moy=p->moy;
		fwrite(&e,sizeof(etudiant),1,f);
	}
	fclose (f);

}
void triee (etudiant **tete,FILE *f){
	etudiante t[100];
	int i=0,n=1;
	etudiante e;
	float moy;
	
	f=fopen("etudiant.txt","r");
	while (fread(&e,sizeof(etudiant),1,f)){
		strcpy(e.nom,t[i].nom);
		strcpy(e.prenom,t[i].prenom);
		strcpy(e.mat,t[i].nom);
		t[i].moy=e.moy;
		i=i+1;
		n=n+1;
	}
	fclose (f);
	for (i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if (t[i].moy<t[j].moy){
				x=t[i].moy;
				t[i].moy=t[j].moy;
				t[j].moy=x;
			}
		}	
	}
	f=fopen("etudiant.txt","w");
	for (i=0;i<n;i++){
		fwrite(&t[i],sizeof(etudiante),1,f);
	}
	fclose(f);
	f=fopen("etudiant.txt","r");
	j=1;
	while(fread(&e,sizeof(etudiante),1,f)){
		printf(" %d)-|nom:%s|preom:%s|mat:%s|moy:%.2f| \n",j,e.nom,e.prenom,e.mat,e.moy);
		j=j+1;
	}
}
void nouveau (FILE *f,FILE *g){
	etudiante e;
	int n=0,i=0;
	
	f=fopen("etudiant.txt","r");
	while(fread(&e,sizeof(etudiante),1,f)){
		n=n+1;
	}
	fclose (f);
	f=fopen("etudiant.txt","r");
	
	
	while(fread(&e,sizeof(etudiante),1,f)){
		n=n+1;
	}
	fclose (f);
	f=fopen("etudiant.txt","r");
	g=fopen("etudiant.txt","w");
	while(fread(&e,sizeof(etudiante),1,f) && i<n/2 ){
		fwrite(&e,sizeof(etudiante),1,g);
		printf(" %d)-|nom:%s|preom:%s|mat:%s|moy:%.2f| \n",j,e.nom,e.prenom,e.mat,e.moy);
		i=i+1;
	}
	fclose (g);
	fclose(f);
	
	
	
	
}
