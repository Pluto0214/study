#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//ǰ�����
void PrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

//�������
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;

	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

//�������
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
//	//��������� ����һ��ȫ�ֱ�������ôÿ�εݹ�+��size�Ͳ���ͬһ���ˣ�ÿ�ζ��Ƕ�����һ���µ�size��
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

//���˸����������
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

//���˸��ڵ���Ҷ�ӽڵ���
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}


//��������ĵ�K��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

//����������ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;

	BTNode* node = BinaryTreeFind(root->_left, x);
	if (node)//�ҵ��˾��ǲ�Ϊ�� û�ҵ����ǿ�
		return node;//����ҵ��˾Ͳ�������ȥ����
	//���û�ҵ���������������
	node = BinaryTreeFind(root->_right, x);
	if (node)
		return node;

	//������Ҷ�û�ҵ� �Ǿ�return NULL
	return NULL;
}


//����һ����
void DestoreTree(BTNode* root)
{
	//����ú������٣�����Ļ���Ҫ�ȱ��棬��Ȼ�Ļ����Ҳ�������������
	if (root == NULL)
	{
		return NULL;
	}

	DestoreTree(root->_left);
	DestoreTree(root->_right);
	free(root);
}

//�������Ĳ������
//�Ͳ��÷���  �ݹ��� ���õ��Ƕ��У��Ƚ��ȳ���



//�ж�һ�ö������Ƿ�Ϊ��ȫ������
int BinaryTreeComplete(BTNode* root)
{

}



int main()
{
	return 0;
} 