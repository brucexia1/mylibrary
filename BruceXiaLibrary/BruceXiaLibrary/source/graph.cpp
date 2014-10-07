#include "../include/graph.h"
using namespace std;

void MatToList(MGraph g, ALGraph *&G)	//将邻接矩阵g转换成邻接表G
{
	int i, j, n = g.n;
	ArcNode *p;
	G = new ALGraph;
	for (i = 0; i<n; i++)
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i<n; ++i){
		for (j = n - 1; j >= 0; j--){
			if (g.edges[i][j] != 0)
			{
				p = new ArcNode;
				p->adjvex = j;
				p->info = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->e = g.e;
	G->n = n;
}

void ListToMat(ALGraph *G, MGraph &g)	//将邻接表G转换成邻接矩阵g
{
	size_t i, j, n = G->n;
	ArcNode *p;
	for (i = 0; i<G->n; ++i)
	for (j = 0; j<G->n; ++j)
		g.edges[i][j] = 0;
	for (i = 0; i<G->n; ++i)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			g.edges[i][p->adjvex] = p->info;
			p = p->nextarc;
		}
	}
	g.n = n;
	g.e = G->e;
}

void DispMat(MGraph g)		//输出邻接矩阵g
{
	size_t i, j;
	for (i = 0; i<g.n; ++i)
	{
		for (j = 0; j<g.n; ++j)
		{
			if (g.edges[i][j] == INF)
				printf("%3s", "∞");
			else
				printf("%3d", g.edges[i][j]);
		}
		printf("\n");
	}
}

void DispAdj(ALGraph *G)	//输出邻接表G
{
	size_t i;
	ArcNode *p;
	for (i = 0; i<G->n; ++i)
	{
		p = G->adjlist[i].firstarc;
		if (p != NULL) printf("%3d: ", i);
		while (p)
		{
			printf("%3d", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}

/******************************************************\
图的以邻接表为存储结构的深度优先搜索遍历算法
visited[]为访问标志数组，当顶点vi被访问后，数组visited[i]为1，other为0
\******************************************************/
size_t visited[MAXV];
void DFS(ALGraph *G, size_t v)	//递归深度优先遍历
{
	ArcNode *p;
	visited[v] = 1;//置已访问标记
	printf("%3d", v);
	p = G->adjlist[v].firstarc;
	while (p)
	{
		if (visited[p->adjvex] == 0){
			//printf("<%d,%d>",v,p->adjvex);
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}

void DFS1(ALGraph *G, size_t v)	//非递归深度优先遍历
{	//需要借助一个辅助的栈来实现
	ArcNode *p;
	stack<ArcNode*> Stk;
	for (size_t i = 0; i<G->n; i++) visited[i] = 0;
	printf("%3d", v);
	visited[v] = 1;
	Stk.push(G->adjlist[v].firstarc);
	while (!Stk.empty())	//栈不空是循环
	{
		p = Stk.top(); Stk.pop();
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0){
				printf("%3d", p->adjvex);
				visited[p->adjvex] = 1;
				Stk.push(G->adjlist[p->adjvex].firstarc);
				break;
			}
			p = p->nextarc;
		}
	}
}

void BFS(ALGraph *G, int v)
{
	ArcNode *p;
	queue<int> Qu;
	vector<size_t> vVis(G->n, 0);
	int w;
	printf("%2d", v);
	vVis[v] = 1;
	Qu.push(v);
	while (!Qu.empty())
	{
		w = Qu.front();	Qu.pop();	//出队并赋给w
		p = G->adjlist[w].firstarc;
		while (p != NULL)
		{
			if (vVis[p->adjvex] == 0)
			{
				printf("%3d", p->adjvex);
				//printf("<%d,%d>",w,p->adjvex);
				vVis[p->adjvex] = 1;
				Qu.push(p->adjvex);
			}
			p = p->nextarc;
		}
	}
}

//输出图G中从顶点u到顶点v的所有简单路径
void PathAll1(ALGraph *G, int u, int v, int path[], int i)
{	//从u出发深度优先搜索，当搜索到v时输出路径，然后继续回溯查找其他路径
	int j, n;
	ArcNode *p;
	p = G->adjlist[u].firstarc;
	visited[u] = 1;
	while (p != NULL){
		n = p->adjvex;
		if (n == v)
		{
			path[i + 1] = v;
			for (j = 0; j<i + 1; j++)
				printf("%3d", path[j]);
			printf("\n");
		}
		else if (visited[n] == 0)
		{
			path[i + 1] = n;
			PathAll1(G, n, v, path, i + 1);
		}
		p = p->nextarc;
	}
	visited[u] = 0;
}
//输出图G中从顶点u到顶点v的长度为l的所有简单路径，d是当前为止已走过的路径长度，调用时初值为-1
void PathAll2(ALGraph *G, int u, int v, int l, int path[], int d)
{
	ArcNode *p;
	int i;
	visited[u] = 1;
	d++;
	path[d] = u;
	if (u == v && d == l){
		for (i = 0; i <= d; i++)
			printf("%3d", path[i]);
		printf("\n");
	}
	p = G->adjlist[u].firstarc;
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)
			PathAll2(G, p->adjvex, v, l, path, d);
		p = p->nextarc;
	}
	visited[u] = 0;
}

//MustPass:必须经过点  AvoidPass：必须避免的点
int Cond(int path[], int d, int MustPass[], int n, int AvoidPass[], int m)
{
	int flag1 = 0, f1, flag2 = 0, f2, i, j;
	for (i = 0; i<n; i++){
		f1 = 1;
		for (j = 0; j <= d; j++)
		if (path[j] == MustPass[i]){
			f1 = 0; break;
		}
		flag1 += f1;
	}
	for (i = 0; i<m; i++)
	{
		f2 = 0;
		for (j = 0; j <= d; j++)
		if (path[j] == AvoidPass[i])
		{
			f2 = 1; break;
		}
	}
	if (flag1 == 0 && flag2 == 0) return 1;
	else return 0;
}
void TravPath(ALGraph *G, int vi, int vj, int d, int path[],
	int MustPass[], int n, int AvoidPass[], int m)
{
	int i;
	ArcNode *p;
	visited[d] = vi;
	d++;
	path[d] = vi;
	if (vi == vj && Cond(path, d, MustPass, n, AvoidPass, m) == 1)
	{
		for (i = 0; i <= d; i++)
			printf("%3d", path[i]);
		printf("\n");
	}
	p = G->adjlist[vi].firstarc;
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)
			TravPath(G, p->adjvex, vj, d, path, MustPass, n, AvoidPass, m);
		p = p->nextarc;
	}
	visited[vi] = 0;
	d--;
}
/******************************************************************************\
Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a
connected weighted undirected graph. This means it finds a subset of the edges
that forms a tree that includes every vertex, where the total weight of all
the edges in the tree is minimized.
Informal:
1:Create a tree containing a single vertex, chosen arbitrarily from the graph
2:Create a set containing all the edges in the graph
3:Loop until every edge in the set connects two vertices in the tree
3.1:Remove from the set an edge with minimum weight that connects
a vertex in the tree with a vertex not in the tree
3.2:Add that edge to the tree
\******************************************************************************/
void Prim(MGraph g, int v)//the v is the random selected vertex
{
	//lowcost[i]=0表示i在U中，closet[i]存储该边依附在U中的顶点
	int lowcost[MAXV];
	int min;
	int closest[MAXV], k;
	for (size_t i = 0; i<g.n; i++){  //set the initialization value for lowcost[] and closet[]
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (size_t i = 0; i<g.n; i++) //find the n-1 vertex
	{
		min = INF;
		for (size_t j = 0; j<g.n; j++)	//find the vertex k which nearest with the U in (V-U)
		if (lowcost[j] != 0 && lowcost[j]<min)
		{
			min = lowcost[j];
			k = j;	//k记录最近顶点的编号
		}
		//printf("边(%d,%d)权为：%d\n",closest[k],k,min);
		lowcost[k] = 0; //标记k已加入U
		for (size_t j = 0; j<g.n; j++)	//modify array lowcost and closet
		if (g.edges[k][j] != 0 && g.edges[k][j]<lowcost[j])
		{
			lowcost[j] = g.edges[k][j];
			closest[j] = k;
		}
	}
}

void SortEdge(MGraph g, Edge E[])
{
	int i, j, k(0);
	Edge temp;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
			{
				E[k].u = i; E[k].v = j; E[k].w = g.edges[i][j];
				k++;
			}
		}
	}
	
	for (i = 1; i < k; i++)
	{
		temp = E[i];
		j = i - 1;
		while (j >= 0 && temp.w < E[j].w)
		{
			E[j + 1] = E[j];
			j--;
		}
		E[j + 1] = temp;
	}
}

void Kruskal(Edge E[], int n, int e)
{
	int i, j, k, m1, m2, sn1, sn2;
	int vset[MAXV];
	for (i = 0; i<n; i++) vset[i] = i;
	k = 1;
	j = 0;
	while (k<n)
	{
		m1 = E[j].u; m2 = E[j].v;
		sn1 = vset[m1]; sn2 = vset[m2];
		if (sn1 != sn2)
		{
			printf("(%d,%d):%d\n", m1, m2, E[j].w);
			k++;
			for (i = 0; i<n; i++)
			if (vset[i] == sn2) vset[i] = sn1;
		}
		j++;
	}
}

/******************************************************\
采用狄克斯特拉算法就从顶点v0到其余各定点的最短路径
s[0..n-1]用于标记已找到最短路劲的顶点，s[i]=1表示已找到顶点vi的最短路径
dist[0..n-1]用于保存从源点v到终点vi的目前最短路径长度
path[i]保存从源点v到终点vi当前最短路径中的前一个顶点的编号，它的初值
为源点v的编号或-1
\******************************************************/
void Dijkstra(MGraph g, int v0)
{
	int dist[MAXV], path[MAXV];
	int s[MAXV];
	int minidis, i, j, u, n = g.n;
	for (i = 0; i<n; i++)
	{
		dist[i] = g.edges[v0][i];	//距离初始化
		s[i] = 0;				//s[]置空
		if (g.edges[v0][i]<INF)	//路径初始化
			path[i] = v0;
		else
			path[i] = -1;
	}
	s[v0] = 1; path[v0] = 0;
	for (i = 0; i<n; i++)	//循环直到所有顶点的最短路径都求出
	{
		minidis = INF;
		u = -1;
		for (j = 0; j<n; j++)	//选取不再s中且具有最小距离的顶点u
		{
			if (s[j] == 0 && dist[j]<minidis)
			{
				u = j;
				minidis = dist[j];
			}
		}
		s[u] = 1;		//顶点u加入s中
		for (j = 0; j<n; j++)	//修改不在s中的顶点的距离
		{
			if (s[j] == 0)
			if (g.edges[u][j]<INF && dist[u] + g.edges[u][j]<dist[j])
			{
				dist[j] = dist[u] + g.edges[u][j];
				path[j] = u;
			}
		}
	}
	printf("输出最短路径：\n");
	DisPath(dist, path, s, n, v0);	//输出最短路径
}
void DisPath(int dist[], int path[], int s[], int n, int v0)
{
	int i;
	printf(" path:");
	for (i = 0; i<n; i++)
		printf("%3d", path[i]);
	printf("\n");
	for (i = 0; i<n; i++){
		printf("%d", i);
		if (s[i] == 1 && i != v0)
		{
			printf("从%d到%d的最短路径长度为：%d\t路径为：", v0, i, dist[i]);
			printf("%d,", v0);
			ppath(path, i, v0);
			printf("%d\n", i);
		}
		else
			printf("从%d到%d的不存在路径\n", v0, i);
	}
}
void ppath(int path[], int i, int v0)
{
	int k;
	k = path[i];
	if (k == v0) return;
	ppath(path, k, v0);
	printf("%d,", k);
}

void Flyod(MGraph g, vector<vector<int> > &A)
{
	vector<vector<int> > path(g.n, vector<int>(g.n, 0));//MAXV行MAXV列全0矩阵
	int i, j, k;
	for (i = 0; i<g.n; i++)	//给数组A置初值
	for (j = 0; j<g.n; j++)
	{
		A[i][j] = g.edges[i][j];
		path[i][j] = -1;
	}

	for (k = 0; k<g.n; k++){	//计算Ak
		for (i = 0; i<g.n; i++){
			for (j = 0; j<g.n; j++){
				if (A[i][j]>(A[i][k] + A[k][j])){
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	//printf("\n输出最短路径：\n");
	//DisPath(A,path,g.n);
}
void DisPath(int A[][MAXV], int path[][MAXV], int n)
{
	int i, j;
	for (i = 0; i<n; ++i)
	for (j = 0; j<n; j++)
	if (A[i][j] == INF)
	{
		if (i != j) printf("从%d到%d没有最短路径\n", i, j);
	}
	else
	{
		printf("从%d到%d路径为：", i, j);
		printf("%d,", i);
		ppath(path, i, j);
		printf("%d", j);
		printf("\t路径长度为：%d\n", A[i][j]);
	}
}
void ppath(int path[][MAXV], int i, int j)
{
	int k;
	k = path[i][j];
	if (k == -1) return;
	ppath(path, i, k);
	printf("%d,", k);
	ppath(path, k, j);
}

void TopSort(ALGraph *G)
{
	int i, j;
	int stak[MAXV], top = -1;	//设立一个栈stak用于存放入度为0的顶点
	ArcNode *p;
	for (i = 0; i<G->n; i++)
		G->adjlist[i].count = 0;
	for (i = 0; i<G->n; i++){
		p = G->adjlist[i].firstarc;
		while (p != NULL){
			G->adjlist[p->adjvex].count++;
			p = p->nextarc;
		}
	}
	for (i = 0; i<G->n; i++)
	if (G->adjlist[i].count == 0){
		top++; stak[top] = i;
	}

	while (top>-1)
	{
		i = stak[top]; top--;
		printf("%d", i);
		p = G->adjlist[i].firstarc;
		while (p != NULL){
			j = p->adjvex;
			G->adjlist[j].count--;
			if (G->adjlist[j].count == 0){
				top++; stak[top] = j;
			}
			p = p->nextarc;
		}

	}
}
