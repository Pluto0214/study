#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//左旋k个字符方法2
void reverse(char*left, char*right)
{
	char tmp = 0;
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char arr[], int k)
{
	int len = strlen(arr);
	reverse(arr, arr + k - 1);
	reverse(arr + k, arr + len - 1);
	reverse(arr, arr + len - 1);
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}

////左旋k个字符方法1
//void left_move(char arr[], int k)
//{
//	int i = 0;
//	int len = strlen(arr);
//assert(k <= len);
//	for (i = 0; i < k; i++)
//	{
//		char tmp = arr[0];
//		int j = 0;
//		for (j = 0; j <= len - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int arr[50][50] = { 0 };
//	scanf("%d", &n);
//	for (i = 0; i <= n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i <= n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d  ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<string.h>
//#include<assert.h>
//void left_move(char arr[], int k)
//{
//	int i = 0;
//	int len = strlen(arr);
//	assert(k <= len);
//	for (i = 0; i < k; i++)
//	{
//		char tmp = arr[0];
//		int j = 0;
//		for (j = 0; j < len; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "ABCD";
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, k);
//	printf("%s", arr);
//		return 0;
//}