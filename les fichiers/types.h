struct tsection{
	char nom[50];
	char filier[50];
	
};

typedef struct tsection tsection;


struct tetudiant {

	char nom[50];
	char prenm[50];
	char matricule [50];
	tsection sec ;
	 float moy;
};
typedef struct tetudiant tetudiant;
