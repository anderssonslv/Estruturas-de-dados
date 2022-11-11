#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define RED 1
#define BLACK 0

typedef struct Node{
	char nome[10];
	int age, phone, alt;
	struct Node *L,*R;
	int color;
}Node;

void turnRL (Node **root);
void turnLR(Node **root);
void turnL(Node **root);
void turnR(Node **root);
int FB (Node* root);
int altura (Node *n);
int maior (int a, int b);
Node *newNode (char *nome,int age, int phone);
void *createRoot ();
void List (Node *root);
void Push (Node **root,Node *person);
Node *createPerson (char *argv[]);

int c = 1;
int main(int argc,char *argv[]) {
	Node *root = createRoot();

	for (int i = 0; i < 3; i++){
		Push (&root,createPerson(argv));
		c+=3;
	}
}

Node *createPerson (char *argv[]) {
	return newNode(argv[c],atoi(argv[c+1]),atoi(argv[c+2]));
}

void Push (Node **root,Node *person){
	if (!(*root))
		*root = person;
	else {
		if (person->age > (*root)->age)
			Push(&(*root)->R,person);
		else Push (&(*root)->L,person);
	}

	(*root)->alt = maior (altura((*root)->L), altura((*root)->R)) +1;


	if (FB((*root)) > 1)
		turnR(&(*root));
	else if (FB(*root) < -1)
	 	turnL(&(*root));
}

void List (Node *root){
	if (root) {
		List(root->L);
		printf("%s",root->nome);
		List(root->R);
	}
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
    return altura(root->L) - altura(root->R);
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

