#define _CRT_SECURE_NO_WARNINGS 1

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
	if (nums == NULL || numsSize == 0) {
		*returnSize = 0;//传参检查
		return NULL;
	}
	int size = ((numsSize - k + 1) > 0) ? (numsSize - k + 1) : 1;
	//如果窗口长度 k 大于 numsSize ，则无需滑动
	int first = (size > 1) ? (k - 1) : (numsSize - 1);
	int max = Max(nums, 0, first);//取第一个窗口的最大值
	int *res = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size - 1; ++i) {
		res[i] = max;//赋值
		if (nums[i] < max) {//如果最大值是在滑动区间内，只需比较移动的那一位与原先的最大值
			max = (nums[k] > max) ? nums[k] : max;
		}
		else {//否则最大值不在滑动区间内，需要重新计算滑动区间内的最大值
			max = Max(nums, i + 1, k);
		}
		++k;//向右滑动窗口一步
	}
	res[size - 1] = max;//补上最后一段
	*returnSize = size;
	return res;
}

int Max(int *arr, int left, int right) {//寻找区间内最大值
	int max = arr[left];
	for (; left <= right; ++left) {
		max = (arr[left] > max) ? arr[left] : max;
	}
	return max;
}