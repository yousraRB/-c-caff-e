/**
*@rebai yousra
*31/07/2021
*/
#include <stdio.h>

int main () {
	int tab [100] [100];
	int i,n,j;
	
	printf (" donnez le nombre de ling n : \n ");
	scanf("%d",&n);
	
	j=n-1;
	while (j>=0) {
		for( i=0;i<=j;i++){
			printf(" donnez la valeur  de la case [ %d, %d] :  ", i,j);
			scanf("%d",&tab[i][j]); 
		}
	j=j-1;
	}

	 printf("voila votre matrice triangulaire : \n");
		 
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf ("%d",tab [i][j]);
			printf("  ");
		}
		printf("\n");
	}
	for (i=0;i<n;i++){
		for (j=0;i>j;j++){
		tab [i][j]= tab [j][i];
		}
	
	}
		printf(" voila la forme symétrique de votre matrice : \n");

for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf ("%d",tab [i][j]);
			printf("  ");
		}
		printf("\n");
	}
		
	return 0;
}

