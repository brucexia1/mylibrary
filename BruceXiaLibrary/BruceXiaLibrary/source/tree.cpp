#include <stdio.h>
#include <iostream>
#include "../include/tree.h"
#include "../include/com.h"

using namespace std;


//由二叉树的括号表示法str创建二叉链
void CreateBTNode( BTNode *&b, char *str )
{
	int i(0),top(-1),k(1);
	b = NULL;
	BTNode *St[MAXSIZE],*p(NULL);
	char ch = str[i];
	while ( ch!=NULL ){
		switch (ch)
		{
		case '(': top++;St[top] = p;k=1;
			break;
		case ')': top--;
			break;
		case ',': k=2;
			break;
		default:
			p = new BTNode;
			p->data = ch;
			p->lchild = NULL;
			p->rchild = NULL;
			if( b==NULL ) b = p;
			else{
				switch(k){
				case 1: St[top]->lchild = p; 
					break;
				case 2: St[top]->rchild = p; 
					break;
				}
			}
			break;
		}
		i++;
		ch = str[i];
	}
}

//返回data域为x的结点指针
BTNode * FindNode(BTNode *root, ElemType x)
{
	BTNode *p;
	if ( root== NULL) return NULL;
	else if (root->data == x) return root;
	else{
		p = FindNode(root->lchild, x);
		if(p!=NULL)
			return p;
		else
			return FindNode(root->rchild, x);
	}
}

//返回*p结点的左孩子指针
BTNode * LchildNode( BTNode *p )
{
	return p->lchild;
}

//返回*p结点的右孩子指针
BTNode * RchildNode( BTNode *p )
{
	return p->rchild;
}

//求二叉树b的深度
int BTNodeDepth( BTNode *b )
{
	int lc(0),rc(0);
	if( b==NULL ) return 0;
	else{
		lc = BTNodeDepth( b->lchild );
		rc = BTNodeDepth( b->rchild );
		return (lc>rc)?(lc+1):(rc+1);
	}
}

//以括号表示法输出二叉树
void DispBTNode(BTNode *root)
{
	if ( root!= NULL){
		printf("%c", root->data);
		if (root->lchild != NULL || root->rchild != NULL){
			printf("(");
			DispBTNode(root->lchild);
			if (root->rchild != NULL) printf(",");
			DispBTNode(root->rchild);
			printf(")");
		}
	}
}

//求二叉树b的宽度
int BTWidth( BTNode *b )
{
	struct{
		int lno;
		BTNode *p;
	}Qu[MAXSIZE];
	BTNode *bp;
	int front,rear;
	int lnum,max,i,n;
	front = rear = 0;
	if ( b!=NULL )
	{
		rear++;
		Qu[rear].p = b;
		Qu[rear].lno = 1;
		while ( front!=rear )
		{
			front++;
			bp = Qu[front].p;
			lnum = Qu[front].lno;
			if ( bp->lchild!=NULL )
			{
				rear++;
				Qu[rear].p = bp->lchild;
				Qu[rear].lno = lnum+1;
			}
			if ( bp->rchild!=NULL )
			{
				rear++;
				Qu[rear].p = bp->rchild;
				Qu[rear].lno = lnum+1;
			}
		}
		max=0; lnum=1; i=1;
		while ( i<rear )
		{
			n=0;
			while ( i<rear && Qu[i].lno==lnum )
			{	n++; i++;
			}
			lnum = Qu[i].lno;
			if( n>max ) max = n;
		}
		return max;
	}else return 0;
}

//求二叉树b的结点个数
int Nodes(BTNode *root)
{
	int lnum,rnum;
	if (root == NULL)	return 0;
	else if (root->lchild == NULL && root->rchild == NULL)	return 1;
	else{
		lnum = Nodes(root->lchild);
		rnum = Nodes(root->rchild);
		return (lnum+rnum+1);
	}
}

//求二叉树b的叶结点个数
int LeafNodes(BTNode *root)
{
	int lnum,rnum;
	if (root == NULL)	return 0;
	else if (root->lchild == NULL && root->rchild == NULL)	return 1;
	else{
		lnum = LeafNodes(root->lchild);
		rnum = LeafNodes(root->rchild);
		return (lnum+rnum);
	}
}

void PreOrderRecursion(BTNode *b)		//先序遍历(递归)
{
	if ( b!=NULL )
	{
		printf("%c ",b->data);
		PreOrderRecursion(b->lchild);
		PreOrderRecursion(b->rchild);
	}
}
void PreOrder( BTNode *b )	//先序遍历(非递归)
{	//设立一个栈，先右孩子入栈后左孩子入栈
	vector<ElemType> prenodes;
	
	BTNode *St[MAXSIZE],*p;
	int top(-1);
	if ( b!=NULL )
	{
		top++;
		St[top] = b;
		while ( top>=0 )
		{
			p = St[top];
			top--;
			prenodes.push_back(p->data);
			if ( p->rchild!=NULL )
			{
				top++;
				St[top] = p->rchild;
			}
			if ( p->lchild!=NULL )
			{
				top++;
				St[top] = p->lchild;
			}
		}

		PrintVector<ElemType>(prenodes);
	}
}

void InOrderRecursion(BTNode *b)	//中序遍历(递归)
{
	if ( b!=NULL )
	{
		InOrderRecursion(b->lchild);
		printf("%c ",b->data);
		InOrderRecursion(b->rchild);
	}
}
void InOrder( BTNode *b )	//中序遍历(非递归)
{
	vector<ElemType> innodes;

	BTNode *St[MAXSIZE],*p;
	int top(-1);
	if ( b!=NULL )
	{	
		p = b;
		while ( top>-1 || p!=NULL )
		{
			while( p!=NULL ){
				top++; St[top] = p;
				p = p->lchild;
			}
			if( top>-1 ){
				p = St[top]; top--;
				innodes.push_back(p->data);
				p = p->rchild;
			}
		}

		PrintVector<ElemType>(innodes);
	}
}

void PostOrderRecursion(BTNode *b) //后序遍历(递归)
{
	if ( b!=NULL )
	{
		PostOrderRecursion(b->lchild);
		PostOrderRecursion(b->rchild);
		printf("%c ",b->data);
	}
}
void PostOrder( BTNode *b ) //后序遍历(非递归)
{
	vector<ElemType> postnodes;

	BTNode *St[MAXSIZE],*p;
	int top(-1),flag;
	if ( b!=NULL )
	{
		do 
		{
			while( b!=NULL ){
				top++; St[top] = b;
				b = b->lchild;
			}
			p = NULL;
			flag = 1;
			while ( top>-1 && flag )
			{
				b = St[top];
				if ( b->rchild==p )
				{
					postnodes.push_back(b->data);
					top--;
					p=b;
				}
				else
				{
					b = b->rchild;
					flag = 0;
				}
			}
		} while ( top>-1 );

		PrintVector<ElemType>(postnodes);
	}
}

//层次遍历
void TravLevel(BTNode *root)
{
	vector<ElemType> levelnodes;

	BTNode *Qu[MAXSIZE],*p;
	int front,rear;
	front = rear = 0;
	if (root != NULL)
	{
		levelnodes.push_back(root->data);
	}
	Qu[rear] = root;
	rear++;
	while ( rear!=front )
	{
		p = Qu[front];
		front = (front+1)%MAXSIZE;
		if ( p->lchild!=NULL )
		{
			levelnodes.push_back(p->lchild->data);
			Qu[rear] = p->lchild;
			rear = (rear+1)%MAXSIZE;
			if( (rear+1)%MAXSIZE==front ) return;
		}
		if ( p->rchild!=NULL )
		{
			levelnodes.push_back(p->rchild->data);
			Qu[rear] = p->rchild;
			rear = (rear+1)%MAXSIZE;
			if( (rear+1)%MAXSIZE==front ) return;
		}
	}

	PrintVector<ElemType>(levelnodes);
}

//采用递归方法输出从根结点到叶子结点的路径
void AllPathRecursion(BTNode *b, vector<ElemType> &path)
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
		{
			printf("%c到根结点路径：%c ", b->data, b->data);
			for (int i = path.size() - 1; i >= 0; i--)
				printf("%c ", path[i]);
			printf("\n");
		}
		else
		{
			path.push_back(b->data);
			AllPathRecursion(b->lchild, path);
			AllPathRecursion(b->rchild, path);
			path.pop_back();	//恢复环境，此句一定要有
		}
	}
}

//采用非递归方法输出从根结点到叶子结点的路径
void AllPath( BTNode *b )
{
	typedef struct snode
	{
		BTNode *node;
		int parent;
	}PNode;
	PNode Qu[MAXSIZE];
	int rear,front,p;
	rear = front = -1;
	rear++;
	Qu[rear].node = b;
	Qu[rear].parent = -1;
	while ( front<rear )
	{
		front++;
		b = Qu[front].node;
		if ( b->lchild==NULL && b->rchild==NULL )
		{
			printf("从%c到根结点的路径：",b->data);
			p = front;
			while ( Qu[p].parent!=-1 )
			{
				printf("%c ",Qu[p].node->data );
				p = Qu[p].parent;
			}
			printf( "%c\n",Qu[p].node->data );
		}
		if ( b->lchild!=NULL )
		{
			rear++;
			Qu[rear].node = b->lchild;
			Qu[rear].parent = front;
		}
		if ( b->rchild!=NULL )
		{
			rear++;
			Qu[rear].node = b->rchild;
			Qu[rear].parent = front;
		}
	}
}

//求最长路径
void LongPath(BTNode *b, vector<ElemType> &path, vector<ElemType> &longpath)
{
	int i;
	if (b == NULL){
		if (path.size()>longpath.size()){
			longpath.clear();
			for (i = 0; i<path.size(); i++)
				longpath.push_back(path[i]);
		}
	}
	else
	{
		path.push_back(b->data);
		LongPath(b->lchild, path, longpath);
		LongPath(b->rchild, path, longpath);
		path.pop_back();	//恢复环境，此句一定要有
	}
}

BTNode *CreateBT1( char *pre,char *in, int n )	//由先序和中序遍历序列构造二叉树
{
	BTNode *p;
	char *c;
	if( n==0 || pre==NULL || in==NULL ) return NULL;
	p = new BTNode;
	p->data = *pre; p->lchild = NULL; p->rchild = NULL;
	for ( c=in;c<in+n;c++ )
		if( *c==*pre ) break;
	int k(c-in);
	p->lchild = CreateBT1( pre+1,in,k );
	p->rchild = CreateBT1( pre+k+1,c+1,n-k-1 );
	return p;
}
BTNode *CreateBT2( char *in,char *post, int n, int m )	//由中序和后序遍历序列构造二叉树
{
	BTNode *p = NULL;
	return p;
}

void ConvertNode( BTNode* proot, BTNode** pLastNIList )
{
	if( !proot ) return;
	BTNode *pCur = proot;
	if ( pCur->lchild )
		ConvertNode( pCur->lchild, pLastNIList );

	pCur->lchild = *pLastNIList;
	if( *pLastNIList )
		(*pLastNIList)->lchild = pCur;

	*pLastNIList = pCur;

	if( pCur->rchild )
		ConvertNode( pCur->rchild,pLastNIList );
}
BTNode *Convert( BTNode* proot )	//将一颗二叉搜索树转换成排序双向链表
{
	BTNode *pLastNIList = NULL;
	ConvertNode( proot, &pLastNIList );
	BTNode *phead = pLastNIList;
	while ( phead && phead->lchild )
		phead = phead->lchild;

	return phead;
}
