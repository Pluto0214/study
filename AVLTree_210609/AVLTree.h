#pragma once
#include<assert.h>

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;//�Ǳ��룬���_parent����Ϊ�˼�¼��ȥ��·�������û���������ջ���м�¼Ҳ�ǿ��Ե�
	int _bf;//ƽ������ �Ǳ���
	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V> kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)//�մ�����ʱ��ƽ��������0
		,_kv(kv)
	{}
};

template<class K, class V>
struct AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	
	//����
	pair<Node*, bool>insert(const pair<K, V>& kv)
	{
		//��������Ϊ��
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}

		//��ʼ��������Ҫ�����λ��
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->kv.first > kv.first)
			{
				parent = cur;
				cur = cur->left;
			}
			else//˵���Ѿ����ˣ������������λ�ã����ز���ʧ��
			{
				return make_pair(cur, false);
			}
		}
		//����whileѭ����˵���ҵ����Բ����λ���ˣ����������в���
		cur = new Node(kv);
		if (parent->kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		
		//��������ʼ����ƽ������
		Node* newnode = cur;//Ҫ��whileѭ��֮ǰ��cur����һ�£����return��������²���Ľ��cur���������whileѭ����curһֱ�����϶�

		while (parent)
		{
			if (parent->_right == cur)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}
			
			//������׵�ƽ��������0���Ǿ�˵��û�иı�߶ȣ�����Ҫ�����ϸ�����
			if (parent->_bf == 0)
			{
				break;
			}
			//�������1����-1�Ļ����Ǿ�˵���߶ȱ��ı��ˣ���Ҫ�������ϸ���
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			//���Ϊ+-2�Ļ����Ǿ�˵��������Ѿ���ƽ���ˣ���Ҫͨ����ת�ķ�ʽ������ƽ��
			else if (abs(parent->_bf) == 2)
			{
				//��ת
				if (parent->_bf == -2)
				{
					if (cur->_bf = -1)
					{
						RotateR(parent);
					}
					else//cur->_bf == 1
					{
						RotateLR(parent);
					}
				}
				else
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else
					{
						RoatateRL(parent);
					}
				}
			}
			else
			{
				assert(false);
			}
			break;//��ת��֮�������Ѿ�ƽ���ˣ�����Ҫ����ѭ��
		}

		return make_pair(newnode, true);
	}

	//���� �ҵ���
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = sub->right;
		
		parent->_left = subLR;
		if (subLR)//���subLR���ڵĻ�
		{
			subLR->_parent = parent;
		}
		Node* parentParent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent -> _left = subL;
				subL->_parent = parentParent;
			}
			else
			{
				parentParent->_right = subL;
				subL->_parent = parentParent;
			}
		}
		//��ת��֮�󣬸���һ��parent��subL��ƽ������
		subL->_bf = parent->_bf = 0;
	}

	//���� ����
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		
		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
		//��ת��֮�����ƽ������
		subR->_bf = parent->_bf = 0;
	}

	//���� ���������ҵ���
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		
		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1) //˵��subLR����������
		{
			subL->_bf = -1;
			parent->_bf = subLR->_bf = 0;
		}
		else if (bf == -1)//˵��subLR����������
		{
			parent->_bf = 1;
			subL->_bf = subLR->_bf = 0;
		}
		else if(bf == 0) //˵��subLR���������
		{
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	//���� ������������
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);
		
		if (bf == -1)
		{
			subR->_bf = 1;
			parent->_bf = subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	int Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return max(Height(root->left), Height(root->right)) + 1;
	}

	bool _isBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		int LeftHeight = Height(root->_left);
		int RightHeight = Height(root->_right);
		
		if (rightHeight - leftHeight != root->_bf)
		{
			cout << "ƽ�������쳣��" << root->_kv.first << endl;
		}

		return abs(leftHeight - rightHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	bool isBalance()
	{
		return _isBalance(_root);
	}
private:
	Node* _root ;
};