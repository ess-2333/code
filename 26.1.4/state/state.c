#include <stdio.h>
// int add(int x,int y){
//     int z = 0;
//     z = x + y;
//     return z;
// }

// int main(){
//     int a = 0;
//     int b = 0;
//     scanf("%d %d", &a, &b);
//     printf("%d",add(a,b));
// }

int add(int x,int y);//函数在调用的后面，需要写。

int main(){
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    printf("%d",add(a,b));
}

int add(int x,int y){
    int z = 0;
    z = x + y;
    return z;
}