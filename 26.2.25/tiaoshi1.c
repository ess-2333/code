#include <stdio.h>

int main(){
    int i = 0;
    int arr[10] = {0};
    
    for(i = 0; i < 10; i++){
        arr[i] = i;
    }
    for(i = 0; i < 10; i++){
        printf("%d ",arr[i] );
    }
}