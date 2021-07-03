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
typedef char VerTexType; //设定点的数据类型为字符型
typedef int ArcType; //假设边的权值类型为整型
typedef int OtherInfo;


//图的邻接表存储表示

#define MVNum 100  //最大顶点数

typedef struct ArcNode  //边结点
{
	int adjvex; //该边所指向的顶点的位置
	struct ArcNode* nextarc; //指向下一条边的指针
	OtherInfo info; //和边相关的信息
}ArcNode; 

typedef struct VNode
{
	VerTexType data; //顶点信息
	ArcNode* firstarc; //指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum]; //AdjList表示邻接表类型

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; //图的当前顶点数和弧数
}ALGraph;


//采用邻接表表示法创建无向网
Status CreateUDG(ALGraph* G) //采用邻接表表示法，创建无向图G
{
	int i, j, k;
	int v1, v2;
	ArcNode* p1, *p2;
	scanf("%d%d", &(G->vexnum), &(G->arcnum)); //输入总顶点数和总边数
	for (i = 0;i < G->vexnum;i++) //构造表头结点表
	{
		scanf("%d", &(G->vertices[i].data)); //输入顶点值
		G->vertices->firstarc = NULL; //初始化表头结点的指针域
	}
	for (k = 0;k < G->vexnum;k++) //构造邻接表
	{
		scanf("%d%d", &v1, &v2); //输入一条边依附的两个顶点
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);  //查找v1，v2在G中的位置
		p1->adjvex = j; //临界点序号为j
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1; //将新结点*p1插入顶点v[i]的边表头部
		p2->adjvex = i; //邻接点序号为i
		p2->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = p2; //将新结点*p2插入顶点v[j]的边表头部
	}
	return OK;
}