
typedef struct ville ville ;
struct ville{
	char nom[30];
	float super;
	int habitant;
};

typedef struct PILE PILE;
struct PILE {
	ville info;
	PILE *svt;
};
void init (PILE **tete){
	(*tete)=NULL;
}
void enpiler(PILE **tete,ville inf){
	PILE *p;
	p=(PILE*)malloc(sizeof(PILE));
	p->info=inf;
	p->svt=*tete;
	*tete=p;
}
void depiler(PILE **tete,ville *inf){
	PILE *p;
	p=*tete;
	*inf=(*tete)->info;
	*tete=(*tete)->svt;
	free(p);
}
ville sommet (PILE *tete){
	return tete->info;
}
bool vide (PILE *tete){
	return tete==NULL;
}
