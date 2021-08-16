#include<stdio.h>
#include<stdlib.h>
int mat [5][5];
void remplissage ( );
void affichage ();
void somme ( int *som1, int  *som2);
int main (){
	int som1,som2;
	remplissage ();
	affichage ();
	somme (&som1,&som2);
	printf (" la somme de diagonel 1 est: %d \n la somme de diagonel 2 est: %d ",som1,som2);
	return 0;
}
void remplissage (){
	int i,j;
	for(i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf ("donnez la valeur de la cas [%d,%d]:",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
}
void affichage (){
	int i,j;
	for(i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf ("%d \t",mat[i][j]);
		}
		printf ("\n");
	}
}
void somme ( int *som1,int *som2){
	int i,j;
	*som1=0;
	*som2=0;
	for(i=0;i<3;i++){
		for (j=0;j<3;j++){
		
			if (i==j)
			*som1=*som1+mat [i][j];
			if(i==3-j-1)
			*som2=*som2+mat [i][3-i-1];
			
			
	}}
}


