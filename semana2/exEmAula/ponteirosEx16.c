#include <stdio.h>

/*
 Considere a seguinte declarac¸ao: int A, *B, **C, ***D; Escreva um programa que leia a ˜
variavel a e calcule e exiba o dobro, o triplo e o qu ´ adruplo desse valor utilizando apenas ´
os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D
o quadruplo. 
*/

int main () {
    int A, *B, **C,***D;

    D=&C; C=&B; B=&A;

    A=5;

    printf("%d,%d,%d,%d",A,(*B*2),(**C*3),(***D*4));


}