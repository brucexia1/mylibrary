#include "../include/xsSearch.h"


//���ֲ����㷨
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
���������(BST)�ֶ�������(����)��
���ʣ�
��1�����������ǿգ������������м�¼ֵ��С�ڸ���¼ֵ
��2�����������ǿգ������������м�¼ֵ�����ڸ���¼ֵ
��3�����Ҹ�ʽһ��BST
ע�⣺����������¼ֵ��ͬ��Ԫ��
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
