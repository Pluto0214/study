#define _CRT_SECURE_NO_WARNINGS 1

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* swapNodes(struct ListNode* head, int k) {
	if (head == NULL || k <= 0) {
		return head;
	}
	// �ҵ������ڵ�
	struct ListNode *front = head;
	while (--k > 0 && front != NULL) {
		front = front->next;
	}
	if (front == NULL) {
		return head;
	}
	// �ҵ������ڵ�
	struct ListNode *rear = head;
	struct ListNode *tmp = front;
	while (tmp->next != NULL) {
		rear = rear->next;
		tmp = tmp->next;
	}
	// �����ڵ�ֵ
	int val = front->val;
	front->val = rear->val;
	rear->val = val;
	return head;
}