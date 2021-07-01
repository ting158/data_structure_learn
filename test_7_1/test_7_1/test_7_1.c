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
typedef int ElemType;
typedef int TElemType;
typedef char** HuffmanCode;


//哈弗曼树
int s1, s2;
typedef struct
{
	int weight;
	int parent, lch, rch;
}HTNode, *HuffmanTree;

void CreatHuffmanTree(HuffmanTree HT, int n) //构造哈夫曼树
{
	if (n <= 1)
		return;
	int i;
	int m = 2 * n - 1; //元素个数
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); //0号单元未用，HT[m]表示根节点
	for (i = 1;i <= m;i++) //将2n-1个元素的lch、rch、parent置为0
	{
		HT[i].parent = 0;
		HT[i].lch = 0;
		HT[i].rch = 0;
	}
	for (i = 1;i <= n;i++)
	{
		scanf("%d", HT[i].weight);//输入前n个元素的weight值
	}
	//初始化结束，下面开始建立哈夫曼树

	for (i = n + 1;i <= m;i++) //合并产生n-1个结点--构造哈夫曼树
	{
		Select(HT, i - 1, s1, s2); //在HT[k](1<=k<=i-1)中原则其两个双亲域为0
		                           //且权值最小的结点，并返回他们在HT中序号s1和s2
		HT[s1].parent = i; HT[s2].parent = i; //表示从F中删除s1、s2
		HT[i].lch = s1; HT[i].rch = s2; //s1,s2分别作为i的左右孩子
		HT[i].weight = HT[s1].weight + HT[s2].weight; //i的权值为左右孩子权值之和
	}
}

//哈夫曼编码
void CreatHuffmanCode(HuffmanTree HT, HuffmanCode HC, int n)
//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
{
	int i, start, c, f;
	HC = (char**)malloc((n + 1) * sizeof(char*)); //分配n个字符编码的头指针矢量
	char* cd = (char)malloc(n * sizeof(char)); //分配临时存放编码的动态数组空间
	cd[n - 1] = '\0'; //编码结束符
	for (i - 1;i <= n;i++) //逐个字符求哈夫曼编码
	{
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (!f)  //从叶子结点开始向上回溯，直到根节点
		{
			start--; //回溯一次start向前指一个位置
			if (HT[f].lch == c) //左孩子，则生成代码0
				cd[start] = '0';
			else                //右孩子为1
				cd[start] = '1';
			c = f;
			f = HT[f].parent; //继续向上回溯
		}    //求出第i个字符的编码
		HC[i] = (char*)malloc((n - start) * sizeof(char));//为第i个字符编码分配空间
		strcpy(HC[i], &cd[start]);//将求得的编码从临时空间cd复制到HC的当前行中
	}
	free(cd); //释放临时空间
	cd = NULL;
}