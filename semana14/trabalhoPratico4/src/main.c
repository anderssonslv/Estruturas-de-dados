#include <stdio.h>
#include <stdlib.h>

void sort (int vet[],int N) {
	int temp;
    for (int i = 0; i < N; i++) {
        int element = i;
        for (int j = i; j < N; j++) {
            if (vet[j] %2 == 0 && vet[element] %2==1)
                element = j;
        }
        temp = vet[i];
		vet[i] = vet [element];
		vet[element] = temp;
    }
}

void printVet(int data [],int n){
    for (int i = 0; i < n; i++) 
        printf (" %d",data[i]);
}

int * criaVet (int T) {
	int *vet = (int *) malloc (sizeof (int) * T);

	for (int i = 0; i < T; i++) {
		printf ("\nDigite numero [%d]: ",i);
		scanf ("%d",&vet[i]);
	}

	return vet;
}

int main () {
    int *vet,T;

	while ( 1 ) {
		printf ("\n1 Entrada\n2 Ordenar \n3 Listar \nOutro para sair\nEscolha: ");
		switch ( getchar() ) {
			case '1':
				if (vet) 
					free(vet);
				printf ("\n Digite tamanho do vetor: ");
				scanf ("%d",&T);
				vet = criaVet(T);
				break;
			case '2':
				sort(vet,T);
				break;
			case '3':
				printVet(vet,T);
				break;
			default:
				free(vet);
				exit(0);
				break;
		}
		fflush(stdin);
	}
}