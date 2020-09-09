#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//дһ���������ж��ֲ���
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
		printf("�Ҳ�����\n");
	}
	else
	{
		printf("�ҵ��ˣ��±���:%d\n", ret);
	}
	return 0;
}


//��������Ϸ
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
//        printf("������һ��������\n");
//        scanf_s("%d", &A);
//        if (A == number)
//		{
//            printf("��ϲ����¶���");
//		}
//		else if (A > number)
//		{
//			printf("���Ǹ�����һ��~\n");
//            count++;
//		}
//		else
//		{
//			printf("���Ǹ���Сһ��~\n");
//            count++;
//		}
//
//	}
//	while (A != number);
//	return 0;
//}



//������������
//int main()
//{
//	int i;
//	int A[10];
//	int B[10];
//	int t[10];
//	printf("����������A��");
//	for (i = 0; i<10; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	printf("����������B��");
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
//		printf("����A��:%d ", A[i]);
//	}
//	printf("\n");
//	for (i = 0; i<10; i++)
//	{
//		printf("����B��:%d ", B[i]);
//	}
//	printf("\n");
//	return 0;
//}

//1.ʵ�ֺ���init() ��ʼ������Ϊȫ0
//2.ʵ��print()  ��ӡ�����ÿ��Ԫ��
//3.ʵ��reverse()  �����������Ԫ�ص����á�
//��ʼ������ȫΪ0
//void init(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
////��ӡ�����ÿ��Ԫ��
//void print(int arr[], int sz)
//{
//	int j = 0;
//	for (j = 0; j < sz; j++)
//	{
//		scanf("%d", &arr[j]);
//		printf("%d\n", arr[j]);
//	}
//}
////�������Ԫ�ص�����
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

//��ӡ9*9�˷��ھ���
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

//��10�������е����ֵ
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

//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ
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


//���ֲ��Ҷ�����ϰ
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
//		printf("�Ҳ�����\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±���:%d\n", ret);
//	}
//	return 0;
//}