#include<iostream>
#include<cmath>
using namespace std;
int PI = 3;
class Circle
{
public:
	int radius;
	virtual ~Circle(){};
	virtual int area() = 0;
	virtual int volume() = 0;
};
class Sphere :public Circle
{
	public:
	Sphere(int r)
	{
		radius = r;
	}
	~Sphere(){};
	int area()
	{
		return 4 * pow(radius, 2) * PI;
	}
	int volume()
	{
		return 4 * pow(radius, 3);
	}
};
class Column :public Circle
{
public:
	Column(int r, int h)
	{
		radius = r;
		height = h;
	}
	~Column(){};
	int height;
	int area()
	{
		return 2 * pow(radius, 2) * PI + height * 2 * radius * PI;
	}
	int volume()
	{
		return height * pow(radius, 2) * PI;
	}
};

int main()
{
	int r, h;
	while (cin>>r>>h)
	{
		Circle* p1 = new Sphere(r);
		Circle* p2 = new Column(r,h);
		cout << p1->volume() << " "
			<< p1->area() << " "
			<< p2->volume() << " "
			<< p2->area() << " ";
	}
}