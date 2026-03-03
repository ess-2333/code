#include <stdio.h>
int main() {
    int i = 0;
    while (i < 10){
        for (int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
        i++;
    }

}