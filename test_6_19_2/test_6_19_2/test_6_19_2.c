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
typedef int TElemType;

//链式二叉树存储结构
typedef struct BiTNode
{
	TElemType data;//数据域
	struct BiTNode* lchild, * rchild; //左右孩子结点
}BiNode, * BiTree;

//二叉树的队列类型定义
#define MaxSize 100
typedef struct
{
	BiNode data[MaxSize]; //存放队中元素
	int front, rear; //队头和队尾指针
}SqQueue;  //顺序循环队列类型


//复制二叉树
int Copy(BiTree T, BiTree P)
{
	if (T == NULL)
	{
		P == NULL;
		return 0;
	}
	else
	{
		P = (BiTree)malloc(sizeof(BiNode));
		P->data = T->data;
		Copy(T->lchild, P->lchild);
		Copy(T->rchild, P->rchild);
	}
}

//计算二叉树深度

//创建二叉树
void CreatBiTree(BiTree* T)
{
	char c;
	scanf("%c", &c);
	if (c == '#')
		*T = NULL;
	else
	{
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild));
	}
}
int Depth(BiTree T)
{
	int m, n;
	if (T == NULL)
		return 0;
	else
	{
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}

int main()
{
	BiTree T = NULL;
	printf("请输入一个二叉树（#为空子树）：");
	CreatBiTree(&T);
	printf("二叉树的深度为%d\n", Depth(T));
	return 0;
}
