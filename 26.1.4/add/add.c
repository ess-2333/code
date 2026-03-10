#include <stdio.h>
int add(int x, int y){ //返回一个值需要用int，不需要返回值用void
    int z = x + y;
    return z;
}

int main(){
    int a = 0;
    int b = 0;
    scanf("%d%d",&a,&b);  //scanf需要地址引用
    printf("a+b=%d",add(a,b));
}