#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void remplissage(int *tab,int n);
void affichage (int *tab ,int n);
int rechercher (int *tab,int n ,int val);
int main() {

	int *tab=(int *)malloc (sizeof(int));
	int n,pos,val;
	
	do{
		printf("donnez la taille de tableau :\n");
		scanf("%d",&n);
	}while (n<0);
	
	remplissage(tab,n);
	affichage(tab,n);
	printf ("veuiller entret la valeur val : \n");
	scanf("%d",&val);
	pos=rechercher(tab,n,val);
	if(pos==-1)
		printf ("la valeur n'existe pas!!\n");
	else
		printf("la position de cette valeur est : %d",pos);
}
void remplissage(int *tab,int n){
	int i;

	printf(" la taille est %d \n",n);
	for (i=0;i<n;i++){
		printf(" veuilliez entrer la valeur de la case %d :\n",i);
		scanf("%d",&tab[i]);
	}

}
void affichage(int *tab,int n){
	int i;
	
	printf (" le tableau : \n [");
	for (i=0;i<n;i++){
		printf("%d",tab[i]);
		printf("|");
	}
	printf ("]");
}
int rechercher (int *tab,int n,int val){
	int i=0,pos=-1;
	bool trouve=false;
	
	while (i<n&&trouve==false){
		if (tab[i]==val){
			trouve=true;
			pos=i;
		}
		i++;
	}
	return pos;
}
