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
	printf("\nֻ����һ�ε�����%d��\n", fun(arr, len));
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
	//��ָ�봦��
	if (str == NULL)
		return 0;

	//ֻ��һ�����ַ��Ĵ���(һ�����ַ�Ҳ�ǲ���ת���ģ�
	if (*str == '\0')
		return 0;

	//�հ��ַ��Ĵ���(�������������հ��ַ���
	while (isspace(*str))
	{
		str++;
	}

	//�����Ŵ���
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

	//�ж�*str�Ƿ��������ַ�
	long long ret = 0;
	while (isdigit(*str))//����������ַ��ͽ���
	{
		ret = ret * 10 + flag*(*str - '0');
		if (ret > INT_MAX || ret < INT_MIN)
		{
			ret = 0;
			return (int)ret;
		}
		str++;
	}
	//�����������ַ�ʱ����������
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