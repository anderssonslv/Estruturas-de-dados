#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE ( ( 10 * sizeof(char) ) + ( 2 * sizeof(int) ) )
int nPessoas = 0;

void *Adiciona (void *ptr) {
	ptr = realloc(ptr,SIZE*(nPessoas+1));

	if ( !ptr ){
		printf("\nNão foi possivel realocar!\n");
		exit(1);
	}

	printf("\nDigite nome: ");
	scanf("%s",(char*)(ptr+SIZE*nPessoas));
	getchar();
	printf("Digite telefone: ");
	scanf("%d",(int*)((ptr+sizeof(char)*10)+SIZE*nPessoas));
	getchar();
	printf("Digite idade: ");
	scanf("%d",(int*)((ptr+sizeof(char)*10+sizeof(int))+SIZE*nPessoas));
	getchar();

	printf("\nAdicionado!\n");
	system("pause");
	
	nPessoas++;
	return ptr;
}

void Lista (void *ptr){system("cls");
	for (int i = 0; i < nPessoas; i++){
		printf("\n");
		printf("\nNome: %s",(char *)(ptr+(sizeof(char)*(i*SIZE))));
		printf("\nTelefone: %d",*(int*)(ptr+(sizeof(char)*10)+(i*SIZE)));
		printf("\nIdade: %d\n",*(int*)(ptr+((sizeof(char)*10)+sizeof(int))+(i*SIZE)));
	}
	system("pause");
}

void *Remove (void *ptr){
	char nome[10];
	printf("Digite o nome:");
	scanf("%s",nome);
	getchar();
	int nEncontrado=1;

	for (int i = 0; i < nPessoas; i++){
		if ( strcmp(nome,(char *)ptr+SIZE*i)==0 ){
			for (int c = i; c < nPessoas; c++){
				strcpy((char *)ptr + SIZE*c, (char *)ptr+SIZE*(c+1));
				*(int *)(ptr+(SIZE*c)+(10*sizeof(char))) = *(int *)(ptr+(SIZE*(c+1))+(10*sizeof(char)));
				*(int *)(ptr+(SIZE*c)+(10*sizeof(char)+sizeof(int))) = *(int *)(ptr+(SIZE*(c+1))+(10*sizeof(char)+sizeof(int)));
			}
			nPessoas--;
			nEncontrado--;
			ptr = realloc (ptr,nPessoas*SIZE);
			printf("\nRemovido!\n");
			break;
		}
	}

	if ( nEncontrado==1 )
		printf("\nNão encontrado!\n");
	
	system("pause");
	return ptr;
}

void Pesquisa(void *ptr){
	char nome[10];
	printf("Digite o nome:");
	scanf("%s",nome);
	getchar();
	int nEncontrado=1;

	if ( nPessoas==0 ){
		printf("\nAgenda Vazia!\n");
		system("pause");
		return ptr;
	}

	for (int i=0;i<nPessoas;i++){
		if (strcmp(nome,(char *)ptr+SIZE*i)==0){
			printf("\n");
			printf("\nNome: %s",(char *)(ptr+(sizeof(char)*(i*SIZE))));
			printf("\nTelefone: %d",*(int*)(ptr+(sizeof(char)*10)+(i*SIZE)));
			printf("\nIdade: %d\n",*(int*)(ptr+((sizeof(char)*10)+sizeof(int))+(i*SIZE)));
			nEncontrado--;
			break;
		}
	}
	if ( nEncontrado==1 )
		printf("\nNão encontrado\n");

	system("pause");
	return ptr;
	
}

int main () {
	void *pBuffer = malloc (SIZE);
	if ( !pBuffer ){
		printf("\nNão foi possivel alocar!");
		exit(1);
	}
	while ( 1 ) { system("cls");
		printf("\n--------MENU--------\n");
        printf("1) Adicionar contato\n");
        printf("2) Apagar contato\n");
        printf("3) Buscar contato\n");
        printf("4) Listar contatos\n");
        printf("Outro para sair\n");

		switch ( getchar() ) {
		case '1':
			pBuffer = Adiciona(pBuffer);
			break;
		case '2':
			pBuffer = Remove(pBuffer);
			break;
		case '3':
			Pesquisa(pBuffer);
			break;
		case '4':
			Lista(pBuffer);
			getchar();//se n tiver esse getchar() ele pega o \n da ultima e faz o switch sair no default
			break;
		default:
			free(pBuffer);
			exit(0);
			break;
		}
	}
}