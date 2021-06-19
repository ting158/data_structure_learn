#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int TElemType;

//二叉树链式存储
typedef struct BiTNode
{
	TElemType data;//数据域
	struct BiTNode* lchild, * rchild; //左右孩子结点
}BiNode,*BiTree;
