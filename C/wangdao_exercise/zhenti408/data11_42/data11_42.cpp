// 一个长度为 L（L≥1）的升序序列 S，处在第 (L/2) 个位置的数称为 S 的中
// 位数。例如，若序列 S1 = (11, 13, 15, 17, 19)，则 S1 的中位数是 15，两个序列的中位数是含
// 它们所有元素的升序序列的中位数。例如，若 S2 = (2, 4, 6, 8, 20)，则 S1 和 S2 的中位数是 11。
// 现在有两个等长升序序列 A 和 B，试设计一个在时间和空间两方面都尽可能高效的算法，找出
// 两个序列 A 和 B 的中位数。要求：
// （1）给出算法的基本设计思想。
// （2）根据设计思想，采用 C、C++或 Java 语言描述算法，关键之处给出注释。
// （3）说明你所设计算法的时间复杂度和空间复杂度。
#include <stdio.h>

int MidSearch(int A[], int B[], int n){
    int s1 = 0,d1 = n-1, s2 = 0, d2 = n-1;
    int m1,m2;
    while (s1!=d1||s2!=d2){
        m1 = (s1+d1)/2;
        m2 = (s2+d2)/2;
        if (A[m1] == B[m2]){
            return A[m1];
        }else if(A[m1] < B[m2]){
            if ((s1+d1)%2 == 0){ // 奇数
                s1 = m1;
                d2 = m2;
            }else{
                s1 = m1+1;
                d2 = m2;
            }
        }else{
            if ((s1+d1)%2 == 0){ // 奇数
                d1 = m1;
                s2 = m2;
            }else{
                d1 = m1;
                s2 = m2+1;
            }
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}
int main(){
    int A[] = { 11,13,15,17,19};//我们也可以分别把 A 和 B 都变为偶数个元素来测试
    int B[] = { 2,4,6,8,20};
    int mid = MidSearch(A, B, 5);
    printf("mid=%d\n", mid);
    return 0;
}