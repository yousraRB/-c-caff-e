#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct contact {
	int pos;
	char nom[30];
	char prn[30];
	char tel[30];
};
typedef struct contact contact;

void afficher (FILE *f);
int compteur(FILE *f);
void ajoutFin(contact c, FILE * f);
void rechercheContact(char nom[30], char prenom [30], FILE * f);
void ContactaccesDirect(int numero, FILE * f) ;
void modifienum(FILE *f,char nom[30],char prenom[30],char tel[30]);

int main (){
	int n,i,choix,cpt;
	float taille;
	FILE *f;
	contact c;
	char nom[30];
	char prenom[30];
	char tel [30];
	
	printf(" veuilliez entrer le nombre de votre contact:  \n");
	scanf("%d",&n);
	
	f=fopen("annuaire.dat","a");
	for(i=0;i<n;i++){
		
		printf("* veuilliez entrer les information du contact numero %d * \n le nom: \n ",i+1);
		scanf(" %s",c.nom);
		printf(" le prenom : \n");
		scanf(" %s",c.prn);
		printf(" le numero de telephone: \n");
		scanf(" %s",c.tel);
		c.pos=i+1;
		fwrite(&c,sizeof(contact),1,f);
	}
	fclose(f);
	
	
	while (1){
		printf(" *votre menue*\n");
		printf("-1 pour afficher tous les contacts \n");
		printf("-2 pour calculer la taille du fichier en octets \n");
		printf("-3 pour calculé le nombre de contacts qui ont deja engistre \n");
		printf("-4 pour ajouter un neveau contact \n");
		printf("-5 pour afficher les information et le num d'un contact \n");
		printf("-6 pour rechercher un contact par son ordre \n");
		printf("-7 pour modifier un numero de tlfn d'un contact \n");
		printf("-8 exit\n");
		printf (" veuilliez entrer votre choix svp : \n");
		scanf("%d",&choix);
		switch (choix) {
			case 1:
				printf (" la liste des contact est : \n");
				afficher(f);
			break;
			case 2:
				f=fopen("annuaire.dat","r");
				fseek(f,0L,SEEK_END);
				taille=ftell(f);
				printf("taille du fichier en octets est : %.2f \n ",taille);
				fclose(f);
			break;
			case 3:
				cpt=compteur(f);
				printf ("le nombre de contacts qui ont deja engistre est : %d",cpt);
			break;
			case 4:	
				printf("* veuilliez entrer les information du contact que vous voulez l'ajouter \n le nom: \n ");
				scanf(" %s",c.nom);
				printf(" le prenom : \n");
				scanf(" %s",c.prn);
				printf(" le numero de telephone: \n");
				scanf(" %s",c.tel);
				cpt=compteur (f);
				c.pos=cpt+1;
				ajoutFin(c,f);
			break;
			case 5:
				printf ("*veuilliez entrer le nom et le prenom de conact pour afficher son num* \n");
				printf ("le nom: \n");
				scanf(" %s",nom);
				printf ("le prenom: \n");
				scanf(" %s",prenom);
				rechercheContact(nom,prenom,f);
			break;
			case 6:
				printf( "veuilliez entrer la position *l'ordre*du contact : \n");
				scanf("%d",&cpt);
				ContactaccesDirect(cpt,f);
			break;
			case 7:
				printf ("*veuilliez entrer le nom et le prenom de conact que vous voulez son num* \n");
				printf ("le nom: \n");
				scanf(" %s",nom);
				printf ("le prenom: \n");
				scanf(" %s",prenom);
				printf (" le nouveau num : \n");
				scanf(" %s",tel);
				modifienum(f,nom,prenom,tel);
			break;
			default : (exit);	
			
			
		}
	}
	
}
void afficher(FILE *f){
	contact c;
	
	f=fopen("annuaire.dat","r");
	while(fread(&c,sizeof(contact),1,f)){
		printf ("[*position: %d |]*nom: %s |*prenom: %s|*numero: %s]",c.pos,c.nom,c.prn,c.tel);
		printf("\n");
	}
	fclose (f);
}
int compteur(FILE *f){
	contact c;
	int cpt=0;
	
	f=fopen("annuaire.dat","r");
	while(fread(&c,sizeof(contact),1,f)){
		cpt=cpt+1;
	}
	fclose (f);
	return cpt;
}
void ajoutFin(contact c, FILE * f){
	
	f=fopen("annuaire.dat","a");
	
	fwrite(&c,sizeof(contact),1,f);
	fclose (f);
}
void  rechercheContact(char nom[30], char prenom [30], FILE * f){
	contact c;		
	bool trouve;
	
	f=fopen("annuaire.dat","r");
	while (fread(&c,sizeof(contact),1,f)&& trouve==false){
		if(strcmp(nom,c.nom)==0&& strcmp(prenom,c.prn)==0){
			trouve=true;
			printf("  num : %s \n",c.tel);
		}
	}
	if (trouve==false)
		printf("contact introuvable \n");
	fclose (f);
}
void ContactaccesDirect(int numero, FILE * f) {
	contact c;
	bool trouve=false;
	
	f=fopen("annuaire.dat","r");
	while(fread(&c,sizeof(contact),1,f)&&trouve==false){
		if (c.pos==numero){
			trouve=true;
			printf("le nom du contact d'ordre %d est : %s  %s \n",c.pos,c.nom,c.prn);
		}
	}
	if(trouve==false){
		printf(" pas de contact dans cette position \n ");
	}
}
void modifienum(FILE *f,char nom[30],char prenom[30],char tel[30]){
	FILE *g;
	contact c;
	contact d;
	int pos;
	
	f=fopen("annuaire.dat","r");
	g=fopen("annuairemedia.dat","w");
	
	while (fread(&c,sizeof(contact),1,f)){
		if(strcmp(c.nom,nom)==0 && strcmp(c.prn,prenom)==0){
			pos=c.pos;
			
		}
		else 
		fwrite(&c,sizeof(contact),1,g);
	}
	fclose (f);
	fclose (g);
	f=fopen("annuaire.dat","w");
	g=fopen("annuairemedia.dat","r");
	
	while (fread(&c,sizeof(contact),1,g)){
		if(c.pos<pos){
			fwrite(&c,sizeof(contact),1,f);
		}
		else {
			d.pos=pos;
			strcpy(d.nom,nom);
			strcpy(d.prn,prenom);
			strcpy(d.tel,tel);
			fwrite (&d,sizeof(contact),1,f);
			fwrite (&c,sizeof(contact),1,f);
		}
		
	}
	fclose (f);
	fclose (g);
	
}
