/**
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bachlier {
	char np[50];
	int ni;
	char filier[20];
	float mg;
	float fs;
	float i;
};
typedef struct bachlier bachlier;

struct nvbachlier{
	int ni;
	char np[50];
	char filier[20];
	float fg;
};
typedef struct nvbachlier nvbachlier;

void remplissage(FILE *f);
void formule ();
void classer ();
int main (){
	FILE *f;
	bachlier b;
	nvbachlier nv;
	
	f=fopen("psi.txt","a");
	remplissage (f);
	fclose (f);
	printf ("okk 1 \n");
	formule();
	printf ("ok2");
	classer();
	
	f=fopen("psifg.txt","r");
	while (fread(&nv,sizeof(nvbachlier),1,f)){
		printf("[nom: %s|num inscription:%d|filier:%s|formule generale: %.2f] \n",nv.np,nv.ni,nv.filier,nv.fg);
	}
	fclose (f);
	return 0;
	
}
void remplissage ( FILE *f){
	bachlier b;
	int i, n;
	
	printf ("donnez le nombre de bacheliers: \n");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf ("donnez le nom de bachlier :\n");
		scanf (" %s",b.np);	
		printf ("donnez le numero d''inscription :\n");
		scanf ("%d",&b.ni);	
		printf ("donnez la moyenne generale :\n");
		scanf ("%f",&b.mg);	
		printf ("donnez la formule speciale :\n");
		scanf ("%f",&b.fs);
		printf ("donnez la filier de bachlier :\n");
		scanf (" %s",b.filier);
		printf ("veuilliez entrer la valeur *1* si il est redoublant sinon entrer la valeur *1.12*:\n");
		scanf ("%f",&b.i);	
			
	
		fwrite(&b,sizeof(bachlier),1,f);
	}
	
}
void formule (){
	FILE *f;
	FILE *g;
	bachlier b;
	nvbachlier nv;
	
	f=fopen("psi.txt","r");
	g=fopen("psifg.txt","a");
	
	while(fread(&b,sizeof(bachlier),1,f)){
		strcpy(nv.np,b.np);
		strcpy(nv.filier,b.filier);
		nv.ni=b.ni;
		nv.fg=(5*b.mg+b.fs)*b.i;
		fwrite(&nv,sizeof(nvbachlier),1,g);
	}
	fclose (f);
	fclose(g);
	
}
void classer (){
	nvbachlier tab[100];
	FILE *f;
	nvbachlier nv,x;
	int i,n,j;
	
	f=fopen("psifg.txt","r");
	n=0;
	while(fread(&nv,sizeof(nvbachlier),1,f)){
		tab[n]=nv;
		n++;
	}
	fclose(f);
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if (tab[i].fg<tab[j].fg){
				x=tab[i];
				tab[i]=tab[j];
				tab[j]=x;
			}
			
		}
	}
	f=fopen("psifg.txt","w");
	for(i=0;i<n;i++){
		fwrite(&tab[i],sizeof(nvbachlier),1,f);
	}
	fclose (f);
}
