#ifndef _BIBLIOTECA_H
#define _BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define RED 1
#define BLACK 0

int typeTree,PF;

typedef struct Node{
	char nome[10];
	int age, phone, alt;
	struct Node *L,*R;
	int color;
// tem todas essas informações por que deve servir para varias implementações de arvores
}Node;

void *createRoot ();
Node *newNode (char *nome,int age, int phone);
void def_PFactor ();
int maior(int a,int b);
int altura(Node *n);
int FB(Node *root);
void turnR(Node **root);
void turnL(Node **root);
Node* turnL_R(Node **root);
Node* turnR_L(Node **root);
Node* balancear(Node *raiz);

#endif