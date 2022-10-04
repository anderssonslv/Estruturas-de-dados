#include <stdio.h>
#include <stdlib.h>

float *pontos = NULL;

float *Push(int pos, int *qtd){
	float x,y;
	printf("\nDigite x: ");
	scanf("%f",&x);
	printf("\nDigite y: ");
	scanf("%f",&y);

	*qtd+=2;
	pontos = realloc(pontos,sizeof(float)*(*qtd));

	if (*qtd==2){//primeiro caso
		*pontos = x;
		pontos++;
		*pontos = y;
		pontos--;
		return pontos;
	}

	if (pos>=(*qtd)){//quer dizer q vai no final
		pontos += (*qtd-2);
		*pontos = x;
		pontos++;
		*pontos = y;

		pontos -= (*qtd-1);
	}


	if (pos==0 || pos<(*qtd)){//se for no inicio ou no meio ele arrasta a lista
		for (int i = *qtd-1; i>pos; i--)
			pontos[i] = pontos[i-2];
		
		pontos [pos] = x;
		pontos [pos+1] = y;
	}
	

	return pontos;
}

float *Pop (int pos,int *qtd){
	if (pos==0 || pos<(*qtd))
		for (int i = pos; i<*qtd; i++)
				pontos[i] = pontos[i+1];
	
	*qtd-=1;
	return realloc(pontos,sizeof(float)*(*qtd));
}

void Lista(int qtd){
	for (int i = 0; i < qtd; i++){
		printf("%.2f - ",pontos[i]);
	}
	
}

int main () {
	system("cls");
	int pos;
	int qtd=0;
	printf("Criacao de poligono com lista");
	while (1) {
		printf("\n1 Push pontos");
		printf("\n2 Pop pontos");
		printf("\n3 view");
		printf("\nselect: ");

		switch ( getchar() ){
			case '1':
				printf("Digite a posicao para inserir: ");
				scanf("%d",&pos);
				pontos = Push(pos,&qtd);
				break;
			case '2':
				printf("Digite a posicao para eliminar ");
				scanf("%d",&pos);
				pontos = Pop(pos,&qtd);
				break;
			case '3':
				Lista(qtd);
				break;
			default:
				free(pontos);
				exit(0);
				break;
		}
		fflush(stdin);
	}
	
}