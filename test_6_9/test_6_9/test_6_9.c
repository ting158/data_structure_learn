#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


//多项式的顺序存储结构类型定义

#define MAXSIZE 1000//多项式可能达到的最大长度

typedef struct  //多项式非零项的定义
{
	float p; //系数
	int e; //指数
}Polynomial;

typedef struct
{
	Polynomial* elem; //存储空间的基地址
	int length;  //多项式中当前项的个数
}SqList;


//线性表L的初始化
int InitList_Sq(SqList* L)
{
	L->elem = (SqList*)malloc(sizeof(SqList) * MAXSIZE);
	if (!(L->elem))
	{
		exit(-2);//exit() 一般0为正常退出，非0为异常退出
	}
	L->length = 0;
	return 1;
}

//销毁线性表
void DestroyList(SqList* L)
{
	if (L->elem)
	{
		free(L->elem);
	}
}

//清空线性表L
void ClearList(SqList* L)
{
	L->length = 0;  //将线性表长度置为0
}

//求线性表长度
int GetLength(SqList* L)
{
	return L->length;
}

//判断线性表L是否为空
int IsEmpty(SqList* L)
{
	if (L->length == 0)
		return 1;
	else
		return 0;
}

//顺序表的取值（很具位置i获取相应位置数据元素的内容）
int GetElem(SqList* L, int i, Polynomial* e)
{
	if (i < 1 || i > L->length)
	{
		return 0;
	}
	*e = L->elem[i - 1];
	return 1;
}

//顺序表的查找
int LocateElem(SqList* L, int e)
//在线性表L中查找值为e的数据元素，返回其序号（是第几个元素）
{
	int i = 0;
	for (i = 0;i < L->length;i++)
	{
		if ((L->elem)->e == e)
			return i + 1;//查找成功，返回序号
	}
	return 0;//查找失败，返回0
}

//顺序表的插入
int ListInsert_Sq(SqList* L, int i, Polynomial* e)
{
	int j = 0;
	if (i < 1 || i > L->length)
		return 0;
	if (L->length == MAXSIZE)
		return 0;
	for (j = L->length - 1;j >= i - 1;j--)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i] = *e;
	L->length++;
	return 1;
}

//顺序表的删除
int ListDelete_Sq(SqList* L, int i)
{
	int j = 0;
	if (i < 1 || i > L->length)
		return 0;
	for (j = i;j <= L->length - 1;j++)
	{
		L->elem[j - 1] = L->elem[j];
	}
	L->length--;
	return 1;
}