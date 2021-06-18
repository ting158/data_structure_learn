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

//链式二叉树存储结构
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild; //左右孩子指针
}BiNode,*BiTree;