#pragma once

namespace bit
{
	// 设计模式 -- 适配器模式(配接器)
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front() const
		{
			return _con.front();
		}

		const T& back() const
		{
			return _con.back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_queue()
	{
		//queue<int, vector<int>> q1;  不支持
		queue<int, list<int>> q2;
		queue<int> q1;

		q1.push(1);
		q1.push(2);
		q1.push(3);
		q1.push(4);
		q1.pop();

		q2.push(1);
		q2.push(2);
		q2.push(3);
		q2.push(4);
	}
}
