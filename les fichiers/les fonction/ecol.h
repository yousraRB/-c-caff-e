struct texamen{
	bool result;
	int frais;
};
typedef struct texamen texamen;

struct tcondidat {
	char nom[50];
	int age;
	char code[50];
	int mp;
	int mr;
	int nbrs;
	texamen cod;
	texamen creneau;
	texamen conduit;
	
};
typedef struct tcondidat tcondidat;
