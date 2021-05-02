#include<iostream>
#include<string>
using namespace std;

int main()
{
	//string s1("hello world");
	//s1.push_back('!');
	//cout << s1 << endl;

	//s1.append("abcd");
	//cout << s1 << endl;

	//s1 += '!';//push_back
	//s1 += "abcd";//append
	//cout << s1 << endl;



	
	/*cout << s1.size() << endl;
	cout << s1.capacity() << endl;*/
	


	/*for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << endl;
	}
	
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << endl;
		++it;
	}*/
	
	/*for (auto& i : s1)
	{
		cout << i << endl;
	}*/

	/*string s("string.cpp");
	size_t pos = s.rfind('.');*/

	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return 0;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;
	/*size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return 0;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;*/
	return 0;
}