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

//顺序栈的表示
#define MAXSIZE 100
typedef struct
{
	char name[20];
	int age;
}SElemType;
typedef struct
{
	SElemType* base; //栈底指针
	SElemType* top;   //栈顶指针
	int stacksize;    //栈可用最大容量
}SqStack;


//顺序栈的初始化
Status InitStack(SqStack S)
{
	S.base = (SElemType*)malloc(sizeof(SqStack) * MAXSIZE);
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base; //栈顶指针等于栈底指针
	S.stacksize = MAXSIZE;
	return OK;
}

//判断顺序栈是否为空
//若为空，返回TRUE,否则返回FALSE
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

//求顺序栈的长度
int StackLenth(SqStack S)
{
	return S.top - S.base;
}

//清空顺序栈
Status ClearStack(SqStack S)
{
	if (S.base)
		S.top = S.base;
	return OK;
}

//销毁顺序栈
Status DestroyStack(SqStack S)
{
	if (S.base)
	{
		free(S.base);
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

//顺序栈的入栈
Status Push(SqStack* S, SElemType e)
{
	if (S->top - S->base >= S->stacksize)
		return ERROR;
	*S->top = e;
	S->top++;
	return OK;
}

//顺序栈的出栈
Status Pop(SqStack S, SElemType* e)
{
	if (S.top = S.base)
		return ERROR;
	e = --S.top;
	return OK;
}