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
