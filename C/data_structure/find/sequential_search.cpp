// 顺序查找
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Elemtype;
// 以指针方式定义顺序表
typedef struct {
    Elemtype* elem; // 整型指针
    int len; // 长度
}SSTable;
// 初始化
void ST_init(SSTable &ST, int len){
    // 多存一个哨兵
    ST.len = len + 1;
    // 申请空间
    ST.elem = (Elemtype*)malloc(sizeof(Elemtype)*ST.len);
    // 随机数生成
    int i;
    srand(time(NULL));
    for (i = 1; i < ST.len; i++){
        ST.elem[i] = rand()%100;
    }
}
// 打印顺序表
void ST_print(SSTable ST){
    for (int i = 1; i < ST.len; i++){
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
}
// 顺序查找
int search(SSTable ST, Elemtype key){
    // 哨兵
    ST.elem[0] = key;
    int i;
    for (i=ST.len-1; ST.elem[i]!=key; i--);
    return i;
}
int main(){
    SSTable ST;
    Elemtype key;
    int pos;
    ST_init(ST,10);
    ST_print(ST);
    scanf("%d", &key);
    pos = search(ST, key);
    if (pos){
        printf("%d\n", pos);
    }else{
        printf("没有");
    }
    return 0;
}
