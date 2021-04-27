#pragma once

namespace bit
{
	//template<class T>
	//class stack
	//{
	//private:
	//	T* _a;
	//	size_t _size;
	//	size_t _capacity;
	//};

	// 设计模式 -- 适配器模式(配接器)
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_stack()
	{
		stack<int, vector<int>> st1;
		stack<int, list<int>> st2;
		stack<int> st3;


		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);

		st2.push(1);
		st2.push(2);
		st2.push(3);
		st2.push(4);
	}
}