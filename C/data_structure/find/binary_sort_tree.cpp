// 二叉排序树
#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
// 树结构体
typedef struct BSTNode{
    Elemtype data;
    struct BSTNode *left,*right;
}BSTNode,*BiTree;
// 二叉结构树插入元素
int BST_insert(BiTree &T, Elemtype data){
    // 空树时的处理
    if (NULL == T){
        T =  (BiTree)malloc(sizeof(BSTNode));
        T->data = data;
        T->left = T->right = NULL;
        return 1;
    }
    BiTree p = T;
    BiTree parent;
    // 插入元素作比较,小左大右
    while(p){
        // 保留父亲节点，为插入元素做准备
        parent = p;
        if (data<p->data){
            p = p->left;
        }else if (data>p->data){
            p = p->right;
        }else{
            // 暂不考虑存在相同数据
            return 0;
        }
    }
    BiTree pnew = (BiTree)malloc(sizeof(BSTNode));
    pnew->data = data;
    pnew->left = pnew->right = NULL;
    if (data < parent->data){
        parent->left = pnew;
    }else{
        parent->right = pnew;
    }
    return 1;
}
// 创建二叉树
void create_BST(BiTree &T, Elemtype str[], int n){
    T = NULL;
    int i = 0;
    while(i<n){
        BST_insert(T,str[i]);
        i++;
    }
}
// 中序遍历
void InOrder(BiTree T){
    if (T!=NULL){
        InOrder(T->left);
        printf("%3d",T->data);
        InOrder(T->right);
    }
}
// 二叉查找树查找
BiTree BST_search(BiTree T, Elemtype data, BiTree &p){
    p = NULL;
    while (T!=NULL && T->data!=data){
        p = T;
        if (data<T->data){
            T = T->left;
        }else{
            T = T->right;
        }
    }
    return T;
}
int main(){
    BiTree T = NULL,parent,s;
    Elemtype str[7] = {54,20,66,40,28,79,58};
    create_BST(T,str,7);
    InOrder(T);
    printf("\n");
    s = BST_search(T,57,parent);
    if (s){
        printf("%d\n", s->data);
    }else{
        printf("没有");
    }
    return 0;
}