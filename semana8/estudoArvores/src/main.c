#include <stdio.h>
#include <stdlib.h>
//Arvore sem balanceamento
typedef struct No{
	int num;
	struct No *esq,*dir;
}No;

No *Reset(){
	return NULL;
}

int Empty(No *raiz){
	return raiz == NULL;
}

/*Essa função "vai indo" pra esquerda até achar null, e imprime o numero q ja tava na pilha antes da recursão*/
void inorderList(No *raiz){
	if (!Empty(raiz)){
		printf("\n %d",raiz->num);
		List(raiz->esq);
		List(raiz->dir);
	}
}

/*Essa eu não entendi exatamente, mas ela anda e faz a pilha de forma ordenada*/
void orderList(No *raiz){
	if (raiz){
		orderList(raiz->esq);
		printf("\n %d",raiz->num);
		orderList(raiz->dir);
	}
}

int Altura(No *raiz){
	int esq,dir;

	if (raiz == NULL)
		return 0;
	
	esq = Altura((raiz)->esq);
	dir = Altura((raiz)->dir);

	if (esq>dir)
		return esq+1;
	else return dir+1;
}

int FB(No **raiz){
	if (*raiz == NULL)
		return 0;
	
	return Altura((*raiz)->esq) - Altura((*raiz)->dir);
}

void Push (No **raiz,int n) {
	if (!(*raiz)){
		*raiz = (No*) malloc (sizeof (No));
		(*raiz)->num = n;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		return;
	}

	if ((*raiz)->num > n){
		Push(&(*raiz)->esq,n);
	} else Push(&(*raiz)->dir,n);
}

int main () {
	No *raiz = Reset();
	int array [5] = {34,84,15,0,2};
	
	for (int i = 0; i < 5; i++) {
		Push(&raiz,array[i]);
	}
	
	inorderList(raiz);
}