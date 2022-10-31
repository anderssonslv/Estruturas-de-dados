#include "source.h"

void def_PFactor () {//Define o fator de precedencia
	printf("\n 1 nome | 2 idade");
	printf("\n Digite fator de precedencia: ");
	char c[1];//pq se n atoi fica dando warning
	c[0] = getchar();

	fflush(stdin);

	if ((int)c[0] > 48 && (int)c[0]<51)//Pega o char q da pra passar pra 1 ou 0 como int
		PF = atoi(c);
	else printf("def_PFactor -> Fora de parametro");
}

void *createRoot () {
    return NULL;
}

Node *newNode (char *nome,int age, int phone){
	Node *new = (Node*) malloc (sizeof(Node));

	if (!new)
		return NULL;

	strcpy (new->nome,nome);
	new->age = age;
	new->phone = phone;
    new->L = NULL;
    new->R = NULL;
	new->alt = 0;
    new->color = RED;

	return new;
}

int maior (int a, int b) {
    return a>b? a:b;
}

int altura (Node *n){
    if (!n)
        return 0;
    else return 1 + maior(altura(n->L),altura(n->R));
}

int FB (Node* root) {
    if (root == NULL)
        return 0;
    return Altura(root->L) - Altura(root->R);
}

void turnR(Node **root){
    Node *no;

    no = (*root)->L;
    (*root)->L = no->R;

    no->R = root;

    (*root)->alt = maior(altura((*root)->L), altura((*root)->R)) + 1;
    no->alt = maior(altura(no->L), altura(no->R)) + 1;

    *root = no;
}

void turnL(Node **root){
    Node *no;

    no = (*root)->R; // no aponta para a subárvore direita da raiz root
    (*root)->R = no->L;
    no->L = *root; // o filho L de no passa a ser a raiz root

    // recalcula a altura dos nós que foram movimentados
    (*root)->alt = maior(altura((*root)->L), altura((*root)->R)) + 1;
    no->alt = maior(altura(no->L), altura(no->R)) + 1;

    *root = no;
}

void turnLR(Node **root){
    turnL(&(*root)->L);
    turnR(&(*root));
}

void turnRL (Node **root){
    turnR(&(*root)->R);
    turnL(&(*root));
}