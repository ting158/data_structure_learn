#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAXSIZE 20 //设记录不超过20个
typedef int KeyType; //设关键字为整型量
typedef char InfoType;

typedef struct  //定义每个记录（数据元素）的结构
{
	KeyType key;  //关键字
	InfoType otherinfo; //其他数据项
}RedType; //Record Type

typedef struct  //定义顺序表的结构
{
	RedType r[MAXSIZE + 1]; //存储顺序表的向量
	                        //r[0]一般作哨兵或缓冲区
	int length; //顺序表的长度
}SqList;


//直接插入排序算法
void InserSort(SqList* L)
{
	int i, j;
	for (i = 2;i <= L->length;i++)
	{
		if (L->r[i].key < L->r[i - 1].key)
		{
			L->r[0] = L->r[i];
		}
		for (j = i - 1;L->r[0].key < L->r[j].key;j--)
		{
			L->r[j + 1] = L->r[j];
		}
		L->r[j + 1] = L->r[0];
	}
}