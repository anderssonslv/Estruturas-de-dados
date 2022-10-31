#include "source.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

int Balanceamento(Node** root) {
	int fb = FB(*root);

	if ( fb > 1 )
		return BalancoEsquerda(&(*root));
	else if ( fb < -1 )
		return BalancoDireita(&(*root));
	else
		return 0;
}

void RSD(Node **root){
    Node *no;

    no = (*root)->L;
    (*root)->L = no->R;

    no->R = *root;

    (*root)->alt = maior(altura((*root)->L), altura((*root)->R)) + 1;
    no->alt = maior(altura(no->L), altura(no->R)) + 1;

    *root = no;
}

void RSE(Node **root){
    Node *no;

    no = (*root)->R; // no aponta para a subárvore direita da raiz root
    (*root)->R = no->L;
    no->L = *root; // o filho L de no passa a ser a raiz root

    // recalcula a altura dos nós que foram movimentados
    (*root)->alt = maior(altura((*root)->L), altura((*root)->R)) + 1;
    no->alt = maior(altura(no->L), altura(no->R)) + 1;

    *root = no;
}

int BalancoEsquerda(Node **root){
	int fbe = FB ((*root)->L);

	if (fbe > 0){
		RSD(&(*root));
		return 1;
	}
	else if (fbe < 0){
    	RSE(&(*root)->L);
    	RSD(&(*root));
		return 1;
	}
	return 0;
}

int BalancoDireita(Node **root){
	int fbe = FB ((*root)->R);

	if (fbe < 0){
		RSE(&(*root));
		return 1;
	}
	else if (fbe > 0){
    	RSD(&(*root)->R);
    	RSE(&(*root));
		return 1;
	}
	return 0;
}

Node* INORDEM(Node *n, Node *root){
    if (!root) 
        return NULL;
    
    INORDEM(n,root->L);

    if (n->age < root->age)
        n = root;

    INORDEM(n,root->R);

    return n;
}

