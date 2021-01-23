#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapSort(int* a, int n)
{
	//1.����
	for (int i = (n - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		swap(&a[0], &a[end]);

		//�ټ���ѡ��С��
		AdjustDown(a, end, 0);
		//ѭ���ĵ�һ�����µ����㷨Ҫ��n-1�Σ��ڶ���Ҫ��n-2�Σ�������end�����ҴӸ���ʼ�� ��0
		end--;
	}
}

int main()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapSort(a, sizeof(a)/sizeof(HPDataType));
}