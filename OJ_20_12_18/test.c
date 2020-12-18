#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
	if (head == NULL || k == 0) {
		return NULL;
	}

	struct ListNode* pNode = head;
	for (int i = 0; i < k - 1; ++i) {
		if (pNode->next != NULL) {
			pNode = pNode->next;
		}
		else {
			return NULL;
		}
	}

	while (pNode->next != NULL) {
		pNode = pNode->next;
		head = head->next;
	}

	return head;
}

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

	return mergeHead;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL || l2 == NULL)
	{
		return l1 != NULL ? l1 : l2;
	}
	//合并之后新的头结点
	struct ListNode* new_head = l1->val > l2->val ? l2 : l1;

	struct ListNode* cur1 = l1->val > l2->val ? l2 : l1;
	struct ListNode* cur2 = l1->val > l2->val ? l1 : l2;
	//pre指向cur1前面的结点 
	struct ListNode* pre = cur1;
	while (cur1 && cur2)
	{
		if (cur2->val < cur1->val)
		{
			//next指向cur2后面的结点
			struct ListNode* next = cur2->next;
			cur2->next = cur1;
			pre->next = cur2;
			pre = cur2;
			cur2 = next;
		}
		else
		{
			pre = cur1;
			cur1 = cur1->next;
		}
	}
	//此时cur1和cur2中最多还有一个结点没有录到新链表中
	//将这个结点录入
	pre->next = cur1 == NULL ? cur2 : cur1;
	return new_head;
}

