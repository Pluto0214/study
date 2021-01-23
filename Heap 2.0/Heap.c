#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType* tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向下调整算法。前提：左右子树都是小堆
void AdjustDown(HPDataType* a, int n,int root)//n是数组的大小
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		//找出左右孩子中小的那一个
		//默认左面孩子是小的那一个，然后左右孩子比大小，如果右孩子小的话，那么右孩子再弄过去
		//这样的好处就是不用区分左孩子还是右孩子，只管选出小的那个孩子就行
		if (child+1<n && a[child + 1] < a[child])
		{
			child++;
		}

		//如果孩子小于父亲，则交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//如果一开始父亲就小于孩子，那就直接跳出循环
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

	//构建堆
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
	//除了要把数据放进去还要保持他的性质（大小堆）
	assert(php);
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a,sizeof(HPDataType)*php->_capacity);
		php->_a = tmp;
	}

	//size是数据个数，插在下一个位置
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
	//取堆顶的数据
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}