#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int n;
	struct Node *L,*R;
}Node;

Node* createNode (int n) {
	Node *new = (Node*) malloc (sizeof (Node));
	new->L = NULL; new->R = NULL;
	new->n = n;
	return new;
}

void Push (Node **tree, Node *new) {
	if (!(*tree)) 
		(*tree) = new;
	else {
		if (new->n > (*tree)->n)
			Push (&(*tree)->R, new);
		else Push (&(*tree)->L,new);
	}
}

void orderList (Node *tree) {
	if (!tree)
		return;
	
	orderList(tree->L);
	printf("[%d] ",tree->n);
	orderList(tree->R);
}

Node* RSE (Node **tree) {
	Node *Aux = (*tree)->R;

	(*tree)->R = Aux->L;
	Aux->L = (*tree);

	printf("\nRotação Realizada!");
	return Aux;
}

Node* RSD (Node **tree) {
	Node *Aux = (*tree)->L;

	(*tree)->L = Aux->R;
	Aux->R = (*tree);

	printf("\nRotação Realizada!");
	return Aux; 
}

Node *Busca  (Node **tree, int n) {
	if (!(*tree))
		return NULL;

	if (n == (*tree)->n)
		return (*tree);
	else if (n > (*tree)->n)
	 	Busca (&(*tree)->R,n);
	else Busca (&(*tree)->L,n);
}

void Reset (Node **tree){
	if (!(*tree))
		return;

	Reset (&(*tree)->L);
	Reset (&(*tree)->R);

	free(*tree);
}

int main (int argc, char *argv[]) {
	Node *tree = NULL;
	int n;
	Node *Aux;

	while (1) {
		printf("\n1 Push\n2 Order List \n3 RSD\n4 RSE\nOutro Reset\n");
		switch (getchar()) {
		case '1':
			printf("\nDigite um numero para inserir: ");
			scanf("%d",&n);
			Push (&tree,createNode(n));
			break;
		case '2':
			orderList(tree);
			break;
		case '3':
			printf("Digite um numero para rotacionar:");
			scanf ("%d",&n);
			Aux = Busca(&tree,n);
			if (Aux) 
				tree = RSD(&Aux);
			else printf("\n Não encontrado!");
			break;
		case '4':
			printf("Digite um numero para rotacionar:");
			scanf ("%d",&n);
			Aux = Busca(&tree,n);
			if (Aux) 
				tree = RSE(&Aux);
			else printf("\n Não encontrado!");
			break;
		default:
			Reset(&tree);
			break;
		} 
		getchar();
	}
	
}