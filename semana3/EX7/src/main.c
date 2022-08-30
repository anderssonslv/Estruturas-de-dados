#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[30];
	int idade;
	int altura;
} Pessoa;

Pessoa pessoas[10];


void Adiciona(void *pBuffer){
	int *nPessoas = (int *)(pBuffer+sizeof(int));

	if (*nPessoas==10)
		printf("Lista cheia!");
	else {
		printf("\nDigite nome: ");
		scanf("%s",&pessoas[*nPessoas].nome);
		printf("\nDigite idade: ");
		scanf("%d",&pessoas[*nPessoas].idade);
		printf("\nDigite altura: ");
		scanf("%d",&pessoas[*nPessoas].altura);
		*nPessoas+=1;//se eu colocar *nPessoas++ ele pula a memoria
	}
}



void Lista(void *pBuffer){
	int *i = (int *)(pBuffer+sizeof(int)*2);
	int *tam = (int *)(pBuffer+sizeof(int));

	*i = 0;

	while (*i < *tam){
		printf("\nnome: %s",pessoas[*i].nome);
		printf("\nidade: %d",pessoas[*i].idade);
		printf("\naltura: %d",pessoas[*i].altura);
		*i+=1;
	}
}

int main () {system("cls");
	void *pBuffer = malloc(sizeof(int)*3);

	if (!pBuffer){
		printf("\nErro ao alocar");
		exit(0);
	}

	*(int*)pBuffer=0;//o primeiro serve pra escolha do menu
	pBuffer+=sizeof(int);
	*(int*)pBuffer=0;//o segundo int é um contador de pessoas
	pBuffer+=sizeof(int);
	*(int*)pBuffer=0;//o terceiro é um contador para um for
	pBuffer-=sizeof(int);//volta pro inicio
	pBuffer-=sizeof(int);

	//mapa do pBuffer
	// int op / int  nPessoas / int i /

	while ( 1 ) {
		printf("\n1 para adicionar");
		printf("\n2 para listar\n");
		scanf("%d",(int *)pBuffer);//o primeiro e a escolha

		if (*(int *)pBuffer==1)
			Adiciona(pBuffer);
		else if (*(int *)pBuffer==2)
			Lista(pBuffer);
		else
			exit(0);
	}
	
}