/* Fazer um programa que testa se uma sequencia de caracteres fornecida pelo usuario eh um 
palindromo, ou seja, eh uma palavra cuja a primeria metade eh simetrica a segunda metade. 
Veja os exemplos:

AABCCBAA - sim
ADDFDDA - sim
ABFFBB - nao

O usuario digita uma letra e tecla enter ate que o ele digite x e enter para terminar a sequencia.

Implemente a funcao POP e PUSH de pilha e resolva o problema com elas.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Push(char vet[],char c,int* pos){
	vet[*pos] = c;
	*pos+=1;
	vet[*pos] = '\0';
}

char Pop(char vet[],int *pos){
	//empty
	*pos-=1;
	char del = vet[*pos];
	vet[*pos]='\0';
	return del;
}

void ehPalindromo(char vet[],int *pos){
	char aux [15];
	char impar=NULL;

	int metade = strlen(vet)/2;
	for (int i=0; i<metade; i++){
		aux[i] = Pop(vet,pos);
		aux[i+1]='\0';
	}
	
	if (strlen(vet)!=strlen(aux))
		impar = Pop(vet,pos);
	
	if (strcmp(vet,aux)==0)
		printf("eh palindromo!");

	
	//aqui ele restaura o conteudo de volta pro vet
	if (impar){
		vet[*pos] = impar;
		*pos+=1;
	}
	
	int t = strlen(aux);
	for (int i=0;i<t;i++){
		vet[*pos]=Pop(aux,&t);
		*pos+=1;
	}
}

int main (){
	int pos=0;
	char c;
	char vet[30];

	system("cls");
	while (1) {
		printf("\nDigite um char: ");
		c = getchar();

		if (c=='x'){
			ehPalindromo(vet,&pos);
			exit(0);
		}

		fflush(stdin);

		Push(vet,c,&pos);
		puts(vet);
	}
	
}