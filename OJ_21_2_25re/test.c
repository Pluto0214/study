#define _CRT_SECURE_NO_WARNINGS 1

public int removeElement(int[] nums, int val) {
	int i = 0;
	for (int j = 0; j < nums.length; j++) {
		if (nums[j] != val) {
			nums[i] = nums[j];
			i++;
		}
	}
	return i;
}

int searchInsert(int* nums, int numsSize, int target) {
	/* 使用二分查找来搜索target */
	int left = 0, right = numsSize - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (target > nums[mid]) {
			left = mid + 1;
		}
		else if (target < nums[mid]) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return left;
}