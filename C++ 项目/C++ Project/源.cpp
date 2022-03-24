#include<iostream>
#include<cstring>
#include<iomanip>
#include<string.h>
#include<string>
using namespace std;
class Base
{
	friend ostream& operator<< (ostream&, const Base&);
public:
	int x;
	Base()
	{
		x = 50;

	}



};
ostream& operator<<(ostream& os, const Base& a)
{
	os << '[';
	os << a.x;
	os << "]";
	return os;
}
int main()
{

	Base a;
	cout << a << endl;;
	float g = 5 / 1000.0;
	cout << g << endl;
}