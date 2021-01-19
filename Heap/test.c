#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapSort(int* a, int n)
{
	//1.½¨¶Ñ
	for (int i = (n - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDown(a, n, i);
	}
}

int main()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapSort(a, sizeof(a)/sizeof(HPDataType));
}