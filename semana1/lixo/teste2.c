#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    system("cls");

    char *nome;

    nome = ( malloc ( sizeof ( char ) * 50 ) );//inicialmente alocamos 50

    printf("Digite um nome: ");
    scanf("%s",nome);

    nome = (char *) realloc ( nome , sizeof (char) * strlen(nome) );

    exit(1);
}

