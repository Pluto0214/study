#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace zwh
{
	//�����
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

	//��������
	//�����õ�struct ��Ϊ��Ĭ����public list������Ҫ�õ�����ȥ�������ĳ�Ա���������public�Ļ��Ǿ͵�����Ԫ��
	//ע������Ƶĸ���
	template<class T,class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;
		node* _node;//���ָ��
		
		__list_iterator(node* node)
			:_node(node)
		{}
		//�������� ��ֵ���� ����������Щ������ʵ�֣���Ĭ�ϵľͿ����ˡ�

		//���������������Ҫ���иı�Ļ�����ü���const ����const���ܵ�����const��Ҳ�ܵ�
		bool operator!=(const self& s) cosnt
		{
			return _node != s._node;
		}

		bool operator==(const self& s) const
		{
			return !(*this != s);
		}

		//�Խ����ý�������
		//�����õĻ�ϣ���ǵõ���ǰ���λ�õ�����
		//���ﷵ����������Ϊ_node->data ���������򲻻���ʧ���÷������ü��ܶ�����д
		T& operator*()
		{
			return _node->_data;
		}
		

		//����ǰ�ú���++
		//++����ָ����һ��λ�ã�++֮����һ��������
		//ǰ��++
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		//����++
		//���ﴫ��intû��ʲô���壬ֻ��Ϊ�˸�ǰ��++��������
		self operatpr++(int)
		{
			//�������� ��tmp����һ��++֮ǰ��ֵ��Ȼ�󷵻أ����tmp�������������ʧ�ˣ��������ﲻ�����÷���
			self tmp(*this);
			_node = _node->next;
			return tmp;
		}

		self& operatpr--()
		{
			_node = _node->prev;
			return *this;
		}
		//����--
		self operatpr--(int)
		{
			self tmp(*this);
			_node = _node->prev;
			return tmp;
		}
		

	};

	//������
	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator <T, T&, T*> iterator;
		typedef __list_iterator <T, const T&, const T*> const_iterator;

		//��һ��˫��ѭ������ĵ������������Ǹ�ͼ��stl�е�list����ͷ���ģ�Ҫ��Ȼend���ø�ֵ
		iterator begin()
		{
			return _head->_next;
			//��ôд����ֵ�� ��ʽ���͵�ת��������ָ����ʽ����ת���ɵ�����
			//Ҳ����д������ return iterator(_head->next)�������ǹ�����������
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
			//Ҫ�������һ��˫���ͷѭ������
			_head = new node;
			_head->_prev = _head;
			_head->_next = _head;
		}

		//�������캯�� �ִ�д��
		//��д�ִ�д��֮ǰ��дһ����� �������Ҳ��һ�����캯��
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

		//��ֵ���������
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

			//��insertʵ��
			//insert(end(), x);
		}



		//insert ���ص����²����������
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

		//erase���ص���ɾ�����Ԫ�ص���һ��
		iterator erase(iterator pos)
		{
			//Ҫע���ǲ���ɾ��ͷ���� ����eraseһ�� end()����ͷ���(��һ�´�ͷ˫ѭ��������Ǹ�ͼ)
			assert(pos != end());

			//�ܵ�˼·�����ҵ�Ҫɾ�����λ�õ�ǰһ���ͺ�һ�� Ȼ��ǰ��һ��,�ɵ��м�Ľ��
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;
			
			return iterator(next);
		}

		//ͷ��
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		//βɾ
		void pop_back()
		{
			//end()�����ǵ����� ����--�Ϳ����ˡ�ע�������˳����end()ȥ����������Ȼ���ٵ�erase
			erase(--end());
		}
		
		//ͷɾ
		void pop_front
		{
			erase(begin());
		}


		//ע��clear���������������� clear�Ļ�����������ͷ���������������ݣ������������Ļ����ǵ�����������������Ѿ����ˣ���Ҫ�����������������ͷ���
        void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				//ע������Ҳ�е�����ʧЧ���⣬����Ҫ��erase�ķ���ֵ�ٸ�it
				it = erase(it);
			}
		}

		//����������Ҫ�Լ�д���� �������캯�� ����list��Ҫ�Լ�д
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//�������캯�� lt2(lt1)
		//��ͳд��
		list(const list<T>& lt)
		{
			//����ͷ�ڵ�ָ���Լ����ٱ���һ��lt������Ľ��һ��һ�����뵽lt2
			_head = new node;
			_head->_next = head;
			_head->_prev = head;

			//ע������lt��const���󣬵��õ�beginҲ��const�ģ�����Ӧ�ü���const
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