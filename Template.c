#include<iostream>
using namespace std;

//template<typename T>
template<class T>

T Add(const T& x, const T& y)
{
	return x + y;
}

//void Swap(int& x1, int& x2)
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}

//void Swap(T& x1, T& x2)
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}

void Swap(int& x1, int& x2)
{
	int x = x1;
	x1 = x2;
	x2 = x;
}

//int Add(const int& x, const int& y)
//{
//	return x + y;
//}
//
//double Add(const double x,const double y)
//{
//	return x + y;
//}


int main()
{
	int a = 1, b = 2;
	double c = 1.11, d = 2.22;
	Add(c, d);
	Add(a, (int)c);
	Add<int>(a, c);
	cout << Add(c, d) << endl;
	//Swap(a, b);
	
	/*Add(a, b);
	Add(c, d);
	cout << Add(a, b) << endl;
	cout << Add(c, d) << endl;*/

	//cout << a << "-" << b <<endl;
	system("pause");
	return 0;
}
