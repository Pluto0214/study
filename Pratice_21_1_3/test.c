#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reorderList(struct ListNode* head) {
	if (head == NULL) {
		return;
	}
	struct ListNode* vec[40001];
	struct ListNode* node = head;
	int n = 0;
	while (node != NULL) {
		vec[n++] = node;
		node = node->next;
	}
	int i = 0, j = n - 1;
	while (i < j) {
		vec[i]->next = vec[j];
		i++;
		if (i == j) {
			break;
		}
		vec[j]->next = vec[i];
		j--;
	}
	vec[i]->next = NULL;
}

struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* curr = head;
	while (curr != NULL) {
		struct ListNode* nextTemp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextTemp;
	}
	return prev;
}

void mergeList(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* l1_tmp;
	struct ListNode* l2_tmp;
	while (l1 != NULL && l2 != NULL) {
		l1_tmp = l1->next;
		l2_tmp = l2->next;

		l1->next = l2;
		l1 = l1_tmp;

		l2->next = l1;
		l2 = l2_tmp;
	}
}

void reorderList(struct ListNode* head) {
	if (head == NULL) {
		return;
	}
	struct ListNode* mid = middleNode(head);
	struct ListNode* l1 = head;
	struct ListNode* l2 = mid->next;
	mid->next = NULL;
	l2 = reverseList(l2);
	mergeList(l1, l2);
}
