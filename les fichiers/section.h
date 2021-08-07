void afficherSEC (char nom [50]){
	tetudiant e;
	FILE *f;
	
	f=fopen("liste_etudiants.txt","r");
	while (fread( &e,sizeof ( tetudiant),1,f)){
		if (strcmp ( e.sec.nom ,nom)==0){
			printf ( " %s %s %s %.2f %s %s \n ",e.nom,e.prenm ,e.matricule,e.moy, e.sec.nom,e.sec.filier);
		}
	}
	fclose(f);
}
float moysec(char nom[50]){
	tetudiant e;
	FILE*f;
	int nb ;
	float som=0;
	f=fopen("liste_etudiants.txt","r");
	
	while (fread(&e,sizeof ( tetudiant),1,f)){
		if ( strcmp(e.sec.nom,nom)==0){
			som=som+e.moy;
			nb++;
		}
	}
	fclose (f);

	return som/nb;
}
