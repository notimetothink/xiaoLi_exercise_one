// 层次建树
#include "tree.h"

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
    return 0;
}