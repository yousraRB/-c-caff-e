/**
*@rebai yousra
*29/07/2020
*/

#include<stdio.h>
#include<stdbool.h>
int main () {
	
	int N,i,som,j;
	
	printf (" veuillez entrer un nombre N : \n");
	scanf ("%d",&N);
	som=0; j=1;
	for (i=0; i<N; i++){
		j=j* (j+1);
		som=som+j;
	}
	printf(" la somme est :%d ",som);
	return 0 ;
}

