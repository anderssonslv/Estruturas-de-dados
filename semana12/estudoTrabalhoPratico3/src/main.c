#include "../lib/lib.h"

Node *createNode (int n) {
    Node *new = (Node *) malloc (sizeof(Node));
    if (!new) {
        printf("Erro de alocação!");
        return NULL;
    }
    new->L = NULL;
    new->R = NULL;
    new->alt = 0;
    new->num = n;
    return new;
}

int maior (int a, int b){
    return a>b? a:b;
}

int altura (Node *tree) {
    if (!tree) return -1;
    return tree->alt;
}

int FB (Node *tree){
    if (!tree)
        return 0;
    return altura(tree->L) - altura (tree->R);
}

Node* RSE(Node **root){
    Node *Aux = (*root)->R; // Aux aponta para a subárvore direita da raiz root
    (*root)->R = Aux->L;
    Aux->L = *root; // o filho L de Aux passa a ser a raiz root

    // recalcula a altura dos nós que foram movimentados
    (*root)->alt = maior(altura((*root)->L), altura((*root)->R)) + 1;
    Aux->alt = maior(altura(Aux->L), altura(Aux->R)) + 1;

    *root = Aux; 
}

Node* RSD (Node **root) {
    Node *Aux = (*root)->L;

    (*root)->L = Aux->R;
    Aux->R = *root;

    (*root)->alt = maior (altura((*root)->L), altura((*root)->R)) +1;
    Aux->alt = maior (altura(Aux->L),altura(Aux->R))+1;

    *root = Aux;
}

Node* RED (Node *root) {
    root->L = RSE (&root->L);
    return RSD (&root);
}

Node* RDE (Node *root) {
    root->R = RSD (&root->R);
    return RSE(&root);
}

int Balancear (Node *root){
    int fb = FB (root);

    if (fb < -1 && FB (root->R) <= 0)
        RSE(&root);
    else if (fb > 1 && FB(root->L) >= 0)
        RSD(&root);
    else if (fb > 1 && FB(root->L) < 0)
        RED (root);
    else if (fb < -1 && FB (root->R) > 0)
        RDE (root);
}   

void centerOrder (Node *tree) {
    if (!tree)
        return;
    centerOrder (tree->L);
    printf("[%d] ",tree->num);
    centerOrder(tree->R);
}

Node* Push (Node **tree,Node *Data) {
    if (!(*tree))
        (*tree) = Data;
    else{
        if (Data->num > (*tree)-> num)
            Push (&(*tree)->R,Data);
        else Push (&(*tree)->L,Data);
    }
    (*tree)->alt = maior (altura ((*tree)->L), altura((*tree)->R)) +1;
    Balancear((*tree));
    return *tree;
}

int main (int argc,char *argv[]) {
    Node *tree = NULL;
	for (int i = 1; i < 8; i++)
        tree = Push(&tree,createNode(atoi(argv[i])));
    centerOrder(tree);
}






















/*
void preOrder (Node *tree) {
    if (!tree)
        return;

    printf("[%d] ",tree->num);

    preOrder(tree->L);
    preOrder(tree->R);
}

void posOrder(Node *tree) {
    if (!tree)
        return;

    posOrder(tree->L);
    posOrder(tree->R);

    printf("[%d] ",tree->num);
}


//Exemplo sem ptr pra ptr

Node *turnL (Node *tree){ //Gira o lado esquerdo da raiz //essa usa somente um ponteiro
    Node *R = tree->R ,*RL = R->L; // R = Filho a direita do tree
    //RL Filho a esquerda do R (Filho a esquerda do filho a direta do tree);

    R->L = tree; // a esquerda do filho direita recebe tree
    tree->R = RL; // e a direta do tree recebe Filho a esquerda do R se tiver

    tree->alt = maior(altura(tree->L) , altura(tree->R)) +1;
    R->alt = maior(altura(R->L) , altura(R->R)) +1;

    return R;//retorna a nova sub/raiz q antes era a direira do tree
}
*/