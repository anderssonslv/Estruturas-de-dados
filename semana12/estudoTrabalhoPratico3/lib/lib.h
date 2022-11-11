#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int num;
    struct Node *L,*R;
    int alt;
}Node;