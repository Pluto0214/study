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
	//ע�ⷵ��ֵ��bool
	bool insert(const K& key)
	{
		//�����Ϊ�յ����
		if (_root == nullptr)
		{
			_root = new Node(key);
			return bool;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		//�����ǿ���ʱ�����Ҫ����ı�Ŀǰ�Ľ��С���Ǿ�������壬���������ұ߲�
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
			//�����ȵĻ����ͷ���false������д�����������������֧�ֲ�����ͬ������
			else
			{
				return false;
			}
		}
		//�������ѭ���Ǿ�˵��curָ���˿գ�parent����Ҫ����Ľ��ĸ��ڵ�
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

	//����
	//ע��ҪǶ��һ�£����õ�ʱ����Ҫ���Σ�_root��˽�еģ����������ǲ����õģ����Բ���д��������Ҫ���εı���
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

	//���� 
	//����ҵ��˾ͷ��ؽ���ָ�룬���û�ҵ��Ļ��ͷ��ؿ�
	//findҲ�� �� �Ĺ��ܣ�Ŀǰд���������������ǲ��ܽ����޸ĵģ������޸ĵĻ������ṹ�����ˣ����Լ���const
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
				cout << "�ҵ���" << endl;
				return cur;
			}
		}
		return nullptr;
	}
	  
	
private:
	Node* _root;
};