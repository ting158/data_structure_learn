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

typedef int Status;


//邻接矩阵的存储表示

#define MaxInt 32767 //表示极大值，即∞
#define MVNum 100 //最大顶点数
typedef char VerTexType; //设定点的数据类型为字符型
typedef int ArcType; //假设边的权值类型为整型

typedef struct
{
	VerTexType vexs[MVNum];  //顶点表
	ArcType arcs[MVNum][MVNum];  //邻接矩阵
	int vexnum, arcnum;  //图的当前点数和边数
}AMGraph;


//补充算法：在图中查找顶点
int LocateVex(AMGraph G, VerTexType u)
//在图G中查找顶点u，存在则返回顶点表中的下标；否则返回-1
{
	int i;
	for (i = 0;i < G.vexnum;i++)
	{
		if (u == G.vexs[i])
			return i;
	}
	return -1;
}

//采用邻接矩阵表示法创建无向网
Status CreateUDN(AMGraph* G)  //采用邻接矩阵表示法，创建无向网G
{
	int i, j, k;
	char v1, v2;
	int w;
	scanf("%d%d", &G->vexnum, &G->arcnum); //输入总顶点数，总边数
	for (i = 0; i < G->vexnum; i++) //依次输入点的信息
	{
		scanf("%c", &(G->vexs[i]));
	}
	for (i = 0;i < G->vexnum;i++) //边的权值均置为极大值
	{
		for (j = 0;j < G->vexnum;j++)
		{
			G->arcs[i][j] = MaxInt;
		}
	}
	for (k = 0;k < G->arcnum;k++)  //构造邻接矩阵
	{
		scanf("%c%c%d", &v1, &v2, &w); //输入一条边所依附的定点及边的权值
		i = LocateVex(G, v1);
		j = LocateVex(G, v2); //确定v1和v2在G中的位置
		G->arcs[i][j] = w; //边<v1,v2>的权值置为w
		G->arcs[j][i] = w; //置<v1,v2>的对称边<v2,v1>的权值为w
	}
	return OK;
}

