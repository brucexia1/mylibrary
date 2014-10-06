#ifndef __BRUCEXIALIBRARY_GRAPH_C_H_
#define __BRUCEXIALIBRARY_GRAPH_C_H_


#include <vector>
#include <stack>
#include <queue>
#include <iostream>


typedef int InfoType;
#define MAXV 100 //��󶥵����
#define MAXE 100 //������
#define INF 32767

//���¶����ڽӾ�������
typedef struct
{
	int no;			//������
	InfoType info;  //����������Ϣ���������ڴ�űߵ�Ȩֵ
}VertexType;		//��������
typedef struct	mnode	//ͼ�Ķ���
{
	int edges[MAXV][MAXV];	//�ڽӾ���
	int n, e;				//������������
	VertexType vexs[MAXV];	//��Ŷ�����Ϣ
}MGraph;					//ͼ���ڽӾ�������

//���¶����ڽӱ�����
typedef struct ANode		//���Ľ��ṹ����
{
	int adjvex;				//�Ļ����յ�λ��
	struct ANode *nextarc;	//ָ����һ������ָ��
	InfoType info;			//�Ļ��������Ϣ���������ڴ��Ȩֵ
}ArcNode;
typedef int Vertex;
typedef struct Vnode		//�ڽӱ�ͷ��������
{
	Vertex data;			//������Ϣ
	int count;				//��Ŷ�������
	ArcNode *firstarc;		//ָ���һ����
}VNode;
typedef VNode AdjList[MAXV]; //AdjList���ڽӱ�����
typedef struct
{
	AdjList adjlist;		//�ڽӱ�
	int n, e;				//ͼ�ж�����n�ͱ���e
}ALGraph;					//ͼ���ڽӱ�����

void MatToList(MGraph g, ALGraph *&G);	//���ڽӾ���gת�����ڽӱ�G
void ListToMat(ALGraph *G, MGraph &g);	//���ڽӱ�Gת�����ڽӾ���g
void DispMat(MGraph g);		//����ڽӾ���g
void DispAdj(ALGraph *G);	//����ڽӱ�G

// 1:ͼ�ı����㷨
/******************************************************\
ͼ�����ڽӱ�Ϊ�洢�ṹ������������������㷨
visited[]Ϊ���ʱ�־���飬������vi�����ʺ�����visited[i]Ϊ1��otherΪ0
\******************************************************/
void DFS(ALGraph *G, size_t v);	//������ȱ���(�ݹ�)
void DFS1(ALGraph *G, size_t v);	//������ȱ���(�ǵݹ�)
void BFS(ALGraph *G, int v);		//������ȱ���

//���ͼG�дӶ���u������v�����м�·��
void PathAll1(ALGraph *G, int u, int v, int path[], int i);
//���ͼG�дӶ���u������v�ĳ���Ϊl�����м�·����d�ǵ�ǰΪֹ���߹���·�����ȣ�����ʱ��ֵΪ-1
void PathAll2(ALGraph *G, int u, int v, int l, int path[], int d);
//MustPass:���뾭����  AvoidPass���������ĵ�
int Cond(int path[], int d, int MustPass[], int n, int AvoidPass[], int m);
void TravPath(ALGraph *G, int vi, int vj, int d, int path[],
	int MustPass[], int n, int AvoidPass[], int m);

// 2��ͼ����С�������㷨
void Prim(MGraph g, int v);
typedef struct
{
	int u, v, w; //�ߵ���㣬�յ㣬Ȩֵ
}Edge;
void SortEdge(MGraph g, Edge E[]);
void Kruskal(Edge E[], int n, int e);

// 3��ͼ�����·���㷨
/******************************************************\
���õҿ�˹�����㷨�ʹӶ���v0���������������·��
\******************************************************/
void Dijkstra(MGraph g, int v0);
//��path������·��
void DisPath(int dist[], int path[], int s[], int n, int v0);
void ppath(int path[], int i, int v0);

/******************************************************\
���ø��������㷨�����ж���֮������·��
\******************************************************/
void Flyod(MGraph g, std::vector<std::vector<int> > &A);
void DisPath(int A[][MAXV], int path[][MAXV], int n);
void ppath(int path[][MAXV], int i, int j);

//ͼ����������
void TopSort(ALGraph *G);


#endif