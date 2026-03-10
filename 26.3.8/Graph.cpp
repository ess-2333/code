#include <iostream>
using namespace std;

typedef enum {DG, DN, UDG, UDN} GraphType;

#define MaxVertexNum 100

struct Graph{
    GraphType typ;
    char vexs[MaxVertexNum]; //顶点表
    int arcs[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int vexNum; //当期顶点数
    int arcNum; //当前边数
};

struct ArcNode{ 
    //边/弧定义
    int adjvex; //边指向哪个顶点
    ArcNode *next; //指向下一条边的指针
    int weight; //边权值
};

struct VtxNode{
    //顶点定义
    char info; //顶点信息
    ArcNode *first; //第一条边
};