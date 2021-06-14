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
//链栈的表示
typedef struct
{
	char name[20];
	int age;
}SElemType;
typedef struct StackNode
{
	SElemType data;
	StackNode* next;
}StackNode, *LinkStack;


//链栈的初始化
Status InitStack(LinkStack S)
{
	//构造一个空栈，栈顶指针置为空
	S = NULL;
	return OK;
}

//判断链栈是否为空
Status StackEmpty(LinkStack S)
{
	if (S == NULL)
		return TRUE;
	else
		return FALSE;
}

//链栈的入栈
Status Push(LinkStack S, SElemType e)
{
	LinkStack p = (LinkStack)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}

//链栈的出栈
Status Pop(LinkStack S, SElemType e)
{
	if (S == NULL)
		return ERROR;
	e = S->data;
	LinkStack p = S;
	S = S->next;
	free(p);
	return OK;
}

//队列的顺序表示 - 用一维数组base[MAXQSIZE]
#define MAXQSIZE 100  //最大队列长度

typedef char QElemType;

typedef struct
{
	QElemType* base; //初始化的动态分配存储空间
	int front; //头指针
	int rear;  //尾指针
}SqQueue;

//队列的初始化
Status InitQueue(SqQueue* Q)
{
	Q->base = (SqQueue*)malloc(sizeof(SqQueue)*MAXQSIZE); //分配数组空间
	if (!Q->base) //储存分配失败
		exit(OVERFLOW);
	Q->front = Q->rear = 0;//头指针和尾指针置为0，队列为空
	return OK;
}

//求队列的长度
int QueueLenth(SqQueue Q)
{
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

//循环队列入队
Status EnQueue(SqQueue* Q, QElemType e)
{
	if ((Q->rear + 1) % MAXQSIZE == Q->front)
		return ERROR;  //队满
	Q->base[Q->rear] = e;  //新元素加入队尾
	Q->rear = (Q->rear + 1) % MAXQSIZE; //队尾指针加一
	return OK;
}

//循环队列出队
Status DeQueue(SqQueue* Q,QElemType e)
{
	if (Q->rear == Q->front)
		return ERROR; //队空
	e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}

//取队头元素
SElemType GetHead(SqQueue Q)
{
	if (Q.front != Q.rear) //队列不为空
		return Q.base[Q.front]; //队头指针元素的值，队头指针不变
}