/**
*/
#include<stdio.h>
 void  division (int nombre,int nombr,int *r,int *q);
 
 int main () {
 	int nombre;
 	int nombr;
 	int r,q;
 	
 	printf (" donnez le 1er nombre : \n ");
 	scanf("%d",&nombre);
 	do {
 		printf ( " donnez le 2em nombre dfrn de 0 : \n");
 		scanf("%d",&nombr);
 		
	 }while (nombr==0);
	 
	 division( nombre,nombr,&r,&q);
	 printf (" le rest est :%d,  \n le qotion est: %d",r,q);
	 return 0;
	 
 }
 void division ( int nombre, int nombr , int *r, int *q){
 	
 	*r=nombre ; *q=0;
 	while ( *r>=nombr ){
 		*r=*r-nombr ;
 		*q= *q+1;
	 }
 }
