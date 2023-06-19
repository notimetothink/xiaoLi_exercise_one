#include <stdio.h>
#define MAXSIZE 20

typedef int ElemType;
// 顺序存储线性表
typedef struct{
    ElemType data[MAXSIZE];
    int length; // 长度
}SqList;

// 获取第i个位置元素
int GetElem(SqList L,int i,ElemType &e){
    if(L.length==0 || i<1 || i>L.length+1){
        return false;
    }
    e = L.data[i-1];
    return true; 
}

// 打印整个列表
void PrintList(SqList L){
    int i;
    for(i=0;i<L.length;i++){
        printf("%3d",L.data[i]);
    }
    printf("\n");
}

// 插入操作
int InsertList(SqList &L, int i, ElemType e){
    if (L.length==MAXSIZE){
        return false;
    }
    if (i<0 || i>L.length+1){
        return false;
    }
    int k;
    if(i<=L.length){
        for(k=L.length-1;k>=i-1;k--){
            L.data[k+1] = L.data[k];
        }
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

// 删除操作
int ListDelete(SqList &L, int i, ElemType &e){
    if (L.length == 0){
        return false;
    }
    if (i<1||i>L.length){
        return false;
    }
    e = L.data[i-1];
    if(i!=L.length){
        for(int j = i;j<L.length;j++){
            L.data[j-1] = L.data[j];
        }
    }
    L.length--;
    return true;
}

int main(){
    SqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    
    // 插入测试
    // InsertList(L,2,60);
    // InsertList(L,5,60);

    // 删除测试
    ElemType e;
    ListDelete(L,2,e);
    printf("%3d\n", e);
    // 打印测试
    PrintList(L);
    
    // 查找测试
    // ElemType e;
    // e = 23;
    // printf("%d\n",e);
    // GetElem(L,1,e);
    // printf("%d\n",e);

    return 0;
}