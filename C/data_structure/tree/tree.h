#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;
typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode;
typedef struct tag{
    BiTNode *p;
    struct tag *next; 
}tag;
