// 使用C++的引用，注意提交时把代码选为C++；
// 在主函数定义字符指针 char *p,然后在子函数内malloc申请空间（大小为100个字节），
// 通过fgets读取字符串，然后在主函数中进行输出；
// 要求子函数使用C++的引用，注意在C++中从标准输入读取字符串，需要使用fgets(p,100,stdin)
#include <stdio.h>
#include <stdlib.h>
void fun(char* &p){
    p = (char*)malloc(100);
    fgets(p,100,stdin);

}
int main(){
    char *p = NULL;
    fun(p);
    puts(p);
    free(p);
    return 0;
}