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


//折半插入排序
void BInsertSort(SqList* L) {
	int low, high, mid, i, j;
	for (i = 2;i <= L->length;i++) { //依次插入第2-n个元素
		L->r[0] = L->r[i]; //当前插入元素存到哨兵位置
		low = 1;
		high = i - 1; //采用二分查找法查找插入位置
		while (low <= high) {
			mid = (low + high) / 2;
			if (L->r[0].key > L->r[mid].key)
				low = mid + 1;
			else
				high = mid - 1;
		} //循环结束，high + 1则为插入位置
		for (j = i - 1;j > high + 1;j--) //移动元素
			L->r[j + 1] = L->r[j]; 
		L->r[high + 1] = L->r[0]; //插入到正确位置
	}
}



//快速排序
int Partition(SqList* L, int low, int high) {
	int pivotkey = L->r[low].key;
	L->r[0] = L->r[low];
	while (low < high) {
		while (low < high && L->r[high].key >= pivotkey)
			high--;
		L->r[low] = L->r[high];
		while (low < high && L->r[high].key <= pivotkey)
			low++;
		L->r[high] = L->r[low];
	}
	L->r[low] = L->r[0];
	return low;
}

void QSort(SqList* L, int low, int high) { //对顺序表L快速排序
	int pivotloc;
	if (low < high) { //长度大于1
		pivotloc = Partition(L, low, high); //将L.r[low...high]一分为二，pivotloc为枢纽元素排好序位置
		QSort(L, low, pivotloc - 1); //对低子表递归排序
		QSort(L, pivotloc + 1, high); //对高字表递归排序
	}
}

void main() {
	SqList L;
	QSort(&L, 1, L.length);
}