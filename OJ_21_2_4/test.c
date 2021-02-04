#define _CRT_SECURE_NO_WARNINGS 1

int singleNumber(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++) {
		int  j = 0;
		for (j = 0; j < numsSize; j++) {
			if (i != j && nums[i] == nums[j]) break;
		}
		if (j == numsSize) return nums[i];
	}
	return 0;
}


int singleNumber(int* nums, int numsSize) {
	int min = INT_MAX, max = INT_MIN;
	for (int i = 0; i < numsSize; i++) {
		min = fmin(min, nums[i]);
		max = fmax(max, nums[i]);
	}
	int len = max - min + 1; // 会溢出的情况
	int *hashtable = malloc(sizeof(int) * len);
	memset(hashtable, 0, sizeof(int) * len);
	for (int i = 0; i < numsSize; i++) {
		hashtable[nums[i] - min]++;
	}
	for (int i = 0; i < numsSize; i++) {
		if (hashtable[nums[i] - min] == 1) return nums[i];
	}
	return 0;
}

typedef struct Node {
	int key;
	int cnt;
	struct Node * next;
} HashNode;

int hash(int key, int numsSize)
{
	return key & (numsSize - 1);
}

int singleNumber(int* nums, int numsSize) {
	HashNode * hashtable = malloc(sizeof(HashNode) * numsSize);
	memset(hashtable, 0, sizeof(HashNode) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		HashNode * head = &hashtable[hash(nums[i], numsSize)];
		HashNode * tail = head->next;
		int flag = 1;
		while (tail) {
			if (tail->key == nums[i]) {
				flag = 0;
				tail->cnt++;
				break;
			}
			tail = tail->next;
		}
		if (flag) { // 说明节点不存在，头插法创建新的节点
			HashNode * q = malloc(sizeof(HashNode));
			q->key = nums[i];
			q->cnt = 1;
			q->next = head->next;
			head->next = q;
		}
	}

	for (int i = 0; i <numsSize; i++) {
		HashNode * head = &hashtable[hash(nums[i], numsSize)];
		HashNode * tail = head->next;
		while (tail) {
			if (tail->key == nums[i]) {
				if (tail->cnt == 1) return tail->key;
			}
			tail = tail->next;
		}
	}
	return nums[0];
}

int singleNumber(int* nums, int numsSize) {
	int ans = 0;
	for (int i = 0; i < numsSize; i++) {
		ans ^= nums[i];
	}
	return ans;
}