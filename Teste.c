#include <stdio.h>
#include <stdlib.h>

void Teste();

int main () {system("cls");
    Teste();
}

void Teste () {
    void *pBuffer = malloc (10);

    *pBuffer[0]='a';

    *pBuffer[9]='z';

    for (int i=0;i<10;i++){
        printf("%c",pBuffer);
    }

}




/*
void T1 () {
    
    void *pBuffer = malloc(sizeof(10));

    printf("Digite str: ");
    scanf ("%s",(char *)pBuffer);

    printf("\nDigite int1: ");
    scanf("%d",(int *)pBuffer);//pra ler tbm n precisa de *antes do cast independente do tipo

    printf("\nDigite o int2: ");
    scanf("%d",(int *)pBuffer);

    printf("\nSTR: %s, INT1: %d, INT2:%d",(char *)pBuffer,*(int *)pBuffer,*(int *)pBuffer);

    for (int i=0;i<10;i++)
        pBuffer++;
    
    pBuffer=(char *)'Z';
    printf("\n%c",(char *)pBuffer);

    for (int i=0;i<10;i++){
        printf("\n%c",(char *)pBuffer);
        pBuffer--;
    }
    //Parece que ele mostra sempre o ultimo dado

    //esse "jeito" de incrementar deve estar errado
}
*/
//printf("%s",(char *)pBuffer);//pra printar char não precisa de * antes do cast