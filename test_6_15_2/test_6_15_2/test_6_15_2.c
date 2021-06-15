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

//串的顺序储存结构
#define MAXLEN 255

typedef struct
{
	char ch[MAXLEN + 1];//储存串的一维数组
	int length;//串的当前长度
}SString;

//串的链式存储结构 - 块链结构
#define CHUNKSIZE 80 //块的大小

typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct
{
	Chunk* head, * tail; //串的头指针和尾指针
	int curlen; //串的当前长度
}LString; //字符串的块链结构


//BF算法描述
int Index_BF(SString S, SString T)
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		} //主串和子串依次匹配下一个字符
		else
		{
			i = i - j + 2;
			j = 1;
		} //主串、子串指针回溯重新开始下一次匹配
	}
	if (j > T.length)
		return i - T.length; //返回匹配的第一个字符的下标
	else
		return 0; //模式匹配不成功
}