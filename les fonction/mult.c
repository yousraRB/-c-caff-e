/**
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int chaine ( char ch[50]);
int main (){
int cpt;
char ch [50];

   printf ( "veuilliez saisir  les mots : \n ");
	gets (ch );
	cpt=0;
	cpt = chaine (ch );
	
		
  printf ( " le nombre de mots est : %d",cpt);
	return 0; 
}
int  chaine ( char ch[50]){
int i=0;
int cpt=0; 

	 while ( i<strlen  (ch)) {
	 	if ( strcmp (ch [i], " ") ==1) {
	 	cpt++;}
		 i++;
	 }
	  return cpt;
}
