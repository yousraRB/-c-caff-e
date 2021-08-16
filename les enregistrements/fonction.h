void saisir ( int n, tetudiant*e[100]){
	int i;
	
	for (i=1;i<=n;i++){
	e[i].num=i;
	printf( " veuilliez enter le matricule d'etudiant numéro %d :\n'",i);
	scanf (" %s",&e[i].matricul);
	printf( " veuilliez enter le nom d'etudiant numéro %d :\n'",i);
	scanf (" %s",&e[i].nom);
	printf( " veuilliez enter le prenom d'etudiant numéro %d :\n'",i);
	scanf (" %s",&e[i].prenom);
	printf( " veuilliez enter la moyenne  d'etudiant numéro %d :\n'",i);
	scanf ("%f",&e[i].moy);
	do {	
	printf( " veuilliez enter l'age ' d'etudiant numéro %d :\n'",i);
	scanf ("%d",&e.age);
}while (e[i].age <16 || e[i].age >70 );
		if (e[i].moy>=10)
		e.result = "ADM";
		else 
		e.result="AJN"
	}
}
void affichage (int n, tetudiant e[100]){
	int i;
	for (i=1;i<=n;i++){
		printf ( "etudiant numero %d : \n *nom : %s \n *prenom : %s \n *age : \n *matricule : %s \n *moyenne : %.2f \n *resultat:%s \n\n\n ",i,e[i].nom,e[i].prenom,e[i].age,e[i].matricul,e[i].moy,e[i].result);
	}
}
