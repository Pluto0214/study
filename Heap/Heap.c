#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType* tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//���µ����㷨��ǰ�᣺������������С��
void AdjustDown(HPDataType* a, int n,int root)//n������Ĵ�С
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		//�ҳ����Һ�����С����һ��
		//Ĭ�����溢����С����һ����Ȼ�����Һ��ӱȴ�С������Һ���С�Ļ�����ô�Һ�����Ū��ȥ
		//�����ĺô����ǲ����������ӻ����Һ��ӣ�ֻ��ѡ��С���Ǹ����Ӿ���
		if (child+1<n && a[child + 1] < a[child])
		{
			child++;
		}

		//�������С�ڸ��ף��򽻻�
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//���һ��ʼ���׾�С�ں��ӣ��Ǿ�ֱ������ѭ��
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(php->_a, a, sizeof(HPDataType)*n);
	php->_size = n;
	php->_capacity = n;

	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php);
HPDataType HeapTop(Heap* php);