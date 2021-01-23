#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//前序遍历
void PrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;

	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);

}

//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int size = 0;
//	//如果像这样 定义一个全局变量，那么每次递归+的size就不是同一个了，每次都是定义了一个新的size。
//	size++;
//	TreeSize(root->_left);
//	TreeSize(root->_right);
//	return size; 
//}

//void TreeSize(BTNode* root,int* psize)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		*psize++;
//	}
//	TreeSize(root->_left, psize);
//	TreeSize(root->_right, psize);
//}

//给了根结点求结点数
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + TreeSize(root->_left) + TreeSize(root->_right); 
	}
}

//给了根节点求叶子节点数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}


int main()
{
	return 0;
} 