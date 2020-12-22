#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *p = head, *q = head;
	while (p) {
		if (n < 0) { q = q->next; }
		n--;
		p = p->next;
	}
	if (n == 0) { return head->next; }
	q->next = q->next->next;
	return head;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *cur = head;

	while (l1 && l2)
	{
		if (l1->val > l2->val)
		{
			cur->next = l2;
			l2 = l2->next;
		}
		else
		{
			cur->next = l1;
			l1 = l1->next;
		}
		cur = cur->next;
	}

	cur->next = l1 ? l1 : l2;
	return head->next;
}

struct ListNode* sortList(struct ListNode* head)
{
	if (!head || !head->next)
		return head;
	struct ListNode *slow = head, *fast = head, *pre = head;
	while (fast && fast->next)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = NULL;
	return mergeTwoLists(sortList(head), sortList(slow));//slow为原链表的中间节点
}