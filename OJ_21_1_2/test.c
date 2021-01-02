#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode* merge(struct ListNode* head1, struct ListNode* head2) {
	struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
	dummyHead->val = 0;
	struct ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
	while (temp1 != NULL && temp2 != NULL) {
		if (temp1->val <= temp2->val) {
			temp->next = temp1;
			temp1 = temp1->next;
		}
		else {
			temp->next = temp2;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	if (temp1 != NULL) {
		temp->next = temp1;
	}
	else if (temp2 != NULL) {
		temp->next = temp2;
	}
	return dummyHead->next;
}

struct ListNode* toSortList(struct ListNode* head, struct ListNode* tail) {
	if (head == NULL) {
		return head;
	}
	if (head->next == tail) {
		head->next = NULL;
		return head;
	}
	struct ListNode *slow = head, *fast = head;
	while (fast != tail) {
		slow = slow->next;
		fast = fast->next;
		if (fast != tail) {
			fast = fast->next;
		}
	}
	struct ListNode* mid = slow;
	return merge(toSortList(head, mid), toSortList(mid, tail));
}

struct ListNode* sortList(struct ListNode* head) {
	return toSortList(head, NULL);
}

struct ListNode* merge(struct ListNode* head1, struct ListNode* head2) {
	struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
	dummyHead->val = 0;
	struct ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
	while (temp1 != NULL && temp2 != NULL) {
		if (temp1->val <= temp2->val) {
			temp->next = temp1;
			temp1 = temp1->next;
		}
		else {
			temp->next = temp2;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	if (temp1 != NULL) {
		temp->next = temp1;
	}
	else if (temp2 != NULL) {
		temp->next = temp2;
	}
	return dummyHead->next;
}

struct ListNode* sortList(struct ListNode* head) {
	if (head == NULL) {
		return head;
	}
	int length = 0;
	struct ListNode* node = head;
	while (node != NULL) {
		length++;
		node = node->next;
	}
	struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
	dummyHead->next = head;
	for (int subLength = 1; subLength < length; subLength <<= 1) {
		struct ListNode *prev = dummyHead, *curr = dummyHead->next;
		while (curr != NULL) {
			struct ListNode* head1 = curr;
			for (int i = 1; i < subLength && curr->next != NULL; i++) {
				curr = curr->next;
			}
			struct ListNode* head2 = curr->next;
			curr->next = NULL;
			curr = head2;
			for (int i = 1; i < subLength && curr != NULL && curr->next != NULL;
			i++) {
				curr = curr->next;
			}
			struct ListNode* next = NULL;
			if (curr != NULL) {
				next = curr->next;
				curr->next = NULL;
			}
			struct ListNode* merged = merge(head1, head2);
			prev->next = merged;
			while (prev->next != NULL) {
				prev = prev->next;
			}
			curr = next;
		}
	}
	return dummyHead->next;
}