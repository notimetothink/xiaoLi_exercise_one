#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

// 获取链表第i元素
bool GetElem(LinkList L,int i,ElemType &e){
    LinkList p;
    p = L->next;
    int j=1;
    while(p&&j<i){
        p = p->next;
        j++;
    }
    if(!p||j>i){
        return false;
    }
    e = p->data;
    return true;
} 

// 元素插入链表
bool ListInsert(LinkList &L,int i,ElemType e){
    LinkList p,s;
    p = L->next;
    int j=1;
    if(p&&j<i){
        p = p->next;
        j++;
    }
    if(!p||j>i){
        return false;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除i位置元素
bool DeleteList(LinkList &L,int i,ElemType &e){
    LinkList p,q;
    int j=1;
    p = L->next;
    if(p&&j<i){
        p = p->next;
        j++;
    }
    if(!p||j>i){
        return false;
    }
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

int main(){
    
    return 0;
}