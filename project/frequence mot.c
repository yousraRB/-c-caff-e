/**
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct mo {
	char mot[30];
	int nbr;
};
typedef struct mo mo;

bool verifier (mo tab[100],int n,char mot[30]);
void modifier (int nbr,mo tab[100],int n,char mot[30]);
void afficher (FILE *f);
void fichier ();

int main (){
	mo m;
	mo tab[100];
	int i,n;
	char mot[30];
	int choix ,nbr;
	bool trouve;
	FILE *f;
	
	
	
	while (1){
		printf("voila votre menu \n");
		printf ("-1 pour verfier si un mot est existe deja \n");
		printf ("-2 pour mettre à jours le nombre d’apparition d’un mot \n ");
		printf ("-3 pour Afficher le mot le plus frequent dans le fichier \n ");
		printf ("-4 pour afficher tout le fichier \n");
		printf(" -5 pour remplire le fichier \n");
		printf ("-6 exit \n ");
		printf ("veuilliez entrer votre choix \n");
		scanf("%d",&choix);
		switch(choix){
			case 1:
				printf ("entrer le mot que vous voulez verifier :\n");
				scanf (" %s",mot);
				trouve=verifier(tab,n,mot);
				if (trouve==true)
					printf ("le mot est existe dans le tableau \n");
				else
					printf (" le mot n' existe pas !! \n");
			break;
			case 2:
				printf ("entrer le mot que vous voulez modifier son nombre\n");
				scanf(" %s",mot);
				printf ("entrer le nouveau nombre d'apparition \n");
				scanf("%d",&nbr);
				modifier (nbr,tab,n,mot);
			break;
			case 3:
				afficher (f);
			break;
			case 4 :
				fichier ();
			break;
			case 5:
				
				printf ("veuillez entrer le nombre de mots : \n");
				scanf ("%d",&n);
				f=fopen("analyse.txt","a");
	
				for (i=0;i<n;i++){
					printf (" donnez le mot numbre %d :",i);
					scanf(" %s",m.mot);
					printf (" donnez son nombre d'apparition \n'");
					scanf ("%d",&m.nbr);
					fwrite(&m,sizeof(mo),1,f);
				}
				fclose (f);
				f=fopen("analyse.txt","r");
				i=0;
				while (fread(&m,sizeof(mo),1,f)){
				tab[i]=m;
				i++;
				}
				fclose (f);
			break;
			
			default : (exit);
				
		}
	}
	return 0;
}
bool verifier (mo tab[100], int n,char mot[30]){
	int i=0;
	bool trouve=false;
	
	while (i<n && trouve==false){
		
		if ( strcmp (tab[i].mot,mot)==0){
			trouve=true;
			
		}
		i++;
	}
	return trouve;
}
void modifier (int nbr,mo tab[100], int n,char mot[30]){
	int i=0;
	FILE *f;
	FILE *g;
	mo m;

	
	f=fopen("analyse.txt","r");
	g=fopen ("analyse.txt","w");
	while (fread(&tab[i],sizeof(mo),1,f)){
		if (strcmp(mot,tab[i].mot)==0){
			tab[i].nbr=nbr;
			fwrite(&tab[i],sizeof(mo),1,g);
		}
		else {
			fwrite(&tab[i],sizeof(mo),1,g);
		}
		i++;
	}
	fclose(f);
	fclose(g);
	f=fopen("analyse.txt","w");
	g=fopen ("analyse.txt","r");
	i=0;
	while (fread(&tab[i],sizeof(mo),1,g)){
		fwrite(&tab[i],sizeof(mo),1,f);		
	}
	fclose(f);
	fclose(g);
}
void afficher (FILE *f){
	mo m;
	int max=0;
	bool trouve;
	
	f=fopen("analyse.txt","r");
	while (fread(&m,sizeof(mo),1,f)){
		if (m.nbr>max)
		max=m.nbr;
	}
	fclose (f);
	
	f=fopen("analyse.txt","r");
	while (fread(&m,sizeof(mo),1,f)&& trouve ==false){
		if (m.nbr==max){
			printf ("le mot le plus frequent dans le fichier est << %s>> \n",m.mot);
			trouve=true;
		}	
	}
	fclose(f);
}
void fichier (){
	FILE *f;
	mo m;
	
	f=fopen("analyse.txt","r");
	
	while (fread(&m,sizeof(mo),1,f)){
		printf("%s : %d \n",m.mot,m.nbr);
	}
	fclose(f);
}
