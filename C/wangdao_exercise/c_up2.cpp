#include <stdio.h>

int main(){
    int a = 0;
    // switch
    switch (a){
        case 2:
            printf("22222\n");
            break; 
        case 0:
            printf("qidaizhi\n");  
        case 1:
            printf("11111\n");
            break; 
        default:
            printf("lalala\n");
            break;
    }
    printf("------------------------------------------\n");
    // do while,先执行循环体，再判断
    do{
        printf("do while\n");
    }while (0);
    printf("------------------------------------------\n");

    // 二维数组
    int b[2][3] = {0,1,2,3,4,5};
    printf("%3d\n",b[1][0]);
    printf("------------------------------------------\n");
    // 补码
    short s = 0x7fff;
    printf("%d\n", s);
    s = s+1;
    printf("%d\n", s);
    s = 0xfffd; // 1111 1111 1111 1101为补码, 1000 0000 0000 0011为原码,最高位不变，取反后加1
    printf("%d\n", s);
    s = s+1;
    printf("%d\n", s);
    
    return 0;
}