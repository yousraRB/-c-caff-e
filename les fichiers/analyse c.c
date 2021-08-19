#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct mo{
	char nom[30];
	int nbr;
};
typedef struct mo mo;

void affichage ();
void compteur (mo *tab,int *i);

int main (){
	mo tab[100];
	int i,j;
	
	affichage ();
	printf ("\n");
	compteur (tab,&i);
	printf (" le tableau : \n");
	
	for (j=0;j<i;j++){
		printf (" %s : %d \n",tab[j].nom,tab[j].nbr);
	}
	
	
	return 0;
}
void affichage (){
	FILE *f;
	char nom[30];
	
	f=fopen("analyse.txt","r");
	while (!feof (f)){
		fgets(nom,30,f);
		printf (" %s \n",nom);
	}
	fclose (f);
}
void compteur (mo *tab,int *i){
	int j ;
	char nom[30];
	bool trouve=false;
	int nbr;
	FILE *f;
	*i=0;
	f=fopen("analyse.txt","r");
	while(!feof (f)){
		fgets(nom,30,f);
		strtok(nom,"\n");
		j=0; trouve=false;
		while(j<*i&& trouve==false){
			if (strcmp(nom,tab[j].nom)==0){
				trouve=true;	
			}
			else
				j++;
		}
		if (trouve==false){
			
			strcpy(tab[*i].nom,nom);
			tab[*i].nbr=1;
			*i=*i+1;
		}
		else{
			tab[j].nbr=tab[j].nbr+1;
		}
	}
	fclose (f);
}
