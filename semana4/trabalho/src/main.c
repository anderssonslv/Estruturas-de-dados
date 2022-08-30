#include <stdio.h>
#include <stdlib.h>

int *Procura (int *pBuffer,int num,int *tam){
	int *inicio = pBuffer;
	int c=0,encontrado=0;
	
	//procura por 1
	for (c = 0; c < *tam; c++){
		if (num == *pBuffer){
			encontrado=1;
			for (int j = c; j < *tam; j++){
				*pBuffer = *(pBuffer+1);
				pBuffer++;
			}
			*tam-=1;
			break;
		}
		pBuffer++;
	}

	pBuffer=inicio;

	if (encontrado==0){
		int s1,s2;
		for (int i = 0; i < *tam; i++) {
			s1 = *(pBuffer+i);
			s2 = *(pBuffer+(i+1));
			if ( (s1+s2) == num ){
				encontrado = 2; 
				for (int j = i; j < *tam; j++)
					*(pBuffer+j)=*(pBuffer+(j+1));

				for (int g = i; g < *tam; g++)
					*(pBuffer+g)=*(pBuffer+(g+1));
				*tam-=2;
				break;
			}
		}
		if (encontrado==2)
			printf ("\n %d + %d = %d \n",s1,s2,num);
	}
		
	for (int i = 0; i < *tam; i++) 
		printf(" [ %d ] ",*(pBuffer+i));

	if (encontrado>0)
		pBuffer = realloc (pBuffer,sizeof(int)*(*tam));
	return pBuffer;
}


int main () {
	int *pBuffer;
	int tam=0,num;

	printf("\nDigite o tamanho do vetor: ");
	scanf("%d",&tam);
	getchar();

	pBuffer = malloc(tam*sizeof(int));

	for (int i = 0; i < tam; i++) 
		*(pBuffer+i) = rand();
	
	for (int i = 0; i < tam; i++) 
		printf(" [ %d ] ",*(pBuffer+i));

	printf("\nDigite um numero: ");
	scanf("%d",&num);
	getchar();

	pBuffer = Procura(pBuffer,num,&tam);
	system("pause");
	free(pBuffer);
}