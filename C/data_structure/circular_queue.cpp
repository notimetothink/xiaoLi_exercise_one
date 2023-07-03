// 循环队列
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;
// 队列初始化
void initQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}
// 判断队列是否为空
bool isEmpty(SqQueue Q){
    if (Q.front == Q.rear){
        return true;
    }else{
        return false;
    }
}
// 入队
bool enQueue(SqQueue &Q,ElemType x){
    // 队满
    if ((Q.rear+1)%MaxSize == Q.front){
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;
    return true;
}
// 出队
bool deQueue(SqQueue &Q,ElemType &x){
    // 队空
    if (Q.front == Q.rear){
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    return true;
}
int main(){
    SqQueue Q;
    ElemType x;
    initQueue(Q);
    enQueue(Q,1);
    enQueue(Q,2);
    deQueue(Q,x);
    printf("%d\n", x);
    deQueue(Q,x);
    printf("%d\n", x);
    return 0;
}
