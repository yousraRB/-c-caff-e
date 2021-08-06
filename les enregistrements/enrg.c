#include<stdio.h>
#include <stdlib.h>
#include "typerg.h"
#include"regtngl.h"


int main (){
	rectongle  rect;
	
	
	printf (" donnez x : \n");
	scanf ("%f",&rect.x);
	printf (" donnez y : \n");
	scanf ("%f",&rect.y);
	
	rect=pirim(rect);
	rect= surf(rect);
	printf ( "p= %.2f \n   s= %.2f" , rect.p, rect.s);
	
	
}
