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

	if (!Aux)
		return *tree;

	(*tree)->R = Aux->L;
	Aux->L = (*tree);

	printf("\nRotação Realizada!");
	return Aux;
}

Node* RSD (Node **tree) {
	Node *Aux = (*tree)->L;

	if (!Aux)
		return *tree;

	(*tree)->L = Aux->R;
	Aux->R = (*tree);

	printf("\nRotação Realizada!");
	return Aux; 
}

Node *Busca  (Node **tree, int n, int R) {
	if (!(*tree))
		printf("Não encontrado!");

	if (n == (*tree)->n){
		if (R == 1)
			*tree = RSE (&(*tree));
		else *tree = RSD (&(*tree));
	}
	else if (n > (*tree)->n)
	 	Busca (&(*tree)->R,n,R);
	else Busca (&(*tree)->L,n,R);

	return *tree;
}

void Reset (Node **tree){
	if (!(*tree))
		return;

	Reset (&(*tree)->L);
	Reset (&(*tree)->R);

	free(*tree);
}

int main () {
	Node *tree = NULL;
	int n;

	while (1) {
		printf("\n1 Push\n2 Order List \n3 RSD\n4 RSE\n5 Sair \n6 Reset\n");
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
				tree = Busca (&tree,n,-1);
				break;
			case '4':
				printf("Digite um numero para rotacionar:");
				scanf ("%d",&n);
				tree = Busca (&tree,n,1);
				break;
			case '5':
				Reset(&tree);
				exit(0);
				break;
			default:
				Reset(&tree);
				break;
		} 
		getchar();
	}
}
