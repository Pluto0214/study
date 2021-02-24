#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

char * toLowerCase(char * str) {
	char *p;
	p = str;
	for (; *p != '\0'; p++)
	{
		if ((int)*p < 91 && (int)*p > 64)
		{
			*p = (int)*p + 32;
		}
	}
	return str;
}


void rotate(int* nums, int numsSize, int k) {
	int newArr[numsSize];
	for (int i = 0; i < numsSize; ++i) {
		newArr[(i + k) % numsSize] = nums[i];
	}
	for (int i = 0; i < numsSize; ++i) {
		nums[i] = newArr[i];
	}
}
void rotate(int* nums, int numsSize, int k) {
	int i = 0;
	int j = 0;
	int tmp = 0;
	k %= numsSize;//ȷ����k����numsSizeʱ��ת�����ֵʱnumsSize
				  //����ǰ�벿��
	for (i = 0, j = numsSize - 1 - k; i < j; i++, j--)
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	//���ú�벿��
	for (i = numsSize - k, j = numsSize - 1; i < j; i++, j--)
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	//��������
	for (i = 0, j = numsSize - 1; i < j; i++, j--)
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}
