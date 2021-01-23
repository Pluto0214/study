#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapSort(int* a, int n)
{
	//1.建堆
	for (int i = (n - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		swap(&a[0], &a[end]);

		//再继续选次小的
		AdjustDown(a, end, 0);
		//循环的第一次向下调整算法要调n-1次，第二次要调n-2次，正好是end。并且从根开始调 即0
		end--;
	}
}

int main()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapSort(a, sizeof(a)/sizeof(HPDataType));
}