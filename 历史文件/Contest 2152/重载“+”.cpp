#include<iostream>
#include<string>
using namespace std;

class str
{
public:
	str();
	~str();
	str operator+(str s2);
	string s;
private:

};

str::str()
{
}

str::~str()
{
}

str str::operator+(str s2)
{
	this->s += s2.s;
	return *this;
}

int main()
{
	str s1, s2;
	while (cin>>s1.s>>s2.s)
	{
		s1 =s1 + s2;
		cout << s1.s << endl;
	}



}
