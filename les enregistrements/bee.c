#include <stdio.h>
#include <math.h>
struct ruche {
	int num;
	int age;
	char type [20];
	float qant;
};
typedef struct ruche ruche ;

int main(){
	ruche tab[200]	;
	int i ,n ;
	ruche max;
	
	
	do{
	printf ( " donnez n la taille de tableau : \n");
	 scanf ("%d",&n);
}while (n<0 || n>200);

	
	for (i=0;i<n;i++){
		printf ( " donnez le numero de ruch de la case %d : \n " , i);
		scanf ("%d",&tab [i].num);
		printf ( " donnez l'age 'de ruch de la case %d : \n" , i);
		scanf ("%d",& tab[i].age);
		printf ( " donnez le type de ruch de la case %d : \n" , i);
		scanf (" %s",tab[i].type);
		printf ( " donnez le qant de ruch de la case %d : \n" , i);
		scanf("%f" ,&tab [i].qant);
	}
	 max = tab [0];
	

	 for (i=1; i<n; i++){
	 	if ( tab[i].qant>max.qant)
	 	max=tab [i];
	 	
	 }
	 printf ( "the numbre of the best bee quantety is : %d", max.num );
	 return 0;

}
