#include <stdio.h>
#include <stdlib.h> 

typedef int ElemType;
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *left;
    struct BiTNode *right;
}BiTNode, *BiTree;

typedef struct tag{
    BiTNode *p;
    struct tag *next;
}tag, *ptag;