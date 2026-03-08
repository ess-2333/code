#include <stdio.h>
#include <string.h>

// int strl(char* str){
//     int i = 0;
//     while(*str != '\0'){ //字符串abc 为 a b c \0
//         str++;
//         i++;
//     }
//     return i;
// } 非递归

int strl(char* str){
    if(*str != '\0') return 1+strl(str + 1); //返回1加下一个字符后的长度；
    else return 0; //‘0’ 后的长度为0
} //递归



int main(){
    char arr[] = "abc";
    printf("%d",strl(arr));
}