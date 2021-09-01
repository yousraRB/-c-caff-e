#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct element element;
struct element{
	float note;
	int coe;
	element *svt;
};
typedef struct etudiant etudiant;
struct etudiant{
	char nom[50];
	char prenom[50];
	char mat[20];
	float moy;
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
void cree(etudiant *tete);
void triee ();
void nouveau ();
int main (){
	int n,choix;
	etudiant *tete ;
	FILE *f;
	FILE *g;
	printf ("*welcom:)* \n");
	while (1){
		printf("1-remplissage \n");
		printf("2-affichage \n");
		printf("3-calculer et mettre à jour le champ moy de chque etudiant :\n");
		printf("4-créer un fichier contenant que les étudiants \n");
		printf("5-trier le fichier en ordre décroissant avec affichage\n");
		printf("6-créer un nouveau fichier contenant que les 50 Prsn premiers étudiants\n \n");
		printf("0-exit \n");
		printf("veuilliez entrer votre choix :\n");
		scanf("%d",&choix);
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
				cree(tete);
			break;
			case 5: 
				triee ();
			break;
			case 6:
				nouveau ();
				
			break;
			default :exit (0);
		}
		
		
	}
	
}
void remplissage (int n,etudiant **tete){
	int i,j,nb,cof;
	etudiant *p,*q ;
	element *a , *b;
	*tete =NULL;
	float moy;
	
	for (i=0;i<n;i++){
		p=(etudiant*)malloc (sizeof(etudiant));
		printf ("veuilliez entrer les information d etudiant %d : \n",i+1);
		printf ("le nom : \n");
		scanf(" %s",p->nom);
		printf (" le prenom : \n");
		scanf (" %s",p->prenom);
		printf (" le matricule : \n");
		scanf(" %s",p->mat);
		printf (" donner le nombre de module d etudiant %d : \n",i+1);
		scanf("%d",&nb);
		p->eval=NULL;
		moy=0;cof=0;
		for(j=0;j<nb;j++){
			a=(element *)malloc (sizeof (element));
			printf(" la note de  module %d : \n",j+1);
			scanf("%f",&a->note);
			printf (" coefficient de ce module : \n");
			scanf("%d",&a->coe);
			moy=moy+a->note*a->coe;
			cof=cof +a->coe;
			a->svt=NULL;
			if (p->eval==NULL){
				p->eval=a;
			}
			else {
				b->svt=a;
			}
			b=a;
		}
		if(cof!=0)
			p->moy=moy/cof;
		else
			p->moy=0;
		p->svt=NULL;
		if (*tete==NULL){
			*tete=p;
		}
		else {
			q->svt=p;
		}
		q=p;
	}
	
}
void affichage (etudiant *tete){
	etudiant *p;
	int i,j=1;
	p=tete;
	element *a;
	while (p!=NULL){
		printf(" %d)-|nom:%s|preom:%s|mat:%s|moy:%.2f| __",j,p->nom,p->prenom,p->mat,p->moy);
		a=p->eval;
		i=0;
		while (a!=NULL){
			printf (" note %d :%.2f|coefficent :%d __",i+1,a->note,a->coe);
			a=a->svt;
		}
		printf("\n");
		p=p->svt;
		j=j+1;
		
	}
}
void calcule(etudiant **tete){
	etudiant *p;
	float s;
	int cof;
	int i=0;
	
	p=*tete;
	element *a;
	while(p!=NULL){
		s=0;cof=0;
		printf ("mise a jour la moyenne de * %s  %s * \n",p->nom,p->prenom);
		
		a=p->eval;
		
		while (a!=NULL)	{
			printf ("donnez la nouvelle note de module %d :\n",i+1);
			scanf("%f",&a->note);
			s=s+a->note*a->coe;
			cof =cof+a->coe;
			a=a->svt;
			i=i+1;
		}
		p->moy=s/cof;
		p=p->svt;
	}
}
void cree(etudiant *tete){
	etudiant *p;
	etudiante e;
	FILE *f;
	int j;
	f=fopen("etudiant.txt","a");
	p=tete;
	while (p!=NULL){
		strcpy (e.nom,p->nom);
		strcpy(e.prenom,p->prenom);
		strcpy(e.mat,p->mat);
		e.moy=p->moy;
		fwrite(&e,sizeof(etudiante),1,f);
		p=p->svt;
	}
	fclose (f);j=1;
	f=fopen("etudiant.txt","r");
	while(fread(&e,sizeof(etudiante),1,f)){
		printf(" %d)-|nom:%s|preom:%s|mat:%s|moy:%.2f| \n",j,e.nom,e.prenom,e.mat,e.moy);
		j=j+1;
	}
	fclose(f);
}
void triee (){
	etudiante *t=(etudiante *)malloc (100 * sizeof(etudiante));
	int n=0,i,j;
	etudiante e;
	FILE *f;
	float moy,x;
	
	f=fopen("etudiant.txt","r");
	while (fread(&e,sizeof(etudiante),1,f)){
		t[n]=e;
		n=n+1;
	}
	fclose (f);
	
	for (i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
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
	fclose(f);

}
void nouveau (){
	FILE *f,*g;
	etudiante e;
	int n=0,i=0,j;
	
	f=fopen("etudiant.txt","r");
	while(fread(&e,sizeof(etudiante),1,f)){
		n=n+1;
	}
	fclose (f);
	f=fopen("etudiant.txt","r");
	g=fopen("etudiante.txt","w");
	while(fread(&e,sizeof(etudiante),1,f) && i<n/2 ){
		fwrite(&e,sizeof(etudiante),1,g);
		i=i+1;
	}
	fclose (g);
	fclose(f);
	
	g=fopen("etudiante.txt","r");
	printf ("*affichage 50 % * : \n");
	j=1;
	while(fread(&e,sizeof(etudiante),1,f)){
	
		printf(" %d)-|nom:%s|preom:%s|mat:%s|moy:%.2f| \n",j,e.nom,e.prenom,e.mat,e.moy);
		j=j+1;
	}
	
	fclose(g);
}
