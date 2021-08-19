#include <stdio.h>
#include <stdbool.h>


bool verifie ( FILE *f);
void remplissage (int n );
void affichage ( );
bool recherche (int vlr);
void minmax (int *min,int *max);
int main (){
	FILE *f;
	int n;
	int vlr,min,max;
	
	f=fopen ("fichier.txt","r");
	if (verifie(f)==true)
	printf (" le fichier est ouvert correctement \n");
	else
	printf (" le fichier n'est pas ouvert correctement \n");
	fclose (f);
	do{
		printf (" donner n : \n");
		scanf ("%d",&n);
	}while (n<0);

	
	remplissage(n);
	affichage();
	
	printf ( " donnez la valeur :");
	scanf("%d",&vlr);
	
	if ( recherche (vlr)==true)
	printf ("la valeur est existe  \n");
	else 
	printf ("cette valeur n'existe pas \n");
	
	minmax(&min,&max);
	printf (" la max est :%d \n le min est: %d ",max,min);
	
	
	return 0;
}
bool verifie ( FILE *f){
	
	return f==NULL;
}
void remplissage (int n){
	FILE *f;
	int i,nbr;
	f=fopen ("fichier.txt","w");
	
	for (i=0;i<n;i++){
		printf ( " donnez un nombre : \n");
		scanf ("%d",&nbr);
		fwrite(&nbr,sizeof (int),1,f);
	}

	fclose (f);
}
void affichage ( ){
	FILE *f;
	int nbr;
	f=fopen("fichier.txt","r");
	printf ("[");
	while (fread(&nbr,sizeof(int),1,f)){
		printf ( "%d |",nbr);
	}
	printf ("] \n");
	fclose (f);
}
bool recherche (int vlr){
	FILE *f;
	bool trouve=false;
	int nbr;
	f=fopen ("fichier.txt","r");
	
	while (fread(&nbr,sizeof(int),1,f) && trouve==false){
		if ( nbr==vlr)
		trouve =true;
	}
	fclose (f);
	return trouve;
}
void minmax (int *min,int *max){
	FILE *f;
	int nbr;

	f=fopen("fichier.txt","r");
	 fread(&(*min),sizeof(int),1,f);
	*max=*min;
	while (fread(&nbr,sizeof (int),1,f)){
		if ( nbr<*min)
		*min=nbr;
		if(nbr>*max)
		*max=nbr;
	}
	fclose (f);
}
