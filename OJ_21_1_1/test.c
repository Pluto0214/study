#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct hashTable {
	struct ListNode* key;
	UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(struct ListNode* ikey) {
	struct hashTable* tmp;
	HASH_FIND_PTR(hashtable, &ikey, tmp);
	return tmp;
}

void insert(struct ListNode* ikey) {
	struct hashTable* tmp = malloc(sizeof(struct hashTable));
	tmp->key = ikey;
	HASH_ADD_PTR(hashtable, key, tmp);
}

struct ListNode* detectCycle(struct ListNode* head) {
	hashtable = NULL;
	while (head != NULL) {
		if (find(head) != NULL) {
			return head;
		}
		insert(head);
		head = head->next;
	}
	return false;
}

struct ListNode* detectCycle(struct ListNode* head) {
	struct ListNode *slow = head, *fast = head;
	while (fast != NULL) {
		slow = slow->next;
		if (fast->next == NULL) {
			return NULL;
		}
		fast = fast->next->next;
		if (fast == slow) {
			struct ListNode* ptr = head;
			while (ptr != slow) {
				ptr = ptr->next;
				slow = slow->next;
			}
			return ptr;
		}
	}
	return NULL;
}