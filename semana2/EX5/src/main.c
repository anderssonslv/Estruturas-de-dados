#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[30];
	int idade;
	int altura;
}Pessoa;

int nPessoas = 0;

void Lista (Pessoa *pBuffer){
	for (int i = 0; i < nPessoas; i++){
		printf("\nNome: %s",(char *)pBuffer);
		printf("\nIdade: %d",pBuffer->idade);
		printf("\nAltura: %d\n",pBuffer->altura);
		pBuffer+=sizeof(Pessoa);
	}
	system("pause");
}

Pessoa *Adiciona (Pessoa *ptr){
	if (nPessoas>4)
		ptr = (Pessoa*) realloc(ptr,(sizeof(Pessoa)*(nPessoas+1)));
	Pessoa  p;
	printf("\nDigite o nome: ");
	scanf("%s",p.nome);
	printf("\nDigite idade: ");
	scanf("%d",&p.idade);
	printf("\nDigite Altura: ");
	scanf("%d",&p.altura);

	
	ptr+=(sizeof(Pessoa)*nPessoas);//anda o numero de casas e dps volta pro inicio
	*ptr=p;//Da segmentation fault na 8/9ª pessoa independente de usar realoc ou não, e independente do número inicial q eu alocar
	ptr-=(sizeof(Pessoa)*nPessoas);

	nPessoas++;
	return ptr;
}

int main () { 
	Pessoa *pBuffer = malloc (sizeof(Pessoa)*5);
	int op;
	
	while ( 1 ) { system("cls");
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
