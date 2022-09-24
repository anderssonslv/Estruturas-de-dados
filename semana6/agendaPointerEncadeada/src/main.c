#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10*sizeof(char)+4*sizeof(int)

int *pBuffer = NULL;

int *frontPush(int *pBuffer, void *person){//person aponta pro q estava sendo apontado pelo buffer, buffer aponta pra person
	if (!pBuffer)
		return person;

	void *iniPerson = person;

	void **pessoaBuffer = (void*)&pBuffer;
	person+=10*sizeof(char)+3*sizeof(int);

	*(int *)person = (int)pBuffer;//pessoa q ta sendo adicionada aponta pro que o buffer apontava
	*(int*)(*pessoaBuffer+10*sizeof(char)+2*sizeof(int)) = (int)iniPerson;//o prev da pessoa q tava no buffer aponta pra q entrou

	return iniPerson;
}

void endPush(int *pBuffer, void *person){//faz o next da ultima receber person, e o prev de person receber essa ultima
	void **pessoaBuffer = (void*)&pBuffer;
	int *nextLastPerson = (int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int));
	//.next da ultima pessoa do buffer

	*nextLastPerson = (int)person;
	person += SIZE-2*sizeof(int);//vai pro prev de person
	*(int*)person = (int)(int*)(*pessoaBuffer);//faz ele receber a ultima pessoa q tava no buffer
}

void list(int *pBuffer){
	if (!pBuffer)
		return;

	void **pessoaBuffer = (void*)&pBuffer;
	void *prev;

	//caso só tenha uma pessoa
	if (*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int))==0){
		printf("\n===========================");
		printf("\nNome: %s",(char*)pBuffer);
		printf("\nIdade: %d",(int*)*(int*)(*pessoaBuffer+10*sizeof(char)));
		printf("\nTelefone: %d",(int*)*(int*)(*pessoaBuffer+10*sizeof(char)+sizeof(int)));
		system("pause");
	}

	printf("\nPercorrendo pelo inicio\n");
	while (pBuffer!=0){
		printf("\nNome: %s",(char*)pBuffer);
		printf("\nIdade: %d",(int*)*(int*)(*pessoaBuffer+10*sizeof(char)));
		printf("\nTelefone: %d",(int*)*(int*)(*pessoaBuffer+10*sizeof(char)+sizeof(int)));
		pBuffer = (int*)*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int));
		if (pBuffer!=0)
			prev=pBuffer;
	} 
	pBuffer= prev;
	printf("\nPercorrendo pelo fim\n");
	while ((int*)pBuffer!=0){
		printf("\nNome: %s",(char*)pBuffer);
		printf("\nIdade: %d",(int*)*(int*)(*pessoaBuffer+10*sizeof(char)));
		printf("\nTelefone: %d",(int*)*(int*)(*pessoaBuffer+10*sizeof(char)+sizeof(int)));
		pBuffer = (int*)*(int*)(*pessoaBuffer+10*sizeof(char)+2*sizeof(int));
	} 
	printf("\n");
	system("pause");
}

int *Push (int *pBuffer, void *person){
	if (!pBuffer){
		pBuffer = frontPush(pBuffer,person);
		return pBuffer;
	}

	//compara se o elemento deve vir como primeiro
	if (strcmp((char*)pBuffer,(char*)person)>=1){
		pBuffer = frontPush(pBuffer,person);
		return pBuffer;
	}

	int *ini = pBuffer;
	int *prev;
	void **pessoaBuffer = (void*)&pBuffer;
	void **prevPessoa = (void*)&prev;
	while ( 1 ){
		prev = pBuffer;
		if (strcmp((char*)pBuffer,(char*)person)>=1){
			prev = (int*)*(int*)(*prevPessoa+10*sizeof(char)+2*sizeof(int));//prev recebe a pessoa de tras
			*(int*)(*prevPessoa+10*sizeof(char)+3*sizeof(int)) = (int) person;
			//nó da frente da pessoa de tras = nova pessoa
	
			*(int*)(*pessoaBuffer+10*sizeof(char)+2*sizeof(int)) = (int) person;
			//nó de trás da ultima pessoa = person

			//atualizando os nós da nova pessoa
			person += SIZE-2*sizeof(int);
			*(int*)person = *(int*)prevPessoa;
			person += sizeof(int);
			*(int*)person = *(int*)pessoaBuffer;//o nó da frente da nova pessoa recebe a pessoa do buffer
			
			return ini;
		}

		pBuffer = *(int**)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int));//incrementa

		if (!pBuffer){//se for a ultima pessoa
			endPush(prev,person);
			return ini;
		} 
		//só cai aqui se for no meio, então se a pessoa q eu to tentando adicionar vier antes da prox ele adiciona
	}
	return 0;
}

int *Pop (int *pBuffer) {//apaga o primeiro elemento pois segue as regras da fila
	void **pessoaBuffer = (void*)&pBuffer;
	void *del = pBuffer;

	if (!pBuffer)
		return 0;
	if (*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int))==0){
		free(pBuffer);
		return 0;//caso tenha apenas um elemento
	}

	if (*(int*)(*pessoaBuffer+10*sizeof(char)+2*sizeof(int))==0){
		pBuffer = (int*)*(int*)(*pessoaBuffer+SIZE-sizeof(int));
		//pBuffer vai pra prox pessoa
		*(int*)(*pessoaBuffer+10*sizeof(char)+2*sizeof(int)) = 0;
		//limpa o prev da segunda pessoa
		free(del);
		return pBuffer;
	}
	return 0;
}

int main() {
	void *person,*del,**pessoaBuffer = (void*)&pBuffer;
	while ( 1 ) { system ("cls");
		printf("\n1 Adicionar\n2 Listar\n3 Remover\n");
		switch ( getchar() ) {
			case '1':
				person = malloc (SIZE);
				if (!person)
					exit(0);
				printf("\nDigite nome: ");
				scanf("%s",(char*)person);
				printf("\nDigite idade: ");
				scanf("%d",(int*)(person+10*sizeof(char)));
				printf("\nDigite telefone: ");
				scanf("%d",(int*)(person+10*sizeof(char)+sizeof(int)));
				*(int*)(person+10*sizeof(char)+2*sizeof(int))=0;
				*(int*)(person+10*sizeof(char)+3*sizeof(int))=0;

				pBuffer = Push (pBuffer,person);
				if (!pBuffer)
					exit(1);
				getchar();
				break;
			case '2':
				list(pBuffer);
				getchar();
				break;
			case '3':
				pBuffer = Pop(pBuffer);
				getchar();
				break;
			default:
				if (pBuffer){
					while (1){
						del = *(void**)(pessoaBuffer);
						if (*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int))==0){
							free(del);
							break;
						}
						pBuffer = (int*)*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int));
						free(del);
						free(person);
					}	
					printf("\nBuffer Limpo!");
				}
				exit(0);
				break;
		}
	}
}