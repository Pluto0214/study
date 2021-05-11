#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace zwh
{
	//结点类
	template<class T>
	struct __list_node
	{
		T _data;
		__list_node<T>* _next;
		__list_node<T>* _prev;

		__list_node(const T& x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	//迭代器类
	//这里用的struct 因为它默认是public list类中需要用迭代器去处理它的成员，如果不是public的话那就得用友元了
	//注意类设计的复用
	template<class T,class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;
		node* _node;//结点指针
		
		__list_iterator(node* node)
			:_node(node)
		{}
		//拷贝构造 赋值重载 析构函数这些都不用实现，用默认的就可以了。

		//像参数这块如果不需要进行改变的话那最好加上const 这样const的能调不是const的也能调
		bool operator!=(const self& s) cosnt
		{
			return _node != s._node;
		}

		bool operator==(const self& s) const
		{
			return !(*this != s);
		}

		//对解引用进行重载
		//解引用的话希望是得到当前这个位置的数据
		//这里返回引用是因为_node->data 出了作用域不会消失，用返回引用既能读还能写
		T& operator*()
		{
			return _node->_data;
		}
		

		//重载前置后置++
		//++是想指向下一个位置，++之后还是一个迭代器
		//前置++
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		//后置++
		//这里传的int没有什么意义，只是为了跟前置++进行区分
		self operatpr++(int)
		{
			//拷贝构造 让tmp保存一下++之前的值，然后返回，这个tmp除了作用域就消失了，所以这里不用引用返回
			self tmp(*this);
			_node = _node->next;
			return tmp;
		}

		self& operatpr--()
		{
			_node = _node->prev;
			return *this;
		}
		//后置--
		self operatpr--(int)
		{
			self tmp(*this);
			_node = _node->prev;
			return tmp;
		}
		

	};

	//链表类
	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator <T, T&, T*> iterator;
		typedef __list_iterator <T, const T&, const T*> const_iterator;

		//想一下双向循环链表的迭代器遍历的那个图。stl中的list是有头结点的，要不然end不好给值
		iterator begin()
		{
			return _head->_next;
			//这么写返回值是 隐式类型的转换，结点的指针隐式类型转换成迭代器
			//也可以写成这样 return iterator(_head->next)这样就是构造匿名对象
		}
		iterator end()
		{
			return _head;
		}
		const_iterator begin() const
		{
			return _head->next;
		}
		const_iterator end() const
		{
			return _head;
		}


		list()
		{
			//要构造的是一个双向带头循环链表
			_head = new node;
			_head->_prev = _head;
			_head->_next = _head;
		}

		//拷贝构造函数 现代写法
		//再写现代写法之前先写一个这个 下面这个也是一个构造函数
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
			swap(_head, tmp._head);
		}

		//赋值运算符重载
		list<T>& operator=(list<T> lt)
		{
			swap(_head, lt._head);
			return *this;
		}

		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* tail = newnode->_prev;
			tail->_next = newnode;
			head->_prev = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;

			//用insert实现
			//insert(end(), x);
		}



		//insert 返回的是新插入的这个结点
		iterator insert(iterator pos, const T& x)
		{
			iterator newnode = new node(x);
			iterator cur = pos._node;
			iterator prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		//erase返回的是删除最近元素的下一个
		iterator erase(iterator pos)
		{
			//要注意是不能删除头结点的 所以erase一下 end()就是头结点(想一下带头双循环链表的那个图)
			assert(pos != end());

			//总的思路就是找到要删除这个位置的前一个和后一个 然后前后一连,干掉中间的结点
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;
			
			return iterator(next);
		}

		//头插
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		//尾删
		void pop_back()
		{
			//end()调的是迭代器 所以--就可以了。注意这里的顺序，先end()去调迭代器，然后再调erase
			erase(--end());
		}
		
		//头删
		void pop_front
		{
			erase(begin());
		}


		//注意clear和析构函数的区别 clear的话是清楚点除了头结点以外的所有数据，而析构函数的话则是到了链表的生命周期已经到了，需要把整个都清掉，包括头结点
        void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				//注意这里也有迭代器失效问题，所以要把erase的返回值再给it
				it = erase(it);
			}
		}

		//迭代器不需要自己写析构 拷贝构造函数 但是list需要自己写
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//拷贝构造函数 lt2(lt1)
		//传统写法
		list(const list<T>& lt)
		{
			//先让头节点指向自己，再遍历一遍lt把里面的结点一个一个插入到lt2
			_head = new node;
			_head->_next = head;
			_head->_prev = head;

			//注意这里lt是const对象，调用的begin也是const的，所以应该加上const
			const_iterator it = lt.begin();
			while (it != lt.end())
			{
				push_back(*it);
				++it;
			}
		}

		
		
		
		
        

	private:
		node* _head;
		
	};

}