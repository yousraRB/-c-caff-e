/**
*/
#include<stdio.h>
#include<stdbool.h>
 void remplissage ( int n, int *tab );
 void affichage (   int tab [100],int  n);
 int occurence (int nmbr, int tab [100] ,int n  );
 bool recherche (int val,int tab[100],int n);
 
 int main (){
 	
	int tab [100]; 
	int n ,nombre ,cpt;
 	bool trouve;
	do {
		printf ( " donnez la taille de tableau : \n");
		scanf ("%d",&n);
	}while ( n<0 || n >100 );
		 	
	remplissage ( n,tab);
	affichage ( tab ,n);		
	
	printf ( " veuilliez entrer un nombre : \n")	;
	scanf ("%d",&nombre);
	cpt= occurence(nombre,tab ,n);
	
	printf (" \n le nombre d'occurence de la valeur %d est : %d fois  \n",nombre,cpt);
	
  	printf ( "  \n veuilliez entrer un nombre : \n");
  	scanf ( "%d", &nombre);
  	
	trouve = recherche (nombre, tab,n);
	
	if ( trouve==true )
	printf ( " le nombre est existe");
	else
	printf (" le nombre n' est existe pas !'");
  return 0;
 }
  void remplissage( int n , int *tab){
  	int i;
  		for ( i=0;i<n;i++){
  			printf (" donnez la valeur de %d case :  ",i);
  			scanf ("%d",&tab [i]);
	  }  
  }
  void affichage (  int tab [100], int n){
  	int i ;
  		for ( i=0;i<n;i++){
  			printf ("  %d  :  ",tab [i]);
  		    
	  }  
  	
  }
  int occurence ( int nbr , int tab [100], int n ){
  	int i , cpt;
  	cpt=0;
  		for ( i=0;i<n; i++){
  			if ( tab[i]==nbr )
  			cpt =cpt +1;
		  }
		  return cpt;
  }
   bool recherche (int val,int tab[100],int n){
   	int i;
   	bool trouve =false;
   	i=0;
   		while  ( i<n && trouve == false){
   			if (tab[i] == val )
   				trouve =true;
   				i++;
   			}
   			return trouve;
   			
   		
	   }
   
