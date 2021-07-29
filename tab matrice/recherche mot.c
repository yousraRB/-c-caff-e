/**
*@rebai yousra
*29/07/2020
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main () {
	char tab [100] [100];
	int n ,i; 
	char chaine [30];
	bool egal;
	
	do {
	printf("donnez n le nombre de ling : \n");
	scanf ("%d",&n);
    } while ( n<0 || n>100 );
    
    for (i=0;i<n;i++){
    	printf(" donnez le  %d mot : \n" ,i);
    	scanf(" %s",tab[i] );
	}
	
		printf (" veuillez entrer le nom ici : \n");
		scanf (" %s",chaine);
		
		egal=false;    i=0;
		
	while (i<n  && egal ==false){
		if (strcmp(tab [i],chaine)==0) 
			egal=true;
			
			else
			i=i+1;
	}
	if ( egal ==true )
	printf ( " le mot existe");
	else 
	printf (" le mot n'existe pas");
	return 0;
}
