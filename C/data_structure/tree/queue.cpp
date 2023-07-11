// 辅助队列
#include "tree.h"
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
bool EnQueue(LinkQueue &Q,BiElemType x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = Q.rear->next;
    return true;
}
// 出队
bool DeQueue(LinkQueue &Q,BiElemType &x){
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