#ifndef __BRUCEXIALIBRARY_BASESTRUCTURES_C_H_
#define __BRUCEXIALIBRARY_BASESTRUCTURES_C_H_


//#ifdef __cplusplus
//extern "C" {
//#endif


typedef int Elem;
typedef struct LNode	//定义单链表结点类型
{
	Elem data;
	struct LNode *next;
}LinkList;

typedef struct DNode	//定义双链表结点类型
{
	Elem data;
	struct DNode *prior;
	struct DNode *next;
}DLinkList;


//#ifdef __cplusplus
//}
//#endif

#endif