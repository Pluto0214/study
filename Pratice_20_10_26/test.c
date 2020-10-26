#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//memmove的模拟实现
void * my_memmove(void * dest, const void * src, size_t count)
{
	assert(src);
	assert(dest);
	void* ret = dest;
	if (dest < src)
	{
		while (count--)
		{
			*(char *)dest = *(char *)src;
			dest = (char*)dest + 1;
			src = (char *)src + 1;
		}
	}
	else
	{
		while (count--)
		{
			*((char *)dest + count) = *((char *)src + count);
		}
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1 + 2, arr1, 16);
	return 0;
}


////memcpy的模拟实现
//void * my_memcpy(void * dest, const void * src, size_t count)
//{
//	void*ret = dest;
//	assert(dest);
//	assert(src);
//	while (count--)
//	{
//	   //一个字节一个字节的copy
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//		//另一种写法 ++(char*)dest;
//
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[20] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}

////strstr
//char* my_strstr(const char * str1, const char * str2)
//{
//	assert(str1);
//	assert(str2);
//	const char*s1 = str1;
//	const char*s2 = str2;
//	const char*cp = str1;
//	if (*s2 == '\0')
//	{
//		//没有一个定论要返回什么，所以自己设置
//		return (char*)str1;
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
//		cp++;
//		if (*s2 == '\0')
//		{
//			return (char*)cp;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char *str1 = "abcdef";
//	char *str2 = "cde";
//	char*ret = strstr(str1, str2);
//	printf("%s\n", ret);
//	return 0;
//}
