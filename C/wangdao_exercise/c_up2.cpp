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
    
    return 0;
}