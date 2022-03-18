#include<iostream>
#include<string>
using namespace std;

class Rectangle
{
public:
	int length;
	int width;
	int square()
	{
		return length * width;
	}
};

class Rectangular :public Rectangle
{
public:
	int height;
	int volume()
	{
		return square() * height;
	}
};


int main()
{
	Rectangle r1;
	Rectangular r2;
	while (cin >> r1.length >> r1.width)
	{
		cin >> r2.length >> r2.width >> r2.height;
		cout << r1.square() << endl
			<< r2.volume() << endl;
	}
}
