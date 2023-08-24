// 43．(15分)已知由n(n≥2)个正整数构成的集合A={ak|0≤k<n}，
// 将其划分为两个不相交的子集A1和A2，
// 元素个数分别是n1和n2,A1和A2中元素之和分别为S1和S2。
// 设计一个尽可能高效的划分算法，满足|n1-n2|最小且|S1-S2|最大。
// 要求:(1)给出算法的基本设计思想。 
// (2)根据设计思想,采用C或C++语言描述算法,关键之处给出注释。 
// (3)说明你所设计算法的平均时间复杂度和空间复杂度。

/*
(1)算法的基本设计思想 由题意知，将最小的 n/2 个元素放在 A1 中，
其余的元素放在 A2 中，分组结果即可满足题目要求。 
仿照快速排序的思想，基于枢轴将 n 个整数划分为两个子集。
根据划分后枢轴所处的位置 i 分别处理：
①若 i=n/2，则分组完成，算法结束； 
②若 i＜n/2，则枢轴及之前的所有元素均属于 A1，继续对 i 之后的元素进行划分； 
③若 i＞n/2)，则枢轴及之后的所有元素均属于 A2，继续对 i 之前的元素进行划分； 
基于该设计思想实现的算法，毋须对全部元素进行全排序，
其平均时间复杂度是 O(n)，空间复杂度 是 O(1)
*/
#include <stdio.h> 
#include <stdlib.h>
int setPartition(int A[], int len){
    int low = 0,high = len-1,k = len/2,flag = 1;
    int pos = low,lowc = low,highc = high;
    int s1 = 0,s2 = 0;
    while(flag){
        int value = A[low];
        while(low<high){
            while(low<high && A[high]>= value){
                high--;
            }
            A[low] = A[high];
            while(low<high && A[low]<= value){
                low++;
            }
            A[high] = A[low];
        }
        A[low] = value;
        if(low == k-1){
            flag = 0;
        }else{
            if(low<k-1){
                low++;
                lowc = low;
                high = highc;
            }else{
                high--;
                highc = high;
                low = lowc;
            }
        }
    }
    for(int i = 0;i<k;i++){
        printf("%3d",A[i]);
        s1 += A[i];
    }
    for(int i = k;i<len;i++){
        printf("%3d",A[i]);
        s2 += A[i];
    }
    printf("\n");
    printf("%d %d\n",s1,s2);
    return s2 - s1;
}
int main() { 
    int A[10] = { 4,1,12, 18, 7,13, 18, 16, 5, 15}; 
    int difference; 
    difference=setPartition(A, 10);//考研初试只需要完成 setPartition 即可，无需编写这个 main 函数 
    printf("%d\n", difference); 
    return 0; 
}