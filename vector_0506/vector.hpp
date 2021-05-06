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
		//跟string一样 vector中的迭代器也是原生指针
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

		T& operator[](size_t pos)//注意返回值 返回pos这个位置的引用，这样既可以访问也可以修改
		{
			assert(pos < size());
			return _start[pos];//_start + pos也行
		}

		//重新声明迭代器，使迭代器区间[first,end)可以使任何容器的迭代器
		template <class InputIterator>
		vector(InputIterator first, InputIterator end)
		{
			while (first != end)
			{
				push_back(*first);
				first++;
			}
		}

		//构造函数
		//无参
		vector()
			:_begin(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}
		
		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage;
		}
		
		/*构造函数 有参
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

		//拷贝构造函数
		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			vector tmp = (v.begin(), v.end());
			swap(tmp);
		}

		//拷贝运算符重载
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
				//增容四步
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T)*size();
				delete[] _start;
				_start = tmp;

				_finish = _start + size();
				_endofstorage = _start + n;
			}
		}

		//resize
		void resize(size_t n, const T& val = T())//这个缺省值T()是去调用它的默认构造函数的临时对象
		{
			//resize有两种情况 一种是比size()小 另一种是比他大
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				//如果空间不够的话就增容
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
			//先检查空间够不够
			check_capacity();

			*_finish = x;
			++_finish;
		}

		//pop_back
		void pop_back()
		{
			//不能删超了
			assert(_finish > _start);
			--_finish;
		}

		//insert
		iterator insert(iterator pos, const T& x)
		{
			//注意pos的位置
			assert(pos >= _start && pos <= _finish);//等于的话就相当于是头插尾插

			////这种插入的都先看看空间够不够
			//check_capacity();
			
			//注意：如果要增容的话，一定会发生迭代器失效，pos失效了。
			//因为如果增容的话，新开了一块空间，然后把旧空间拷贝过去，_start _finish _endofstorage都拷过去了，但是pos并没有拷过去，还留在旧空间中
			//所以这里要用临时变量把pos保存一下
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
