// 408 19年41题
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

// 双指针寻找单链表中间元素，并将链表一分为二
void FindMiddle(LinkList L,LinkList &L2){
    LinkList pm,pe = L->next;
    pm = pe = L->next;
    L2 = (LinkList)malloc(sizeof(LNode));
    while(pe->next&&pe->next->next){
        pe = pe->next->next;
        pm = pm->next;
    }
    L2->next = pm->next;
    pm->next = NULL;
}

// 三指针原地逆置链表
void ListReverse(LinkList &L){
    LinkList s,p,t;
    s = L->next;
    if(s == NULL){
        return;
    }
    p = s->next;
    if(p == NULL){
        return;
    }
    t = p->next;
    while(t != NULL){
        p->next = s;
        s = p;
        p = t;
        t = t->next;
    }
    p->next = s;
    L->next->next = NULL;
    L->next = p;
    return;
}
// 合并两个链表
int ListMerge(LinkList L,LinkList L2){
    LinkList per,p,q;
    per = p = L->next;
    p = p->next;
    q = L2->next;
    printf("%d\n", per->data);
    while(p!=NULL&&q!=NULL){
        per->next = q;
        q = q->next;
        per = per->next;
        printf("%d\n", per->data);
        per->next = p;
        p = p->next;
        per = per->next;
        printf("%d\n", per->data);
    }
    // if(p!=NULL){
    //     per->next = p;
    // }
    if(q!=NULL){
        per->next = q;
    }
    return 9999;
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

int main(){
    LinkList L,L2;
    int a;
    ListTailInsert(L);
    ListPrint(L);
    FindMiddle(L,L2);
    ListPrint(L);
    ListPrint(L2);
    ListReverse(L2);
    ListPrint(L2);
    a = ListMerge(L,L2);
    printf("%d\n",a);
    ListPrint(L);
    return 0;
}