// 链表实现队列
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
// 定义链表
typedef struct LinkNode{
    Elemtype data;
    struct LinkNode *next;
}LinkNode;
// 定义队列
typedef struct LinkQueue{
    LinkNode *front,*rear;
}LinkQueue;
// 初始化
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
// 判断是否为空
bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear){
        return true;
    }else{
        return false;
    }
}
// 入队
bool EnQueue(LinkQueue &Q,Elemtype x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = Q.rear->next;
    return true;
}
// 出队
bool DeQueue(LinkQueue &Q,Elemtype &x){
    if(IsEmpty(Q)){
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(p == Q.rear){
        Q.rear = Q.front;
    }
    free(p);
    return true;
}
int main(){
    LinkQueue Q;
    Elemtype x;
    InitQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    DeQueue(Q,x);
    printf("%d\n",x);
    DeQueue(Q,x);
    printf("%d\n",x);
    DeQueue(Q,x);
    printf("%d\n",x);
    return 0;
}