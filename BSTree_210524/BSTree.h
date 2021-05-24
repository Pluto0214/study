#pragma once

template<class K>
struct BSTreeNode
{
private:
	k _key;
	struct BSTreeNode<k>* _left;
	struct BSTreeNode<k>* _right;

	BSTreeNode(const K& key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<k> Node;
public:
	//注意返回值是bool
	bool insert(const K& key)
	{
		//如果树为空的情况
		if (_root == nullptr)
		{
			_root = new Node(key);
			return bool;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		//当不是空树时，如果要插入的比目前的结点小，那就往左面插，如果大就往右边插
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			//如果相等的话，就返回false，现在写的这个二叉搜索树不支持插入相同的数据
			else
			{
				return false;
			}
		}
		//如果出了循环那就说明cur指向了空，parent就是要插入的结点的父节点
		Node* newnode = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = newnode;
		}
		else
		{
			parent->_left = newnode;
		}
	}

	//遍历
	//注意要嵌套一下，调用的时候不需要传参，_root是私有的，在类外面是不能用的，所以不能写出调用需要传参的遍历
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		InOrder(root->_left);
		cout << root->_key << " ";
		InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
	}

	//查找 
	//如果找到了就返回结点的指针，如果没找到的话就返回空
	//find也有 改 的功能，目前写的搜索树的数据是不能进行修改的，进行修改的话整个结构就乱了，所以加上const
	const Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->key < key)
			{
				cur = cur->_right;
			}
			else
			{
				cout << "找到了" << endl;
				return cur;
			}
		}
		return nullptr;
	}
	  
	
private:
	Node* _root;
};