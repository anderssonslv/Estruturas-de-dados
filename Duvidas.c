#include <stdio.h>
#include <stdlib.h>

int main () {system("cls");

    void *pBuffer = malloc(sizeof(50));

    printf("Digite str: ");
    scanf ("%s",(char *)pBuffer);

    printf("\nDigite int1: ");
    scanf("%d",(int *)pBuffer);//pra ler tbm n precisa de *antes do cast independente do tipo

    printf("\nDigite o int2: ");
    scanf("%d",(int *)pBuffer);

    printf("\nSTR: %s, INT1: %d, INT2:%d",(char *)pBuffer,*(int *)pBuffer,*(int *)pBuffer);

    pBuffer+49;
    pBuffer='Z';
    printf("\n%c",(char *)pBuffer);

    pBuffer-49;
    printf("\n%c",(char *)pBuffer);
    //Parece que ele mostra sempre o ultimo dado
}

//printf("%s",(char *)pBuffer);//pra printar char não precisa de * antes do cast