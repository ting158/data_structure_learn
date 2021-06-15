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


//队列的顺序表示 - 用一维数组base[MAXQSIZE]
//#define MAXQSIZE 100  //最大队列长度
//
//typedef char QElemType;
//
//typedef struct
//{
//	QElemType* base; //初始化的动态分配存储空间
//	int front; //头指针
//	int rear;  //尾指针
//}SqQueue;


//链队列的类型定义
#define MAXQSIZE 100  //最大队列长度

typedef char QElemType;

typedef struct Qnode
{
	QElemType data;
	struct Qnode* next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front; //队头指针
	QueuePtr rear;  //队尾指针
}LinkQueue;



//链队列的初始化
Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

//销毁链队列
Status DestroryQueue(LinkQueue* Q)
{
	LinkQueue* p;
	while (Q->front)
	{
		p = Q->front->next;
		free(Q->front);
		Q->front = p;
		/*Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;*/
	}
	return OK;
}

//将元素e入队
Status EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

//链队列出队
Status DeQueue(LinkQueue* Q, QElemType e)
{
	if (Q->front == Q->rear)
		return ERROR;
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = Q->front->next;
	e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}