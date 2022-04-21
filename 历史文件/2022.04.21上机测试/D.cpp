#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
using namespace std;
enum TimeZone {
	W12 = -12, W11, W10, W9, W8, W7, W6, W5, W4, W3, W2, W1,
	GMT, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12
};

class Time
{
public:
	Time() {}
	Time(int hh, int mm, int ss) :h(hh), m(mm), s(ss) {}
	void set(int hh, int mm, int ss) {
		h = hh; m = mm; s = ss;
	}
	void increment() {
		s += 1;
		if (s == 60)
		{
			s = 0;
			m += 1;
		}
		if (m == 60)
		{
			m = 0;
			h += 1;
		}
		if (h == 24)
		{
			h = 0;
		}
	}
	void display()
	{
		cout << setfill('0') << setw(2) << h;
		cout << ":";
		cout << setfill('0') << setw(2) << m;
		cout << ":";
		cout << setfill('0') << setw(2) << s;
		cout << endl;
	}
	bool equal(Time ot) {
		return h == ot.h && m == ot.m && s == ot.s;
	}
	bool less_than(Time ot)
	{
		if (ot.h > h)
		{
			return true;
		}
		else if (ot.m > m)
		{
			return true;
		}
		else if (ot.s > s)
		{
			return true;
		}
		return false;
	}
	int h = 0;
	int m = 0;
	int s = 0;
};

class ExtTime:public Time
{
public:
	ExtTime() :Time() {};
	ExtTime(int hh, int mm, int ss, TimeZone t) :Time(hh,mm,ss),tz(t){};
	
	void set(int hh, int mm, int ss, TimeZone t)
	{
		h = hh; m = mm; s = ss; tz = t;
	}

	void display()
	{
		if (tz==GMT)
		{
			cout << "(GMT) ";
		}
		else
		{
			cout << "(GMT";
			if (tz<0)
			{
				cout<< tz << ") ";
			}
			else
			{
				cout << "+" << tz << ") ";
			}
			
		}
		Time::display();
	}
	bool equal(ExtTime ot)
	{
		return (h-tz == ot.h-ot.tz) && m == ot.m && s == ot.s;
	}
	bool less_than(ExtTime ot)
	{
		if (ot.h-ot.tz > h-tz)
		{
			return true;
		}
		else if (ot.h - ot.tz < h - tz)
		{
			return false;
		}
		if (ot.m  > m)
		{
			return true;
		}
		else if (ot.m < m)
		{
			return false;
		}
		if (ot.s > s)
		{
			return true;
		}
		return false;
	}
	enum TimeZone tz = GMT;
};



int main()
{
	ExtTime t1;
	t1.display();
	int z1, h1, m1, s1, z2, h2, m2, s2;
	cin >> z1 >> h1 >> m1 >> s1;
	cin >> z2 >> h2 >> m2 >> s2;
	ExtTime t2(h2, m2, s2, TimeZone(z2));
	t2.display();
	t1.set(h1, m1, s1, TimeZone(z1));
	t1.display();
	if (t1.equal(t2))
		cout << "t1==t2" << endl;
	else
		cout << "t1!=t2" << endl;
	t1.increment();
	t1.display();
	if (t2.less_than(t1))
		cout << "t2 earlier than t1" << endl;
	else
		cout << "t2 is not earlier than t1" << endl;
}