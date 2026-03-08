#include <stdio.h>

// void swap(int* px, int* py){
//     *px = *px + *py;
//     *py = *px - *py;
//     *px = *px - *py;
// }

// int main(){
//     int x = 2;
//     int y = 3;
//     swap(&x,&y);
// }

int main(){
    int a = 2;
    int b = 3;
    printf("%d %d \n",a,b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("%d %d ",a,b);
}