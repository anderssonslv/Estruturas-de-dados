/*Faca um programa que leia 2 valores inteiros e chame uma funcao que receba estas 2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas variaveis A e B por exemplo e, apos a execucao da funcao, A contera o valor de B e B tera o valor de A.*/

#include <stdio.h>
#include <stdlib.h>

void Troca (int *A,int *B) {
    int aux;

    aux = *A;
    *A = *B;
    *B = aux;
}

int main () { 
    system ("cls");
    int A=5,B=7;

    Troca(&A,&B);//passa o end das var e altera o valor da var do main!

    printf ("\nA = %d B=%d",A,B);
}