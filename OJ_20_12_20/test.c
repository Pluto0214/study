#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//两个链表的第一个公共节点
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* cur1 = headA;
	struct ListNode* cur2 = headB;
	while (cur1 != cur2)
	{
		cur1 = cur1 == NULL ? headB : cur1->next;
		cur2 = cur2 == NULL ? headA : cur2->next;
	}
	return cur1;
}

struct ListNode* partition(struct ListNode* head, int x) {
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* bf_newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* af_newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* before = bf_newlist;
	struct ListNode* after = af_newlist;
	struct ListNode* cur = head;

	while (cur)
	{
		if (cur->val < x)
		{
			before->next = cur;
			before = before->next;
		}
		else
		{
			after->next = cur;
			after = after->next;
		}
		cur = cur->next;
	}
	after->next = NULL;
	//这块以及下面return部分要记得跳过第一个头结点
	before->next = af_newlist->next;


	return bf_newlist->next;
}