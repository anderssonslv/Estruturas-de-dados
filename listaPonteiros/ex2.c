#include <stdio.h>

/*
Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e exiba o maior endereco
*/

int main () {

    int a=1,b=1;

    printf ("\n&A = %d    &B = %d\n",&a,&b);

    if (&a>&b)
        printf ("Endereco da var A : %d",&a);
    else printf("Endereco da var B : %d",&b);

}