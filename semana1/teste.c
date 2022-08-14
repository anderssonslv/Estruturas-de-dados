#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char *buffer = malloc (sizeof(20));

    bufferSize(buffer);

    
    printf("Digite a str: ");
    fgets (buffer,20,stdin);

    //realloc (buffer, sizeof(char) * strlen (buffer));

    printf ("%d",sizeof(buffer));
}

