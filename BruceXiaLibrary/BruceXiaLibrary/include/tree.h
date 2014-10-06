#ifndef __BRUCEXIALIBRARY_TREE_C_H_
#define __BRUCEXIALIBRARY_TREE_C_H_

#include <vector>

#define MAXSIZE 100

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

//由二叉树的括号表示法str创建二叉链
void CreateBTNode( BTNode *&b, char *str );

//返回data域为x的结点指针
BTNode * FindNode( BTNode *b, ElemType x );

//返回*p结点的左孩子指针
BTNode * LchildNode( BTNode *p );

//返回*p结点的右孩子指针
BTNode * RchildNode( BTNode *p );

//求二叉树b的深度
int BTNodeDepth( BTNode *b );

//以括号表示法输出二叉树
void DispBTNode( BTNode *b );

//求二叉树b的宽度
int BTWidth( BTNode *b );

//求二叉树b的结点个数
int Nodes( BTNode *b );

//求二叉树b的叶结点个数
int LeafNodes( BTNode *b );

void PreOrder( BTNode *b );		//先序遍历(递归)
void PreOrder1( BTNode *b );	//先序遍历(非递归)

void InOrder( BTNode *b );	//中序遍历(递归)
void InOrder1( BTNode *b );	//中序遍历(非递归)

void PostOrder( BTNode *b ); //后序遍历(递归)
void PostOrder1( BTNode *b ); //后序遍历(非递归)

void TravLevel( BTNode *b );	//层次遍历

//采用递归方法输出从根结点到叶子结点的路径
void AllPath(BTNode *b, std::vector<ElemType> &path);

//采用非递归方法输出从根结点到叶子结点的路径
void AllPath1( BTNode *b );

//求最长路径
void LongPath(BTNode *b, std::vector<ElemType> &path, std::vector<ElemType> &longpath);

BTNode *CreateBT1( char *pre,char *in, int n );	//由先序和中序遍历序列构造二叉树
BTNode *CreateBT2( char *in,char *post, int n, int m );	//由先序和中序遍历序列构造二叉树

BTNode *Convert( BTNode* proot );	//将一颗二叉搜索树转换成排序双向链表


#endif