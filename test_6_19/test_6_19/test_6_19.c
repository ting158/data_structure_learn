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

//二叉树先序遍历算法
Status PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK; //空二叉树
	else
	{
		visit(T); //访问根结点
		PreOrderTraverse(T->lchild); //递归遍历左子树
		PreOrderTraverse(T->rchild); //递归遍历右子树
	}
}

//二叉树中序遍历算法
Status InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK; //空二叉树
	else
	{
		InOrderTraverse(T->lchild); //递归遍历左子树
		visit(T); //访问根结点
		InOrderTraverse(T->rchild); //递归遍历右子树
	}
}

//二叉树后序遍历算法
Status PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK; //空二叉树
	else
	{
		PostOrderTraverse(T->lchild); //递归遍历左子树
		PostOrderTraverse(T->rchild); //递归遍历右子树
		visit(T); //访问根结点
	}
}