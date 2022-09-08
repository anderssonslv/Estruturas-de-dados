#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
	int num;
	struct ponto *prox;
}ponto;

int main () {
	ponto *ini;
	ponto *proxPonto;
	ponto *fim;
	ini = (ponto*) malloc (sizeof(ponto));
	proxPonto = ini;

	while ( 1 ) {
		printf("\n1 Add\n2 Lista");
		switch ( getchar() ) {
			case '1':
				printf("\nDigite n: ");
				scanf("%d",&proxPonto->num);
				getchar();

				proxPonto->prox = (ponto*) malloc(sizeof(ponto));
				proxPonto = proxPonto->prox;
				fim = proxPonto;
				proxPonto->prox = NULL;
				break;
			case '2':
				proxPonto = ini;
				while ( proxPonto != NULL ){
					printf("[ %d ]",proxPonto->num);
					proxPonto = proxPonto->prox;
				}
				proxPonto = fim;
			default:
				break;
		}
	}
	

}