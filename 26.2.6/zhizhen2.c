#include <stdio.h>

// int main(){
//     int arr[10] = {0};
//     int* p = arr;
// }

int main(){
    float values[10];
    float *vp;
    for(vp = &values[0];vp < &values[10];) *vp++ = 1;
    //for(vp = &values[10];vp > &values[0];) *--vp = 1;
    for (int i = 0; i < 10; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}