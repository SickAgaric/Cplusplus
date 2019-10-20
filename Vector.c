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


