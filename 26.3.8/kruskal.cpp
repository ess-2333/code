#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring> 
using namespace std;

const int MAXN = 100;

struct edge{
    int from;
    int to;
    int length;
};

edge ed[MAXN*MAXN];

int father[MAXN];
int height[MAXN];

void Init(int n){
    for(int i = 0; i < n; ++i){
        father[i] = i;
        height[i] = 1;
    }
}

int Find(int x){
    if(x == father[x]) return x;
    else{
        father[x] = Find(father[x]);
        return father[x];
    }
}

void Union(int i, int j){
    int x = Find(i), y = Find(j);
    if(x != y){
        if(height[x] < height[y]) father[x] = y;
        else if(height[x] > height[y]) father[y] = x;
        else{
            father[y] = x;
            height[x]++;
        }
    }
}

bool compare(edge x, edge y){
    return x.length < y.length;
}

int kruskal(int n, int ednum){
    Init(n);
    sort(ed, ed + ednum, compare);
    int sum = 0;
    for(int i = 0; i < ednum; i++){
        edge current = ed[i];
        if(Find(current.from) != Find(current.to)){
            sum += current.length;
            Union(current.from, current.to);
        }
    }
    return sum;
}

int main() {
    int n;
    // 循环输入顶点数，输入0结束程序
    while (scanf("%d", &n) != EOF && n != 0) {
        if (n == 1) { // 特殊处理：只有1个顶点
            printf("最小生成树权值：0\n");
            continue;
        }
        
        int max_edge_num = n * (n - 1) / 2; // 完全图最大边数
        memset(ed, 0, sizeof(ed)); // 初始化边数组，避免残留数据
        int actual_edge_num = 0;    // 实际输入的有效边数
        
        printf("请输入%d条边（格式：起点 终点 权值），输入“0 0 0”结束输入：\n", max_edge_num);
        for (int i = 0; i < max_edge_num; i++) {
            int from, to, len;
            // 校验输入是否有效
            if (scanf("%d%d%d", &from, &to, &len) != 3) break;
            // 输入0 0 0，终止边输入
            if (from == 0 && to == 0 && len == 0) break;
            // 存储有效边
            ed[i].from = from;
            ed[i].to = to;
            ed[i].length = len;
            actual_edge_num++; // 有效边数+1
        }
        
        // 调用Kruskal算法，传入实际有效边数
        int result = kruskal(n, actual_edge_num);
        printf("最小生成树的总权值：%d\n\n", result);
    }
    printf("程序结束\n");
}