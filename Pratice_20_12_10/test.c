#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
	int fast = 0;
	int slow = 0;
	while (fast < numsSize)
	{
		if (nums[fast] != val)
		{
			nums[slow] = nums[fast];
			fast++;
			slow++;
		}
		else
		{
			fast++;
		}
	}
	return slow;
}