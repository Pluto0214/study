#define _CRT_SECURE_NO_WARNINGS 1

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* curr = head;
	while (curr) {
		struct ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	struct ListNode* newHead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}