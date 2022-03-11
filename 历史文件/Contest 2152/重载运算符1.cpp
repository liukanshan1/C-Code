#include<iostream>
#include<string>
using namespace std;

class Integer
{
public:
	Integer();
	~Integer();
	long long int d;
	Integer& operator+(Integer m);
	Integer& operator-(Integer m);
	Integer& operator*(Integer m);
	Integer& operator/(Integer m);
private:

};

Integer::Integer()
{
}

Integer::~Integer()
{
}

Integer& Integer::operator+(Integer m)
{
	this->d = this->d + m.d;
	return *this;
}
Integer& Integer::operator-(Integer m)
{
	this->d = this->d - m.d;
	return *this;
}
Integer& Integer::operator*(Integer m)
{
	this->d = this->d * m.d;
	return *this;
}
Integer& Integer::operator/(Integer m)
{
	this->d = this->d / m.d;
	return *this;
}

int main()
{
	char ope;
	Integer i1, i2;
	while (cin>>ope>>i1.d>>i2.d)
	{
		switch (ope)
		{
		case'+':
			i1 = i1 + i2;
			break;
		case'-':
			i1 = i1 - i2;
			break;
		case'*':
			i1 = i1 * i2;
			break;
		case'/':
			i1 = i1 / i2;
			break;
		default:
			break;
		}
		cout << i1.d << endl;
	}



}
