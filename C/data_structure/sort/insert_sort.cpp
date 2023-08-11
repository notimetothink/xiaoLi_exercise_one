// 插入排序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int Elemtype;
typedef struct SSTable{
    Elemtype* elem;
    int len;
}SSTable;

void ST_init(SSTable &T, int len){
    T.len = len;
    T.elem = (Elemtype*)malloc(sizeof(Elemtype)*len);
    int i;
    srand(time(NULL));
    for (int i = 0; i < len; i++){
        T.elem[i] = rand()%100;
    }   
}
void ST_print(SSTable T){
    for (int i=0; i<T.len; i++){
        printf("%3d", T.elem[i]);
    }
    printf("\n");
}

void insert_sort(Elemtype A[], int n){
    int i ,j ,k;
    for (i=1;i<n;i++){
        k = A[i];
        for (j=i-1;j>=0&&A[j]>k;j--){
            A[j+1] = A[j];
        }
        A[j+1] = k;
    }
}

int main(){
    SSTable ST;
    ST_init(ST,10);//初始化
    ST_print(ST);
    insert_sort(ST.elem,10);
    ST_print(ST);
    return 0;
}