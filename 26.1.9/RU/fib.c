#include <stdio.h>
#include <stdlib.h>
// int fib(int n){
//     if (n <= 0) return 0;
//     else if (n == 1 || n == 2) return 1;
//     else return fib(n-1) + fib(n-2);
// }  
//从上到下递归

// long long fib(int n){
//     if (n <= 0) return 0;
//     else if (n == 1 || n == 2) return 1;
//     int i;
//     long long *dp = (long long*)malloc((n+1)*sizeof(long long));
//     if (dp == NULL) {
//         printf("内存分配失败！\n");
//         return -1; // 异常返回值
//     }
//     dp[1] = 1;
//     dp[2] = 1;
//     for(i = 3; i <= n; i++){
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     long long result = dp[n];
//     free(dp);
//     return result;
// } //方法1 空间复杂度O(n),dp记录n以内所有fib（）

long long fib(int n){
    if (n <= 0) return 0;
    long long a = 1;
    long long b = 1; 
    long long c = 1;
    while(n >= 3){
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
} //方法2 空间复杂度O(1)
//从下往上迭代（减少重复计算）

int main(){
    int num = 0;
    scanf("%d",&num);
    printf("%lld",fib(num));
}