#include <stdio.h>

void imprimeArray(char *c){

    for (int i = 0; i < 5; i++){
        printf("%c",*c);
        c++;
    }
    
}

int main () {
    char c [5] = {'t','e','s','t','e'};

    imprimeArray(&c);    
}