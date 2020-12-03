#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
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



void left_move(char arr[], int k)
{
	int i = 0;
	int len = strlen(arr);
	assert(k <= len);
	for (i = 0; i < k; i++)
	{
		//旋转一个字符
		char tmp = arr[0];
		int j = 0;
		for (j = 0; j < len; j++)
		{
			//把j+1下标和j下标的元素进行交换
			arr[j] = arr[j + 1];
		}
		arr[len - 1] = tmp;
	}
}
int main()
{
	char arr[] = "abcdef";
	//不能写成char*arr=".."因为这是一个常量字符串，不能改变
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("")
		//因为这是一个字符串，所以不用传字符串有多少元素，因为有\0，
		//如果是整形字符串之类的话就要传sz了。
		return 0;
}