#include <iostream>
using namespace std;

const int MAXN = 1000;
int father[MAXN];
int height[MAXN];

void Init(int n){
    for(int i = 0; i <= n; ++i){
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