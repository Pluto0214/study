#include<iostream>
#include<assert.h>
using namespace std;
#pragma once

namespace zwh
{
	template<class T>
	class vector
	{
	public:
		//��stringһ�� vector�еĵ�����Ҳ��ԭ��ָ��
		typedef T* iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		typedef T* const_iterator;
		const_iterator begin() const
		{
			return _begin;
		}
		const_iterator end() const
		{
			return _finish;
		}

		T& operator[](size_t pos)//ע�ⷵ��ֵ ����pos���λ�õ����ã������ȿ��Է���Ҳ�����޸�
		{
			assert(pos < size());
			return _start[pos];//_start + posҲ��
		}

		//����������������ʹ����������[first,end)����ʹ�κ������ĵ�����
		template <class InputIterator>
		vector(InputIterator first, InputIterator end)
		{
			while (first != end)
			{
				push_back(*first);
				first++;
			}
		}

		//���캯��
		//�޲�
		vector()
			:_begin(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}
		
		//��������
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage;
		}
		
		/*���캯�� �в�
		vector(int n, const T& value = T())
			:_begin(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}*/

		//swap
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		//�������캯��
		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			vector tmp = (v.begin(), v.end());
			swap(tmp);
		}

		//�������������
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		

		//capacity
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		//size
		size_t size()
		{
			return _finish - _start;
		}

		//reserve
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//�����Ĳ�
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T)*size();
				delete[] _start;
				_start = tmp;

				_finish = _start + size();
				_endofstorage = _start + n;
			}
		}

		//resize
		void resize(size_t n, const T& val = T())//���ȱʡֵT()��ȥ��������Ĭ�Ϲ��캯������ʱ����
		{
			//resize��������� һ���Ǳ�size()С ��һ���Ǳ�����
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				//����ռ䲻���Ļ�������
				if (n > _capacity)
				{
					reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		

		//check_capacity
		void check_capacity()
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() = 0 ? 8 : (2 * capacity());
				reserve(newcapacity);
			}
		}

		//push_back
		void push_back(const T& x)
		{
			//�ȼ��ռ乻����
			check_capacity();

			*_finish = x;
			++_finish;
		}

		//pop_back
		void pop_back()
		{
			//����ɾ����
			assert(_finish > _start);
			--_finish;
		}

		//insert
		iterator insert(iterator pos, const T& x)
		{
			//ע��pos��λ��
			assert(pos >= _start && pos <= _finish);//���ڵĻ����൱����ͷ��β��

			////���ֲ���Ķ��ȿ����ռ乻����
			//check_capacity();
			
			//ע�⣺���Ҫ���ݵĻ���һ���ᷢ��������ʧЧ��posʧЧ�ˡ�
			//��Ϊ������ݵĻ����¿���һ��ռ䣬Ȼ��Ѿɿռ俽����ȥ��_start _finish _endofstorage������ȥ�ˣ�����pos��û�п���ȥ�������ھɿռ���
			//��������Ҫ����ʱ������pos����һ��
			iterator posi = pos - _start;
			check_capacity();
			pos = _start + posi;

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;

			return pos;
		}

		//erase
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*it = *it + 1;
				++it;
			}
			--_finish;

			return pos;
		}

	private:
		iterator _begin;
		iterator _finish;
		iterator _endofstorage;
		
	};
}
