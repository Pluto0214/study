#define _CRT_SECURE_NO_WARNINGS 1

/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL)
			return NULL;
		Node *newHead = new Node(head->val);
		Node *srcNode = head, *destNode = newHead;
		map<Node*, Node*> m;
		while (srcNode->next != NULL) {//先不考虑random的指向问题，先将链表复制下来解决好next指针问题
			destNode->next = new Node(srcNode->next->val);
			m.insert(pair<Node*, Node*>(srcNode, destNode));
			//srcNode->val=*(int*)(void*)destNode;//将srcNode的val保存为destNode的地址
			destNode = destNode->next;
			srcNode = srcNode->next;
		}
		m.insert(pair<Node*, Node*>(srcNode, destNode));
		//srcNode->val=*(int*)(void*)destNode;

		destNode = newHead;
		srcNode = head;
		while (srcNode != NULL) {
			if (srcNode->random == NULL)
				destNode->random = NULL;
			else {
				auto iter = m.find(srcNode->random);
				destNode->random = iter->second;
				//destNode->random=(Node*)(void*)&(srcNode->random->val);//将val变量转换为地址
			}
			destNode = destNode->next;
			srcNode = srcNode->next;
		}
		return newHead;
	}
};