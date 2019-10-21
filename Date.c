#pragma once 
#include<iostream>
using namespace std;

class  Date
{
public:
	int GetDay(int year, int month)
	{
		static int _Day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2
			&& (year % 4 == 0 && year % 100 != 0
			|| year % 400 == 0))
			return 29;


		else
			return _Day[month];
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year >= 1900
			&& month > 0 && month < 13
			&& day > 0 && day <= GetDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}

		else
		{
			cout << "输入错误\n" << endl;
		}

	}

	Date(const Date& date)
		:_year(date._year)
		, _month(date._month)
		, _day(date._day)
	{}

	/*~Date()
	{
		cout << "调用一次析构" << endl;
	}*/

	Date& operator=(const Date& date)
	{
		if (this != &date)
		{
			_year = date._year;
			_month = date._month;
			_day = date._day;
		}

		return *this;
	}

	bool operator>(const Date& d)  //m
	{
		if (_year > d._year || (_year == d._year && _month > d._month) || (_year==d._year&&_month==d._month&&_day>d._day))
			return true;
		else
			return false;
	}
	bool operator<(const Date& d)
	{
		return !(*this>d);
	}
	bool operator==(const Date& d)
	{
		/*if (_year == d._year&&_month == d.month&&_day == d.day)
			return true;
		else
			return false;*/
		return _year == d._year && _month == d._month&&_day == d._day;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}
	bool operator<=(const Date& d)
	{
		return !(*this>d);
	}

	Date operator+(int day)
	{
		while (day)
		{
			if (_day + day > GetDay(_year, _month))
			{
				day -= (GetDay(_year, _month) - _day);
				_day = 0;

				_month++;
				if (_month > 12)
				{
					_month = 1;
					_year--;
				}
			}
			else
			{
				_day += day;
				day = 0;
			}

		}
		return *this;
	}
	Date operator-(int day)
	{
		while (day)
		{
			if (_day < day)
			{
				day -= _day; //错误
				--_month;
				if (_month < 1)
				{
					_month = 12;
					_year--;
				}
				_day = GetDay(_year, _month);

			}
			else
			{
				_day -= day;
				day = 0;
			}
		}
		return *this;
	}
	
	

	Date operator++()
	{
		int day = GetDay(_year, _month);
		if (++_day >= day)
		{
			_month++;
			_day = 1;
			if (_month > 12)
				_year++;
		}
		return *this;
	}
	Date operator++(int)
	{
		Date tmp(*this);
		++(*this);
		return tmp;
	}

	Date operator--()
	{
		if (_day == 1)
		{
			_month--;
			if (_month < 1)
				_year--;
		}
		_day = GetDay(_year, _month);

		return *this;
	}
	Date operator--(int)
	{
		Date tmp(*this);
		--(*this);
		return tmp;
	}

	int operator-(const Date&d)//与1900-1-1相减计算
	{
		Date max(*this);
		Date min(d);

		if (max < min)
		{
			max = d;
			min = *this;
		}
		int day = 0;

		while (1)
		{
			if ((min + day) == max)
				break;
			day++;
		}

		return day;
	}
private:
	friend ostream& operator<<(ostream& _cout, const Date& date);
	friend istream& operator>>(istream& _cin, Date& date);


private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& date)
{
	_cout << date._year << "-" << date._month << "-" << date._day;
	return _cout;
}

istream& operator>>(istream& _cin, Date& date)//istream类型
{
	_cin >> date._year >> date._month >> date._day;
	return _cin;
}


void Test()
{
	Date d1(2019, 1, 31);
	Date d2(2019, 2, 1);
	Date d3(2019, 2, 1);

	//cout << d1 - 300 << endl;
	cout << (d1 - d2) << endl;

	//cout << (d1 == d2) << endl;

}