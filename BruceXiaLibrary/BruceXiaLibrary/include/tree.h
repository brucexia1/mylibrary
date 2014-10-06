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
BTNode * FindNode( BTNode *b, ElemType x );

//����*p��������ָ��
BTNode * LchildNode( BTNode *p );

//����*p�����Һ���ָ��
BTNode * RchildNode( BTNode *p );

//�������b�����
int BTNodeDepth( BTNode *b );

//�����ű�ʾ�����������
void DispBTNode( BTNode *b );

//�������b�Ŀ��
int BTWidth( BTNode *b );

//�������b�Ľ�����
int Nodes( BTNode *b );

//�������b��Ҷ������
int LeafNodes( BTNode *b );

void PreOrder( BTNode *b );		//�������(�ݹ�)
void PreOrder1( BTNode *b );	//�������(�ǵݹ�)

void InOrder( BTNode *b );	//�������(�ݹ�)
void InOrder1( BTNode *b );	//�������(�ǵݹ�)

void PostOrder( BTNode *b ); //�������(�ݹ�)
void PostOrder1( BTNode *b ); //�������(�ǵݹ�)

void TravLevel( BTNode *b );	//��α���

//���õݹ鷽������Ӹ���㵽Ҷ�ӽ���·��
void AllPath(BTNode *b, std::vector<ElemType> &path);

//���÷ǵݹ鷽������Ӹ���㵽Ҷ�ӽ���·��
void AllPath1( BTNode *b );

//���·��
void LongPath(BTNode *b, std::vector<ElemType> &path, std::vector<ElemType> &longpath);

BTNode *CreateBT1( char *pre,char *in, int n );	//�����������������й��������
BTNode *CreateBT2( char *in,char *post, int n, int m );	//�����������������й��������

BTNode *Convert( BTNode* proot );	//��һ�Ŷ���������ת��������˫������


#endif