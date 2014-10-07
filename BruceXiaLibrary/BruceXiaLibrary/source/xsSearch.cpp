#include "../include/xsSearch.h"


//二分查找算法
template<typename T>
int BinSearch(std::vector<T> &vec, int key)
{
	if (vec.empty()) return -1;
	int low(0), high(vec.size() - 1), mid(0);
	while (low <= high){
		mid = low + (high - low) / 2;
		if (vec[mid] == key) return mid;
		if (vec[mid]>key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

/************************************************************************\
二叉查找树(BST)又二叉排序(搜索)树
性质：
（1）若左子树非空，则左子树所有记录值均小于根记录值
（2）若右子树非空，则右子树所有记录值均大于根记录值
（3）左右各式一颗BST
注意：不能有两记录值相同的元素
\************************************************************************/
int InsertBST(BSTNode *&p, KeyType k)
{
	if (!p){
		p = new BSTNode;
		p->key = k;
		p->lchild = p->rchild = NULL;
		return 1;
	}
	else if (k == p->key)
		return 0;
	else if (k<p->key)
		return InsertBST(p->lchild, k);
	else
		return InsertBST(p->rchild, k);
}

BSTNode *CreateBST(std::vector<KeyType> &vec)
{
	BSTNode * bt = NULL;
	int i(0);
	while (i<vec.size()){
		InsertBST(bt, vec[i++]);
	}
	return bt;
}

void Del(BSTNode *p, BSTNode *&r)
{
	return;
}
