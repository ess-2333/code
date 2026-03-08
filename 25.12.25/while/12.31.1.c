#include <stdio.h>
int main(){
    char password[20] = { 0 };
    printf("输入密码:>");
    scanf("%s",password);
    
    int ch = 0;
    while((ch = getchar()) != '\n');

    printf("确认密码(Y/N):>");
    int ret = getchar();
    if(ret == 'Y'||ret == 'y'){
        printf("Yes\n");
    }
    else
        printf("No\n");
}