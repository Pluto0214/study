#pragma once
#include<assert.h>

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;//非必须，这个_parent就是为了记录回去的路径，如果没有这个，用栈进行记录也是可以的
	int _bf;//平衡因子 非必须
	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V> kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)//刚创建的时候平衡因子是0
		,_kv(kv)
	{}
};

template<class K, class V>
struct AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	
	//插入
	pair<Node*, bool>insert(const pair<K, V>& kv)
	{
		//如果这颗树为空
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}

		//开始找这个结点要插入的位置
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
			else//说明已经有了，返回这个结点的位置，返回插入失败
			{
				return make_pair(cur, false);
			}
		}
		//出了while循环，说明找到可以插入的位置了，接下来进行插入
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
		
		//接下来开始更新平衡因子
		Node* newnode = cur;//要在while循环之前把cur保存一下，最后return的是这个新插入的结点cur，而下面的while循环中cur一直在向上动

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
			
			//如果父亲的平衡因子是0，那就说明没有改变高度，不需要再向上更新了
			if (parent->_bf == 0)
			{
				break;
			}
			//如果等于1或者-1的话，那就说明高度被改变了，需要继续向上更新
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			//如果为+-2的话，那就说明这棵树已经不平衡了，需要通过旋转的方式来让它平衡
			else if (abs(parent->_bf) == 2)
			{
				//旋转
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
			break;//旋转完之后树就已经平衡了，所以要跳出循环
		}

		return make_pair(newnode, true);
	}

	//左左 右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = sub->right;
		
		parent->_left = subLR;
		if (subLR)//如果subLR存在的话
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
		//旋转完之后，更新一下parent和subL的平衡因子
		subL->_bf = parent->_bf = 0;
	}

	//右右 左单旋
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
		//旋转完之后更新平衡因子
		subR->_bf = parent->_bf = 0;
	}

	//左右 先左单旋再右单旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		
		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1) //说明subLR是右树插入
		{
			subL->_bf = -1;
			parent->_bf = subLR->_bf = 0;
		}
		else if (bf == -1)//说明subLR是左树插入
		{
			parent->_bf = 1;
			subL->_bf = subLR->_bf = 0;
		}
		else if(bf == 0) //说明subLR是新增结点
		{
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	//右左 先右旋再左旋
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
			cout << "平衡因子异常：" << root->_kv.first << endl;
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