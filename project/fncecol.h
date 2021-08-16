void ajouter( ){
	tcondidat c ;
	FILE *f;
	
	printf (" *les paiments doit etre en DA*\n\n ");
	printf (" donnez le nom de condidat : \n");
	scanf (" %s", c.nom);
	printf ( " donnez le numero de dossier de ce condidat  : \n");
	scanf (" %s",c.code);
	printf ( " veuilliez entrer son age    : \n");
	scanf ("%d", &c.age);
	printf ( " donnez le nombre de seances que vous avez assisté  : \n");
	scanf ("%d",&c.nbrs);
	printf ( " donnez le montant paye : \n");
	scanf ("%d",&c.mp );
	printf ( " donnez le montant restant  : \n");
	scanf ("%d",&c.mr);
	
	if (c.mp>=5000){
	printf ("dossier de candidature est accepté \n ");
	c.cod.frais=0 ;
	c.creneau.frais =0;
	c.conduit.frais =0;
	c.cod.result=0;
	c.creneau.result=0;
	c.conduit.result=0;
	
	f=fopen("condidat.txt","a");
	fwrite( &c,sizeof(tcondidat),1,f);
	fclose (f);}
	else 
	printf ( " dossier de candidature ne peut être accepté! le montant paye doit etre minimum 5000da *sans les frais des examens*\n");
	
}
void passer (char nom[50] , char code[50],int choixe){
	tcondidat c;
	FILE *f;
	bool trouve=false;
	tcondidat c1;
	

	f=fopen("condidat.txt","r");
	
	while (fread(&c1,sizeof(tcondidat),1,f) && trouve==false){
		if(strcmp(c1.nom,nom)==0 && strcmp(c1.code,code)==0 ){
			trouve=true;
			c=c1;}
	}
	
	switch (choixe){
		case 1: 
			if ( c.cod.frais==1000 && c.nbrs>=5 &&c.cod.result==0)
		 	printf(" \n le condidat a le droit  de passer ce examen \n");
		 	else
		 	printf("\n le condidat  n'a pas le droit  de passer ce examen \n");
		 	break;
		case 2: 
			if ( c.creneau.frais==1000 && c.nbrs>=5&&c.creneau.result==0)
		 	printf(" \n le condidat a le droit  de passer ce examen\n ");
		 	else
		 	printf(" le condidat  n'a pas le droit  de passer ce examen \n");
		 	break;
		case 3: 
			if ( c.conduit.frais==1000 && c.nbrs>=5 &&c.conduit.result==0)
		 	printf(" le condidat a le droit  de passer ce examen \n");
		 	else
		 	printf(" le condidat  n'a pas le droit  de passer ce examen \n");
		break;
	default : printf ("choix indesponible!\n");
	}
}
void supprime (){
	tcondidat c;
	FILE *f;
	FILE *g;
	bool trouve=false;
	
	f=fopen("condidat.txt","r");
	
	g=fopen("condidatmedia.txt","w");
	
	while (fread(&c,sizeof(tcondidat),1,f)){
		if (c.cod.result!=1 &&c.creneau.result!=1 &&c.conduit.result!=1 && c.mr!=0){
			fwrite(&c,sizeof(tcondidat),1,g);
			trouve =true;}
		
	}
	
	
	fclose(f);
	fclose(g);
	if (trouve==true){

	
		f=fopen("condidat.txt","w");
		g=fopen("condidatmedia.txt","r");
	
		while( fread(&c,sizeof(tcondidat),1,g)){
			fwrite(&c,sizeof(tcondidat),1,f);
		}
		fclose(g);
		fclose(f);
   }
}
void modifie ( char nom[50],char code[50],int ma){
tcondidat c1;
FILE *f;
FILE *g;

	f=fopen("condidat.txt","r");
	g=fopen("condidae.txt","w");
	while (fread(&c1,sizeof(tcondidat),1,f)){
		if(strcmp(c1.nom,nom)==0 && strcmp(c1.code,code)==0 ){
			c1.mr=c1.mr-ma;
			c1.mp=c1.mp+ma;
			fwrite(&c1,sizeof(tcondidat),1,g);}
		else
		fwrite(&c1,sizeof(tcondidat),1,g);
	}
	fclose(g);
	fclose(f);
	f=fopen("condidat.txt","w");
	g=fopen("condidae.txt","r");
	
	while (fread(&c1,sizeof(tcondidat),1,g)){
		fwrite(&c1,sizeof(tcondidat),1,f);}
	
	fclose(g);
	fclose(f);
}
void misajour ( char nom[50],char code[50],int choixe){
tcondidat c;
FILE *f;
FILE *g;
	f=fopen("condidat.txt","r");
	g=fopen("condidae.txt","w");
	while (fread(&c,sizeof(tcondidat),1,f)){
		if(strcmp(c.nom,nom)==0 && strcmp(c.code,code)==0){
			
		switch(choixe){
			case 1: printf ("*examen code* \n");
				do{
					printf (" est ce que le condidact a payé les frais de l’examen *code* ? ( 1000 pour oui / 0 pour nn)\n");
					scanf ("%d",&c.cod.frais);
					
				}while (c.cod.frais!=0 && c.cod.frais !=1000);
				do{
					printf (" est ce que le condidact a reussit dans l’examen *code* ? (   1 pour oui / 0 pour nn)\n");
					scanf ("%d",&c.cod.result);
				}while (c.cod.result!=0 && c.cod.result !=1);

			break;
		
			case 2: printf ("*examen creneau* \n");
				do{
					printf (" est ce que le condidact a payé les frais de l’examen *creneau* ? ( 1000 pour oui / 0 pour nn)\n");
					scanf ("%d",&c.creneau.frais);
				}while (c.creneau.frais!=0&&c.creneau.frais !=1000);
			
		 		do{
					printf (" est ce que le condidact a reussit dans l’examen *creneau* ? (  1 pour oui / 0 pour nn)\n");
					scanf ("%d",&c.creneau.result);
				}while (c.creneau.result!=0 && c.creneau.result !=1);
			break;
			case 3: printf ("*examen conduit* \n");
				do{
					printf (" est ce que le condidact a payé les frais de l’examen *conduit* ? ( 1000 pour oui / 0 pour nn)\n");
					scanf ("%d",&c.conduit.frais);
				}while (c.conduit.frais!=0&& c.conduit.frais !=1000);
			
		 		do{
					printf (" est ce que le condidact a reussit dans l’examen *coNDUIT* ? (  1 pour oui / 0 pour nn)\n");
					scanf ("%d",&c.conduit.result);
				}while (c.conduit.result!=0 &&c.conduit.result !=1);
			break;
		
			default : printf("choix indesponible\n");		
			
		}
		fwrite(&c,sizeof(tcondidat),1,g);
		}
		else 
		fwrite(&c,sizeof(tcondidat),1,g);
	}
	fclose(g);
	fclose(f);
	f=fopen("condidat.txt","w");
	g=fopen("condidae.txt","r");
	
	while (fread(&c,sizeof(tcondidat),1,g)){
		fwrite(&c,sizeof(tcondidat),1,f);}
	
	fclose(g);
	fclose(f);
}
void affichage (){
	FILE *f;
	tcondidat c;
	
	f=fopen("condidat.txt","r");
	printf ("\n *remarque*: la resultat 1=admis  0=ajourne ou il n a pas passe lexamen!!\n ");
	while (fread(&c,sizeof(tcondidat),1,f)){
		printf("*nom:%s |*numero dossier: %s |*age: %d|*montant paye:%d|*montant restant:%d|*resultat : code (%d),creneau(%d),conduit(%d)",c.nom,c.code,c.age,c.mp,c.mr,c.cod.result,c.creneau.result,c.conduit.result);
		printf ("\n");
	}
}
void nbrseance (char nom[50],char code[50],nbrse){
	FILE *f;
	FILE *g;
	tcondidat c;
	
	f=fopen("condidat.txt","r");
	g=fopen("condidatE.txt","w");
	while (fread(&c,sizeof(tcondidat),1,f)){
		if (strcmp(c.nom,nom)==0 && strcmp(c.code,code)==0){
			c.nbrs=nbrse;
			fwrite(&c,sizeof(tcondidat),1,g);}
		else
			fwrite(&c,sizeof(tcondidat),1,g);
		}
	}
	fclose (f);
	fclose (g);
	f=fopen("condidat.txt","w");
	g=fopen("condidatE.txt","r");

	while (fread(&c,sizeof(tcondidat),1,g)){
		fwrite(&c,sizeof(tcondidat),1,f);}

	fclose (f);
	fclose (g);
}

