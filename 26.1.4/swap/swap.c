#include <stdio.h>

// void Swap(int x, int y){
//     int z = 0;
//     z = x;
//     x = y;
//     y = z;
// }

// int main(){
//     int a, b;
//     scanf("%d%d",&a,&b);
//     printf("交换前,a=%d,b=%d",a,b);
//     Swap(a,b);
//     printf("交换后,a=%d,b=%d",a,b);
// }
// 形参不改变实际参

void Swap(int* px, int* py){ //指针指向地址改变实参
    int z = 0;
    z = *px;
    *px = *py;
    *py = z;
}

int main(){
    int a=0;
    int b=0;
    scanf("%d%d",&a,&b);
    printf("交换前,a=%d,b=%d",a,b);
    Swap(&a,&b); //改变实参需要地址引用
    printf("交换后,a=%d,b=%d",a,b);
}