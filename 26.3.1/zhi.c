#include <stdio.h>

int main(){
    int* arr[4];
    char* ch[5];
    int arr2[5];
    int (*pa)[5] = &arr2;

    char* arr3[5];
    char* (*p3) = &arr3;
}