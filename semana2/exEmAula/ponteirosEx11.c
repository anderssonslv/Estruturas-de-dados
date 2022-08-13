#include <stdio.h>

int main () {
    int array[5] = {1,2,3,4,5};

    int *p = &array;

    //printf("%d",p[0]);

    for (int i=0;i<5;i++){
        if (p[i]%2==0)
            printf("\n end:%d pos :%d ",&p[i],p[i]);
    }








}