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

	return mergeHead;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL || l2 == NULL)
	{
		return l1 != NULL ? l1 : l2;
	}
	//�ϲ�֮���µ�ͷ���
	struct ListNode* new_head = l1->val > l2->val ? l2 : l1;

	struct ListNode* cur1 = l1->val > l2->val ? l2 : l1;
	struct ListNode* cur2 = l1->val > l2->val ? l1 : l2;
	//preָ��cur1ǰ��Ľ�� 
	struct ListNode* pre = cur1;
	while (cur1 && cur2)
	{
		if (cur2->val < cur1->val)
		{
			//nextָ��cur2����Ľ��
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
	//��ʱcur1��cur2����໹��һ�����û��¼����������
	//��������¼��
	pre->next = cur1 == NULL ? cur2 : cur1;
	return new_head;
}

