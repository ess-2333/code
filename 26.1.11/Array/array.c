#include <stdio.h>

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // char ch[5];
    // double data[20];

    // int n = 10;
    // int arr2[n];

    int n = sizeof(arr)/sizeof(arr[0]); //总大小/单个大小=多少个

    // for(int i = n - 1; i >=0; i--){
    //     printf("%d\n",arr[i]);
    // }

    for(int i = 0; i < n; i++){
        printf("&arr[%d] = %p\n",i,&arr[i]);
    }
}