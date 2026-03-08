#include <stdio.h>

struct S{
    int data[200];
    int num;
};

void print(struct S* ps){
    printf("%d", ps->num);
}

int main(){
    struct S s = {
        .data = {10, 20, 30, 40},
        .num = 4
    };
    print(&s);
}