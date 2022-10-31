#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int n;
	struct Node *L,*R;
	int H;
}Node;

Node *createNode (int n) {
	Node *new = (Node*) malloc(sizeof(Node));

	if (new){
		new->L = NULL;
		new->R = NULL;
		new->n = n;
		new->H = 0;
	} else printf("\nErro ao alocar novo no");

	return new;
}

int alturaNode (Node *node){
	if (!node)
		return -1;
	return node->H;
}

int FB (Node *node){
	if (node)
	 	return (alturaNode(node->L) - alturaNode(node->R));
	return 0;
}

Node *leftTurn(Node *node){
	Node *y;

	y = node->R;

	node->H = maior ( alturaNode(node->L) , alturaNode(node->R) ) + 1 ;
	y->H = maior ( alturaNode(node->L) , alturaNode(node->R) ) + 1 ;

	return y;
}

Node *rightTurn (Node *node) {
	Node *y,*f;

}

int maior (int a,int b) {
	return (a>b)? a:b;
}

void Push (Node **raiz, int n) {
	if (!(*raiz))
		*raiz = createNode(n);
	else if (n < (*raiz)->R)
		Push (&(*raiz)->L,n);
	else Push (&(*raiz)->R,n);
}	

int main() {
	Node *raiz = NULL;

	Push(&raiz,5);
	Push(&raiz,8);
	Push(&raiz,10);
}