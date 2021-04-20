#include<iostream>
#include<string>
using namespace std;

int main()
{
	/*string s0;
	string s1("hello world");
	string s2(s1);
	cout << s0 << endl;
	cout << s1 << endl;
	cout << s2 << endl;*/

	/*s1.push_back('!');
	cout << s1 << endl;
    cout << s1.size() << endl;*/

	/*s1.resize(20,'!');
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;*/

	/*s1.reserve(50);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;*/

	/*s1 += '!';
	cout << s1 << endl;*/
	//int num = 0;
	//string::iterator it = s1.begin();
	//while (it != s1.end())
	//{
	//	num *= 10;
	//	num += *it - '0';
	//	it++;
	//}
	/*string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find('://');
	start += 3;
	size_t finish = url.find('/',start);
	string address = url.substr(start, finish - start);
	cout << address << endl;*/


	//size_t start = url.find("://");
	///*if (start == string::npos)
	//{
	//	cout << "invalid url" << endl;
	//	return;
	//}*/
	//start += 3;
	//size_t finish = url.find('/', start);
	//string address = url.substr(start, finish - start);
	//cout << address << endl;

	string s1("123456");
	int nums = 0;
	for (int i = 0; i < s1.size(); ++i)
	{
		nums = nums * 10 + (s1[i] - '0');
	}
	cout << s1 << endl;
	cout << nums << endl;
	return 0;
}