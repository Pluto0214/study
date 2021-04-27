#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
using namespace std;

#include "Stack.h"
#include "Queue.h"

void test_priority_queue()
{
	// 默认是大的优先级高
	priority_queue<int> pq;
	pq.push(1);
	pq.push(5);
	pq.push(3);
	pq.push(0);
	pq.push(6);
	pq.push(3);

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

int main()
{
	bit::test_stack();
	bit::test_queue();

	test_priority_queue();

	return 0;
}