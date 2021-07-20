#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 20 //设记录不超过20个
typedef int KeyType; //设关键字为整型量
typedef char InfoType;

typedef struct  //定义每个记录（数据元素）的结构
{
	KeyType key;  //关键字
	InfoType otherinfo; //其他数据项
}RedType; //Record Type

typedef struct  //定义顺序表的结构
{
	RedType r[MAXSIZE + 1]; //存储顺序表的向量
							//r[0]一般作哨兵或缓冲区
	int length; //顺序表的长度
}SqList;


//简单选择排序算法
void SelectSort(SqList* L) {
	int i, j, k;
	RedType tmp;
	for (i = 1;i < L->length;i++) {
		k = i;
		for (j = i + 1;j <= L->length;j++)
			if (L->r[j].key < L->r[k].key)
				k = j; //记录最小值位置
		if (k != i) {  //交换
			tmp = L->r[i];
			L->r[i] = L->r[k];
			L->r[k] = tmp;
		}
	}
}

typedef int elem;
//堆排序

//筛选过程
void HeapAdjust(elem R[], int s, int m)
/*
已知R[s...m]中记录的关键字除R[s]之外均满足堆的定义，
本函数调整R[s]的关键字，使R[s...m]成为一个大根堆
*/
{
	int rc = R[s];
	for (int j = 2 * s;j <= m;j *= 2) //沿key较大的孩子结点向下筛选
	{
		if (j < m && R[j] < R[j + 1]) //j为key较大的记录的下标
			j++;
		if (rc >= R[j])
			break;
		R[s] = R[j];
		s = j;   //rc应插入在位置s上
	}
	R[s] = rc; //插入
}