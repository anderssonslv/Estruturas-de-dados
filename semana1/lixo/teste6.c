#include <stdio.h>
#include <stdlib.h>

char *nomes;
int i=0;

void Adiciona (){
    char c;

    nomes = malloc ( sizeof (char) * 30);

    printf("\nDigite nome: ");

    getchar();
    while ( c!='\n' ){        
        c = getchar();
        nomes[i]=c;
        i++;
    }

    printf ("Nome adicionado: %s",nomes);
}

int main () {
    system("cls");
    int op;
    while ( 1 ) {
        printf("\n1 Adicionar Nome");
        printf("\n2 Remover Nome");
        printf("\n3 Listar");
        printf("\n4 Sair\nEscolha: ");

        scanf("%d",&op);

        switch ( op ) {
        case 1:
            Adiciona();
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