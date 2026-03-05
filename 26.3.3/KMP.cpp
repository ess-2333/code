#include <iostream>
#include <vector> 
using namespace std;

void buildnext(string pattern, int next[]) {
    int m = pattern.size();
    int i = 0;   // 后缀指针（从0开始）
    int j = -1;  // 前缀指针（初始为-1）
    next[0] = -1; // 第一个值固定为-1

    while (i < m - 1) { // 注意边界：i最多到m-2（因为i++后到m-1）
        if (j == -1 || pattern[i] == pattern[j]) {
            // 匹配成功，指针前进，记录next值
            i++;
            j++;
            next[i] = j;
        } else {
            // 匹配失败，前缀指针回退
            j = next[j];
        }
    }
}


int KMP(string s,string t, int next[]){ // s主串 t子串
    int m = t.size(); 
    int n = s.size();
    buildnext(t, next);
    int i = 0, j = 0;
    while (i < n && j < m) {
        // 匹配成功 或 模式串指针回退到起点（j=-1）
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
        } else {
            // 匹配失败，模式串指针回退（主串指针不回退）
            j = next[j];
        }
    }

    // 如果模式串遍历完，说明匹配成功，返回起始索引
    if (j == m) {
        return i - m;
    }
    // 无匹配
    return -1;
}

int main(){
    string s = "abaabc";
    int m = s.size();
    int* next = new int[m];
    buildnext(s, next);
    cout << "next";
    for (int k = 0; k < m; k++) {
        cout << next[k] << " ";
    }
    string p = "abaabbabaabc";
    cout << endl;
    cout << "match: ";
    int index = KMP(p, s, next);
    cout << index;
}