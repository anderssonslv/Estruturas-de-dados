#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int n;
	int alt;
	struct Node *L,*R;
}Node;

void Push (Node **tree, Node *new);
int FB(Node *tree);
int maior (int a,int b);
int altura (Node *tree);
int Balanceamento (Node **tree);
int BalancoEsquerda (Node **tree);
int BalancoDireita (Node **tree);
void RSE (Node**tree);
void RSD (Node **tree);
Node *createNode (int n);
Node* POP(Node* root, int value);

int main() {
	Node *tree = NULL;

	Push (&tree, createNode (1));
	Push (&tree, createNode (2)); 
	Push (&tree, createNode (3)); 
	Push (&tree, createNode (4)); 
	Push (&tree, createNode (5)); 

	POP (tree, 3);
}

Node* createNode(int n){
	Node *new = (Node *) malloc (sizeof(Node));
	new->alt = 1; new->n =n;
	new->L = NULL; new->R = NULL;
	return new;
}

void Push (Node **tree, Node *new) {
	if (!(*tree)) (*tree) = new;
	else {
		if (new->n > (*tree)->n)
			Push (&(*tree)->R,new);
		else Push (&(*tree)->L, new);

		(*tree)->alt = (maior (altura((*tree)->L), altura((*tree)->R)) +1);
		Balanceamento (&(*tree));
	}
}

int maior (int a,int b){
	return a>b? a:b;
}

int altura (Node *tree){
	if (!tree) return 0;
	return maior(altura(tree->L),altura(tree->R))+1;
}

int FB (Node *tree){
	if (!tree) return 0;
	return altura(tree->L) - altura (tree->R);
}

int Balanceamento (Node **tree) {
	int fb = FB ((*tree));
	if (fb > 1) return BalancoEsquerda(&(*tree));
	else if (fb < -1) return BalancoDireita(&(*tree));
	return 0;
}

int BalancoEsquerda(Node **tree) {
	int fb = FB((*tree)->L);
	if (fb>0) {
		RSD(&(*tree));
		return 1;
	}
	else if (fb<0) {
		RSE(&(*tree)->L);
		RSD(&(*tree));
		return 1;
	}
	return 0;
}

int BalancoDireita (Node **tree){
	int fb = FB ((*tree)->R);
	if (fb < 0){
		RSE(&(*tree));
		return 1;
	}
	if (fb>0) {
		RSD(&(*tree)->R);
		RSE(&(*tree));
	}
	return 0;
}

void RSE (Node **tree){
	Node *Aux = (*tree)->R;
	(*tree)->R = Aux->L;
	Aux->L = (*tree);

	(*tree)->alt = maior(altura((*tree)->L),altura((*tree)->R))+1;
	Aux->alt = maior (altura(Aux->L),altura(Aux->R))+1;

	(*tree) = Aux;
}

void RSD (Node **tree){
	Node *Aux = (*tree)->L;
	(*tree)->L = Aux->R;
	Aux->R = (*tree);

	(*tree)->alt = maior(altura((*tree)->L),altura((*tree)->R))+1;
	Aux->alt = maior (altura(Aux->L),altura(Aux->R))+1;

	(*tree) = Aux;
}

Node* POP(Node* root, int value){
	if (root == NULL) return NULL;
	else {
		if (root->n == value){
			//Se for folha
			if (root->L == NULL && root->R == NULL){
				free(root);
				return NULL;
			}
			else {
				if (root->L == NULL || root->R == NULL){ 
					//se tiver apenas um filho
					Node* aux;
					if (root->L != NULL)
						aux = root->L;
					else aux = root->R;
					free(root);
					return aux;
				}
				else { //removes nodes with two childs
					Node* aux = root->L;
					while (aux->R != NULL)
						aux = aux->R;
					root->n = aux->n;
					aux->n = value;
					root->L = POP(root->L, value);
					return root;
				}
			}
		} 
		else {
			if (value < root->n)
				root->L = POP(root->L, value);
			else 
				root->R = POP(root->R, value);
		}
		root->alt = maior (altura(root->R), altura (root->L))+1;
		Balanceamento(&root);
		return root;
	}
}