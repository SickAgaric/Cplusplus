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
		_year = year;
		_month = month;
		_day = day;

		if (year >= 1900
			&& month > 0 && month < 13
			&& day > 0 && day <= GetDay(year, month))
		{
			cout << year << "-" << month << "-" << day << endl;
		}

		else
		{
			cout << "输入错误\n" << endl;
		}

	}

	bool operator>(const Date& d)   //m
	{
		if (_year > d._year)
			return 1;
		else if (_month > d._month)
			return 1;
		else if (_day > d._day)
			return 1;
		else
			return -1;

		/*return _year > d._year
			&&_month > d._month
			&&_day > d._day;*/
	}
	bool operator<(const Date& d)
	{
		;
	}
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}//m
	bool operator!=(const Date& d)
	{
		return !(_year == d._year
			&& _month == d._month
			&& _day == d._day);
	}
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);

	Date operator+(int day);
	Date operator-(int day);
	Date operator+=(int day);   //负数
	Date operator-=(int day);


	Date operator++(); //为什么要写一个++，用++的时候可能出现非法日期。
	Date operator++(int);

	Date operator--();
	Date operator--(int);

	int operator-(const Date&d); //与1900-1-1相减计算


private:
	int _year;
	int _month;
	int _day;
};

void Test()
{
	//重载操作符必须有一个类类型
	Date d1;
	Date d2(1993, 2, 2);
	Date d3(1995, 4, 5);
	//cout << "da" << endl;
	cout << (d2 > d3) << endl;
	cout << (d2 == d3) << endl;
	cout << (d2 != d3) << endl;

}