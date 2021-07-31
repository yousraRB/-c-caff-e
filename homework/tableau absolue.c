/**
*@rebai yousra
*31/07/2021
*yousrarebai886@gmail.com
*/
#include<stdio.h>

int main (){
	int tab [100];
	int i, n ;
	
	do {
		printf (" veuilliez entrer le nombre des cases n : \n");
		scanf("%d",&n);
	}while (n<0);

   printf ( " /!\ remarque : les valeur doit etre negatives ! \n");
	
	i=0;
	while ( i<n){
	  
	 	 do {
	  		printf ( " entre la %d valeur de tableau  : ",i);
	  		scanf ("%d",&tab [i]);
	  	} while (tab [i]>=0);
	  	i=i+1;
	}
	printf ( " le tableau avec la valeur absolut recoit : \n");
	
	for (i=0;i<n;i++){
		printf ("%d" , -tab [i]);
		printf ("  ");
	}
	return 0;
}

