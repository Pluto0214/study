#define _CRT_SECURE_NO_WARNINGS 1

struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode dummyHead;
	dummyHead.next = head;
	struct ListNode* temp = &dummyHead;
	while (temp->next != NULL && temp->next->next != NULL) {
		struct ListNode* node1 = temp->next;
		struct ListNode* node2 = temp->next->next;
		temp->next = node2;
		node1->next = node2->next;
		node2->next = node1;
		temp = node1;
	}
	return dummyHead.next;
}

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	struct ListNode* newHead = head->next;
	head->next = swapPairs(newHead->next);
	newHead->next = head;
	return newHead;
}