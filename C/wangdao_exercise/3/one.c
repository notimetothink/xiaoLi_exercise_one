// 判断某个年份是不是闰年，如果是闰年，请输出“yes”，否则请输出“no”
#include <stdio.h>
int main(){
    int year;
    scanf("%d", &year);
    if(year%400==0 || year%4==0 && year%100!=0){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return 0;
}