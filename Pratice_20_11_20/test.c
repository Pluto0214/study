#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
////ststr的模拟实现
//char * my_strstr(const char * str1, const char * str2)
//{
//	assert(str1);
//	assert(str2);
//	const char * cp = str1;
//	const char * s1 = str1;
//	const char * s2 = str2;
//	if (*s2 == '\0')
//	{
//		return (char *)s1;
//	}
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char *)cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char * str1 = "abcde";
//	char * str2 = "cde";
//	char * ret = my_strstr(str1, str2);
//	printf("%s\n", ret);
//	return 0;
//}