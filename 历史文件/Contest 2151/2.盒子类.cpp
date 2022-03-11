#include<iostream>
#include<string>
using namespace std;

class Box
{
public:
	Box();
	Box(int l, int w, int h);
	~Box();
	void setBox(int l, int w, int h);
	void volume();
	int length;
	int width;
	int height;

private:

};

Box::Box()
{
}

Box::Box(int l, int w, int h)
{
	length = l;
	width = w;
	height = h;
}

Box::~Box()
{
}

void Box::setBox(int l, int w, int h)
{
	length = l;
	width = w;
	height = h;
}

void Box::volume()
{
	long long int temp;
	temp = length * width * height;
	cout << temp << endl;
}

int main()
{
	Box b;
	while (cin >> b.length >> b.width >> b.height)
	{
		b.volume();
	}
}