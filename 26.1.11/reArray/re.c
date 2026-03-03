#include <stdio.h>
int main(){
    int arr[3][4] = {1,2,3,4,2,3,4,5,3,4,5,6}; //列【】不可省略
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}