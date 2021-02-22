#define _CRT_SECURE_NO_WARNINGS 1

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* reversePrint(struct ListNode* head, int* returnSize) {
	if (head == NULL) {
		*returnSize = 0;
		return NULL;
	}
	struct ListNode*p = head;
	int num = 0;
	while (p != NULL) {
		p = p->next;
		num++;
	}
	int *res = (int *)malloc(sizeof(int)*num);
	for (int i = 0; i<num; i++) {
		res[num - 1 - i] = head->val;
		head = head->next;
	}
	*returnSize = num;
	return res;
}