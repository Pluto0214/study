#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct {
	int *data;
	int cnt, size;
} KthLargest;

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}


KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
	KthLargest *q = (KthLargest *)malloc(sizeof(KthLargest));
	q->data = (int *)malloc(sizeof(int) * (k + 1));
	q->cnt = 0;
	q->size = k;
	for (int i = 0; i < numsSize; i++) {
		kthLargestAdd(q, nums[i]);
	}
	return q;
}

int kthLargestAdd(KthLargest* obj, int val) {
	if (obj == NULL) return 0;
	if (obj->cnt == obj->size) {
		if (val <= obj->data[1]) return obj->data[1];
		obj->data[1] = val;
		int ind = 1;
		while ((ind << 1) <= obj->cnt) {
			int temp = ind, l = ind << 1, r = ind << 1 | 1;
			if (obj->data[l] < obj->data[temp]) temp = l;
			if (r <= obj->cnt && obj->data[r] < obj->data[temp]) temp = r;
			if (temp == ind) break;
			swap(obj->data[ind], obj->data[temp]);
			ind = temp;
		}
		return obj->data[1];
	}//return 0;
	obj->cnt += 1;
	obj->data[obj->cnt] = val;
	int ind = obj->cnt;
	while (ind >> 1 && obj->data[ind] < obj->data[ind >> 1]) {
		swap(obj->data[ind], obj->data[ind >> 1]);
		ind >>= 1;
	}
	return obj->data[1];
}

void kthLargestFree(KthLargest* obj) {
	free(obj->data);
	free(obj);
	return;
}

/**
* Your KthLargest struct will be instantiated and called as such:
* KthLargest* obj = kthLargestCreate(k, nums, numsSize);
* int param_1 = kthLargestAdd(obj, val);

* kthLargestFree(obj);
*/

