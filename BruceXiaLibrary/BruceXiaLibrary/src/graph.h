#ifndef __BRUCEXIALIBRARY_GRAPH_C_H_
#define __BRUCEXIALIBRARY_GRAPH_C_H_


#include <vector>
#include <stack>
#include <queue>
#include <iostream>


typedef int InfoType;
#define MAXV 100 //最大顶点个数
#define MAXE 100 //最大边数
#define INF 32767

//以下定义邻接矩阵类型
typedef struct
{
	int no;			//顶点编号
	InfoType info;  //顶点其他信息，这里用于存放边的权值
}VertexType;		//顶点类型
typedef struct	mnode	//图的定义
{
	int edges[MAXV][MAXV];	//邻接矩阵
	int n, e;				//顶点数，弧数
	VertexType vexs[MAXV];	//存放顶点信息
}MGraph;					//图的邻接矩阵类型

//以下定义邻接表类型
typedef struct ANode		//弧的结点结构类型
{
	int adjvex;				//改弧的终点位置
	struct ANode *nextarc;	//指向下一条弧的指针
	InfoType info;			//改弧的相关信息，这里用于存放权值
}ArcNode;
typedef int Vertex;
typedef struct Vnode		//邻接表头结点的类型
{
	Vertex data;			//定点信息
	int count;				//存放顶点的入度
	ArcNode *firstarc;		//指向第一条弧
}VNode;
typedef VNode AdjList[MAXV]; //AdjList是邻接表类型
typedef struct
{
	AdjList adjlist;		//邻接表
	int n, e;				//图中顶点数n和边数e
}ALGraph;					//图的邻接表类型

void MatToList(MGraph g, ALGraph *&G);	//将邻接矩阵g转换成邻接表G
void ListToMat(ALGraph *G, MGraph &g);	//将邻接表G转换成邻接矩阵g
void DispMat(MGraph g);		//输出邻接矩阵g
void DispAdj(ALGraph *G);	//输出邻接表G

// 1:图的遍历算法
/******************************************************\
图的以邻接表为存储结构的深度优先搜索遍历算法
visited[]为访问标志数组，当顶点vi被访问后，数组visited[i]为1，other为0
\******************************************************/
void DFS(ALGraph *G, size_t v);	//深度优先遍历(递归)
void DFS1(ALGraph *G, size_t v);	//深度优先遍历(非递归)
void BFS(ALGraph *G, int v);		//广度优先遍历

//输出图G中从顶点u到顶点v的所有简单路径
void PathAll1(ALGraph *G, int u, int v, int path[], int i);
//输出图G中从顶点u到顶点v的长度为l的所有简单路径，d是当前为止已走过的路径长度，调用时初值为-1
void PathAll2(ALGraph *G, int u, int v, int l, int path[], int d);
//MustPass:必须经过点  AvoidPass：必须避免的点
int Cond(int path[], int d, int MustPass[], int n, int AvoidPass[], int m);
void TravPath(ALGraph *G, int vi, int vj, int d, int path[],
	int MustPass[], int n, int AvoidPass[], int m);

// 2：图的最小生成树算法
void Prim(MGraph g, int v);
typedef struct
{
	int u, v, w; //边的起点，终点，权值
}Edge;
void SortEdge(MGraph g, Edge E[]);
void Kruskal(Edge E[], int n, int e);

// 3：图的最短路径算法
/******************************************************\
采用狄克斯特拉算法就从顶点v0到其余各定点的最短路径
\******************************************************/
void Dijkstra(MGraph g, int v0);
//由path输出最短路径
void DisPath(int dist[], int path[], int s[], int n, int v0);
void ppath(int path[], int i, int v0);

/******************************************************\
采用弗洛伊德算法求所有顶点之间的最短路径
\******************************************************/
void Flyod(MGraph g, std::vector<std::vector<int> > &A);
void DisPath(int A[][MAXV], int path[][MAXV], int n);
void ppath(int path[][MAXV], int i, int j);

//图的拓扑排序
void TopSort(ALGraph *G);


#endif