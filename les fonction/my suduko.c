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
bool ling (int mat[9] [9]);
bool colone (int mat[9] [9]);
bool matrice (int mat[9] [9]);
int main (){
	bool trouve,trouvec,trouvem ;
	int i,j;
	
	

	remplissage ();
	printf ( " /n  here is your board ^-^ :  \n");
	
	for (i=0;i<9;i++){
		printf ("[");
		for (j=0;j<9; j++){
			printf ("%d" ,mat [i][j]);
			printf ("|");
		}
		printf ("] \n");
	}
	
	
		printf ("so we have : \n ");
	trouve=ling(mat);
		
	if (trouve == false){
		printf ("|-1) on a  les lings sont correct  :)     \n ");
	}
	else 
	printf("|-1) y a des nombre repititive  dans les lings :(        \n");
	
	trouvec=colone (mat);
	if (trouvec== false){
		printf ("|-2) les colones sont correct :)                       	   \n ");
	}
	else 
		printf ("|-2) y a des nombre repititive dans les  colonnes :(   	     \n");
	
	trouvem=matrice (mat);
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
	
	for (i=0;i<9;i++){
		for (j=0;j<9; j++){
			printf (" entre la valeur de la case [%d,%d] :",i,j);
			scanf ("%d",&mat [i][j]);
		}
	}
}
bool ling (int mat[9] [9]){
	int i,j,nbr;
	bool trouve=false;

	
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
bool colone (int mat[9] [9]){
		int i,j,nbr;
		bool trouve=false;

	
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
bool matrice (int mat[9] [9]){
	int i,j,y,k,l,g,nbr;
	bool trouve=false;
	
y=0;
while (y<9 && trouve==false){
g=0; 
	while ( g<9 && trouve ==false )	{
	i=g;
		while (i<3+g){
		j=y;
			while (j<3+y){
	    	  nbr =mat [i][j];
	    	k=g;
		 		while (k<3+g && trouve ==false){
				l=y;
		   			while(l<3+y && trouve ==false){
		   				
			  			if ( i+g==k+g && j+y==l+y){
						  
			  	     	l++;
			  	     	
			  	    		}else if ( mat [k] [l] == nbr) {
							  
								trouve=true; 
									}else{
									
									l++;}
			    	}
			
				k++;}
			j++;
	    	}
	    i++;	
		}
	g=g+3;
	}
y=y+3;
}
	return trouve;	
}
