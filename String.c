#include<iostream>
#include<string>
using namespace std;

void Test()
{
	string s1;
	string s2("hello");
	string s3(10, 'a'); 
	string s4(s2); 
	string s5(s3, 5); 
}

void Test2()
{
	string s;

	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	/*string s("ABCDEFG");
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << endl;

	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << endl;

	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.resize(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;*/

}



int main()
{
	//Test();
	/*string s("aaaaa");
	cout << s << endl;*/
	Test2();

	system("pause");
	return 0;
}

