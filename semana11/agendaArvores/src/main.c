#include "../lib/source.h"
#include "../lib/avl.c"

//arvore insere corretamente, e as alturas estão corretas, rotações funcionando
int c = 1;

void def_PFactor () {//Define o fator de precedencia
	printf("\n 1 nome | 2 idade");
	printf("\n Digite fator de precedencia: ");
	char c[1];//pq se n atoi fica dando warning
	c[0] = getchar();

	fflush(stdin);

	if ((int)c[0] > 48 && (int)c[0]<51)
		PF = atoi(c);
	else printf("def_PFactor -> Fora de parametro");
}

void *createRoot () {
    return NULL;
}

Node *newNode (char *nome,int age, int phone){
	Node *new = (Node*) malloc (sizeof(Node));

	if (!new)
		return NULL;

	strcpy (new->nome,nome);
	new->age = age;
	new->phone = phone;
    new->L = NULL;
    new->R = NULL;
	new->alt = 1;
    new->color = RED;

	return new;
}

Node *createPerson (char *argv[]) {//Esta assim para testes na linha de comando
	return newNode(argv[c],atoi(argv[c+1]),atoi(argv[c+2]));
}

int Push (Node **root,Node *person){
	int compP = 0 ,compR = 0;
	if (!(*root))
		*root = person;
	else {
		if (PF==1){
			compP = person->age;
			compR = (*root)->age;
		} else {
			if (strcmp(person->nome,(*root)->nome)>=1)
				compP = 1;
			else compR = 1;
		}		

		if (compP > compR){
			Push(&(*root)->R,person);
			(*root)->alt = maior (altura((*root)->L), altura((*root)->R)) +1;
			if (Balanceamento(root))
				return 0;
			else return 1;
		}
		else if (compP < compR){
			Push (&(*root)->L,person);
			(*root)->alt = maior (altura((*root)->L), altura((*root)->R)) +1;
			if (Balanceamento(root))
				return 0;
			else return 1;
		} 
		else return 0;

	}
}

void List (Node *root){
	if (root) {
		List(root->L);
		printf("%s",root->nome);
		List(root->R);
	}
}

Node* Pop(Node **root,char *nome){
    if (!(*root))
		return NULL;
	else {
        if (strcmp(nome,(*root)->nome) == 0) {
            if ((*root)->L == NULL && (*root)->R == NULL){//caso seja nó folha
                free((*root));
                return NULL;
            }
            else {
                if ((*root)->L != NULL && (*root)->R != NULL) {

                }
                else {
                    Node *aux;
                    if ((*root)->L != NULL)
                        aux = (*root)->L;
                    else aux = (*root)->R;
                    free (*root);

                    return aux;
                }
            }
        } else {
            if ( strcmp(nome,(*root)->nome) >=1)
                (*root)->R = Pop (&(*root)->R,nome);
            else (*root)->L = Pop (&(*root)->L,nome);
            return *root;
        }
	}
}

int main(int argc,char *argv[]) { system("cls");
	Node *root = createRoot();

	for (int i = 0; i < argc/3-1; i++){
		Push (&root,createPerson(argv));
		c+=3;
	}

	char NOMEE[5]  = {'A','l','a','n','\0'};

	root = Pop(&root,NOMEE);

	/*
	while (1) {
		printf("\n1 Push \n2 List \n3 Pop \n4 Reset");
		switch ( getchar() ) {
			case '1':
				Push(root,createPerson(NULL));
				break;
			case '2':
				List(root);
			break;
			default:
				break;
		}
		fflush(stdin);
	}
	*/

}