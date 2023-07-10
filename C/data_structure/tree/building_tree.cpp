// 层次建树
#include "tree.h"

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
    return 0;
}