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

int mat [3][3];
void remplissage ( );

bool matrice (int mat[3] [3]);
int main (){
	bool trouve,trouvec,trouvem ;
	int i,j;
	
	

	remplissage ();
	printf ( " /n  here is your board ^-^ :  \n");
	
	for (i=0;i<3;i++){
		printf ("[");
		for (j=0;j<3; j++){
			printf ("%d" ,mat [i][j]);
			printf ("|");
		}
		printf ("] \n");
	}
	
	
	trouvem=matrice (mat);
	if (trouvem== false){
		printf ("|-3) les petites matrice sont correct :)               	     \n \n ");
	}
	else 
		printf ("|-3) y a des nombre repititive dans les petites matrice :(    \n \n");
	

	
	
	
	
	
	
	return 0;
}
void remplissage ( ){
	int i,j;
	
	for (i=0;i<3;i++){
		for (j=0;j<3; j++){
			printf (" entre la valeur de la case [%d,%d] :",i,j);
			scanf ("%d",&mat [i][j]);
		}
	}
}
	

bool matrice (int mat[3] [3]){
		int i,j,k,l,nbr;
		bool trouve=false;

	i=0;
		while (i<3){
		j=0;
			while (j<3){
	    	  nbr =mat [i][j];
	    	k=0;
		 		while (k<3 && trouve ==false){
				l=0;
		   			while(l<3 && trouve ==false){
		   				
			  			if ( i==k && j==l)
			  	     	l++;
			  	     	
			  	    		else if ( mat [k] [l] == nbr) 
								trouve=true; 
									else
										l++;
			    	}
			
				k++;}
			j++;
	    	}
	    i++;	

}
	return trouve;	
}
