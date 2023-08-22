// 堆排序
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
// 交换
void swap(Elemtype &a, Elemtype &b){
    Elemtype temp = a;
    a = b;
    b = temp;
    return;
}
// 调整子树
void adjust_down(Elemtype A[], int dad, int len){
    // 左孩子
    int son = dad*2+1;
    while(son<len){
        if(son+1<len && A[son]<A[son+1]){
            son++;
        }
        if(A[son]>A[dad]){
            swap(A[son], A[dad]);
            dad = son;
            son = dad*2+1;
        }else{
            break;
        }
    }
}
// 堆排序
void heap_sort(Elemtype A[], int len){
    int i;
    for(i=len/2-1;i>=0;i--){
        adjust_down(A,i,len);
        // printf("%d %d\n",i,len);
    }
    swap(A[0],A[len-1]);
    for(i=len-1;i>0;i--){
        adjust_down(A,0,i);
        // printf("%d %d\n",i,len);
        swap(A[0],A[i-1]);
    }
}
int main(){
    SSTable ST; 
    ST_init(ST,10);//初始化 
    // Elemtype A[10] = { 3, 87, 2, 93, 78, 56, 61, 38, 12, 40 }; 
    // memcpy(ST.elem,A,sizeof(A)); 
    ST_print(ST); 
    heap_sort(ST.elem,10);//所有元素参与排序 
    ST_print(ST);
    return 0;
}