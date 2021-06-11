#define _CRT_SECURE_NO_WARNINGS 1\

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


//取值 - 取单链表中第i个元素的内容
Status GetElem_L(LinkList L, int i, ElemType e)//通过e变量返回
{
	LinkList p = L->next;
	int j = 1; //向后扫描，直到p指向第i个元素或p为空
	while (p && (j < i))
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) //第i个元素不存在
		return ERROR;
	e = p->data; //取第i个元素
	return OK;
}

//查找
//（按值查找 - 根据指定数据获取该数据的指定位置（地址））
LNode* LocateElem_L(LinkList L, ElemType e)
//找到，返回e的地址，否则返回空指针
{
	LinkList p = L->next;
	while (p && (p->data != e))
	{
		p = p->next;
	}
	return p;
}

//插入 - 在第i个结点前插入新结点
Status ListInsert_L(LinkList L, int i, ElemType e)
//在L中第i个元素之前插入数据元素e
{
	LinkList p = L;
	int j;
	while (p && (j < i - 1)) //寻找第i-1个结点，p指向i-1结点
	{
		p = p->next;
		j++;
	}
	if (!p || (j > i + 1))
		return ERROR;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//删除 - 删除第i个结点
Status ListDelete_L(LinkList L, int i, ElemType e)
{
	LinkList p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;   //保存删除结点的数据域
	free(q);
	return OK;
}
