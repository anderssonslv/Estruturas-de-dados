#include <stdio.h>

void frac(float num, int* inteiro, float* frac){
    inteiro = &num; 
    frac = &num;

    printf("%d  %f",**inteiro,*frac);
}

int main () {
    float f=2.75;
    int*i = (char) &f;

    float *ptrF =(int) &f;
    ptrF++;

    frac (f , i, ptrF);
}
