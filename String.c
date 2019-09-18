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

	string f("aa");
	cout << f.size() << endl;
	int index = f.find('c');
	cout << index << endl;
	/*string s;

	cout << s.size() << endl;
	cout << s.capacity() << endl;

	cout << s.size() << endl;
	cout << s.capacity() << endl;*/

	string s1("ABCD!EF");
	cout << s1.c_str() << endl;

	size_t a = s1.find('F', 0);
	cout << a << endl;

	size_t b = s1.rfind('A', s1.size());
	cout << b << endl;

	string s3("abc.com");
	size_t _s3 = s3.find('.', 0);
	
	string s4(s3.substr(_s3, s3.size() - _s3));
	string s5(s3.substr(3)); //取从三开始找，之后的字符串
	cout <<"---"<< s4<<"---"<<  endl;
	cout << "---" << s5 << "---" << endl;

	string url("http://www.abc.com");
	cout << url << endl;
	size_t start = url.find("://");  
	if (start == string::npos) //此处用来判断，是否找到了这个字符或者符号，找到了就不等于npos（-1）
	{
		cout << "invalid url" << endl;
		return;
	}

	size_t i = url.find("://", 0);  //find(" ",0)
	url.erase(0, i + strlen(";//"));

	cout << url << endl;


	
		/*string s;
		size_t sz = s.capacity();
		cout << "making s grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			s += 'c';
			if (sz != s.capacity())
			{
				sz = s.capacity();
				cout << "capacity changed: " << sz<<endl;
			}
		}

		string _s;
		size_t _sz = s.capacity();
		s.reserve(100);
		cout << "making s grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			s += 'c';
			if (_sz != s.capacity())
			{
				_sz = s.capacity();
				cout << "capacity changed: " << _sz << endl;
			}
		}*/




	//const string s2("abc!ef");
	//
	//cout << s1 << " " << s2 << endl;

	//cout << s1[0] << " " << s2[0] << endl;

	//s1[0] = '@';
	//cout << s1 << endl;

	//for (int i = 0; i < s1.size(); ++i)
	//{

	//	cout << s1[i] << endl;
	//}

	//s1.push_back('!');
	//s1.push_back('@');

	//cout << s1 << endl;

	////s1.append("### ##");
	////s1.append("%%%%%");
	//s1.append(s2);
	//s1.append(5, '.');

	//cout << s1 << endl;

	////s1.operator+=("***** *****");

	//cout << s1 << endl;

	//{
	//	char szTest[] = "\0abc";
	//	string s;
	//	s += szTest;
	//	printf("size is %u\n", s.size());
	//}
	////string和append的区别
	//{
	//	char szTest[] = "\0abc";
	//	string s;
	//	s.append(szTest, sizeof(szTest)-1);
	//	printf("size is %u\n", s.size());
	//}

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
class Solution {
public:
    int firstUniqChar(string s) {
        
        /*if(s.empty())
            return -1;
        
        int pos = 0;
        
        size_t _i = 0;
        
        
        
        for(size_t i = 0;i < s.size(); i++)
        {
            
            for(_i = i+1;i<s.size();i++)
            {
                if(s[i]==s[_i])
                {
                    pos++;
                    break;
                }
            }
            if(pos==0)
                return i;
            else
                pos = 0;
            
            
        }
        return -1;
    }*/
        
        
};


int main()
{
	//Test();
	/*string s("aaaaa");
	cout << s << endl;*/
	Test2();

	system("pause");
	return 0;
}

