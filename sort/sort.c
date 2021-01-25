#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"


//// 直接插入排序
//void InsertSort(int* a, int n)
//{
//	assert(a);
//	//先假设认为有序区间的最后一个数的下标是end
//	//现在要做的是把end的后面那个位置往前插入
//	//如果end后面这个数比end小，那end就要往后挪了，这个时候就会把end+1覆盖，所以要先用一个tmp来保存这个end+1
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//			a[end + 1] = tmp;
//		}
//	}
//}

//// 希尔排序
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;//+1是为了保证最后一次gap一定是1
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end = end - gap;
//				}
//				else
//					break;
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}


// 直接 选择排序
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
  
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	int max, min;
	max = min = begin;
	while (begin < end)
	{
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}

		}
		swap(&a[begin], &a[min]);
		swap(&a[end], &a[max]);
		end--;
		begin++;
	}
}

//快速排序 三数取中
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
    if(a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin]>a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else//a[begin]>a[mid]
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
}

//快速排序
//三指针法
//单趟排序
int PartSort1(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	swap(&a[midIndex], &a[end]);

	int key = a[end];
	int keyindex = end;
	//key在右面，就要左面先走（也就是begin）
	//因为这样就能保证最后遇到的位置比key要大
	//所以选哪边作key都一样，区别就是让哪边先走
	while (begin < end)
	{
		//begin找大
		while (begin < end && begin <= key)
		{
			begin++;
		}
		
		//end找小
		while (begin < end && end >= key)
		{
			end--;
		}
		swap(&a[begin], &a[end]);
	}
	//相遇的位置和key的位置交换
	swap(&a[begin], &a[keyindex]);

	return begin;
}

//挖坑法
int PastSort2(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	swap(&a[midIndex], &a[end]);
	//end相当于一开始的坑
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end && begin <= key)
		{
			begin++;
		}

		//左边找到比key大的填到右面的坑，begin位置就形成了新的坑
		a[end] = a[begin];
		
		while (begin < end && end >= key)
		{
			end--;
		}
		//右边找到比key小的值填到左边的坑，end位置就形成了新的坑
		a[begin] = a[end];
	}
	a[begin] = key;

	return begin;
}


//前后指针法
void PartSort3(int* a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int keyindex = end;

	while (cur < end)
	{
		if (a[cur] < a[keyindex] && ++prev != cur)
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}

	swap(&a[++prev], &a[keyindex]);

	return prev;
}


void QuickSort(int* a, int left, int right)
{
	assert(a);
	//递归什么时候结束呢？
	if (left >= right)
	{
		return;
	}
	//或者直接给下面一个if(left<=right)

	int div = PartSort(a, left, right);
	//分为三个部分  [left,div-1],div,[div+1,right]
	QucikSort(a, left, div - 1);
	QucikSort(a, div+1, right);


}
