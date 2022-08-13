#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    system ("cls");

    /*
    char *frase = malloc (sizeof (char) * 6);

    strcpy (frase,"frase");

    printf ("%s",frase);

    char *p = strstr(frase,"se");

    printf("%s",strtok(frase,p));
    */

    char *entrada = malloc (6);

    entrada[0] = 't';
    entrada[1] = 'e';
    entrada[2] = 's';

    char c ='e';

    printf("%s",strtok(entrada,"s"));

}