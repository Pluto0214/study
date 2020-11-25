#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<limits.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
int fun(int* p, int len) 
{
	int m;
	int count = 0;
	for (int i = 0; i < len; ++i) 
	{
		for (int j = 0; j < len; ++j) 
		{
			if (j == i) 
			{
				continue;
			}
			for (m = 0; m < 32; ++m) 
			{
				if (((p[i] >> m) & 1) ^ ((p[j] >> m) & 1)) 
				{
					break;
				}
			}
			if (m == 32) 
			{
				break;
			}
			if (j == len - 1) 
			{
				++count;
				printf("%d\t", p[i]);
			}
		}
	}
	return count;
}
int main() 
{
	int arr[] = { 1,2,3,4,1,9,11,2,3,4,5,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; ++i) 
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	printf("\n只出现一次的数有%d个\n", fun(arr, len));
}

enum State
{
	VALID,
	INVALID
}; state = VALID;
int my_atoi(const char * str)
{
	int flag = 0;
	state = INVALID;
	//空指针处理
	if (str == NULL)
		return 0;

	//只有一个空字符的处理(一个空字符也是不能转换的）
	if (*str == '\0')
		return 0;

	//空白字符的处理(不做处理，跳过空白字符）
	while (isspace(*str))
	{
		str++;
	}

	//正负号处理
	if (*str == '+')
	{
		flag = 1;
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}

	//判断*str是否是数字字符
	long long ret = 0;
	while (isdigit(*str))//如果是数字字符就进来
	{
		ret = ret * 10 + flag*(*str - '0');
		if (ret > INT_MAX || ret < INT_MIN)
		{
			ret = 0;
			return (int)ret;
		}
		str++;
	}
	//当不是数字字符时，跳到这里
	if (*str == '\0')
	{
		state = VALID;
		return (int)ret;
	}
	return (int)ret;
}
int main()
{
	char * p = "-123";
	int ret = my_atoi(p);
	printf("%d\n", ret);
	return 0;
}