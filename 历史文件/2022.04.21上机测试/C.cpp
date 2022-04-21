#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
using namespace std;

class Time
{
public:
	Time(){}
	Time(int hh, int mm, int ss):h(hh),m(mm),s(ss){}
	void set(int hh, int mm, int ss) {
		h = hh; m = mm; s = ss;
	}
	void increment() {
		s += 1;
		if (s==60)
		{
			s = 0;
			m += 1;
		}
		if (m==60)
		{
			m = 0;
			h += 1;
		}
		if (h==24)
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

private:
	int h=0;
	int m=0;
	int s=0;
};



int main()
{
	Time t1;
	t1.display();
	int h1, m1, s1, h2, m2, s2;
	cin >> h1 >> m1 >> s1;
	cin >> h2 >> m2 >> s2;
	Time t2(h2, m2, s2);
	t2.display();
	t1.set(h1, m1, s1);
	t1.display();
	if (t1.equal(t2))
		cout << "t1==t2" << endl;
	else
		cout << "t1!=t2" << endl;
	if (t2.less_than(t1))
		cout << "t2 earlier than t1" << endl;
	else
		cout << "t2 is not earlier than t1" << endl;
	t1.increment();
	t1.display();
}