
/**
*@rebai yousra
*06/08/2021
*yousrarebai886@gmail.com
*/
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>

int mat [9][9];
void remplissage ( );
bool ling ();
bool colone ();
bool matrice ();
int main (){
	bool trouve,trouvec,trouvem ;
	int i,j;
	
	printf ( "  here is your board ^-^ :  \n");

	remplissage ();
	for (i=0;i<9;i++){
		printf ("[");
		for (j=0;j<9; j++){
			printf ("%d" ,mat [i][j]);
			printf ("|");
		}
		printf ("] \n");
	}
	
	
		printf ("so we have : \n ");
	trouve=ling();
		
	if (trouve == false){
		printf ("|-1) on a  les lings sont correct  :)     \n ");
	}
	else 
	printf("|-1) y a des nombre repititive  dans les lings :(        \n");
	
	trouvec=colone ();
	if (trouvec== false){
		printf ("|-2) les colones sont correct :)                       	   \n ");
	}
	else 
		printf ("|-2) y a des nombre repititive dans les  colonnes :(   	     \n");
	
	trouvem=matrice ();
	if (trouvem== false){
		printf ("|-3) les petites matrice sont correct :)               	     \n \n ");
	}
	else 
		printf ("|-3) y a des nombre repititive dans les petites matrice :(    \n \n");
	
	if (trouve==false && trouvec==false && trouvem==false)
	printf (" sooo felicitaion la matrices est sudoku ");
	else printf ("so it'snt :( try again :( :(");
	
	
	
	
	
	
	return 0;
}
void remplissage ( ){
	int i,j;
	long ltime;
	int stime;
	
	
	ltime =time (NULL);
	srand (ltime);
	
	for (i=0;i<9;i++){
		for (j=0;j<9; j++){
			mat [i][j]=rand () %10;
		}
	}
}
bool ling (){
	int i,j,nbr;
	bool trouve=false;

	remplissage ( );
	i=0;
	while (i<9 && trouve ==false){
		j=0;
		nbr =mat [i][j];	
		j=j+1;
		while(j<9 && trouve ==false)  {
			if ( mat [i] [j] == nbr) {
				trouve=true;
			}
			else
			j++;
		}
		i++;
	}
	return trouve;
}
bool colone (){
		int i,j,nbr;
		bool trouve=false;

	remplissage ( );
	i=0;
	while (i<9 && trouve ==false){
		j=0;
		nbr =mat [j][i];	
		j=j+1;
		while(j<9 && trouve ==false)  {
			if ( mat [j] [i] == nbr) {
				trouve=true;
			}
			else
			j++;
		}
		i++;
	}
	return trouve;
	
}
bool matrice (){
		int i,j,y,k,l,g,nbr;
		bool trouve=false;

	remplissage ( );
	
y=0;
while (y<9&& trouve==false){
g=0;
	while ( g<9 && trouve ==false )	{
		for (i=0;i<3+g;i++){
			for (j=0;j<3+y;j++){
	    	nbr =mat [i+g][j+y];
	    	k=0;
		 		while (k<3 && trouve ==false){
				l=0;
		   			while(l<3 && trouve ==false){
		   				
			  			if ( i==k && j==l)
			  	     	l++;
			  	     	
			  	    		else if ( mat [k+g] [l+y] == nbr) 
								trouve=true; 
									else
										l++;
			    	}
			
				k++;}
	    	}
		}
	g=g+3;
	}
y=y+3;
}
	return trouve;	
}

