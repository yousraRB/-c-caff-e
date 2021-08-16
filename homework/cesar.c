/**
*yousra rebai
*yousrarebai886@gmail.com
*16/08/2021
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct lettre {
	char a;
	int  cod;
};
typedef struct lettre lettre;
void chiffrer (lettre tab[26],char mot[50],char *phrase);

int main (){
	lettre tab[26];
	int i,j;
	char mot[50][50],phrase[50] [50];
	bool trouve=true;
	
	for (i=0;i<26;i++){
		tab[i].cod=i;
		tab[i].a=i+65;
	}
	for(i=0;i<9;i++){
		do {
			printf ("donnez  le %d mot   *en majuscule*: \n",i);
			scanf(" %s",mot[i]);
			trouve=false;
			for(j=0;j<strlen(mot)&&trouve==false;j++){
				if( mot[i][j]< 65 || mot [i][j]>90)
					trouve=true;
		}
		}while (trouve==true );
		chiffrer(tab,mot[i],phrase[i]);
		
	}
	
	for (i=0;i<9;i++){
		printf (" %s",phrase[i]);
	}
	
}
void chiffrer (lettre tab[26],char mot[50],char *phrase){
	int i,j,code;
	bool trouve;
	
	
	for (i=0;i<strlen(mot);i++){
		trouve=false;
		for (j=0;j<26 && trouve==false;j++){
			if (mot[i] ==tab[j].a){
				code=tab[j].cod + 3;
				trouve=true;
			}
		}
		
		if (code>25)
			code=code-26;
		
		trouve=false;
		for (j=0;j<26 && trouve==false;j++){
			if (tab[j].cod==code){
				phrase[i]=tab[j].a;
				trouve=true;
			}
		}
		
	}
}
