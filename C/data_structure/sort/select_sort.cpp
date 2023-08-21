// 选择排序
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
void select_sort(Elemtype A[], int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(A[j]<A[min]){
                min = j;
            }
        }
        if(min!=i){
            swap(A[i],A[min]);
        }
    }
}
int main(){
    SSTable ST; 
    ST_init(ST,10);
    ST_print(ST); 
    select_sort(ST.elem,10); 
    ST_print(ST); 
    return 0;
}