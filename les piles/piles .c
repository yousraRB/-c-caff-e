/**

 -@rebai yousra
 -09/09/2021
 -yousrarebai886@gmail.com
*/


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "piles.h"
#include <string.h>
int main (){
	PILE *tete,*r;
	int i,n;
	char val;
	char kelma [30];
	bool trouve;
 /*
	init(&tete);
	do{
		printf ("a3toni un nombre \n");
		scanf("%d",&n);
	}while (n<0);
	
	
	for(i=0;i<n;i++){
		printf (" ara valeur \n");
		scanf("%d",&val);
		enpiler(&tete,val);
	}
	init (&r);
	printf ("*affichage*\n");
	while (!vide(tete)){
		depiler(&tete,&val);
		printf ("%d \n",val);
		enpiler (&r,val);
	}
	init (&tete);
	while (!vide(r)){
		depiler(&r,&val);
		enpiler (&tete,val);
	}
	*/
	//exo 2 ()
	printf ("kteb klma \n");
	gets(kelma);
	init (&tete);
	init(&r);
	i=0;trouve=false;
	while (i<strlen(kelma)&&trouve==false ){
		if (kelma [i]== '(')
			enpiler(&tete,kelma[i]);
		else if (kelma[i]==')'){
			if (vide(tete))
				trouve=true;
			else
				depiler(&tete,&val);
		}
		i++;
	}
	if(trouve==false&& vide(tete))
		printf ("la phrase ry msgma \n");
	else
		printf(" fiha 3fsa ");
	
	
}
