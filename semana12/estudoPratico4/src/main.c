#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int num;
	struct Node *L,*R;
	int alt;
}Node;

Node *createNode (int n);
void *Push (Node** tree, Node *new);
void OrderList (Node *tree);
int maior (int a, int b);
int altura(Node *tree);
int FB (Node *tree);


int main (int argc,char *argv[]) {
	Node * tree = NULL;

	for (int i = 1; i < 5; i++)
		Push(&tree,createNode(atoi(argv[i])));
}

Node *createNode (int n) {
	Node *new = (Node*) malloc (sizeof(Node));
	new->L = NULL; new->R = NULL;
	new->num = n; new->alt = 0;
	return new;
}

void *Push(Node** tree,Node *new){
	if (!*tree)
		*tree = new;
	else {
		if (new->num > (*tree)->num)
			Push(&(*tree)->R, new);
		else Push (&(*tree)->L,new);
	}
}

void OrderList (Node *tree){
	if (!tree)
		return;
	
	OrderList(tree->L);
	printf("[%d] ",tree->num);
	OrderList(tree->R);
}

int maior (int a, int b){
	return a>b? a:b;
}

int altura (Node *tree) {
	if (!tree) return 0;
	return maior(altura(tree->L), altura(tree->R)) +1;
}

int FB (Node *tree) {
	if (!tree) return NULL;
	return altura(tree->L) - altura(tree->R);
}

void RSE (Node **tree){
	Node *Aux = (*tree)->R;
	(*tree)->R = Aux->L;
	Aux->L = (*tree);

	Aux->alt = maior(altura(Aux->L),altura(Aux->R))+1;
	(*tree)->alt = maior(altura((*tree)->L),altura((*tree)->R))+1;

	*tree = Aux;
}

void RSD (Node **tree){
	Node *Aux = (*tree)->L;

	(*tree)->L = Aux->R;
	Aux->R = (*tree);

	(*tree)->alt = maior (altura((*tree)->L), altura((*tree)->R)) + 1;
	Aux = maior (altura(Aux->L),altura(Aux->R)) +1;

	(*tree) = Aux;
}