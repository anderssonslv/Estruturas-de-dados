/*Faca um programa que leia dois valores inteiros e chame uma funcao que receba estes 2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na ´
segunda variavel. Escreva o conteudo das 2 variaveis na tela*/

#include <stdio.h>

void Compara (int *a, int *b) {
    int aux;
    if (!(*a>*b)){//se o conteudo de a não for maior q o de b
        aux = *a;
        *a = *b;//a aponta pro end da var primeira, aqui ele troca o conteudo dela
        *b = aux;//troca o conteudo da var segunda q é apontada
    }
}

int main () {
    int primeira=5, segunda=15;

    Compara (&primeira,&segunda);

    printf ("Primeira = [ %d ]   Segunda = [ %d ]",primeira,segunda);

}