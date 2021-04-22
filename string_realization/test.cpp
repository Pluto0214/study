#pragma once
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

namespace zwh
{
	class string
	{
	public:
		size_t size()
		{
			return _size;
		}

		//s1.swap(s2)
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//���캯��
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//��������
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//�������캯��
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
			//s1.swap(s2)  this->swap(tmp)
		}

		//��ֵ���������
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(tmp);
			}
			return *this;
		}

		//��һ�ֱ�����ʽ
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		//�ڶ��ֱ�����ʽ ������
		typedef char* iterator;
		typedef char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//const������
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		//reserve
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//��ס����Ҫ+1����\0Ҳ��һ��λ��
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}

		//resize
		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_str[_size] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; i++)
				{
					_str[_size] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}

		//erase
		string& erase(size_t pos, size_t len = npos)
		{
			if (pos == npos || pos + len>=_size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		//find
		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		//push_back
		void push_back(char ch)
		{
			//���жϿռ乻����������ռ䲻���Ļ���Ҫ���ռ�
			//push_back �� append����Ҫ���ռ䣬����ֱ��дһ������reserve
			if (_size == _capacity)
			{
				reserve(2 * _capacity);
			}
			_str[_size] = ch;
			_size++;
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

			//operator+=
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const string& s)
		{
			append(s._str);
			return *this;
		}

		//��̬���͵ı������������������������涨��
		static const size_t npos;

		private:
			char* _str;
			size_t _size;
			size_t _capacity; //�ܴ���ٸ���Ч�ַ��Ŀռ�
			};

		const size_t string::npos = -1;

		}

		//operator>
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
			if (i1 < s1.size())
			{
				return true;
			}
			else if (i2 < s2.size())
			{
				return false;
			}
			else
			{
				return false;
			}
		}

		//operator==
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
			if (i1 < s1.size())
			{
				return false;
			}
			else if (i2 < s2.size())
			{
				return false;
			}
			else
			{
				return true;
			}
		}