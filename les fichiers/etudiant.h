void ajouterEtudiant ( ){
	tetudiant e ;
	FILE *F;

	printf (" donnez le matricule : \n");
	scanf (" %s", e.matricule);
	printf ( " donnez le nom  : \n");
	scanf (" %s", e.nom);
	printf ( " donnez le prenom  : \n");
	scanf (" %s", e.prenm);
	printf ( " donnez la moyenne   : \n");
	scanf ("%f", &e.moy);
	printf ( " donnez le nom de la section  : \n");
	scanf (" %s", e.sec.nom);
	printf ( " donnez la filiere  : \n");
	scanf (" %s", e.sec.filier);
	
	F=fopen("liste_etudiants.txt","a");
	fwrite( &e,sizeof(tetudiant),1,F);
	fclose (F);
}
void afficherEtudiants(){
	tetudiant e ;
	FILE *f;
	bool trouve=false;
	f=fopen("liste_etudiants.txt","r");
	
	while (fread ( &e,sizeof ( tetudiant),1,f )&&trouve==false){
		printf ( " %s %s %s %.2f %s %s \n ",e.nom,e.prenm ,e.matricule,e.moy, e.sec.nom,e.sec.filier);
	}
		
	fclose (f);
	
}
void modifieEtudiants  (tetudiant e1,tetudiant e2){
	tetudiant e;
	FILE *f;
	FILE *g;
	
	
	f=fopen("liste_etudiants.txt","r");
	g=fopen("inermedia.txt","w");
	
	while (fread(&e,sizeof( tetudiant),1,f)){
		if (strcmp(e.matricule,e1.matricule)==0){
			fwrite (&e2,sizeof (tetudiant),1,g);
		}
		else {
			fwrite (&e,sizeof (tetudiant),1,g);
		}
	}
	fclose(f);
	fclose(g);
	
	f=fopen("liste_etudiants.txt","w");
	g=fopen("inermedia.txt","r");
	
	while( fread (&e,sizeof (tetudiant),1,g)){
		fwrite (&e,sizeof(tetudiant),1,f);
	}
	fclose (f);
	fclose(g);
}
void supprimerEtudiants (char matricule [50]){
	tetudiant e;
	FILE *f;
	FILE *g;
	
	f=fopen("liste_etudiants.txt","r");
	g=fopen("inermedia.txt","w");
	while ( fread(&e,sizeof(tetudiant) ,1,f)){
		if ( strcmp(e.matricule ,matricule)!=0){
			fwrite (&e,sizeof (tetudiant),1,g);
		}
	}
	fclose (f);
	fclose (g);
	
	f=fopen("liste_etudiants.txt","w");
	g=fopen("inermedia.txt","r");
	
	while (fread (&e,sizeof (tetudiant),1,g)){
		fwrite( &e,sizeof(tetudiant),1,f);
	}
	fclose(f);
	fclose(g);
}
