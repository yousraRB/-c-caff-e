/**
*@rebai yousra
*28/07/2021
*/

#include<stdio.h>



int main () {
	int i,F, N;
	
 	do {
	 
     	printf ("donnez N  \n");
	 	scanf ("%d",&N);
}	while (N<=0); 

   F=1; 
   printf("%d! = 1 ",N);
	for (i=2;i<=N;i++){
	 F=F*i;
	 printf (" * %d",i);
	
	}
	

	
	printf ("= %d ", F);
	
	return 0;
}
