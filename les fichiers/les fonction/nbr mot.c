/**
*@rebai yousra
*02/08/2021
*yousrarebai886@gmail.com
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int compteur (char chaine [50] );
int main(){
	int i,  cpt;
	char chaine [50];
	
	printf (" veuilliez entrer les mots : \n");
	gets ( chaine);
	
	cpt= compteur (chaine);
	if ( strlen(chaine)!=0){
		cpt=cpt+1;
	}

	if (chaine [strlen(chaine)]==' ')
	printf ( " le nombre de mots est : %d", cpt-1);
	else 
	printf ( " le nombre de mots est : %d", cpt-1);


	return 0;
	
}
int compteur (char chaine [50] ){
	int i,j,cpt,fin ;
j=0;cpt=0;fin =strlen(chaine);
	do {
		j=j+1;
	}while (chaine [j]==' ');
	
	for (i=j;i< fin; i++){
		if (chaine[i]==' '){
			cpt=cpt+1;
			do {
				i=i+1;
			}while (chaine [i]==' ');
		}
	}
	
	
	

	return cpt;	
	}

