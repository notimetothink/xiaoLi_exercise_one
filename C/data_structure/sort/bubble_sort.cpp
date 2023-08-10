// 冒泡排序
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
// 排序
void bubble_sort(Elemtype A[], int len){
    int i,j,flag;
    for (i=0; i<len-1; i++){
        flag = 0;
        for (j=len-1; j>i; j--){
            if (A[j-1]>A[j]){
                swap(A[j-1], A[j]);
                flag = 1;
            }
        }
        if (flag == 0){
            return;
        }
    }
}
int main(){
    SSTable T;
    int len=10;
    ST_init(T,len);
    ST_print(T);
    bubble_sort(T.elem,len);
    ST_print(T);
    return 0;
}