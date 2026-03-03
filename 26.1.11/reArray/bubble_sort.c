#include <stdio.h>

void swap(int* px, int* py){ //指针指向地址改变实参
    int z = 0;
    z = *px;
    *px = *py;
    *py = z;
}

void bubble_sort(int arr[],int size){
    for(int j = size;j > 0; j--){
        for(int i= 0;i < j; i ++){
            if(arr[i]>arr[i+1]) swap(&arr[i],&arr[i+1]); //升序
        }
    }
}

int main(){
    int arr1[] = {10,50,90,60,40,30,20,11,6,7,2,1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    bubble_sort(arr1,n);
    for(int i = 0; i < n; i++){
        printf("%d ",arr1[i]);
    }
}