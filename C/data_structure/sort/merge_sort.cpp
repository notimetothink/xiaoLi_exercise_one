// 归并排序
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
// 归并
void merge(Elemtype A[], int low, int mid, int high){
    static Elemtype B[7];
    for(int i=0; i<7; i++){
        B[i] = A[i];
    }
    int i,j,k;
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<=B[j]){
            A[k] = B[i];
            i++;
        }else{
            A[k] = B[j];
            j++;
        }
    }
    while(i<=mid){
        A[k] = B[i];
        k++;
        i++;
    }
    while(j<=high){
        A[k] = B[j];
        k++;
        j++;
    }
}
// 归并排序(递归)
void merge_sort(Elemtype A[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        merge_sort(A,low,mid);
        merge_sort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}
int main(){
    SSTable ST; 
    ST_init(ST,7);//初始化 
    // Elemtype A[10] = { 3, 87, 2, 93, 78, 56, 61, 38, 12, 40 }; 
    // memcpy(ST.elem,A,sizeof(A)); 
    ST_print(ST); 
    merge_sort(ST.elem,0,6); 
    ST_print(ST);
    return 0;
}