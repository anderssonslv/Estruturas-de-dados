#include <stdio.h>
#include <stdlib.h>

char nome[10];
int telefone,idade;
int size = sizeof(nome) + sizeof(idade) + sizeof(telefone);

void Adiciona(void *p){
    printf("Digite nome: ");
    scanf("%s",(char *)p);//Eu to contando q isso vai fazer a string ser 10, mas acho q n

    p+=10;

    printf("Digite telefone: ");
    scanf("%d",&telefone);
    p = (int *) telefone;

    p+=4;
    printf("Digite idade: ");
    scanf("%d",&idade);
    p = (int *) idade;

    size*=2;
}

int main  () { system ("cls");
    void *pBuffer = malloc (size+1);

    printf("End que aponta o pBuffer: %d",pBuffer);

    while ( 1 ) { 
        printf("\n-----MENU-----\n");
        printf("1) Adicionar contato\n");
        printf("2) Apagar contato\n");
        printf("3) Buscar contato\n");
        printf("4) Listar contatos\n");
        printf("Outro para sair\n");

        char op = getchar();
        getchar();
        switch (op){
            case '1':
                Adiciona(pBuffer);
                
                pBuffer-=14;
                printf("%s",*(char*)pBuffer);

                pBuffer+=10;
                printf("\n%d",*(int*)pBuffer);
                
                pBuffer+=4;
                printf("\n%d",*(int*)pBuffer);
                break;
            case '2':

                break;
            case '3':
                
                break;
            case '4':
                break;
            default:
                free(pBuffer);
                break;
        }
    }
}