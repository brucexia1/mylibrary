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
	KeyType key;					//�ؼ���
	BInfoType data;					//����������
	struct bnode *lchild,*rchild;
}BSTNode;

//���ֲ����㷨
template<typename T>
int BinSearch(std::vector<T> &vec, int key);

/************************************************************************\
���������(BST)�ֶ�������(����)��
���ʣ�
��1�����������ǿգ������������м�¼ֵ��С�ڸ���¼ֵ
��2�����������ǿգ������������м�¼ֵ�����ڸ���¼ֵ
��3�����Ҹ�ʽһ��BST
ע�⣺����������¼ֵ��ͬ��Ԫ��
\************************************************************************/
int InsertBST(BSTNode *&p, KeyType k);

BSTNode *CreateBST(std::vector<KeyType> &vec);

void Del(BSTNode *p, BSTNode *&r);


#endif