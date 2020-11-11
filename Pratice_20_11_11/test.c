#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//memcpy
void * my_memcpy(void  * dest, const void * src, size_t count)
{
	assert(dest);
	assert(src);
	void * ret = dest;
	while (count--)
	{
		*(char *)dest = *(char *)src;
		dest = (char *)dest + 1;
		src = (char *)src + 1;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, 5);
	return 0;
}


//strstr 
//char * my_strstr(const char*str1, const char *str2)
//{
//	assert(str1);
//	assert(str2);
//	const char * s1 = str1;
//	const char * cp = str1;
//	const char *s2 = str2;
//	if (*s2 == '\0')
//	{
//		return (char *)str1;
//	}
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
//	char *str1 = "abcdef";
//	char *str2 = "cde";
//	char *ret = my_strstr(str1, str2);
//	printf("%s\n", ret);
//	return 0;
//}
