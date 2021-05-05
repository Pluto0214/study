#pragma once
#include<iostream>
#include <assert.h>
using namespace std;

namespace zwh
{
	class string
	{
	public:
		//构造函数
		//注意这里
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}

		//下面size和capacity两个接口 都加一个const 这样const和非const都可以调（权限可以缩小，但不能放大）
		//size
		size_t size() const
		{
			return _size;
		}
		//capacity
		size_t capacity() const
		{
			return _capacity;
		}

		//实现两种遍历方式 operator[]和迭代器
		//operator[]
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		//const operator[]
		//相当于上面的函数重载
		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		//迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			//注意迭代器end（）是返回最后一个位置的下一个位置
			//最后一个位置是_size-1 ，所以最后一个位置的下一个位置就是_size
			return _str + _size;
		}
		//const迭代器
		typedef const char* const_iterator;
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		

		//swap 用于拷贝构造函数和赋值运算符重载
		//s1.swap(s2)
		void swap(string& s)
		{
			//注意这里用的swap是std里面的swap 所以加一个std::防止跟正在写的这个swap冲突
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//拷贝构造函数 
		string(const string& s)
			:_str(nullptr)
			,_capacity(0)
			,_size(0)
		{
			string tmp(s._str);
			swap(tmp);
			//this->swap(tmp) this->通常不写，可以省略
		}

		//赋值运算符重载
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		
		//reserve
		void reserve(size_t n)
		{
			//增容四部曲
			//1.先开一块大小为n的空间
			//2.把旧空间的数据拷贝到新空间
			//3.把旧空间释放
			//4.指向新空间
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		//push_back
		void push_back(const char& ch)
		{
			//先判断空间够不够，不够的话用reserve增容
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity = 0 ? 8 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;//size-1是最后一个位置 size是最后一个位置的下一个位置
			++_size;
			//记得要在最后一个位置的下一个位置加上\0
			_str[_size] = '\0';
		}

		//append
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		//+=
		string& operator+=(const char& ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string& operator+=(const string& s)
		{
			append(s._str);
			return *this;
		}

		//resize
		void resize(size_t n, char ch = '\0')
		{
			//注意resize的时候要在最后一个有效字符的下一个位置加上\0;
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[n] = '\0';
			}
		}

		//insert
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);//pos可以等于_size 相当于尾插
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity = 0 ? 8 : (_capacity * 2);
				reserve(newcapacity);
			}
			size_t end = _size+1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
		}
		void insert(size_t pos, char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
		}

		//erase  从pos位置开始删除 删除len个字符
		//注意文档中len的缺省值是npos 可以看作是无穷大 
		//静态类型的变量在类中声明 在类外面定义
		static const size_t npos;
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			//第一种情况 全删完了
			if (len == npos || (pos + len) >= _size)
			{
				_str[pos] = '\0';//注意_str[pos]是pos的下一个位置
				_size = pos;
			}
			//第二种情况 删了一部分
			else
			{
				//直接把后面的值往前拷贝
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}	
		}

		//find
		size_t find(char ch, size_t pos)
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					//找到了
					return i;
				}
			}
			//没找到
			return npos;
		}
		size_t find(char* sub, size_t pos)
		{
			char* ret = strstr(_str + pos, sub);
			//没找到
			if (ret == nullptr)
			{
				return npos;
			}
			//找到了，返回ret的位置
			else
			{
				//两个指针相减就能得到ret的位置了
				return ret - _str;
			}

		}
		

	private:
		char* _str;
		size_t _size;//目前有多少个有效字符
		size_t _capacity;//总共能存多少个有效字符
	};

	//定义npos
	const size_t string::npos = -1;

	bool operator>(const string& s1, const string& s2)
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < s1.size() && i2 < s2.size())
		{
			if (s1[i1] > s2[i2])
			{
				return true;
			}
			else if (s1[i1] < s2[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}
		//如果i1还没走完 那就说明它的字母多 所以它大
		if (i1 < s1.size())
		{
			return true;
		}
		//与上面同理
		else if (i2 < s2.size())
		{
			return false;
		}
		//相等
		else
		{
			return false;
		}
	}

	bool operator==(const string& s1, const string& s2)
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < s1.size() && i2 < s2.size())
		{
			if (s1[i1] > s2[i2])
			{
				return false;
			}
			else if (s1[i1] < s2[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}
		if (i1 == s1.size() && i2 == s2.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}