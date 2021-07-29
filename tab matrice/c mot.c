/**
*@rebai yousra
*29/07/2020
*/

#include<stdio.h>
#include<string.h>
int main () {
	char tab [100] [100];
	int n ,i; 
	
	do {
	printf("donnez n le nombre de ling : \n");
	scanf ("%d",&n);
    } while ( n<0 || n>100 );
    
    for (i=0;i<n;i++){
    	printf(" donnez le  %d mot : \n" ,i);
    	scanf(" %s",tab[i] );
	}
	for (i=0;i<n;i++){
		printf ( "%s : %d  \n", tab [i],strlen (tab [i]));
	}
	return 0;
}
