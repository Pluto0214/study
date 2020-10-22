#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void Left_Move(char arr[], int k) 
{
	int size = strlen(arr);
	char *p, *arr_end, tmp;
	arr_end = arr + size - 1;
	tmp = *arr;
	for (p = arr; p < arr + size - 1; ++p)
	{
		*p = *(p + 1);
	}
	*arr_end = tmp;
	--k;
	if (k > 0) 
	{
		Left_Move(arr, k);
	}
}
int Is_Move(char* dest, char* src) 
{  
	if (strlen(dest) != strlen(src)) 
	{        
		return 0;
	}
	if (!strcmp(dest, src)) 
	{
		return 1;
	}
	int k = strlen(dest);
	while (--k) 
	{
		Left_Move(src, 1);
		if (!strcmp(dest, src)) 
		{
			return 1;
		}
	}
	return 0;
}
int main() 
{
	char dest[1024];
	char src[1024];
	printf("������Ҫ�жϵ������ַ�����\n");
	scanf("%s", &dest);
	scanf("%s", &src);
	int ret = Is_Move(dest, src);
	printf("%d\n", ret);
	system("pause");
	return 0;
}


//#define ROW 4
//#define COL 4
//���Ͼ���
//int Yang(int arr[ROW][COL], int val)
//{
//	int i = 0;
//	int j = COL - 1;
//	int tmp = arr[i][j];
//	while (1)
//	{
//		if (tmp == val)
//		{
//			return 1;
//		}
//		else if (tmp < val && j >= 0)
//		{
//			tmp = arr[++i][j];
//		}
//		else if (tmp > val &&j >= 0)
//		{
//			tmp = arr[i][--j];
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//}
//int main()
//{
//	int a[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//	int i = 0;
//	int j = 0;
//	int num;
//	printf("����Ϊ:\n");
//	for (i = 0; i<ROW; i++)
//	{
//		for (j = 0; j < COL; j++);
//		{
//			printf("%5d", a[i][j]);
//		}
//		printf("\n");
//	}
//	printf("Please Enter:");
//	scanf("%d", &num);
//	if (Yang(a, num))
//	{
//		printf("%d�ڸ�������\n", num);
//	}
//	else
//	{
//		printf("%d���ڸ�������\n", num);
//	}
//	system("pause");
//	return 0;
//}


//qsort������ģ��ʵ��
//int int_cmp(const void * p1, const void * p2)
//{
//	return (*(int *)p1 - *(int *)p2);
//}
//void _swap(void * p1, void * p2, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		char tmp = *((char *)p1 + i);
//		*((char *)p1 + i) = *((char *)p2 + i);
//		*((char *)p2 + i) = tmp;
//	}
//}
//void bubble(void *base, int count, int size, int(*cmp)(void*, void*))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < count - 1; i++)
//	{
//		for (j = 0; j < count - i - 1; j++)
//		{
//			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) > 0) 
//			{
//				_swap((char *)base + j*size, (char *)base + (j + 1)*size, size); 
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,4,7,9,5,3,2,8,6 };
//	int i = 0;
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//qsort������ʹ��
//int int_cmp(const void * p1, const void * p2)
//{
//	return (*(int *)p1 - *(int *)p2);
//}
//int main()
//{
//	int arr[] = { 1,4,7,9,5,3,2,8,6 };
//	int i = 0;
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
////ģ��ʵ��strcpy
//char*my_strcpy(char*dest, const char*src)
//{
//	char*ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "hello";
//	char arr2[50] = "XXXXXXXXXXXX";
//	printf("%s\n", my_strcpy(arr2, arr1));
//	return 0;
//}

//3.�ҵ�h��\0�ĵ�ַ������ָ��������õ��м��Ԫ�ظ���
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char*start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - start;
//}
//int main()
//{
//	char arr[] = "hello";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//
//2.��ʹ����ʱ����ģ��ʵ��strlen
//my_strlen("abcdef")
//1+my_strlen("bcdef")
//1+1+my_strlen("cdef")
//.....
//1+1+1+1+1+1my_strlen("")
//1+1+1+1+1+1+0
//�õ�6
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "hello";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//
//1.ʹ����ʱ������ģ��ʵ��strlen
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "hello";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

////����strlen����ֵsize_t
//int main()
//{
//	char*p1 = "abc";
//	char*p2 = "abcde";
//	if (strlen(p1) - strlen(p2) > 0)
//	{
//		printf("hehe\0");
//	}
//	else
//	{
//		printf("haha\0");
//	}
//	return 0;
//}