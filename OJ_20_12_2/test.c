#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int* singleNumbers(int* nums, int numsSize, int* returnSize) {
	int mask = 0;
	int i;
	for (i = 0; i < numsSize; i++)
	{
		mask ^= nums[i];
	}
	mask = mask & (-1 * mask);
	int m1 = 0, m2 = 0;
	for (i = 0; i < numsSize; i++)
	{
		if ((nums[i] & mask) == 0)//位运算优先级低于关系运算
		{
			m1 ^= nums[i];
		}
		else
		{
			m2 ^= nums[i];
		}
	}
	*returnSize = 2;
	int *a = (int *)malloc(2 * sizeof(int));
	a[0] = m1;
	a[1] = m2;
	return a;
}
int missingNumber(int* nums, int numsSize) {
	int sum = 0;
	int i;
	for (i = 1; i < numsSize + 1; i++) 
	{
		sum += i - nums[i - 1];
	}
	return sum;
}

