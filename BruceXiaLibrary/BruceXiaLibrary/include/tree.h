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

//�ɶ����������ű�ʾ��str����������
void CreateBTNode( BTNode *&b, char *str );

//����data��Ϊx�Ľ��ָ��
BTNode * FindNode( BTNode *root, ElemType x );

//����*p��������ָ��
BTNode * LchildNode( BTNode *p );

//����*p�����Һ���ָ��
BTNode * RchildNode( BTNode *p );

//�������b�����
int BTNodeDepth( BTNode *b );

//�����ű�ʾ�����������
void DispBTNode( BTNode *root );

//�������b�Ŀ��
int BTWidth( BTNode *b );

//�������b�Ľ�����
int Nodes( BTNode *root );

//�������b��Ҷ������
int LeafNodes( BTNode *root );

void PreOrderRecursion( BTNode *b );		//�������(�ݹ�)
void PreOrder( BTNode *b );	//�������(�ǵݹ�)

void InOrderRecursion(BTNode *b);	//�������(�ݹ�)
void InOrder( BTNode *b );	//�������(�ǵݹ�)

void PostOrderRecursion(BTNode *b); //�������(�ݹ�)
void PostOrder( BTNode *b ); //�������(�ǵݹ�)

void TravLevel( BTNode *root );	//��α���

//���õݹ鷽������Ӹ���㵽Ҷ�ӽ���·��
void AllPathRecursion(BTNode *b, std::vector<ElemType> &path);

//���÷ǵݹ鷽������Ӹ���㵽Ҷ�ӽ���·��
void AllPath( BTNode *b );

//���·��
void LongPath(BTNode *b, std::vector<ElemType> &path, std::vector<ElemType> &longpath);

BTNode *CreateBT1( char *pre,char *in, int n );	//�����������������й��������
BTNode *CreateBT2( char *in,char *post, int n, int m );	//������ͺ���������й��������

BTNode *Convert( BTNode* proot );	//��һ�Ŷ���������ת��������˫������


#endif