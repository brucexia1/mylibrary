#ifndef __BRUCEXIALIBRARY_BASESTRUCTURES_C_H_
#define __BRUCEXIALIBRARY_BASESTRUCTURES_C_H_


//#ifdef __cplusplus
//extern "C" {
//#endif


typedef int Elem;
typedef struct LNode	//���嵥����������
{
	Elem data;
	struct LNode *next;
}LinkList;

typedef struct DNode	//����˫����������
{
	Elem data;
	struct DNode *prior;
	struct DNode *next;
}DLinkList;


//#ifdef __cplusplus
//}
//#endif

#endif