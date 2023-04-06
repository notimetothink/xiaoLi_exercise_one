// 输入一个整型数，判断是否是对称数，如果是，输出yes，否则输出no
// 不用考虑这个整型数过大，int类型存不下，不用考虑负值；
// 例如 12321是对称数，输出yes，124421是对称数，输出yes，1231不是对称数，输出no
#include <stdio.h>
int main(){
    int a,aa;
    int b = 0;
    scanf("%d", &a);
    aa = a;
    while (a)
    {
        b = b*10;
        b += a%10;
        a = a/10;
    }
    printf("%d\n", b);
    if (aa==b){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    
}