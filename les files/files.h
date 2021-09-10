typedef struct element element ;
struct element {
	int val;
	element *svt;
};

typedef struct FILEs FILEs;
struct FILEs {
	element *head;
	element *queue;
};

void init (FILEs *tete){
	(*tete).head=NULL;
	(*tete).queue=NULL;
}
void enfiler (FILEs *tete,int val){
	element *p;
	p=(element*)malloc(sizeof(element));
	p->val=val;
	p->svt=NULL;
	if((*tete).head==NULL)
		(*tete).head=p;
	else {
		(*tete).queue->svt=p;
	}
	(*tete).queue=p;	
}
void defiler (FILEs *tete,int *val){
	element *p;
	*val=(*tete).head->val;
	p=(*tete).head;
	if((*tete).head==(*tete).queue){
		(*tete).head=NULL;
		(*tete).queue=NULL;
	}
	else {
		(*tete).head=(*tete).head->svt;
		
	}
	free(p);
}
int sommet (FILEs tete){
	return tete.head->val;
}
bool vide(FILEs tete){
	return (tete.head==NULL);
}

	

