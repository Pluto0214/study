#pragma once
#include<iostream>
#include <assert.h>
using namespace std;

namespace zwh
{
	class string
	{
	public:
		//���캯��
		//ע������
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
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}

		//����size��capacity�����ӿ� ����һ��const ����const�ͷ�const�����Ե���Ȩ�޿�����С�������ܷŴ�
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

		//ʵ�����ֱ�����ʽ operator[]�͵�����
		//operator[]
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		//const operator[]
		//�൱������ĺ�������
		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		//������
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			//ע�������end�����Ƿ������һ��λ�õ���һ��λ��
			//���һ��λ����_size-1 ���������һ��λ�õ���һ��λ�þ���_size
			return _str + _size;
		}
		//const������
		typedef const char* const_iterator;
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		

		//swap ���ڿ������캯���͸�ֵ���������
		//s1.swap(s2)
		void swap(string& s)
		{
			//ע�������õ�swap��std�����swap ���Լ�һ��std::��ֹ������д�����swap��ͻ
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//�������캯�� 
		string(const string& s)
			:_str(nullptr)
			,_capacity(0)
			,_size(0)
		{
			string tmp(s._str);
			swap(tmp);
			//this->swap(tmp) this->ͨ����д������ʡ��
		}

		//��ֵ���������
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		
		//reserve
		void reserve(size_t n)
		{
			//�����Ĳ���
			//1.�ȿ�һ���СΪn�Ŀռ�
			//2.�Ѿɿռ�����ݿ������¿ռ�
			//3.�Ѿɿռ��ͷ�
			//4.ָ���¿ռ�
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		//push_back
		void push_back(const char& ch)
		{
			//���жϿռ乻�����������Ļ���reserve����
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity = 0 ? 8 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;//size-1�����һ��λ�� size�����һ��λ�õ���һ��λ��
			++_size;
			//�ǵ�Ҫ�����һ��λ�õ���һ��λ�ü���\0
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
			//ע��resize��ʱ��Ҫ�����һ����Ч�ַ�����һ��λ�ü���\0;
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
			assert(pos <= _size);//pos���Ե���_size �൱��β��
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

		//erase  ��posλ�ÿ�ʼɾ�� ɾ��len���ַ�
		//ע���ĵ���len��ȱʡֵ��npos ���Կ���������� 
		//��̬���͵ı������������� �������涨��
		static const size_t npos;
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			//��һ����� ȫɾ����
			if (len == npos || (pos + len) >= _size)
			{
				_str[pos] = '\0';//ע��_str[pos]��pos����һ��λ��
				_size = pos;
			}
			//�ڶ������ ɾ��һ����
			else
			{
				//ֱ�ӰѺ����ֵ��ǰ����
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
					//�ҵ���
					return i;
				}
			}
			//û�ҵ�
			return npos;
		}
		size_t find(char* sub, size_t pos)
		{
			char* ret = strstr(_str + pos, sub);
			//û�ҵ�
			if (ret == nullptr)
			{
				return npos;
			}
			//�ҵ��ˣ�����ret��λ��
			else
			{
				//����ָ��������ܵõ�ret��λ����
				return ret - _str;
			}

		}
		

	private:
		char* _str;
		size_t _size;//Ŀǰ�ж��ٸ���Ч�ַ�
		size_t _capacity;//�ܹ��ܴ���ٸ���Ч�ַ�
	};

	//����npos
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
		//���i1��û���� �Ǿ�˵��������ĸ�� ��������
		if (i1 < s1.size())
		{
			return true;
		}
		//������ͬ��
		else if (i2 < s2.size())
		{
			return false;
		}
		//���
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