#include <stdio.h>
#include <stdlib.h>

int main () {
    system ("cls");

    int i=2;
    float f=5.7;
    char c= 'a';

    int *ptrI = &i;
    float *ptrF = &f;
    char *ptrC = &c;

    printf("valores: i=%d f=%f c=%c",i,f,c);

    *ptrI = 10;
    *ptrF = 2.68;
    *ptrC = 'z';

    printf("\n\nNovos valores: i=%d f=%f c=%c (alterados com ponteiro)",i,f,c);






}