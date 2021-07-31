/**
 *@REBAI YOUSRA
 *30/°7/2021
 *yousrarebai886@gmail.com
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
int  main () {
	int tab [100]; 
	int tabpair[100];
	int tabimpair[100];
	int i,j,k,n ,choix;
	int stime;
	long ltime; 

	printf("donnez le nombre des cases de tableau : \n");
	scanf("%d",&n);
	
		ltime =time (NULL);
		srand(ltime);
		
	for (i=0;i<n;i++) {
		tab [i]= rand () % 1000;
	}
		j=0; k=0;
	for (i=0;i<n;i++){
		if ( tab[i]%2==0 ){
		tabpair[j]=tab[i];
		j=j+1;}
		
		else {
		tabimpair[k]=tab[i];
		k=k+1;}
	}
	printf ( "1- affichage du grand tableau :       \n    ");
	
			for (i=0;i<n;i++){
				printf ("%d",tab [i]);
				printf (" ");}
				printf ("\n");
	
	printf ( "2- affichAGE  de les Deux tableau eclatent  : \n ");
	
			for (i=0;i<j;i++){
				printf (" %d",tabpair [i]);
				printf (" ");}
				printf ("\n");
			for (i=0;i<k;i++){
				printf (" %d",tabimpair [i]);
				printf (" ");}  

	return 0;
	
}
