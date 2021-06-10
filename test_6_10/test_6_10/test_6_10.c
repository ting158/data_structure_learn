#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

//链表

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
}LNode, *LinkList;


//单链表的初始化
Status InitList_L(LinkList L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}

//判断链表是否为空
int ListEmpty(LinkList L)
{
	if (L->next) //非空
		return 0;
	else
		return 1;
}

//单链表的销毁
//  (从头指针开始，依次释放所有结点)
Status DestroyList_L(LinkList L)
{
	LinkList p;
	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}
	return OK;
}

//清空链表
 //(链表还在，但链表中无元素，成为空链表（头指针和头结点仍在）)
Status ClearList_L(LinkList L)
{
	LinkList p, q;
	p = L->next;
	free(p);
	while (q)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}

//求链表的表长
Status ListLength_L(LinkList L)
{
	LNode* p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

