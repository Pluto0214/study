#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
//malloc和free
//int main()
//{
//	int * ptr = NULL;
//	ptr = (int *)malloc(10);
//	if (ptr != NULL)
//	{
//		;
//	}
//	free(ptr);
//	ptr = NULL;
//return 0;
//}

//常见的动态内存错误
void test()
{
	int *p = (int *)malloc(100);
	if (p != NULL)
	{
		*p = 20;
	}
}
int main()
{
	test();
	while (1);
}
//void test()
//{
//	int * p = (int *)malloc(100);
//	free(p);
//	free(p);
//}
//void test()
//{
//	int * p = (int *)malloc(100);
//	p++;
//	free(p);
//}
//void test()
//{
//	int a = 10;
//	int * p = &a;
//	free(p);
//}
//void test()
//{
//	int i = 0;
//	int * p = (int *)malloc(10 * sizeof(int));
//	if (p != NULL)
//	{
//		for (i = 0; i <= 10; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//}
//void test()
//{
//	int * p = (int *)malloc(INT_MAX / 4);
//	*p = 20;
//	free(p);
//}


//memmove
//void * my_memmove(void * dest, const void * src, size_t num)
//{
//	assert(dest);
//	assert(src);
//	void * ret = dest;
//	if (dest < src)
//	{
//		while (num--)
//		{
//			*(char *)dest = *(char *)src;
//			dest = (char *)dest + 1;
//			src = (char *)src + 1;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*((char *)dest + num) = *((char *)src + num);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1 + 2, arr1, 16);
//	return 0;
//}


//memcpy
//void * my_memcpy(void * dest, const void * src, size_t count)
//{
//	assert(dest);
//	assert(src);
//	void * ret = dest;
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char *)dest + 1;
//		src = (char *)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[20] = { 0 };
//	my_memcpy(arr2, arr1,sizeof(arr1));
//	return 0;
//}

//char * my_strstr(const char * s1, const char * s2)
//{
//	const char * cp = s1;
//	while (*cp)
//	{
//		s1 = cp;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		cp++;
//		if (*s2 == '\0')
//		{
//			return (char *)cp;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "bcd";
//	char * ret = my_strstr(arr1, arr2);
//	printf("%s\n", ret);
//	return 0;
//}
