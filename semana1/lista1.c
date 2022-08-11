#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    system("cls");

    char *nome;

    nome = ( malloc ( sizeof ( char ) * 15 ) );

    printf("Digite um nome: ");
    scanf("%s",nome);



    puts(nome);

    exit(1);
}

