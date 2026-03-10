#include <stdio.h>

//求一个数补码中1的个数
int one(int b){
    if(b == 0) return 0;
    int count = 0;
    int set = 0; 
    int x = 0;
    unsigned int a = (unsigned int)b;
    //原码 -> 补码 最后一个1的前面全部取反
    //算出从最后一个1开始后面有多少位x，同时计算原码有多少个1 count
    //负数： 31（int32位） - x - count + 1 + 1
    //正数： count
    while(a != 0){ 
        if(a % 2 == 1) set = 1;
        if(set == 0) x++;
        if(a % 2 == 1) count++;
        a = a/2;
    }
    if(b > 0) return count;
    if(b < 0) return 31 - x - count + 2;
}