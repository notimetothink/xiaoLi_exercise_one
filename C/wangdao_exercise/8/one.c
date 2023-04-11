// 输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出
#include <stdio.h>
typedef struct student
{
    int id;
    char name[20];
    char sex;
}stu,*pstu;
int main(){
    stu s;
    scanf("%d%s %c",&s.id,s.name,&s.sex);
    printf("%d %s %c\n",s.id,s.name,s.sex);
}
