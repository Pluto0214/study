#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<limits.h>
#include<ctype.h>
//�򿪡��ر��ļ�����
int main()
{
	//���ļ�
	FILE * pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;//��㷵��һ������
	}
	//д�ļ�
	//�ر��ļ�
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
//	//��ָ�봦��
//	if (str == NULL)
//		return 0;
//
//	//ֻ��һ�����ַ��Ĵ���(һ�����ַ�Ҳ�ǲ���ת���ģ�
//	if (*str == '\0')
//		return 0;
//
//	//�հ��ַ��Ĵ���(�������������հ��ַ���
//	while (isspace(*str))
//	{
//		str++;
//	}
//
//	//�����Ŵ���
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
//	//�ж�*str�Ƿ��������ַ�
//	long long ret = 0;
//	while (isdigit(*str))//����������ַ��ͽ���
//	{
//		ret = ret * 10 + flag*(*str - '0');
//		if (ret > INT_MAX || ret < INT_MIN)
//		{
//			ret = 0;
//			return (int)ret;
//		}
//		str++;
//	}
//	//�����������ַ�ʱ����������
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