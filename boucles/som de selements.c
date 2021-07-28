/**
*@rebai yousra
*28/07/2021
*/

#include<stdio.h>



int main () {
	int i,som, N;
	
 	do {
	 
     	printf ("donnez N  \n");
	 	scanf ("%d",&N);
}	while (N<=0); 

    som=0;
    printf (" les nombres paire sont  : \n");
    
	for (i=1;i<=N;i++){
		if  (i%2==0)
		printf (" %d ", i);
	
	}
	printf ("\n");
	
	for (i=1;i<=N;i++){
			if ( i%2 !=0) {
			som=som+i;
			printf("%d ",i);
			if (i<N) 
			printf ("+ ") ;
			
		}
	}
	printf ("= %d ", som);
	
	return 0;
}
