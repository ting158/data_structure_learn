#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef  char *KeyType;

typedef struct
{
	KeyType key; //关键字域
	//...        //其他域
}ElemType;

//顺序表结构类型定义
typedef struct
{
	ElemType* R; //表地址
	int length; //表长
}SSTable;

SSTable ST; //定义顺序表ST


//若成功返回位置信息，否则返回0
int Search_Seq(SSTable ST, KeyType key)
{
	int i;
	for (i = ST.length;i >= 1;i--)
	{
		if (ST.R[i].key == key)
			return i;
	}
	return 0;
}