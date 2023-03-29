#include <stdio.h>

void change(int *j){
    *j = *j/2;
}
int main(){
    int i;
    scanf("%d", &i);
    change(&i);
    printf("%d", i);
}