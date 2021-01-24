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


//求二叉树的第K层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

//二叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;

	BTNode* node = BinaryTreeFind(root->_left, x);
	if (node)//找到了就是不为空 没找到就是空
		return node;//如果找到了就不到右面去找了
	//如果没找到，就再来右面找
	node = BinaryTreeFind(root->_right, x);
	if (node)
		return node;

	//如果左右都没找到 那就return NULL
	return NULL;
}


//销毁一颗树
void DestoreTree(BTNode* root)
{
	//最好用后序销毁，否则的话就要先保存，不然的话就找不到他的子树了
	if (root == NULL)
	{
		return NULL;
	}

	DestoreTree(root->_left);
	DestoreTree(root->_right);
	free(root);
}

//二叉树的层序遍历
//就不用分治  递归了 ，用的是队列（先进先出）



//判断一棵二叉树是否为完全二叉树
int BinaryTreeComplete(BTNode* root)
{

}



int main()
{
	return 0;
} 