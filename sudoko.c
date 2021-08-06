/**
*@rebai yousra
*28/07/2021
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int mat [9][9];
void remplissage ( );
bool verfie ();

int main ( ){
	int mat [9][9];
	bool trouve;
	int i,j;	
		
	remplissage (mat);
	printf (" affichage de la matrice aleatoire : \n");
	
	for (i=0;i<9;i++){
		printf ("[");
			for (j=0;j<9;j++){
			 printf ( " %d ",&mat [i][j]);
			 printf ( " |");
			}
			printf ( "] \n");
		}
		trouve= verfie (mat);
		if (trouve==false)
		printf ( " la matrice est sudoko ");
		else 
		printf (" la matrice n est pas un sudoko");
		
		return 0;
}
void remplissage ( int*mat [9][9]){
	int i,j;
	int stime;
	long ltime;
	
	ltime=time(NULL);
	
	srand(ltime);
	
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			mat [i][j]=rand () % 9;
		}
	}
	
}
bool verfie (int mat [9] [9]){
	
		
return trouve;
}
