#pragma once 
#include<string.h>
#include<iostream>
#include<assert.h>

using namespace std;
namespace cx
{
	class my_string
	{
	public:
		typedef char* _iterator;
		
	public:
		my_string(const char* str = "")
		{
			if (nullptr == str)
			{
				assert(str);
				return;
			}

			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		my_string(const my_string& s)
			:_str(new char[s._capacity+1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}

		~my_string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		my_string& operator=(const my_string& s)
		{
			if (this != &s)
			{
				char* s_str = new char[s._capacity + 1];
				strcpy(s_str, s._str);

				delete[] _str;

				_str = s_str;
				_size = s._size;
				_capacity = s._capacity;

			}
			return *this;
		}

		_iterator begin()
		{
			return _str;
		}

		_iterator end()
		{
			return _str + _size;
		}

		void my_push_back(char c)
		{
			if (_size == _capacity)
			{
				Creat(_capacity*2);
			}

			/**(_str + _size) = c;
			_size++;*/

			_str[_size++] = c;
			_str[_size] = '\0';

		}

		void my_append(size_t n,char c)
		{
			for (size_t i = 0; i<n; i++)
				my_push_back(c);
		}

		my_string& operator+=(char c)
		{
			my_push_back(c);
			return *this;
		}

		void my_append(const char* str)//追加字符串
		{
			for (size_t i = 0; i < strlen(str); i++)
				my_push_back(str[i]);
		}
my_string& operator+=(const char* str)
		{
			for (size_t i = 0; i < strlen(str); i++)
				my_push_back(str[i]);

			return *this;
		}


		void clear_init() //清空数据
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void Swap(my_string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		const char* my_c_str()const
		{
			return _str;
		}

		size_t my_size()const
		{
			return _size;
		}

		size_t my_capacity()const
		{
			return _capacity;
		}

		bool my_empty()
		{
			return _size == 0;
		}

		void my_resize(size_t newsize, char c = char())
		{
			if (newsize > _size) 
			{
				if (newsize > _capacity)
					Creat(newsize);

				memset(_str, c, newsize-_size);
			}

			_size = newsize;
			_str[newsize] = '\0';
		}

		char& operator[](size_t index)
		{
			
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			
			return _str[index];
		}

		bool operator<(const my_string& s)
		{
			/*int i = 0;

			while (i<_size && i<s._size)
			{
				if (_str[i] < s._str[i])
					return true;
				else if (_str[i] > s._str[i])
					return false;

				i++;
			}

			if (_size<s._size)
				return true;
			else
				return false;*/
			return !strcmp(_str, s._str);
		}
		bool operator<=(const my_string& s)
		{
			return !(*this > s);
		}
		bool operator>(const my_string& s)
		{
			return strcmp(_str, s._str) == 1;
		}
		bool operator>=(const my_string& s)
		{
			return !(*this < s);
		}
		bool operator==(const my_string& s)
		{
			if (_size != s._size)
				return false;

			return strcmp(_str, s._str) ? false : true;
		}
		bool operator!=(const my_string& s)
		{
			return !(*this == s);
		}
		

		void Creat(size_t newcapacity)//扩容
		{
			if (newcapacity > _capacity)
			{
				char* s = new char[newcapacity + 1];
				strcpy(s, _str);

				delete[] _str;
				_str = s;
				_capacity = newcapacity;
			}
		}

		// 返回c在string中第一次出现的位置
		
		size_t Find(char c, size_t pos = 0) 
		{
			size_t i = 0;
			while (_str[i])
			{
				if (_str[i] == c)
					return i;
				i++;
			}
			return -1;
		}

		size_t Find(char c, size_t pos = 0) const
		{
			size_t i = 0;
			while (_str[i])
			{
				if (_str[i] == c)
					return i;
				i++;
			}
			return -1;
		}

		size_t Find(const char* s, size_t pos = 0) const
		{
			size_t begin = 0;
			size_t len = strlen(s);
			size_t end = _size - len - 1;
			size_t flag = 0;

			if (_size < len)
				return -1;

			while (begin <= end)
			{
				size_t i = 0;
				size_t f = Find(s[0], begin);

				pos = f;//防止flag++之后，所返回的位置不正确。

				while (i < len)
				{
					if (_str[pos] == s[i])
					{
						i++;
						pos++;
					}

					else
					{
						flag++;
						break;
					}
					if (flag == 0)
						return f;
					begin += flag;
				}
			}


		}
		my_string SubStr(size_t pos, size_t n)
		{
			char* s = new char[n + 1];
			size_t i = 0;
			while (pos<_size && n)
			{
				s[i] = _str[pos];
				i++;
				pos++;
				n--;
			}
			s[i] = '\0';
			_str = s;

			return *this;
		}
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		my_string& Insert(size_t pos, char c)
		{

			assert(pos <= _size);

			Creat(_size + 1);
			size_t end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}

			_str[pos] = c;
			_size++;
			return *this;

		}
		my_string& Insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			Creat(len+_size);

			size_t end = _size;
			while (end >= pos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			size_t i = 0;
			size_t _len = len;//注意，len会在循环中发生变化，所以在_size+=len的时候得小心出现错误
			while (len--)
			{
				_str[pos] = str[i];
				i++;
				pos++;
			}
			_size += _len;//_capacity在CREAT函数中变化，_size发生变化

			return *this;
		}
		// 删除pos位置上的元素，并返回该元素的下一个位置
		my_string& Erase(size_t pos, size_t len)
		{
			/*assert(pos <= _size&&len<_size-pos);

			size_t _len = len;
			while (len--)
			{
				_str[pos] = _str[pos + _len];
				pos++;
			}*/

			assert(pos <= _size);

			size_t start = pos + len;
			size_t end = _size;

			while (start <= end)
			{
				_str[pos++] = _str[start++];//直接从后往前进行覆盖，然后对_size进行改变
			}
			_size -= len;
			return *this;
		}
		
	private:
		friend ostream& operator<<(ostream& _cout, const cx::my_string& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};

}
ostream& cx::operator<<(ostream& _cout, const cx::my_string& s) {
	cout << s._str;
	return _cout;
}

void test1()
{
	cx::my_string s1;
	cx::my_string s2("abcde");
	cx::my_string s3(s2);


	s2.my_push_back('f');
	s2.my_push_back('g');
	s2.my_append(3, 'i');

	s2 += 'j';

	/*auto it = s2.begin();

	while (it != s2.end())
	{
		cout << *it++;
	}
	cout << endl;*/

	s1 = s3;

	cout << s1 << endl;
	cout << s2 << endl;

	s1.Swap(s2);
	cout << s1 << endl;
	cout << s2 << endl;

	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
}


void test2()
{
	cx::my_string s1("hello");
	cx::my_string s2("hello");

	//cout << s1.Find("hell") << endl;
	//cout << s1.SubStr(0, 2) << endl;
	s1.Insert(1, "abc");
	s1.Erase(1, 3);
	cout << s1;
	/*if (s1 == s2)
	{
		cout << 123 << endl;
	}*/

	
	/*cout << s1.my_size() << endl;
	cout << s1.my_capacity() << endl;
	cout << s1 << endl;

	s1.my_resize(10, 'a');
	cout << s1.my_size() << endl;
	cout << s1.my_capacity() << endl;
	cout << s1 << endl;*/

}



