/**
*@rebai yousra
*28/07/2021
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>


void remplissage ( int*mat [9][9]);
bool verfie (int mat [9] [9]);

int main ( ){
	int mat [9][9];
	bool trouve;
	int i,j;	
		
	remplissage (&mat);
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
		for (j=0;i<9;i++){
			mat [i][j]=rand () % 9;
		}
	}
	
}
bool verfie (int mat [9] [9]){
	int k, l,nbr,i,j;
	bool trouve;
	trouve =false;

	remplissage (&mat);
	i=0;
	while (i<9 && trouve ==false ){
		for(j=0;j<9;j++){
		 nbr=mat[i][j];
		 k=j+1;
		 while(k<9 && trouve==false){
		 	if (nbr==mat[i][k])
		 	trouve =true;
		 	k++;
		
		 }
		}
		i++;
	}
	
	i=0;
	while (i<9 && trouve ==false ){
		for(j=0;j<9;j++){
		 nbr=mat[j][i];
		 k=j+1;
		 while(k<9 && trouve==false){
		 	if (nbr==mat[k][i])
		 	trouve =true;
		 	k++;
		
		 }
		}
		i++;
	}

i=0;l=0;
while (l<9 && trouve== false ){
	while (i<i+3 && trouve ==false ){
		while(j<j+3&& trouve== false){
		 nbr=mat[j][i];
		 k=j+1;
		 while(k<3 && trouve==false){
		 	if (nbr==mat[k][i])
		 	trouve =true;
		 	k++;
		
		 }
		 j++;
		}
		i++;
	}
	l=l+1;
}

i=0;l=0;
while (l<9 && trouve== false ){
	while (i<i+3 && trouve ==false ){
		while(j<j+3&& trouve== false){
		 nbr=mat[i][j];
		 k=j+1;
		 while(k<3 && trouve==false){
		 	if (nbr==mat[i][k])
		 	trouve =true;
		 	k++;
		
		 }
		 j++;
		}
		i++;
	}
	l=l+1;
}
return trouve;
}
