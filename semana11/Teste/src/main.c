#include <stdio.h>
#include <stdlib.h>

int main() {
	int *vet;

	vet = (int *) malloc ( 1000000 * sizeof ( int ) );

	for (int i = 0; i < 1000000; i++) 
		vet[i] = i;

	if ( vet )
		printf("%d %d %d",vet[15],vet[5000], vet[500000]);

	free(vet);

	return (0);
}