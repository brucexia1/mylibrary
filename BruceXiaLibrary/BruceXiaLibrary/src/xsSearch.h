#ifndef __BRUCEXIALIBRARY_XSSEARCH_C_H_
#define __BRUCEXIALIBRARY_XSSEARCH_C_H_


#include <vector>

#ifndef KeyType
	typedef int KeyType;
#endif

#ifndef BInfoType
	typedef char BInfoType;
#endif

typedef struct bnode
{
	KeyType key;					//关键字
	BInfoType data;					//其他数据域
	struct bnode *lchild,*rchild;
}BSTNode;

//二分查找算法
template<typename T>
int BinSearch(std::vector<T> &vec, int key);

/************************************************************************\
二叉查找树(BST)又二叉排序(搜索)树
性质：
（1）若左子树非空，则左子树所有记录值均小于根记录值
（2）若右子树非空，则右子树所有记录值均大于根记录值
（3）左右各式一颗BST
注意：不能有两记录值相同的元素
\************************************************************************/
int InsertBST(BSTNode *&p, KeyType k);

BSTNode *CreateBST(std::vector<KeyType> &vec);

void Del(BSTNode *p, BSTNode *&r);


#endif