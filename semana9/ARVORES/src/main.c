#include "source.h"
//#include "source.c"

/*
arvore insere corretamente, e as alturas estão corretas

*/

int c = 1;

Node *createPerson (int argc,char *argv[]) {
	return newNode(argv[c],atoi(argv[c+1]),atoi(argv[c+2]));
}

void Push (Node **root,Node *person){
	if (!(*root))
		*root = person;
	else {
		if (person->age > (*root)->age)
			Push(&(*root)->R,person);
		else Push (&(*root)->L,person);
	}

	/*
    else if (PF == 1){
		if (strcmp(person->nome,(*root)->nome)>=1)
			Push(&(*root)->R,person);
		else Push(&(*root)->L,person);
	} else {

	*/
	
	//}
	(*root)->alt = maior (altura((*root)->L), altura((*root)->R)) +1;


	if (FB((*root)) > 1)
		turnR(&(*root));
	else if (FB(*root) < -1)
	 	turnL(&(*root));
}

void List (Node *root){
	if (root) {
		List(root->L);
		printf("%s",root->nome);
		List(root->R);
	}
}

int main(int argc,char *argv[]) { system("cls");

	for (int i = 0; i < argc; i++) {
		printf("\n%s",argv[i]);
	}
	

	Node *root = createRoot();
	//def_PFactor();

	while (1) {
		printf("\n1 Push \n2 List \n3 Pop \n4 Reset");
		switch ( getchar() ) {
			case '1':
				for (int i = 0; i < 8; i++){
					Push (&root,createPerson(argc,argv));
					c+=3;
				}
				break;
			case '2':
				List(root);
			break;
			default:
				break;
		}
		fflush(stdin);
	}
}