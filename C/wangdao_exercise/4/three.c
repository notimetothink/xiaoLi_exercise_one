// 某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。
// 要求换正好40张，且每种票子至少一张。问：有几种换法？
#include <stdio.h>
int main(){
    int i,j,m,n;
    int num = 0;
    for(i=1;i<=39;i++){
        for(j=1;j<=39;j++){
            for(m=1;m<=20;m++){
                for(n=1;n<=10;n++){
                    if(i+j+m+n==40 && i+2*j+5*m+10*n == 100){
                        num+=1;
                    }
                }
            }
        }
    }
    printf("%d\n",num);
}