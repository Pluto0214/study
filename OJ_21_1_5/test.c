#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode* oddEvenList(struct ListNode* head) {
	if (head == NULL) {
		return head;
	}
	struct ListNode* evenHead = head->next;
	struct ListNode* odd = head;
	struct ListNode* even = evenHead;
	while (even != NULL && even->next != NULL) {
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;
}


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
	if (m == n)
		return head;

	struct ListNode *prev = NULL, *next = NULL, *p = head;
	// left is the m point left point, right is the m point
	// left->next should be the n point, right->next should be the n->next point
	struct ListNode *left = NULL, *right = NULL;
	int count = 1;
	while (p != NULL && count <= n)
	{
		next = p->next;

		if (count == m)
		{
			left = prev;
			right = p;
		}

		if (count >= m)
			p->next = prev;

		if (count == n)
		{
			if (left != NULL)
				left->next = p;
			right->next = next;

			// if reverse from the original head, the new head should locate on the n point
			// otherwise the head should be the original head
			if (m == 1)
				head = p;
		}

		prev = p;
		p = next;
		count++;
	}
	return head;
}