#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	/* ���� */
	if (l1 == NULL || l2 == NULL) {
		return l1 != NULL ? l1 : l2;
	}

	/* ��ȡ�ϲ�֮���������ͷ�ڵ� */
	struct ListNode* mergeHead = l1->val > l2->val ? l2 : l1;
	/* ��¼���������нڵ�ֵ��С�Ľڵ㣬���ڱ������� */
	struct ListNode* cur1 = mergeHead == l1 ? l1 : l2;
	struct ListNode* cur2 = mergeHead == l1 ? l2 : l1;
	/* ��¼�ϴαȽ�ʱ�ڵ�ֵС�Ľڵ� */
	struct ListNode* pre = NULL;
	/* ��¼��ǰ�ڵ�ֵ��Ľڵ����һ�ڵ㣬��ֹ������Ͽ�֮���޷��ҵ�����Ľڵ� */
	struct ListNode* next = NULL;
	while (cur1 != NULL && cur2 != NULL) {
		if (cur1->val <= cur2->val) {
			pre = cur1;
			cur1 = cur1->next;
		}
		else {
			next = cur2->next;
			/* ����ǰ�ڵ�ֵ��С�Ľڵ����ӵ���һ�����нڵ�ֵ��Ľڵ� */
			pre->next = cur2;
			/* ����һ�����нڵ�ֵ��Ľڵ����ӵ���ǰ�ڵ�ֵ��С�Ľڵ����һ�ڵ� */
			cur2->next = cur1;
			pre = cur2;
			cur2 = next;
		}
	}
	/* �ϲ��� l1 �� l2 ���ֻ��һ����δ���ϲ��ֱ꣬�ӽ�����ĩβָ��δ�ϲ�������� */
	pre->next = cur1 == NULL ? cur2 : cur1;

	struct ListNode* deleteDuplicates(struct ListNode* head) {
		struct ListNode* slow = head;
		struct ListNode* fast = head;
		while (fast)
		{
			if (slow->val != fast->val)
			{
				slow = slow->next;
				slow = fast;
			}
			else
			{
				fast = fast->next;
			}
		}
		return head;
	}

	struct ListNode* cur = head;
	struct ListNode* next = head->next;
	while (next != NULL && cur != NULL) {
		if (next->val != cur->val) {
			cur = cur->next;
		}
		else {
			cur->next = next->next;
		}
		next = next->next;
	}

	return head;

	struct ListNode* deleteDuplicates(struct ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		struct ListNode* cur = head;
		struct ListNode* next = NULL;
		while (cur != NULL) {
			next = cur->next;
			while (next != NULL) {
				if (cur->val == next->val) {
					cur->next = next->next;
				}
				next = next->next;
			}
			cur = cur->next;
		}

		return head;
	}

	struct ListNode* deleteDuplicates(struct ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		struct ListNode* slow = head;
		struct ListNode* fast = head->next;
		while (fast && slow)
		{
			if (fast->val != slow->val)
			{
				slow = slow->next;
			}
			else
			{
				slow->next = fast->next;
			}
			fast = fast->next;
		}
		return head;
	}