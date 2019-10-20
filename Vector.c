#include<iostream>
#include<string.h>
#include<assert.h>

using namespace std;

namespace cx
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;

		Vector()
			:_start(nullptr)
			, _end_of_storage(nullptr)
			, _finish(nullptr)
		{}

		/*Vector(const Vector<T>& vec)
		{

		}

		Vector<T>& operator=(Vector<T> vec)
		{

		}*/

		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		iterator start()
		{
			return _start;
		}

		iterator finish()
		{
			return _finish;
		}
		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			return _start[pos];
		}

		void resize(size_t n, const T& v = T())
		{
			if (n < size())
			{
				_finish = _start + n;
				return;
			}

			if (n>size())
			{
				reserve(n);
			}

			while (_finish != _start + n)
			{
				*_finish = v;
				_finish++;
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();  //保存n是因为，当_start改变后，size()也会改变，会导致_finish出错
				T* a = new T[n];
				if (_start)
				{
					memcpy(a, _start, sizeof(T)*n);

					delete[] _start;
				}

				_start = a;
				_finish = _start + sz;
				//_finsh = _start + size();
				_end_of_storage = _start + n;

				/*size_t sz = size();
				T* s = new[n];
				if (_start)
				{
				memcpy(s, _start, sizeof(T)*n);

				delete[] _start;
				}
				_start = s;
				_finish = _start + sz;
				_end_of_storage = _start + n;*/
			}
		}

		void push_back(const T& x)
		{
			if (_start == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			_finish++;
		}

		void pop_back()
		{
			assert(_start < _finish);
			--_finish;
		}

		void insert(iterator pos, const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t sz = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				//reserve(size() * 2);
				pos = sz + _start;
			}

			iterator end = _finish - 1;

			while (end != pos)
			{
				*(end + 1) = *end;
				end--;
			}

			*pos = x;
			_finish++;
		}

		void erase(iterator pos)
		{
			assert(pos < _finish&&pos >= _start);
			iterator index = pos + 1;
			while (index != _finish)
			{
				*index = *(index + 1);
				index++;
			}

			_finish--;
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void Test()
	{
		Vector<int> ve;

		ve.push_back(1);
		ve.push_back(2);

		//ve.pop_back();
		
		ve.insert(0, 0);
		for (size_t i = 0; i < ve.size(); i++)
		{
			cout << ve[i] << " ";
		}

		cout << endl;
	}

}


