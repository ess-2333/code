#include <stdio.h>
#include "add.h"

int main(){
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    printf("%d",add(a,b));
}