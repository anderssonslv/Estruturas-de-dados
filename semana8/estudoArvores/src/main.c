#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	struct No *esq,*dir;
}No;

No *raiz = NULL;

void Reset(No *raiz){
	raiz = NULL;
}

int Empty(No *raiz){
	return raiz == NULL;
}

void List(No *raiz){
	if (!Empty(raiz)){
		printf("%d",raiz->num);
		List(raiz->esq);
		List(raiz->dir);
	}
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
	Reset(&raiz);
	Push(&raiz,1);
	Push(&raiz,3);
	Push(&raiz,2);
	List(raiz);
}