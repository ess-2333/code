#include <stdio.h>
int fac(int n){
    if(n < 0) return 0;
    else if(n >= 0 && n <=1) return 1;
    else return n*fac(n-1);
}

int main(){
    int num = 0;
    scanf("%d",&num);
    printf("%d",fac(num));
}