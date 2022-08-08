#include <stdio.h>

int CalculaMaior(){//Lista 2 ex 1
    int n1,n2;
    printf("Digite o numero 1: ");
    scanf("%d",&n1);

    printf("Digite o numero 2: ");
    scanf("%d",&n2);

    if (n1==n2)
        printf("iguais");
    else if (n1>n2)
        printf("n1 eh maior");
    else printf("n2 eh maior");
}

int Contagem(){//Lista 3 ex 3
    printf("\nFazendo a contagem");
    for (int i=10;i>-1;i--){
        printf("%d\n",i);
        if (i==0)
            printf("Fim!");
    }
}

int PositivoNegativo(int a){//lista 7 ex 3
    if (a==0)
        return 0;

    if (a>0)
        return 1;
    else
        return -1;

}


float CalculaPeso(){
    printf("\n");
    float alt;
    char sexo;
    
    printf("Digite sua altura: ");
    scanf("%f",&alt);

    getchar();

    printf("Digite seu sexo[m/f]: ");
    scanf("%c",&sexo);

    if (sexo=='m')
        return (72.7*alt)-58;
    else return (62.1*alt)-44.7;
        
}



int main (){
    printf("Seu peso ideal é: %.2f",CalculaPeso());
}


