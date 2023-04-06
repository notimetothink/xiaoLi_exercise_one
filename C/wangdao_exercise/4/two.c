// 利用while或者for循环计算n！的值。
// 提示：n！＝1*2*3…*n
#include <stdio.h>
int main(){
    int i,n;
    scanf("%d",&n);
    int count = 1;
    for(i=1;i<=n;i++){
        count = count*i;
    }
    printf("%d\n", count);
    return 0;
}