/**
*@rebai yousra
*02/08/2021
*yousrarebai886@gmail.com
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void affichage ( int bi ,int bs );
int main (){
	int bi ,bs;
	
	printf ( " /!\ LES VALEURS DOIT ETRES POSITIVE !!  \n");
	do{
	printf (" veuilliez enter la borne inferieur ( bi) : \n");
	scanf ("%d",&bi);
	}while (bi<0);
	do{
	printf (" veuilliez enter la borne superieur ( doit etre > bi) : \n");
	scanf ("%d",&bs);
	}while (bs <=0 || bs<bi); 
	affichage (bi,bs);
	
	return 0;
}
void affichage ( int bi , int bs){
	int i;
	bool trouve;
	
	printf ( " les nombres premiers sont : \n");
	
	while (bi<2){
		bi=bi+1;
	}
	while (bi<=bs){
		i=2; trouve=false; 
		while (i<=bi/2 && trouve == false){
			if ( bi%i==0){
				trouve=true;
			}
			i++;
		}
		if (trouve ==false){
		printf ("%d",bi);
		printf (" \n");}
		bi=bi+1;
	}
	
}
