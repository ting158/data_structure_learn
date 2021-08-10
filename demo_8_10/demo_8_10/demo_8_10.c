#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//线性表

#define LIST_INIT_SIZE 100 //线性表储存空间的初始分配量
#define LISTINCREMENT 4   //线性表存储空间的分配增量

typedef int ElemType;

typedef struct
{
	ElemType* elem;  //存储空间基地址
	int length;  //当前长度
	int listsize;  //当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;

//构造空线性表
void InitList_Sq(SqList* L)
{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(L->elem))
	{
		printf("分配失败\n");
		exit(1);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	printf("分配成功\n");
}

int main()
{
	SqList L;
	InitList_Sq(&L);

	free(L.elem);
	return 0;
}