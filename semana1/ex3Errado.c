#include <stdio.h>
#include <stdlib.h>

struct Agenda {//Essa struct ocupa 36 bytes
    char nome[10];
    char telefone[20];
    int idade;
}Agenda;

void Adiciona(struct Agenda *a,int *size, void *pBuffer){

    printf ("\nDigite nome: ");
    fgets(a[*size].nome,10,stdin);

    getchar();

    printf("\nDigite telefone: ");
    fgets(a[*size].telefone,20,stdin);

    printf("\nDigite Idade: ");
    scanf("%d",a[*size].idade);//usar &?

    realloc (pBuffer, sizeof(*a) * (*size) );
    *size++;

}

void Lista(struct Agenda *a,int *size){
    for (int i=0;i<*size;i++){
        printf("\n-----------------");
        printf("%s   ",*a[i].nome);
        printf("%s   ",*a[i].telefone);
        printf("%d   ",a[i].idade);
    }
}


int main () {
    system("cls");
    int size=0;

    struct Agenda agenda;

    void *pBuffer = &agenda;//como linka a variavel void com a struct???? coloquei assim mas n deve ser

    pBuffer = malloc(sizeof(agenda)*1);

    while ( 1 ) { 
        printf("\n-----MENU-----\n");
        printf("1) Adicionar contato\n");
        printf("2) Apagar contato\n");
        printf("3) Buscar contato\n");
        printf("4) Listar contatos\n");
        printf("Outro para sair\n");

        char op = getchar();
        getchar();
        switch (op){
            case '1':
                Adiciona(&agenda,&size,&pBuffer);
                break;
            case '2':

                break;
            case '3':
                
                break;
            case '4':
                Lista(&agenda,&size);
                break;
            default:
                free(pBuffer);
                break;
        }
    }
    
}

