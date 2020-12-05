#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//对数组进行初始化
void SeqListInit(SL *ps)
{
	////这是一种初始化方式,把a直接NULL
	/*s.size = 0;
	s.a = NULL; 
	s.capacity = 0;*/
	
	//第二种初始化方式  给a一块空间
    ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}
//因为用到了malloc，所以要进行销毁
//销毁的是s里面动态开辟的空间，结构体变量s不需要销毁
//因为他是个变量，所以存在了栈，自动销毁
void SeqListDestory(SL *ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SL *ps)//打印
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL *ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof
			(SLDataType)*ps->capacity);
		if (ps->a = NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
}


//尾插尾删和头插头删
void SeqListPushBack(SL *ps, SLDataType x)
{
	//size就是尾的下标
	assert(ps);

	//插入这步注意要判断空间够不够，如果空间不够的话进行增容
	//因为下面还有插入的步骤，它们都需要判断是否增容，所以为了方便直接用接口
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SL *ps, SLDataType x)
{
	assert(ps);
	//注意删除数据时没必要赋值0
	//直接size--就行了，当然赋值成0也没有错
	ps->size--;
}
void SeqListPushFront(SL *ps, SLDataType x)
{
	//注意插入步骤需要判断空间够不够，是否需要增容
	SeqListCheckCapacity(ps);

	//注意一个点，size是数组的尾端，他不是有效数字
	//而size-1才是数组有效数据中的最后一位
	int tmp = ps->size - 1;
	while (tmp >= 0)
	{
		ps->a[tmp + 1] = ps->a[tmp];
		tmp--;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SL *ps, SLDataType x)
{
	//直接把头部需要删除的数据覆盖
	int tmp = 0;
	while (tmp < ps->size-1)
	{
		ps->a[tmp] = ps->a[tmp + 1];
		tmp++;
	}
	ps->size--;
}

//任意位置的插入删除
void SeqListInsert(SL *ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);

	//是插入 同样也要判断
	SeqListCheckCapacity(ps);

	int tmp = ps->size - 1;
	while (tmp >= pos)
	{
		ps->a[tmp + 1] = ps->a[tmp];
		tmp--;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL *ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);

	int tmp = pos;
	while (tmp < ps->size - 1)
	//pos应该到size-2的位置就停下了，否则到size-1位置再挪的话可能会发生越界
	{
		ps->a[tmp] = ps->a[tmp + 1];
		tmp++;
	}
	ps->size--;
}

//顺序表查找
//找到了返回下标
int SeqListFind(SL *ps, SLDataType x)
{
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
		{
			printf("找到了\n");
			return i;
		}
		i++;
	}
	return -1;
}