/**
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (){
	char mat[50][50];
	int i,j,nbr,l,n,m,k;
	char mot[50];
	
	printf (" veulliez entrer le nombre de ling svp: \n");
	scanf("%d",&n);
	printf (" veulliez entrer le nombre de colone svp: \n");
	scanf("%d",&m);
	printf (" veulliez entrer le nombre de mots svp: \n");
	scanf("%d",&nbr);
	
	
	printf ("*!<entrer la phrase ou bien le text mot par mot>!*\n");
	
	i=0; j=0;
	for(l=0;l<nbr;l++){
		printf (" veuilliez entre le %d mot  : \n",l);
		scanf (" %s",mot);
		k=0;
		while (i<n && k<strlen(mot)){
	    	while(k<strlen(mot) && j<m){
				mat[i][j]=mot[k];
				k++;
				j++;
			}
			if (j>=m){
				j=0;
				i++;
			}
		}
    }
    printf ( " votre matrice text est : \n");
    
	printf(" HOLA IS : %c \n",mat[0][3]);
	
	for (i=0;i<n;i++){
		printf("[");
		for(j=0;j<m;j++){
			printf ("%c",mat[i][j]);
			printf("|");
		}
		printf("] \n");
	}
	 
	printf (" le texte chiffrer est  = << ");
	
	for (j=0;j<m;j++){
		for(i=0;i<n;i++){
			printf ("%c",mat[i][j]);
		}
		printf("  ");
	}
	printf ( ">>");
	
	
	
	return 0;
	
	
}
