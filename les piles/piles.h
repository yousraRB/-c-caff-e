
typedef struct PILE PILE;
struct PILE {
	char val;
	PILE *svt;
};
void init (PILE **tete){
	*tete=NULL;
}
void enpiler (PILE **tete,char x){
	PILE *p;
	
	p=(PILE*)malloc(sizeof(PILE));
	p->val=x;
	p->svt=*tete;
	*tete=p;
}
void depiler (PILE **tete,char *x){
	PILE *p;
	
	*x=(*tete)->val;
	p=*tete;
	*tete=(*tete)->svt;
	free(p);	
}
char sonnet (PILE *tete){
	return tete->val;
}
bool vide(PILE *tete){
	return tete==NULL;
}
