// 读取一个整型数，字符，浮点数，分别到变量i，j，k中，然后将i，j，k直接相加并输出
// 小数点后保留两位小数，不用考虑输入的浮点数的小数部分超过了两位
#include <stdio.h>
int main(){
    int a;
    float b;
    char c;
    scanf("%d %c%f",&a,&c,&b);
    printf("%.2f\n", a+b+c);
    return 0;
}