// 快速排序
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
int partition(Elemtype A[],int low,int high){
    // 记录对比基准值,因为采用的方法是替换不是交换
    Elemtype pivot = A[low];
    while (low<high){
        while (low<high && A[high]>=pivot)
            high--;
        A[low] = A[high];
        while (low<high && A[low]<=pivot)
            low++;
        A[high] = A[low];
    }
    // 此时不出意外low=high,将记录的基准值带入数组内
    A[low] = pivot;
    return low;
}
void quick_sort(Elemtype A[],int low,int high){
    if (low<high){
        // printf("%d%d\n",low,high);
        // 不断二分
        int pivotpos = partition(A,low,high);
        quick_sort(A,low,pivotpos-1);
        quick_sort(A,pivotpos+1,high);
    }
}
int main(){
    SSTable ST;
    ST_init(ST,10);//初始化
    ST_print(ST);
    quick_sort(ST.elem,0,9);//注意这个位置是 n-1,也就是 9，因为函数里取了 high 位置的值
    ST_print(ST);
    return 0;
}