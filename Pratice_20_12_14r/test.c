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

	return mergeHead;
}



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	/* ���� */
	if (l1 == NULL || l2 == NULL) {
		return l1 != NULL ? l1 : l2;
	}

	struct ListNode* mergeHead = NULL;
	if (l1->val < l2->val) {
		/* ��ȡ�ϲ�֮��������ͷ�ڵ� */
		mergeHead = l1;
		/* ���ϲ�֮�������ҽ���������ͷ�ڵ�֮�� */
		mergeHead->next = mergeTwoLists(l1->next, l2);
	}
	else {
		mergeHead = l2;
		mergeHead->next = mergeTwoLists(l1, l2->next);
	}

	return mergeHead;
}