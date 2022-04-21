#include <iostream>
#include <vector>
#include <string>
using namespace std;
class RMB
{
public:
	RMB(){}
	RMB(int y, int j, int f) {
		jz = 0;
		jz += y;
		jz += j / 10.0;
		jz += f / 100.0;
	}
	RMB(double m) :jz(m) {	}
	int yuan;
	int jiao;
	int fen;
	double jz;
	bool mark;
	friend istream& operator>>(istream& in, RMB& r);
	friend ostream& operator<<(ostream& ou, RMB r);
	RMB operator+(RMB r) {
		static RMB temp;
		temp.jz = jz + r.jz;
		return temp;
	}
	RMB operator-(RMB r) {
		static RMB temp;
		//cout << jz << " " << r.jz;
		temp.jz = jz - r.jz;
		return temp;
	}
private:

};


RMB operator+(double jz,RMB r) {
	static RMB temp;
	temp.jz = jz + r.jz;
	return temp;
}




istream& operator>>(istream& in, RMB& r) {
	double y, j, f;
	in >> y;
	if ((int)y!=y)
	{
		RMB temp(y);
		r = temp;
	}
	else
	{
		in >> j >> f;
		RMB temp(y, j, f);
		r = temp;
	}
	return in;
}

ostream& operator<<(ostream& ou, RMB r)
{
	ou << r.jz;
	return ou;
}


int main()
{
	RMB a, b;
	double c;
	cout.setf(cout.showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	cin >> a;
	cin >> b;
	cin >> c;
	cout << RMB(a + c) << endl;
	cout << RMB(b - a) << endl;
	cout << RMB(2.18 + a) << endl;
	return 0;
}