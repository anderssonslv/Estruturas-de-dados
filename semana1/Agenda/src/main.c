#include <stdio.h>
#include <stdlib.h>

#define SIZE ((sizeof(char)*10)+(sizeof(int)*2))

void *Adiciona(void *ptr);
void *Pesquisa(void *ptr);
void *Remove(void *ptr);
void Lista(void *ptr);

int c=0;

//char[10],int,int,char[10],int,int

int main () { system("cls");
	void *pBuffer = malloc(SIZE);

	int op;
	while ( 1 ) {
		printf("\n-----MENU-----\n");
        printf("1) Adicionar contato\n");
        printf("2) Apagar contato\n");
        printf("3) Buscar contato\n");
        printf("4) Listar contatos\n");
        printf("Outro para sair\n");
		scanf("%d",&op);

		switch (op) {
		case 1:
			Adiciona(pBuffer);
			break;
		case 2:
			Remove(pBuffer);
			break;
		case 3:
			Pesquisa(pBuffer);
			break;
		case 4:
			Lista(pBuffer);
			break;
		default:
			free(pBuffer);
			exit(1);
			break;
		}
	}
}

void *Adiciona (void *ptr) {
	if (c==0){
		printf("Digite nome: ");
		scanf("%s",(char*)ptr);
		getchar();
		printf("Digite telefone: ");
		scanf("%d",(int*)(ptr+sizeof(char)*10));
		getchar();
		printf("Digite idade: ");
		scanf("%d",(int*)(ptr+sizeof(char)*10+sizeof(int)));
	} else {
		realloc(ptr,SIZE*(c+1));
		printf("Digite nome: ");
		scanf("%s",(char*)(ptr+SIZE*c));
		getchar();
		printf("Digite telefone: ");
		scanf("%d",(int*)((ptr+sizeof(char)*10)+SIZE*c));
		getchar();
		printf("Digite idade: ");
		scanf("%d",(int*)((ptr+sizeof(char)*10+sizeof(int))+SIZE*c));
	}
	c++;
}

void *Remove(void *ptr){

}

void *Pesquisa(void *ptr){

}

void Lista(void *ptr){
	for (int i = 0; i < c-1; i++){
		printf("\n");
		printf("\nNome: %s",(char *)(ptr+(sizeof(char)*(i*SIZE))));
		printf("\nTelefone: %d",*(int*)(ptr+(sizeof(char)*10)*(i*SIZE)));
		printf("\nIdade: %d",*(int*)(ptr+((sizeof(char)*10)+sizeof(int))*(i*SIZE)));
	}
	
}