#include <iostream>
#include <string>
#include <algorithm> // 用于reverse函数
using namespace std;

// 将十进制数转换为n进制字符串（n范围2-36）
string decimalToAny(int decimal, int n) {
    if (decimal == 0) return "0"; // 处理0的特殊情况
    string result;
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 支持36进制
    
    while (decimal > 0) {
        int remainder = decimal % n;
        result += digits[remainder]; // 拼接余数对应的字符
        decimal = decimal / n;
    }
    reverse(result.begin(), result.end()); // 反转得到正确顺序
    return result;
}

// 将m进制字符串转换为十进制数（m范围2-36）
int anyToDecimal(const string& num, int m) {
    int decimal = 0;
    int len = num.length();
    
    for (int i = 0; i < len; i++) {
        char c = num[i];
        int digit;
        // 转换字符为对应的数字值
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'Z') {
            digit = 10 + (c - 'A');
        } else if (c >= 'a' && c <= 'z') {
            digit = 10 + (c - 'a');
        } else {
            cerr << "无效的字符：" << c << endl;
            return -1; // 非法字符返回-1
        }
        
        // 检查数字是否超过进制范围
        if (digit >= m) {
            cerr << "数字 " << digit << " 超过 " << m << " 进制范围" << endl;
            return -1;
        }
        
        decimal = decimal * m + digit; // 累加计算十进制值
    }
    return decimal;
}

// 核心进制转换函数：m进制字符串num转换为n进制
string conversion(int m, int n, const string& num) {
    // 第一步：m进制转十进制
    int decimal = anyToDecimal(num, m);
    if (decimal == -1) return ""; // 转换失败返回空字符串
    
    // 第二步：十进制转n进制
    return decimalToAny(decimal, n);
}

// 测试示例
int main() {
    // 示例1：二进制"1010"转十进制
    string res1 = conversion(2, 10, "1010");
    cout << "二进制1010转十进制：" << res1 << endl; // 输出10
    
    // 示例2：十进制"255"转十六进制
    string res2 = conversion(10, 16, "255");
    cout << "十进制255转十六进制：" << res2 << endl; // 输出FF
    
    // 示例3：八进制"17"转二进制
    string res3 = conversion(8, 2, "17");
    cout << "八进制17转二进制：" << res3 << endl; // 输出1111
    
    return 0;
}