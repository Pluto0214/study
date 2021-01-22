#define _CRT_SECURE_NO_WARNINGS 1

inline int partition(int* a, int l, int r) {
	int x = a[r], i = l - 1;
	for (int j = l; j < r; ++j) {
		if (a[j] <= x) {
			int t = a[++i];
			a[i] = a[j], a[j] = t;
		}
	}
	int t = a[i + 1];
	a[i + 1] = a[r], a[r] = t;
	return i + 1;
}

inline int randomPartition(int* a, int l, int r) {
	int i = rand() % (r - l + 1) + l;
	int t = a[i];
	a[i] = a[r], a[r] = t;
	return partition(a, l, r);
}

int quickSelect(int* a, int l, int r, int index) {
	int q = randomPartition(a, l, r);
	if (q == index) {
		return a[q];
	}
	else {
		return q < index ? quickSelect(a, q + 1, r, index)
			: quickSelect(a, l, q - 1, index);
	}
}

int findKthLargest(int* nums, int numsSize, int k) {
	srand(time(0));
	return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}

void maxHeapify(int* a, int i, int heapSize) {
	int l = i * 2 + 1, r = i * 2 + 2, largest = i;
	if (l < heapSize && a[l] > a[largest]) {
		largest = l;
	}
	if (r < heapSize && a[r] > a[largest]) {
		largest = r;
	}
	if (largest != i) {
		int t = a[i];
		a[i] = a[largest], a[largest] = t;
		maxHeapify(a, largest, heapSize);
	}
}

void buildMaxHeap(int* a, int heapSize) {
	for (int i = heapSize / 2; i >= 0; --i) {
		maxHeapify(a, i, heapSize);
	}
}

int findKthLargest(int* nums, int numsSize, int k) {
	int heapSize = numsSize;
	buildMaxHeap(nums, heapSize);
	for (int i = numsSize - 1; i >= numsSize - k + 1; --i) {
		int t = nums[0];
		nums[0] = nums[i], nums[i] = t;
		--heapSize;
		maxHeapify(nums, 0, heapSize);
	}
	return nums[0];
}