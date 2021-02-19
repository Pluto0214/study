#define _CRT_SECURE_NO_WARNINGS 1

struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize) {
	struct ListNode** res = malloc(k*sizeof(struct ListNode*));
	short length = 0, i, left, counter;
	struct ListNode* traverse = root, *tmp;
	while (traverse != 0) {
		length++;
		traverse = traverse->next;
	}
	traverse = root;
	left = length%k;
	length = length / k;
	for (i = 0; i<k; i++) {
		counter = length + (left>0) - 1;
		res[i] = traverse;
		while (counter&&traverse) {
			traverse = traverse->next;
			counter--;
		}
		if (traverse) {
			tmp = traverse->next;
			traverse->next = 0;
		}
		else tmp = 0;
		traverse = tmp;
		left--;
	}
	*returnSize = k;
	return res;
}