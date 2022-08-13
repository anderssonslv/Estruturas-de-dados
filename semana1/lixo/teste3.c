#include <stdio.h>
#include <stdlib.h>

int main () {
    char *nomes;

    nomes = malloc(20 * sizeof(char));

    printf("%d",sizeof(*nomes));

}