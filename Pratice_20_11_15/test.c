#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<limits.h>
#include<ctype.h>
//打开、关闭文件操作
int main()
{
	//打开文件
	FILE * pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;//随便返回一个数。
	}
	//写文件
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

//enum State
//{
//	VALID,
//    INVALID
//}; state = VALID;
//int my_atoi(const char * str)
//{
//	int flag = 0;
//	state = INVALID;
//	//空指针处理
//	if (str == NULL)
//		return 0;
//
//	//只有一个空字符的处理(一个空字符也是不能转换的）
//	if (*str == '\0')
//		return 0;
//
//	//空白字符的处理(不做处理，跳过空白字符）
//	while (isspace(*str))
//	{
//		str++;
//	}
//
//	//正负号处理
//	if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//
//	//判断*str是否是数字字符
//	long long ret = 0;
//	while (isdigit(*str))//如果是数字字符就进来
//	{
//		ret = ret * 10 + flag*(*str - '0');
//		if (ret > INT_MAX || ret < INT_MIN)
//		{
//			ret = 0;
//			return (int)ret;
//		}
//		str++;
//	}
//	//当不是数字字符时，跳到这里
//	if (*str == '\0')
//	{
//		state = VALID;
//		return (int)ret;
//	}
//	return (int)ret;
//}
//int main()
//{
//	char * p = "-123";
//	int ret = my_atoi(p);
//	printf("%d\n", ret);
//	return 0;
//}

//int my_atoi(const char * str)
//{
//	if (str == NULL)
//		return 0;
//
//	int ret = 0;
//	while (*str)
//	{
//		ret = ret * 10 + *str - '0';
//		str++;
//	}
//	return ret;
//}
//int main()
//{
//	char * p = "123";
//	int ret = my_atoi(p);
//	printf("%d\n", ret);
//	return 0;
//}