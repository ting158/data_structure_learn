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
typedef int ElemType;
typedef int TElemType;

//树的双亲表存储表示

#define MAX_TREE_SIZE 100

typedef struct PTNdode
{
	TElemType data;
	int parent;  //双亲位置域
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n; //根结点的位置和结点个数
}PTree;


//树的孩子两边存储表示

typedef struct CTNode  //孩子结点
{
	int child;   //孩子结点下标位置
	struct CTNode* next;
}*ChildPtr;

typedef struct
{
	TElemType data;
	ChildPtr firstchild; //孩子链表指针
}CTBox;

typedef struct
{
	CTBox nades[MAX_TREE_SIZE];
	int n, r;  //结点数和根的位置
};


//树的二叉链表（孩子 - 兄弟）存储表示

typedef struct CSNode
{
	ElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;
