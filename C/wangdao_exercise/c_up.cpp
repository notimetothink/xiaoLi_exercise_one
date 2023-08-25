// C语言进阶语法
#include <stdio.h>

int main(){
    int a=1,b=2,max;
    // 条件(三目)运算符
    max=a>b?a:b;
    printf("%d\n",max);
    a=3;
    max=a>b?a:b;
    printf("%d\n",max);
    printf("---------------------------------------------------\n");
    // 逗号运算符整体值是最后一个表达式的值
    a=b=1;
    if(a,b-1){
        printf("lalala");
    }else{
        printf("逗号运算符整体值是最后一个表达式的值\n");
    }
    printf("---------------------------------------------------\n");
    // 自增自减
    // 后++(--)先赋值再进行加减
    a=233333333;
    b=1;
    a=b++;
    printf("%3d%3d\n",a,b);
    // 前++(--)先进行加减再赋值
    a=233333333;
    b=1;
    a=++b;
    printf("%3d%3d\n",a,b);
    printf("---------------------------------------------------\n");
    // 位运算符
    // << 左移,高位丢弃,低位补0,相当于乘2,申请1G空间:malloc(1<<30),相当于1左移30次,2的30次幂
    short a1=5; // 两字节整型
    short b1;
    b1 = a1<<1; // 左移不改变a1值
    printf("%3d%3d\n",a1,b1);
    printf("---------------------------------------------------\n");
    // >> 右移,低位丢弃,高位正数补0复数补1,对偶数是除2奇数是先减1再除2
    b1 = a1>>1; 
    printf("%3d%3d\n",a1,b1);
    a1 = -8;
    b1 = a1>>1; 
    printf("%3d%3d\n",a1,b1);
    a1 = -7;
    b1 = a1>>1; // 结果是-4
    printf("%3d%3d\n",a1,b1);
    // 左移右移比直接乘2除2效率高,C语言里都是算数左移右移,不是逻辑
    printf("---------------------------------------------------\n");
    a1 = 0x8011;
    unsigned short a2 = 0x8011,b2 = 0; // 无符号数
    printf("%d %d\n",a1,a2);
    b1 = a1>>1;
    b2 = a2>>1;
    printf("%d %d\n",b1,b2);
    printf("---------------------------------------------------\n");
    // 按位与，按位或，按位异或，按位取反
    a1 = 5, b1 = 7;
    printf("a1 & b1=%d\n", a1 & b1);
    printf("a1 | b1=%d\n", a1 | b1);
    // 异或相同为0,不同为1
    printf("a1 ^ b1=%d\n", a1 ^ b1);
    printf("~a1=%d\n", ~a1);
    printf("---------------------------------------------------\n");
    return 0;
}