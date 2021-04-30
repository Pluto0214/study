#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

namespace bit
{
	template<class T>
	struct __list_node
	{
		T _data;
		__list_node<T>* _next;
		__list_node<T>* _prev;

		__list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	// <T, T&, T*> iterator
	// <T, const T&, const T*> const_iterator
	// 类设计的复用
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;
		node* _node;

		__list_iterator(node* node)
			:_node(node)
		{}

		// 拷贝构造 赋值重载 析构都不用实现，默认就可以

		bool operator!=(const self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const self& s) const
		{
			return !(*this != s);
		}

		Ptr operator->() const
		{
			return &_node->_data;
		}

		Ref operator*() const
		{
			return _node->_data;
		}

		// it++  it.operator(&it, 0)
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// ++it it.operator(&it)
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;


		iterator begin()
		{
			//return _head->_next;
			return iterator(_head->_next);
			//iterator it(_head->_next);
			//return it;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
			//return iterator(_head->_next);
			//iterator it(_head->_next);
			//return it;
		}

		const_iterator end() const
		{
			return _head;
		}

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& lt)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			list<T> tmp(lt.begin(), lt.end());
			std::swap(_head, tmp._head);
		}

		//lt1 = lt2
		list<T>& operator=(list<T> lt)
		{
			std::swap(_head, lt._head);
			return *this;
		}

		// lt2(lt1)
		/*list(const list<T>& lt)
		{
		_head = new node;
		_head->_next = _head;
		_head->_prev = _head;

		const_iterator it = lt.begin();
		while (it != lt.end())
		{
		push_back(*it);
		++it;
		}
		}*/

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				//it = erase(it);
				erase(it++);
			}
		}

		void push_back(const T& x)
		{
			//node* newnode = new node(x);
			//node* tail = _head->_prev;
			//// _head  ...  tail  newnode
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& x)
		{
			node* newnode = new node(x);
			node* cur = pos._node;
			node* prev = cur->_prev;

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			node* cur = pos._node;
			node* prev = cur->_prev;
			node* next = cur->_next;

			prev->_next = cur;
			cur->_prev = prev;

			delete cur;

			return iterator(next);
		}

	private:
		// 双向带头循环
		node* _head;
	};
}