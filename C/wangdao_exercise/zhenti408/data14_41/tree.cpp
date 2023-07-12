#include "tree.h"

int perorder(BiTree p, int i){
    static int wpl = 0;
    if(p!=NULL){
        printf("%d--%d\n",p->data,i);
        if (NULL == p->left && NULL == p->right){
            wpl = wpl+i*p->data;
        }
        perorder(p->left,i+1);
        perorder(p->right,i+1);
    }
    return wpl;
}
int main(){
    int wpl;
    BiTree tree = NULL;
    BiTree p;
    ElemType i;
    ptag head,tail,listnew,pcur;
    while (scanf("%d", &i)){
        if (0 == i){
            break;
        }
        p = (BiTree)calloc(1,sizeof(BiTNode));
        p->data = i;
        listnew = (ptag)calloc(1,sizeof(tag));
        listnew->p = p;
        if (NULL == tree){
            tree = p;
            head = listnew;
            tail = listnew;
            pcur = listnew;
            continue;
        }else{
            tail->next = listnew;
            tail = listnew;
        }
        if (NULL == pcur->p->left){
            pcur->p->left = p;
        }else if(NULL == pcur->p->right){
            pcur->p->right = p;
            pcur = pcur->next;
        }
    }
    wpl = perorder (tree, 0);
    printf("%d\n", wpl);
    return wpl;
}