#include <stdio.h>


void print(unsigned int n){
    if(n == 0){
        return;
    }
    print(n / 10);

    printf("%d\n",n%10);
}

int main(){
    unsigned int num = 0;
    scanf("%u", &num);
    print(num);
}