#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op;
char *entrada,*nomes;

void adiciona () {
    entrada = malloc(sizeof(char)*30);

    printf("Digite o nome:");
    scanf("%s",entrada);
    
    printf("Voce alocou o nome: %s",nomes);
}

int main () {
    system("cls");

    while ( 1 ) {
        printf("\n1 Adicionar Nome");
        printf("\n2 Remover Nome");
        printf("\n3 Listar");
        printf("\n4 Sair\nEscolha: ");

        scanf("%d",&op);

        switch ( op ) {
        case 1:
            adiciona();
            break;
        case 2:

            break;
        case 3:

            break;; 
        default:
            exit ( 1 );
        }
    }
    
}