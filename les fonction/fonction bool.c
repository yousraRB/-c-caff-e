/**
*/
#include <stdio.h>
#include<stdbool.h>
bool verfie (int nombre);

int main() {
	int nombre;
	bool verf;
	
	do{
		printf("donnez un nombre positive/ \n");
		scanf("%d",&nombre);
	}while (nombre<0);
	
	verf= verfie(nombre);
	if ( verf==true )
	printf(" le nombre est paire ");
	else 
	printf("le nombre est impair");
	
	return 0;
}

bool verfie (int nombre){
	
	return nombre %2 ==0;
	
}

