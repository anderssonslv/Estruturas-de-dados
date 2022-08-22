#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE ((sizeof(char)*10)+(sizeof(int)*2))

void *Adiciona(void *ptr);
void *Pesquisa(void *ptr);
void *Remove(void *ptr);
void Lista(void *ptr);

int c=0;

int main () { system("cls");
	void *pBuffer = malloc(SIZE);

	if (!pBuffer){
		printf("\nNão foi possivel alocar");
		exit(0);
	}

	int op;
	while ( 1 ) { 
		printf("\n--------MENU--------\n");
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
			//free(aux); depois
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
	realloc(ptr,SIZE*(c+1));

	printf("Digite nome: ");
	scanf("%s",(char*)(ptr+SIZE*c));
	getchar();
	printf("Digite telefone: ");
	scanf("%d",(int*)((ptr+sizeof(char)*10)+SIZE*c));
	getchar();
	printf("Digite idade: ");
	scanf("%d",(int*)((ptr+sizeof(char)*10+sizeof(int))+SIZE*c));
	
	c++;
	return ptr;
}

void *Remove(void *ptr){
	char nome[10];
	int flag=-1;
	void *aux;

	if ( c==0 )
		printf("\nAgenda Vazia!");
	else {
		printf("Digite o nome:");
		scanf("%s",nome);
		getchar();
		for (int i = 0; i < c; i++){
			if (strcmp(nome,(char*)(ptr+SIZE*i))==0){
				flag=i;
			}
		}
		if (flag==-1){
			printf("Não encontrado!");
			return 0;
		}
		else if (flag>-1){
			aux = malloc (SIZE*(c-1));
			for (int i = 0; i < c; i++){
				if (i!=flag){
					if (i>flag){
						i++;
						c++;
					}
					strcpy((char*)aux+SIZE*i,(char*)(ptr+(SIZE*(i-1))));

					*(int *)(aux+(SIZE*i)+sizeof(char)*10) =*(int *)(ptr+(sizeof(char)*10)+(SIZE*(i-1)));
					
					*(int *)(aux+(SIZE*i)+(sizeof(char)*10)+sizeof(int))=*(int *)(ptr+(sizeof(char)*10+sizeof(int)+(SIZE*(i-1))));
				}
				/*
				else if (i>=flag){
					strcpy((char*)aux+SIZE*i,(char*)(ptr+(SIZE*(i+1))));

					*(int *)(aux+(SIZE*i)+sizeof(char)*10) =*(int *)(ptr+(sizeof(char)*10)+(SIZE*(i+1)));

					*(int *)(aux+(SIZE*i)+(sizeof(char)*10)+sizeof(int))=*(int *)(ptr+(sizeof(char)*10+sizeof(int)+(SIZE*(i+i))));
				}
				*/
			}
			c--;
		}
	}
	c--;
	ptr=aux;
	free(aux);
	ptr = realloc(ptr,SIZE*c);
}

void *Pesquisa(void *ptr){
	return ptr;
}

void Lista(void *ptr){system("cls");
	for (int i = 0; i < c; i++){
		printf("\n");
		printf("\nNome: %s",(char *)(ptr+(sizeof(char)*(i*SIZE))));
		printf("\nTelefone: %d",*(int*)(ptr+(sizeof(char)*10)+(i*SIZE)));
		printf("\nIdade: %d",*(int*)(ptr+((sizeof(char)*10)+sizeof(int))+(i*SIZE)));
	}
}
/*
if (flag!=i){
	aux+=SIZE*i;
	strcpy(aux,ptr+(SIZE*i));
	aux-=SIZE*i;

	aux+=(SIZE*i)+sizeof(char)*10;
	*(int *)aux=*(int *)(ptr+(sizeof(char)*10)+(SIZE*i));
	aux-=(SIZE*i)+sizeof(char)*10;

	aux+=(SIZE*i)+(sizeof(char)*10)+sizeof(int);
	*(int *)aux=*(int *)(ptr+(sizeof(char)*10+sizeof(int)+(SIZE*i)));
	aux-=(SIZE*i)+(sizeof(char)*10)+sizeof(int);
	
}
*/

		/*
		for (int i = 0; i < c; i++){
			if (strcmp(nome,(char*)(ptr+SIZE*i))==0){//arrumado
				flag=i;//pega a posição do c
				aux=malloc(SIZE*c-1);
				for (int i = 0; i < c; i++){//ta dando problema
					if (flag!=i){//se não for a posição do c ele adiciona
						scanf((char *)(ptr+(SIZE*i)),aux);
						scanf((int *)(ptr+(sizeof(char)*10)+(SIZE*i)),aux);
						scanf((int *)(ptr+(sizeof(char)*10+sizeof(int)+(SIZE*i))),aux);
					}
				}//Ta apagando apenas o ultimo e escrevendo lixo no primeiro
			}
		*/
		/*
		for (int i = 0; i < c; i++){
				if (i!=flag){
					for (int j = 0; j < (SIZE*i); j++){
						aux++;
						passo++;
					}
					aux = (char *)ptr+(SIZE*i);
					for (int j = 0; j < passo; i++){//volta pro inicio
						aux--;
						passo--;
					}
					for (int j = 0; j < (10+(SIZE*i)); j++){
						aux++;
						passo++;
					}
					aux = *(int *) (ptr+(SIZE*i)+(sizeof(char)*10));
					for (int j = 0; j < passo; i++){//volta pro inicio
						aux--;
						passo--;
					}
					for (int j = 0; j < (10+(SIZE*i))+sizeof(int); j++){
						aux++;
						passo++;
					}
					aux = *(int *) (ptr+(SIZE*i)+(sizeof(char)*10)+(sizeof(int)*2));
					for (int j = 0; j < passo; i++){//volta pro inicio
						aux--;
						passo--;
					}
				}
			}
		*/