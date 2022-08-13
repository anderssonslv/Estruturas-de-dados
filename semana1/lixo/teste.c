#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa
{
    char nome[30];
    int idade;
}Pessoa;

int main (){
    system("cls");
    Pessoa *p;

    p = (Pessoa *) malloc(sizeof(Pessoa));

    if ( !p )
        printf("Erro de alocação!");
    else {
        printf("Digite nome: ");
        scanf("%s",p->nome);//scanf("%s",&(*p).nome); funciona da mesma forma

        printf("Digite idade: ");
        scanf("%d",&p->idade);

        printf("Voce eh %s, e tem %d anos",p->nome,p->idade);
    }

}