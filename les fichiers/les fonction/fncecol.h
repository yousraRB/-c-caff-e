void ajouter( ){
	tcondidat c ;
	FILE *f;
	
	printf (" les paiments doit etre en DA \n\n ");
	printf (" donnez le nom de condidat : \n");
	scanf (" %s", c.nom);
	printf ( " donnez le numero de dossier de ce condidat  : \n");
	scanf (" %s",c.code);
	printf ( " veuilliez entrer son age    : \n");
	scanf ("%d", &c.age);
	printf ( " donnez le nombre de seances que vous avez assisté  : \n");
	scanf (" %d",&c.nbrs);
	printf ( " donnez le montant paye : \n");
	scanf (" %d",&c.mp );
	printf ( " donnez le montant restant  : \n");
	scanf (" %d",&c.mr);
	do{
	printf (" est ce que le condidact a payé les frais de l’examen *code* ( 1000 pour oui / 0 pour nn)");
	scanf ("%d",c.cod.frais);
	}while (c.cod.frais!=0 || c.cod.frais !=1000);
		do{
	printf (" est ce que le condidact a payé les frais de l’examen *creneau* ( 1000 pour oui / 0 pour nn)");
	scanf ("%d",c.code.frais);
	}while (c.code.frais!=0 || c.creneau.frais !=1000);
		do{
	printf (" est ce que le condidact a payé les frais de l’examen *conduit* ( 1000 pour oui / 0 pour nn)");
	scanf ("%d",c.code.frais);
	}while (c.code.frais!=0 || c.conduit.frais !=1000);
		
	c.cod.result=false;
	c.creneau.result=false;
	c.conduit.result=false;
	
	if (c.mp>=5000){
	f=fopen("liste_etudiants.txt","a");
	fwrite( &e,sizeof(tetudiant),1,F);
	fclose (F);}
	else 
	printf ( " désolé vous n'etes pas accepter ! votre paiment  doit etre minimum 5000da *sans les frais des examens*");
	
}
void passer (char nom , char code,int );
	tcondidat c;
	FILE *f;
	bool trouve=false;
	
	f=fopen("fichier.txt","r");
	while (fread(&c,sizeof(tcondidat),1,f)&&trouve==false){
		if(strcmp(c.nom,nom)==0 && strcmp(c.code,code)==0 )
			trouve=true;
	}
	
	switch (){
		case 1: 
		if ( c.cod.frais==1000 && c.nbrs>=5)
		 printf(" le condidat a le droit  de passer ce examen ");
		 else
		 printf(" le condidat  n'a pas le droit  de passer ce examen ");
		case 2: 
		if ( c.creneau.frais==1000 && c.nbrs>=5)
		 printf(" le condidat a le droit  de passer ce examen ");
		 else
		 printf(" le condidat  n'a pas le droit  de passer ce examen ");
		 case 1: 
		if ( c.conduit.frais==1000 && c.nbrs>=5)
		 printf(" le condidat a le droit  de passer ce examen ");
		 else
		 printf(" le condidat  n'a pasle droit  de passer ce examen ");
	}
	
	
