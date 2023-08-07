// 折半查找(二分查找),需被查找数列有序,只应用于顺序表查找
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Elemtype;
typedef struct{
    Elemtype* elem;
    int len;
}SSTable;
// 初始化顺序表
void ST_init(SSTable &ST, int len){
    ST.len = len;
    ST.elem = (Elemtype*)malloc(sizeof(Elemtype)*ST.len);
    int i;
    srand(time(NULL));
    for(i=0; i<ST.len; i++){
        ST.elem[i] = rand()%100;
    }
}
// 打印顺序表
void ST_print(SSTable ST){
    for(int i=0; i<ST.len; i++){
        printf("%3d", ST.elem[i]);   
    }
    printf("\n");
}
// 折半查找,时间复杂度logn
int binary_search(SSTable ST, Elemtype key){
    int low = 0;
    int high = ST.len-1;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        // printf("%d\n",mid);
        if(ST.elem[mid]<key){
            low = mid+1;
        }else if(ST.elem[mid]>key){
            high = mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}
int compare(const void* left, const void* right)//left，right 是任意两个元素的地址值
{
    return *(Elemtype*)left - *(Elemtype*)right;
    //return *(ElemType*)right - *(ElemType*)left;//从大到小
}
int main(){
    SSTable ST;
    Elemtype key;
    int pos;
    ST_init(ST,10);
    qsort(ST.elem, ST.len, sizeof(Elemtype), compare);
    ST_print(ST);
    scanf("%d", &key);
    pos = binary_search(ST,key);
    printf("%d", pos+1);
    return 0;
}