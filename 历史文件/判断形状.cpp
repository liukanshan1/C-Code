#include <iostream>
#include <math.h>
using namespace std;

struct point
{
	int x, y;
};

struct Quadrilateral
{
	point p1, p2, p3, p4;
};

int main()
{
	Quadrilateral q;
	while (cin>>q.p1.x>>q.p1.y)
	{
		cin >> q.p2.x >> q.p2.y >> q.p3.x >> q.p3.y >> q.p4.x >> q.p4.y;
		int a, b, c, d;
		a = pow(q.p1.x - q.p2.x, 2) + pow(q.p1.y - q.p2.y, 2);
		b = pow(q.p3.x - q.p4.x, 2) + pow(q.p3.y - q.p4.y, 2);
		c = pow(q.p1.x - q.p3.x, 2) + pow(q.p1.y - q.p3.y, 2);
		d = pow(q.p2.x - q.p4.x, 2) + pow(q.p2.y - q.p4.y, 2);
		if (a==b&&c==d)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}