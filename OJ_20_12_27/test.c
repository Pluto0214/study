#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	/* 特判 */
	if (l1 == NULL || l2 == NULL) {
		return l1 != NULL ? l1 : l2;
	}

	/* 获取合并之后新链表的头节点 */
	struct ListNode* mergeHead = l1->val > l2->val ? l2 : l1;
	/* 记录两个链表中节点值较小的节点，用于遍历链表 */
	struct ListNode* cur1 = mergeHead == l1 ? l1 : l2;
	struct ListNode* cur2 = mergeHead == l1 ? l2 : l1;
	/* 记录上次比较时节点值小的节点 */
	struct ListNode* pre = NULL;
	/* 记录当前节点值大的节点的下一节点，防止该链表断开之后无法找到后面的节点 */
	struct ListNode* next = NULL;
	while (cur1 != NULL && cur2 != NULL) {
		if (cur1->val <= cur2->val) {
			pre = cur1;
			cur1 = cur1->next;
		}
		else {
			next = cur2->next;
			/* 将当前节点值较小的节点连接到另一链表中节点值大的节点 */
			pre->next = cur2;
			/* 将另一链表中节点值大的节点连接到当前节点值较小的节点的下一节点 */
			cur2->next = cur1;
			pre = cur2;
			cur2 = next;
		}
	}
	/* 合并后 l1 和 l2 最多只有一个还未被合并完，直接将链表末尾指向未合并完的链表 */
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