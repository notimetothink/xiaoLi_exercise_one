// 层次建树
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

void PreOrder(BiTNode *p){
    if(p!=NULL){
        putchar(p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}
void InOrder(BiTNode *p){
    if(p!=NULL){
        InOrder(p->lchild);
        putchar(p->data);
        InOrder(p->rchild);
    }
}

void PostOrder(BiTNode *p){
    if(p!=NULL){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        putchar(p->data);
    }
}

void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q,p);
        putchar(p->data);
        if (p->lchild != NULL)
            EnQueue(Q,p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q,p->rchild);    
    }
    
}
int main(){
    BiTNode *pnew;
    BiTNode *tree = NULL;
    Elemtype c;
    tag *head;
    tag *tail,*listNew,*pcur;
    while(scanf("%c", &c)){
        if ('\n' == c){
            break;
        }
        pnew = (BiTNode*)calloc(1,sizeof(BiTNode));
        pnew->data = c;
        listNew = (tag*)calloc(1,sizeof(tag));
        listNew->p = pnew;
        if (NULL == tree){
            tree = pnew;
            head = listNew;
            tail = listNew;
            pcur = listNew;
            continue;
        }else{
            tail->next = listNew;
            tail = listNew;
        }
        if (NULL == pcur->p->lchild){
            pcur->p->lchild = pnew;
        }else if(NULL == pcur->p->rchild){
            pcur->p->rchild = pnew;
            pcur = pcur->next;
        }
    }
    printf("--------前序遍历----------\n");//也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
    PreOrder(tree);
    printf("\n--------中序遍历------------\n");//先打印左孩子，打印父亲，打印右孩子
    InOrder(tree);
    printf("\n--------后序遍历------------\n");//先打印左孩子，打印右孩子，最后打印父亲
    PostOrder(tree);
    printf("\n--------层序遍历------------\n");
    LevelOrder(tree);
    return 0;
}