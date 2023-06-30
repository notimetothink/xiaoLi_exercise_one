// 栈
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
// 数组实现栈
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

// 初始化栈
void InitStack(SqStack &S){
    S.top = -1;
}
// 判断是否是空栈
bool StackEmpty(SqStack S){
    if (S.top == -1){
        printf("empty\n");
        return true;
    }else{
        printf("not empty\n");
        return false;
    }
}
// 入栈
bool Push(SqStack &S,ElemType x){
    if (S.top == MaxSize-1){
        return false;
    }
    S.top += 1;
    S.data[S.top] = x;
    return true;
}
// 出栈
bool Pop(SqStack &S,ElemType &x){
    if (S.top == -1){
        return false;
    }
    x = S.data[S.top];
    S.top -= 1;
    return true;
}
// 读栈顶元素
bool GetTop(SqStack S,ElemType &x){
    if (-1 == S.top){
        return false;
    }
    x = S.data[S.top];
    printf("%d\n", x);
    return true;
}

int main(){
    SqStack S;
    int x;
    InitStack(S);
    StackEmpty(S);
    Push(S,1);
    GetTop(S,x);
    Push(S,2);
    GetTop(S,x);
    StackEmpty(S);
    Pop(S,x);
    GetTop(S,x);
    return 0;
}
