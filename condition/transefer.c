/**
*@rebai yousra 
* 27/07/2021
*/

#include<stdio.h>
 
int main () {
	 
	float pied ;
	 
	 printf(" donnez  un pied :  ");
	 scanf ("%f",&pied);
	 
	 printf (" %.1f pied = %.1f pouces =%.4f km = %.3f cm ", pied,(pied*12),((pied* 0.3048) /1000),(pied* 0.3048) *100);
	 
	 return 0;
}

