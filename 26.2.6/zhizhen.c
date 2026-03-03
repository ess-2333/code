#include <stdio.h>

// int main(){
//     int a = 10;
//     int* pa = &a;
// }

int main(){
    char* pc = NULL;
    short* ps = NULL;
    int* pi = NULL;
    double* pd = NULL;
    printf("%zu\n%zu\n%zu\n%zu\n",sizeof(pc),sizeof(ps),sizeof(pi),sizeof(pd));
}