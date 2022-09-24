#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10*sizeof(char)+4*sizeof(int)

int *pFirst = NULL;

int *frontPush(int *pFirst, void *person){//person aponta pro q estava sendo apontado pelo buffer, buffer aponta pra person

	if (!pFirst)//Só retorna e aponta pra person
		return person;

	void *iniPerson = person;

	void **pessoaBuffer = (void*)&pFirst;

	person+=10*sizeof(char)+3*sizeof(int);

	*(int *)person = (int)pFirst;//pessoa q ta sendo adicionada aponta pro que o buffer apontava
	*(int*)(*pessoaBuffer+10*sizeof(char)+2*sizeof(int)) = (int)iniPerson;//o prev da pessoa q tava no buffer aponta pra q entrou

	return iniPerson;
}

void endPush(int *pFirst, void *person){//faz o next da ultima receber person, e o prev de person receber essa ultima, o pFirst sempre vem apontando o ultimo contato

	if (!pFirst)//n botei print por que não é pra ser chamado quando null
		return;

	void **pessoaBuffer = (void*)&pFirst;
	int *nextLastPerson = (int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int));
	//.next da ultima pessoa do buffer

	*nextLastPerson = (int)person;
	person += SIZE-2*sizeof(int);//vai pro prev de person
	*(int*)person = (int)(int*)(*pessoaBuffer);//faz ele receber a ultima pessoa q tava no buffer
}

void List(int *pFirst){
	if (!pFirst){
		printf("Lista vazia!\n");
		system("pause");
		return;
	}

	void **pessoaBuffer = (void*)&pFirst;
	void *prev;

	//caso só tenha uma pessoa
	if (*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int))==0){
		printf("\n===========================");
		printf("\nNome: %s",(char*)pFirst);
		printf("\nIdade: %d",(int)*(int*)(*pessoaBuffer+10*sizeof(char)));
		printf("\nTelefone: %d \n",(int)*(int*)(*pessoaBuffer+10*sizeof(char)+sizeof(int)));
		system("pause");
		return;
	}

	printf("\n");

	printf("\nPercorrendo pelo inicio\n");
	while (pFirst!=0){
		printf("\n===========================");
		printf("\nNome: %s",(char*)pFirst);
		printf("\nIdade: %d",(int)*(int*)(*pessoaBuffer+10*sizeof(char)));
		printf("\nTelefone: %d",(int)*(int*)(*pessoaBuffer+10*sizeof(char)+sizeof(int)));
		pFirst = (int*)*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int));
		if (pFirst!=0)
			prev=pFirst;
	} 
	pFirst= prev;
	printf("\nPercorrendo pelo fim\n");
	while ((int*)pFirst!=0){
		printf("\nNome: %s",(char*)pFirst);
		printf("\nIdade: %d",(int)*(int*)(*pessoaBuffer+10*sizeof(char)));
		printf("\nTelefone: %d",(int)*(int*)(*pessoaBuffer+10*sizeof(char)+sizeof(int)));
		pFirst = (int*)*(int*)(*pessoaBuffer+10*sizeof(char)+2*sizeof(int));
	} 
	printf("\n");
	system("pause");
}

int *Push (int *pFirst, void *person){
	//a ordem de um char maiusculo é diferente de um minusculo na tabela ASCII
	char *name = person;
	*name = toupper(*(int*)person);

	if (!pFirst){
		pFirst = frontPush(pFirst,person);
		return pFirst;
	}

	//compara se o elemento deve vir com prioridade na ordem da fila
	if (strcmp((char*)pFirst,(char*)person)>=1){
		pFirst = frontPush(pFirst,person);
		return pFirst;
	}

	int *ini = pFirst;
	int *prev;
	void **pessoaBuffer = (void*)&pFirst;
	void **prevPessoa = (void*)&prev;
	while ( 1 ){
		prev = pFirst;
		if (strcmp((char*)pFirst,(char*)person)>=1){
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

		pFirst = *(int**)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int));//incrementa

		if (!pFirst){//se for a ultima pessoa
			endPush(prev,person);
			return ini;
		} 
		//só cai aqui se for no meio, então se a pessoa q eu to tentando adicionar vier antes da prox ele adiciona
	}
	printf("\nNão foi possivel adicionar!");
	system("pause");
	return 0;
}

int *Pop (int *pFirst) {//apaga o primeiro elemento pois segue as regras da fila
	void **pessoaBuffer = (void*)&pFirst;
	void *del = pFirst;

	if (!pFirst){
		printf("Lista vazia!\n");
		system("pause");
		return 0;
	}
	if (*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int))==0){
		free(pFirst);
		return 0;//caso tenha apenas um elemento
	}

	if (*(int*)(*pessoaBuffer+10*sizeof(char)+2*sizeof(int))==0){
		pFirst = (int*)*(int*)(*pessoaBuffer+SIZE-sizeof(int));
		//pFirst vai pra prox pessoa
		*(int*)(*pessoaBuffer+10*sizeof(char)+2*sizeof(int)) = 0;
		//limpa o prev da segunda pessoa
		free(del);
		return pFirst;
	}
	return 0;
}

void *Reset(void *pFirst){
	void *del,**pessoaBuffer = (void*)&pFirst;
	if (pFirst){
		while (1){
			del = *(void**)(pessoaBuffer);
			if (*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int))==0){
				free(del);
				return NULL;//qnd é o ultimo apaga e retorna
			}
			pFirst = (int*)*(int*)(*pessoaBuffer+10*sizeof(char)+3*sizeof(int));//incrementa
			free(del);//e apaga o que ficou no del
		}		
	}
	return NULL;
}

void Find(char *name,void *pFirst){
	char *aux = name;
	*aux = toupper(*(int*)name);
	void **personBuffer = &pFirst;
	while (pFirst!=NULL){
		if (strcmp((char*)pFirst,name)==0){
			printf("\nNome: %s",(char*)pFirst);
			printf("\nIdade: %d",(int)*(int*)(*personBuffer+10*sizeof(char)));
			printf("\nTelefone: %d \n",(int)*(int*)(*personBuffer+10*sizeof(char)+sizeof(int)));
			system("pause");
			return;
		}
		pFirst = *(int**)(*personBuffer+10*sizeof(char)+3*sizeof(int));
	}
	printf("Não encontrado!\n");
	system("pause");
}

int main() {
	void *person;
	while ( 1 ) { system ("cls");
		printf("\n1 Adicionar\n2 Listar\n3 Remover\n4 Buscar\n5 Reset\nOutro para sair\n");
		switch ( getchar() ) {
			case '1':
				person = malloc (SIZE);
				if (!person){
					printf("Erro de alocação\n saindo...");
					system("pause");
					exit(1);
				}
				printf("\nDigite nome: ");
				scanf("%s",(char*)person);
				printf("\nDigite idade: ");
				scanf("%d",(int*)(person+10*sizeof(char)));
				printf("\nDigite telefone: ");
				scanf("%d",(int*)(person+10*sizeof(char)+sizeof(int)));
				*(int*)(person+10*sizeof(char)+2*sizeof(int))=0;
				*(int*)(person+10*sizeof(char)+3*sizeof(int))=0;

				pFirst = Push (pFirst,person);
				if (!pFirst){
					printf("Erro de entrada\n saindo...");
					system("pause");
					exit(1);
				}
				getchar();
				break;
			case '2':
				List(pFirst);
				getchar();
				break;
			case '3':
				pFirst = Pop(pFirst);
				getchar();
				break;
			case '4':
				person = malloc(10*sizeof(char));
				if (!person){
					printf("Erro de alocação\n saindo...");
					system("pause");
					exit(1);
				}
				printf("\nDigite nome: ");
				scanf("%s",(char*)person);
				Find(person,pFirst);
				getchar();
				free(person);
				break;
			case '5':
				pFirst = Reset(pFirst);
				printf("Reset Finalizado...");
				system("pause");
				getchar();
				break;
			default:
				pFirst = Reset(pFirst);
				printf("\nBuffer Limpo!\nFinalizando...");
				exit(0);
				break;
		}
	}
}