/**
*/
#include<stdio.h>
#include<math.h>
#include "calculatrice.h"

int main () {
	float a,b;
	int x,y;
	
	printf (" donnez la valeur  a :\n");
	scanf("%d",&x);
	printf (" donnez la valeur  b :\n");
	scanf("%d",&y);
	a=x; b=y;
	
	printf (" %.2f + %.2f = %.2f \n", a,b, add (a,b));
	printf (" %d modulo %d = %d \n", x,y, mod (x,y));
	printf (" %.2f / %.2f = %.2f \n", a,b, div (a,b));
	printf (" %.2f - %.2f = %.2f \n", a,b, sous (a,b));
	printf (" %.2f * %.2f = %.2f \n", a,b, mult (a,b));
	
	return 0;
}

