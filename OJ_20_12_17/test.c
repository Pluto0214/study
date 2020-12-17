#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode* removeElements(struct ListNode* head, int val) {
	while (head != NULL && head->val == val) {
		head = head->next;
	}

	struct ListNode* cur = head;  //  当前节点
	struct ListNode* pre = head;  //  保存删除节点的前一节点
	while (cur != NULL) {
		if (cur->val == val) {
			pre->next = cur->next;
		}
		else {
			pre = cur;
		}
		cur = cur->next;
	}

	return head;
}

struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* old_head = head;
	struct ListNode* new_head = NULL;
	struct ListNode* tmp = NULL;
	while (old_head)
	{
		tmp = old_head->next;
		old_head->next = new_head;
		new_head = old_head;
		old_head = tmp;
	}
	head = new_head;
	return head;
}


struct ListNode* middleNode(struct ListNode* head) {
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while ((fast) && (fast->next))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

void deleteNode(struct ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}

bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head->next;
	while (fast != slow)
	{
		if (fast == NULL || fast->next == NULL)
		{
			return false;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}

bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}