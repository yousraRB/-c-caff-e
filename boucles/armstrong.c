/**
*@rebai yousra
*28/07/2021
*/

#include<stdio.h>
#include <math.h>


int main () {
	
	int i,save,som, digit;
	
	for (i=1;i<=1000;i++){
			
		save=i; som=0;
		while (save!=0){
			digit=save%10;
			som=som+pow(digit,3);
			save=save/10;
		}
		if (som==i)
		printf (" %d \n",i);
	}
	return 0;
 }
	
