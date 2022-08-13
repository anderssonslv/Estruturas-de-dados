#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op,c=0;
char *entrada,*nomes;

void Adiciona () {
    entrada = malloc(sizeof(char)*30);

    printf("Digite o nome:");
    scanf("%s",entrada);
    
    if ( c==0 ){
        nomes = malloc(sizeof(char)*(strlen(entrada)));
        strcpy(nomes,entrada);
    }
    else {
        int tam = strlen(nomes) + strlen(entrada);
        realloc (nomes, sizeof(char) * tam);
        strcat(nomes,entrada);
    }
    free (entrada);

    
    printf("Voce alocou o nome: %s",nomes);
    c++;
}

void Remove () {
    entrada = malloc(sizeof(char)*30);

    printf("Digite o nome:");
    scanf("%s",entrada);

    int *p = strstr(nomes,entrada);//Recebe a pos da palavra


    printf("%d   %d", nomes , p);

    int j=0;
    for (int i=0; i<strlen(nomes);i++){
        char c = entrada[j];

        if (nomes >= p){
            strtok(nomes[i],c);//parece q strtok n le char
            j++;
        }
        nomes++;
    }

    printf("Voce alocou o nome: %s",nomes);
}

void Lista () {
    printf("%s",nomes);
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
            Adiciona();
            break;
        case 2:
            Remove();
            break;
        case 3:
            Lista();
            break;; 
        default:
            exit ( 1 );
        }
    }
    
}