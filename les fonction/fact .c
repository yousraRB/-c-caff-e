/**
*@rebai yousra
*03/08/2021
*yousrarebai886@gmail.com
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void calafich ( int bi,int bs );
int main (){
	int bi ,bs;
	
	
	
		printf ( " /!\ LES VALEURS DOIT ETRES POSITIVE !!  \n");
	do{
	printf (" veuilliez enter la borne inferieur ( bi) : \n");
	scanf ("%d",&bi);
	}while (bi<0);
	do{
	printf (" veuilliez enter la borne superieur ( doit etre > bi) : \n");
	scanf ("%d",&bs);
	}while (bs <=0 || bs<bi);

	calafich (bi,bs);
	
	return 0;
}
void calafich ( int bi, int bs){
	int i,fact;
	 
		printf ( " les factoriels des nombre entre %d et %d sont : \n",bi,bs);
	
	if (bi ==0){
		printf ( "0! = 1 \n");bi++;}
	
	while ( bi<=bs){
		fact=1;
		for (i=2;i<=bi;i++){
			fact=fact*i;
		}printf ( " %d ! = %d \n",bi ,fact);
		bi=bi+1;
}


}
	

