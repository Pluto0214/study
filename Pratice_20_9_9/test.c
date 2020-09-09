#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//写一个函数进行二分查找
int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return 0;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 15;
	int ret = binary_search(arr, k, sz);
	if (ret == 0)
	{
		printf("找不到了\n");
	}
	else
	{
		printf("找到了，下标是:%d\n", ret);
	}
	return 0;
}


//猜数字游戏
//#include<stdlib.h>
//#include<time.h>
//int main(void)
//{
//    srand(time(0));
//	int number = rand();
//	int count = 0;
//	int A = 0;
//    do
//    {
//        printf("请输入一个正整数\n");
//        scanf_s("%d", &A);
//        if (A == number)
//		{
//            printf("恭喜，你猜对了");
//		}
//		else if (A > number)
//		{
//			printf("比那个数大一点~\n");
//            count++;
//		}
//		else
//		{
//			printf("比那个数小一点~\n");
//            count++;
//		}
//
//	}
//	while (A != number);
//	return 0;
//}



//交换两个数组
//int main()
//{
//	int i;
//	int A[10];
//	int B[10];
//	int t[10];
//	printf("请输入数组A：");
//	for (i = 0; i<10; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	printf("请输入数组B：");
//	for (i = 0; i<10; i++)
//	{
//		scanf("%d", &B[i]);
//	}
//	for (i = 0; i<10; i++)
//	{
//		t[i] = A[i];
//		A[i] = B[i];
//		B[i] = t[i];
//	}
//	for (i = 0; i<10; i++)
//	{
//		printf("数组A是:%d ", A[i]);
//	}
//	printf("\n");
//	for (i = 0; i<10; i++)
//	{
//		printf("数组B是:%d ", B[i]);
//	}
//	printf("\n");
//	return 0;
//}

//1.实现函数init() 初始化数组为全0
//2.实现print()  打印数组的每个元素
//3.实现reverse()  函数完成数组元素的逆置。
//初始化数组全为0
//void init(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
////打印数组的每个元素
//void print(int arr[], int sz)
//{
//	int j = 0;
//	for (j = 0; j < sz; j++)
//	{
//		scanf("%d", &arr[j]);
//		printf("%d\n", arr[j]);
//	}
//}
////完成数组元素的逆置
//void reverse(int arr[], int sz)
//{
//	int i = 0;
//	int j = sz - 1;
//	while (arr[i] < arr[j])
//	{
//		int tmp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = tmp;
//		i++;
//		j--;
//	}
//}
//int main()
//{
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	init(arr,sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	print(arr, sz);
//	reverse(arr, sz);
//	return 0;
//}

//打印9*9乘法口诀表
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-3d", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//求10个整数中的最大值
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max=%d\n", max);
//	return 0;
//}

//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + flag*1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}


//二分查找二次练习
//int binary_search(int arr[], int sz, int k)
//{
//	int left = 0;
//	int right = sz - 1;
//	int mid = (right + left) / 2;
//	while (left <= right)
//	{
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 8;
//	int ret = binary_search(arr, sz, k);
//	if (ret == -1)
//	{
//		printf("找不到了\n");
//	}
//	else
//	{
//		printf("找到了，下标是:%d\n", ret);
//	}
//	return 0;
//}