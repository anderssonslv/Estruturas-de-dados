#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nomes=0;

void Add (void *pBuffer){
	printf("\nDigite nome: ");
	if (nomes!=0)
		scanf("%s",(char *)pBuffer+strlen(pBuffer));
	else scanf("%s",(char *)pBuffer);
	getchar();
	nomes++;
}	

void Remove (void *pBuffer){
	char nome[30];
	printf("\nDigite nome: ");
	scanf("%s",&nome);
	char *p = strstr((char *)pBuffer,nome);

	int i;
	int bufferSize = (int) strlen((int*)pBuffer);
	int nameSize = (int) strlen(nome);

	if (!p){
		printf("\nnão encontrado");
		return;
	}
	for (i = 0; i < bufferSize; i++){
		if (pBuffer==p){
			*(char*)pBuffer=*(char*)(pBuffer+nameSize);
			break;
		}
		pBuffer++;
	}
	pBuffer-=i-1;
	pBuffer+=bufferSize;
	pBuffer-=nameSize+1;
	*(char*)pBuffer='\0';
}

int main (){ 
	void *pBuffer = malloc (sizeof(char)*30);
	while ( 1 ) { system("cls");
		if (nomes!=0)
			printf("[ %s ]",(char*)pBuffer);

		printf("\n1 Adicionar nome");
		printf("\n2 Remover nome\n");
		switch ( getchar() ) {
		case '1':
			Add(pBuffer);
			break;
		case '2':
			Remove(pBuffer);
			break;
		default:
			break;
		}
	}
	
}