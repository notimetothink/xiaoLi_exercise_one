#include <stdio.h>
#include <stdlib.h>

// 树有关
typedef char Elemtype;
typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;
typedef struct tag{
    BiTNode *p;
    struct tag *next; 
}tag;

// 队列相关
typedef BiTree BiElemType;
typedef struct LinkNode{
    BiElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
bool EnQueue(LinkQueue &Q,BiElemType x);
bool DeQueue(LinkQueue &Q,BiElemType &x);
