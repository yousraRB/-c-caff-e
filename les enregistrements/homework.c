#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct tetudiant {
	int num;
	int age;
	char matricul[50];
	char nom[50];
	char prenom[50];
	float moy;
	char result[5];
};
typedef struct tetudiant tetudiant;
void saisir ( int n, tetudiant *e);
void affichage (int n, tetudiant e[100]);

int main(){
	int n;
	tetudiant tab [100];
	do {
	printf ("donnez le numéro des etudiant n : \n");
	scanf("%d",&n);
}while (n<0 || n>100);

	saisir (n,tab);
	affichage  (n,tab);
	return 0;
}
void saisir ( int n, tetudiant *tab){
	int i;
	
	for (i=1;i<=n;i++){
	tab[i].num=i;
	printf( " veuilliez enter le matricule d'etudiant numéro %d :\n",i);
	scanf (" %s",tab[i].matricul);
	printf( " veuilliez enter le nom d'etudiant numéro %d :\n",i);
	scanf (" %s",tab[i].nom);
	printf( " veuilliez enter le prenom d'etudiant numéro %d :\n",i);
	scanf (" %s",tab[i].prenom);
	printf( " veuilliez enter la moyenne  d'etudiant numéro %d :\n",i);
	scanf ("%f",&tab[i].moy);
	do {	
	printf( " veuilliez enter l'age ' d'etudiant numéro %d :\n",i);
	scanf ("%d",&tab[i].age);
	}while (tab[i].age <16 || tab[i].age >70 );
	
		if (tab[i].moy>=10)
		strcpy ( tab[i].result,"ADM");
		else 
		strcpy (tab[i].result,"AJN");
	}
}
void affichage (int n, tetudiant e[100]){
	int i;
	
	
	for (i=1;i<=n;i++){
		
		printf ( "etudiant numero %d : \n *nom : %s \n *prenom : %s \n *age : %d \n *matricule : %s \n *moyenne : %.2f \n *resultat:%s \n\n\n ",i,e[i].nom,e[i].prenom,e[i].age,e[i].matricul,e[i].moy,e[i].result);
	}
}
