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

void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
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
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_size = php->_capacity = 0;
}
void HeapPush(Heap* php, HPDataType x)
{
	//����Ҫ�����ݷŽ�ȥ��Ҫ�����������ʣ���С�ѣ�
	assert(php);
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a,sizeof(HPDataType)*php->_capacity);
		php->_a = tmp;
	}

	//size�����ݸ�����������һ��λ��
	php->_a[php->_size++] = x;
	
	AdjustUp(php->_a, php->_size, php->_size - 1);
}
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	swap(&php->_a[php->_size], &php->_a[php->_size - 1]);
	php->_size--;

	AdjustDown(php->_a, php->_size, 0);
}
HPDataType HeapTop(Heap* php)
{
	//ȡ�Ѷ�������
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}