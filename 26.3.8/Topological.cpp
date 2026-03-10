#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findorder(int num, vector<vector<int>> &edges, vector<int> &indge){
    vector<int> result;
    queue<int> q;
    for(int i = 0; i < num; i++){
        if(indge[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        result.push_back(u);
        for(int i : edges[u]){
            --indge[i];
            if(indge[i] == 0) q.push(i);
        }
    }
    if(result.size() != num) return {};
    return result;
}

int main(){
    vector<vector<int>> edges;
    vector<int> indge;
    int n, m;
    cin >> n >> m;
    edges.resize(n); //长度初始化
    indge.resize(n);
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> to >> from;
        edges[from].push_back(to); //类似邻接表
        indge[to]++;//入度++
    }
    vector<int>res = findorder(n,edges,indge);
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
}