#include<stdio.h>

int main(){
    int arr[] = {1,2,2,3,4,5,8,6,7,5,9,99};
    int i = 0;
    int size = sizeof(arr)/sizeof(arr[0]); //计算数组个数

    for(i = 0, i < size;i++){
        printf("%c",arr[i]);
        
    }
}