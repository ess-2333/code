#include <stdio.h>
#include <math.h>
int justify(int n){ //素数判断
    int j;
    for(j = 2; j <= sqrt(n); j++){
        if(n%j == 0) return 0;  
    }
    return 1;
}

int main(){
    int i = 0;
    for(i = 100; i <=200; i++){ //判断100~200中的素数
        if(justify(i) == 1) printf("%d\n",i);
        
    }
    return 0;
}
