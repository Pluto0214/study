#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
//×óÐý×Ö·û´®
void reverse(char * left,char *right)
{
	char tmp = 0;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		right--;
		left++;
	}
}
void left_move(char * arr, int n)
{
	int k = strlen(arr);
	reverse(arr, arr + n - 1);
	reverse(arr + n , arr + k - 1);
	reverse(arr, arr + k - 1);
}
int main()
{
	char arr[] = "abcde";
	int n = 0;//×óÐý¼¸¸ö×Ö·û
	scanf("%d", &n);
	left_move(arr, n);
	printf("%s\n", arr);
	return 0;
}