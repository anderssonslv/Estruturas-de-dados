#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[30];
	int idade;
	int altura;
}Pessoa;

int tot = 0;

Pessoa *Adiciona(Pessoa *pBuffer){
	if (tot>0)(
		pBuffer = (Pessoa*) realloc(pBuffer,(sizeof(Pessoa)*(tot*2))));
	Pessoa p;
	printf("\nDigite o nome: ");
	scanf("%s",p.nome);
	printf("\nDigite idade: ");
	scanf("%d",&p.idade);
	printf("\nDigite Altura: ");
	scanf("%d",&p.altura);

	pBuffer+=(tot*sizeof(Pessoa));
	*pBuffer=p;
	pBuffer-=(tot*sizeof(Pessoa));//eu tava esquecendo de decrementar
	tot++;
	return (Pessoa *)pBuffer;
}

int main () { system("cls");
	//Pessoa *pBuffer = malloc (sizeof(Pessoa)*1);
	Pessoa *pBuffer = malloc (sizeof(Pessoa)*5);
	int op;
	
	while ( 1 ) {
		printf("\n1 Para adicionar");
		printf("\n0 Para listar e sair\n");
		scanf ("%d",&op);

		if (op==1)
			pBuffer = Adiciona(pBuffer);
		else {
			Lista(pBuffer);
			free(pBuffer);
			exit(0);
		}
	}
}


/*
	pBuffer+=(tot*sizeof(Pessoa));
	pBuffer=p.nome;
	pBuffer+=sizeof(char)*30;
	pBuffer=p.idade;
*/
	//*(int*)pBuffer->altura=*(int *)p.altura;


/*
void Lista (Pessoa *pBuffer){
	for (int i = 0; i < tot; i++){
		printf("\nNome: %s",(char *)pBuffer);
		printf("\nIdade: %d",pBuffer->idade);
		printf("\nAltura: %d\n",pBuffer->altura);
		pBuffer+=sizeof(Pessoa);
	}
	system("pause");
}
*/