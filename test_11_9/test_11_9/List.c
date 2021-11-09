#define _CRT_SECURE_NO_WARNINGS 1

int arr[101];

//初始化线性表
void InitList(int* L)
{
	for (int i = 1; i < 101; i++)
	{
		*(L + i) = 0;
	}
}

//判断线性表是否为空表，空返回1，否则0
int ListEmpty(int L[])
{
	int i = 0;
	if (!L[1])
	{
		i = 1;
	}
	return i;
}

//将线性表清空
void ClearList(int* L)
{
	for (int i = 0; i < 101; i++)
	{
		*(L + i) = 0;
	}
}

//将线性表中第i个位置插入新元素e
int GetElem(int L[], int i, int* e)
{
	e = L[i + 1];
	return e;
}

//在线性表L中查找与e相等的元素，成功则返回元素序号，失败返回0
int LocateElem(int L[], int e)
{
	int i;
	for (i = 1;i <= 101;i++)
	{
		if (e = L[i])
		{
			return i;
		}
	}
	return 0;
}

//在线性表L中第i个位置插入新元素e
void ListInsert(int* L, int i, int e)
{
	for (int j = 100; j >= i + 1; j--)
	{
		L[j] = L[j - 1];
	}
	L[i] = e;
}

//删除线性表L中第i个位置元素，并用e返回其值
int ListDelet(int* L, int i, int* e)
{
	e = L[i];
	for (int j = i; j <= 100; j++)
	{
		L[j] = L[j + 1];
	}
	L[101] = 0;
	return e;
}

//返回线性表L的元素个数
int ListLength(int L[])
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 100; i++)
	{
		if (L[i])
			j++;
		else
			break;
	}
	return j;
}
