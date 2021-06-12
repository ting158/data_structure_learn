#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;


typedef struct
{
	char num[8];
	char name[20];
	int score;
}ElemType;

typedef struct Londe
{
	ElemType data;//数据域
	struct Londe* next;//指针域
}LNode, * LinkList;


//双向链表
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode, *DuLinkList;



//单链表的建立
//头插法 - 元素插入在链表的头部，也叫前插法
void Create_H(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;//先建立一个带有头结点的空链表
	int i = 0;
	LinkList p;
	for (i = n;i > 0;i--)
	{
		p = (LinkList)malloc(sizeof(LinkList));
		scanf(&p->data);//输入元素值
		p->next = L->next;
		L->next = p;
	}
}
//尾插法 - 元素插在链表尾部，也叫后插法
void CreateList_R(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;
	LinkList p;
	LinkList r = L; //尾指针r指向头结点
	int i = 0;
	for (i = 0;i < n;i++)
	{
		p = (LinkList)malloc(sizeof(LinkList));
		scanf(&p->data);
		p->next = NULL;
		r->next = p; //插入到表尾
		r = p;  //r指向新的尾结点
	}
}

//带尾指针循环链表的合并
LinkList Connect(LinkList Ta, LinkList Tb)
{
	LinkList p = Ta->next;
	Ta->next = Tb->next->next;
	free(Tb->next); //释放Tb的表头结点
	Tb->next = p;
	return Tb;
}

//双向链表的插入
void ListInsert_DuL(DuLinkList L, int i, ElemType e)
//在带头结点的双向循环链表L中第i个位置之前插入元素e
{
	DuLinkList p;
	if (!(p = GetElemP_Dul(L, i)))
		return ERROR;
	DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

//双向链表的删除
void ListInsert_DuL(DuLinkList L, int i, ElemType e)
//删除带头结点的双向循环链表L的第i个元素，并用e返回
{
	DuLinkList p;
	if (!(p = GetElemP_Dul(L, i)))
		return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}