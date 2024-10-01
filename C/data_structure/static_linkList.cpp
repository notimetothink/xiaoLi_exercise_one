// 静态链表
// 静态链表分链表和备用链表
#include <stdio.h>
#include <stdlib.h>

// 定义静态链表结构体
#define MAXSIZE 100
typedef int Elemtype;
typedef struct Component{
    Elemtype data;
    // 替代链表指针,为0表示无指向
    int cur;
}Component,StaticLinkList[MAXSIZE];

// 链表初始化
bool initList(StaticLinkList space){
    int i;
    // space[0]第一个元素为备用链表头结点
    // 初始化使每个结点游标指向下一个结点
    for (i = 0; i < MAXSIZE-1; i++){
        space[i].cur = i+1;
    }
    // 最后一个结点作为链表头结点,初始化为0代表链表无数据
    space[MAXSIZE-1].cur = 0;
    return true;
}