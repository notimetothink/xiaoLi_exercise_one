#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

// 头插法创建链表
LinkList ListHeadInsert(LinkList &L){
    LNode *s;
    // LinkList s;
    ElemType x;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    // printf("%d",x);
    while(x!=9999){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
// 尾插法创建链表
LinkList ListTailInsert(LinkList &L){
    LinkList s,r;
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    r = L;
    scanf("%d", &x);
    while(x!=9999){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = r->next;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 打印链表
void ListPrint(LinkList L){
    L = L->next;
    while(L){
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}

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
    // p = L->next; //i后插入元素
    p = L;//i前插入元素
    int j=1;
    while(p&&j<i){
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
    p = L;
    while(p&&j<i){
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
    LinkList L;
    int e,i;
    scanf("%d",&i);
    bool a;
    // L = ListHeadInsert(L);
    ListTailInsert(L);
    ListPrint(L);
    // a = GetElem(L,3,e);
    ListInsert(L,i,9);
    ListPrint(L);
    DeleteList(L,1,e);
    ListPrint(L);
    DeleteList(L,3,e);
    ListPrint(L);
    DeleteList(L,2,e);
    ListPrint(L);
    // a = GetElem(L,4,e);
    // printf("%d\n", e);
    // if(a){
    //     printf("success\n");
    // }else{
    //     printf("fail\n");
    // }
    return 0;
}