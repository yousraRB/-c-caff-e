/**
*@rebai yousra
*29/07/2020
*/

#include<stdio.h>
#include<string.h>
int main () {
	int mat [100] [100];
	int i,j,n;
	
	do {
		printf(" donnez le nombre de ling n :\n");
		scanf("%d",&n);
	}while ( n<0 || n>100);
	
	for (i=0;i<n;i++){
		for ( j=0;j<n;j++)
			if ( j<=i)
		   	 mat [i][j]=1;
			else 
		     mat [i][j]=0;
	}
	for (i=0;i<n;i++){
	   	for ( j=0;j<n;j++)
			printf (" %d ",mat [i][j]);
     	printf ("\n");
	}
	return 0;
}
