#pragma once
#include<iostream>
#include<assert.h>
using namespace std;


//vector的模拟实现
namespace zwh
{
	template<class T>
	class vector
	{
		typedef T* iterator;
		typedef T* const_iterator const;
	public:
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		//operator[]
		T& operator[](size_t pos)
		{
			//这里返回pos这个数据的引用，既可以读到pos这个位置的值，还能对这个值进行修改
			assert(pos < size());
			return _start[pos]
		}

		//构造函数
		vector()
			:_start(nullptr)
			,_end(nullptr)
			,_endofstorage(nullptr)
		{}

		//析构函数
		~vector()
		{
			delete[]_start;
			_start = _end = _endofstorage = nullptr;
		}

		void capacity()
		{
			return _endofstorage - _start;
		}

		void size()
		{
			return _finish - _start;
		}

		

		//reserve
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				//记住这里要把原来的size()保存起来,要不然后面就delete了
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T)*size());
				delete[]_start;
				_start = tmp;

				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		//检查空间够不够
		void check_capacity(x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : (capacity() * 2);
				reserve(newcapacity);
			}
		}

		//push_back
		void push_back(const T& x)
		{
			check_capacity();

			*_finish = x;
			++_finish
		}
		
		//pop_back
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}

		//resize
		void resize(size_t n, const T& val = T())
		//这个T()是调用它的默认构造函数的匿名对象
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
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

		//运算符重载
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			//this->swap(v);
			return *this;
		}

	private:
		iterator _strart;
		iterator _finish;
		iterator _endofstorage;
	};
}