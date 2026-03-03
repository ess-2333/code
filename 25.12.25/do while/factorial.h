// factorial.h  阶乘函数的头文件
#ifndef FACTORIAL_H    // 防止头文件被重复包含（固定写法，必加）
#define FACTORIAL_H

// 这里就是RT函数的【声明】，和函数定义的头部一模一样，加分号结束！
// 解决你之前的警告：显式声明参数为int类型，杜绝type default to int警告
int RT(int num);

#endif