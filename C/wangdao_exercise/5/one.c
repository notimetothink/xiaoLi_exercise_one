// 输入N个数（N小于等于100），输出数字2的出现次数；
# include <stdio.h>
int main(){
    int i,n;
    int num = 0;
    scanf("%d",&n);
    int a[100];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if (a[i] == 2){
            num += 1;
        }
    }
    printf("%d\n", num);
    return 0;
}