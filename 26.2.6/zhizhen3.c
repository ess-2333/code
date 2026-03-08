#include <stdio.h>
#include <windows.h>

int main(){
    // int a = 10;
    // int* pa = &a;
    // int** ppa = &pa;

    int a = 10;
    int b = 20;
    int c =30;
    
    int* parr[10] = {&a,&b,&c};
    for(int i = 0;i < 3; i++){
        printf("%d ",*(parr[i]));
    }
}