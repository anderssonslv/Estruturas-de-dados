#include <stdio.h>
#include <stdlib.h>

struct Agenda {
    char nome[10];
    char telefone[20];
    int idade;
}*Contato;


void *pBuffer () {
    
}

int main () {

    while ( 1 ) {
        printf("\n-----MENU-----\n");
        printf("1) Adicionar contato\n");
        printf("2) Apagar contato\n");
        printf("3) Buscar contato\n");
        printf("4) Listar contatos\n");
        printf("Outro para sair");

        char op = getchar();
        switch (op){
            case '1':
                
                break;
            case '2':

                break;
            case '3':

                break;
            case '4':

                break;
            default:
                break;
        }
    }
    
}

