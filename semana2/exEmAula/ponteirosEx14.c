#include <stdio.h>

int main (){
    int vet[5] = {1,2,3,4,5}, num=7;

    int *p = &vet;

    for (int i=0;i<5;i++){
        *p=num;
        printf ("%d",*p);
        p++;
    } 

    for (int i = 0; i < 5; i++){
        printf("\n %d",vet[i]);
    }
    

}