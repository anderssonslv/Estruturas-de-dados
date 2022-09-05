#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *Adiciona(void *pBuffer){
	pBuffer = realloc (pBuffer,(4*sizeof(int))+ ((*(int*)pBuffer)+1)*(*(int*)(pBuffer+sizeof(int))));

	if (!pBuffer)
		printf("Erro de alocação");

	int *nPessoas = pBuffer;
	int *SIZE = pBuffer+sizeof(int);

	pBuffer += 4*sizeof(int);//avança os inteiros

	printf("\nDigite nome: ");
	scanf("%s",(char*)(pBuffer+(*nPessoas)*(*SIZE)));

	printf("\nDigite idade: ");
	scanf("%d",(int*)(pBuffer+(10*sizeof(char))+(*nPessoas)*(*SIZE)));

	printf("\nDigite telefone: ");
	scanf("%d",(int*)(pBuffer+10*sizeof(char)+sizeof(int)+((*nPessoas)*(*SIZE))));

	printf("[ %s ] [ %d ] [ %d ] ",(char*)(pBuffer+(*nPessoas)*(*SIZE)),*(int*)(pBuffer+10*sizeof(char)+(*nPessoas)*(*SIZE)),*(int*)(pBuffer+10*sizeof(char)+sizeof(int)+(*nPessoas)*(*SIZE)));
	
	*nPessoas+=1;

	pBuffer-= 4*sizeof(int);//volta os inteiros
	getchar();

	return pBuffer;
}

void *Remove (void *pBuffer){
	if (*(int*)pBuffer == 0)
		return pBuffer;

	pBuffer = realloc(pBuffer,(10*sizeof(char) + 4*sizeof(int)) + ((*(int*)pBuffer))*(*(int*)(pBuffer+sizeof(int))));
	
	int *nPessoas = pBuffer;
	int *SIZE = pBuffer+sizeof(int);
	int *i = pBuffer+2*sizeof(int);
	int *j = pBuffer+3*sizeof(int);

	void *nome = pBuffer + 4*sizeof(int) + (*nPessoas)*(*SIZE);//aponta pros 10 chars alocados no final

	printf("\nDigite nome: ");
	scanf ("%s",nome);

	pBuffer+=4*sizeof(int);
	for (*i = 0; *i < *nPessoas; *i+=1){
		if (strcmp((char*)nome,(char*)(pBuffer+*SIZE**i))==0){
			for ( *j = *i; *j < (*nPessoas) ; *j+=1) {
				*(char*)(pBuffer+*SIZE**j) = *(char*)(pBuffer+*SIZE*(*j+1));
				*(int*)(pBuffer+10*sizeof(char)+*SIZE**j) = *(int*)(pBuffer+10*sizeof(char)+*SIZE*(*j+1));
				*(int*)(pBuffer+sizeof(int)+10*sizeof(char)+*SIZE**j) = *(int*)(pBuffer+sizeof(int)+10*sizeof(char)+*SIZE*(*j+1));
			}
			*nPessoas-=1;
			pBuffer-=4*sizeof(int);
			pBuffer = realloc (pBuffer,(4*sizeof(int)) + (*nPessoas)*(*SIZE));
			printf("\nRemovido");
		}
	}
	
	
	printf("\n");
	system("pause");
	return pBuffer;
}

void Lista (void *pBuffer){
	int *nPessoas = pBuffer;
	int *SIZE = pBuffer+sizeof(int);
	int *i = pBuffer+2*sizeof(int);

	pBuffer+=4*sizeof(int);

	for (*i=0;*i<*nPessoas;*i+=1)
		printf("\n Nome: %s \n Idade: %d \n Tel: %d",(char*)(pBuffer+*SIZE**i),*(int*)(pBuffer+*SIZE**i+10*sizeof(char)),*(int*)(pBuffer+*SIZE**i+10*sizeof(char)+sizeof(int)));
	printf("\n");
	system("pause");
	getchar();
}

int main() {
	void *pBuffer = calloc (4,sizeof(int));

	if (!pBuffer)
		exit(0);

	*(int*)(pBuffer+sizeof(int)) = 10*sizeof(char) + 2*sizeof(int);
	
	//nPessoas/SIZE/i/j
	while ( 1 ) { system ("cls");
		printf("\n1 Adicionar\n2 Listar\n3 Remover\n");
		switch ( getchar() ) {
			case '1':
				pBuffer = Adiciona(pBuffer);	
				break;
			case '2':
				Lista(pBuffer);
				break;
			case '3':
				pBuffer = Remove(pBuffer);
				break;
			default:
			exit(0);
				break;
		}
	}
}