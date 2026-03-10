#include <stdio.h>
    int RT(int num){
        int outcome = 1;
        if(num == 0){
            return outcome;
        }
        else if(num < 0) return 0;
        int i = 1;
        do{
            outcome = outcome * i;
            i++;
        }
        while(i<=num);
        return outcome;
    }