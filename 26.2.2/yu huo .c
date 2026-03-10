#include <stdio.h>
int main(){
    int a = 1;
    int b = 0;
    // printf("%d\n",a||b);
    // printf("%d\n",a&&b);
    // ( 1 ? 2 : 3 )
    // ( 真 ? 算 ：不算)
    // ( 假 ? 不算 ：算) 
    // b = (a > 5 ? 3 : 2);
    // printf("%d",b);
    int c = (a > b, a = b + 2, a, b = a + 10);
    printf("%d",c);
}