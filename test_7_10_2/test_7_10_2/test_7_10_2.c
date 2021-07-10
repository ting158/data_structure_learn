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

typedef  char* KeyType;
typedef  char* InfoType;

//二叉排序树的存储结构
typedef struct
{
	KeyType key;   //关键字项
	InfoType otherinfo;  //其他数据项
}ElemType;

typedef struct BSTNode
{
	ElemType data;      //数据域
	struct BSTNode* lchild, * rchild; //左右孩子指针
}BSTNode,*BSTree;

BSTree T; //定义二叉排序树T


//二叉排序树的递归查找
BSTree SearchBST(BSTree T, KeyType key)
{
	if ((!T) || key == T->data.key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key); //在左子树中继续查找
	else
		return SearchBST(T->rchild, key); //在右子树中继续查找
}