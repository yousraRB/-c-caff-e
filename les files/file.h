typedef struct element element ;
struct element{
	int val;
	element *svt;
};
typedef struct FILEs FILEs ;
struct FILEs {
	element *head;
	element *q;
};
void init (FILEs *tete){
	(*tete).head=NULL;
	(*tete).q=NULL;
}
void enfiler(FILEs *tete,int val){
	element *p;
	p=(element*)malloc(sizeof(element));
	p->val=val;
	p->svt=NULL;
	if((*tete).head==NULL){
		(*tete).head=p;
	}
	else{
		(*tete).q->svt=p;
	}
	(*tete) .q=p;
}
void defiler (FILEs *tete,int *val){
	element *p;
	*val=((*tete).head)->val;
	
	p=(*tete).head;
	if((*tete).head==(*tete).q){
		(*tete).head=NULL;
		(*tete).q=NULL;
	}
	else{
		(*tete).head=(*tete).head->svt;
	}
	free(p);
}
bool vide(FILEs tete){
	return tete.head==NULL;
}
