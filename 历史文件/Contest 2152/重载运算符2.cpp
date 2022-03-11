#include<iostream>
#include<string>
using namespace std;

class Vector
{
public:
	Vector(int n);
	~Vector();
	int t;
	int* p;
	Vector& operator+(const Vector& v);
	Vector& operator-(const Vector& v);
	friend ostream& operator<<(ostream& output,const Vector& v);
	friend istream& operator>>(istream& input, const Vector& v);
	long long int operator*(const Vector& v);
private:

};

Vector::Vector(int n)
{
	p = nullptr;
	t = n;
	if (n > 0)
	{
		p = new int[n];
	}
}

Vector::~Vector()
{
	if (p!=nullptr)
	{
		delete[] p;
	}
}

Vector& Vector::operator+(const Vector& v)
{
	for (int i = 0; i < this->t; i++)
	{
		this->p[i] = this->p[i] + v.p[i];
	}
	return *this;
}
Vector& Vector::operator-(const Vector& v)
{
	for (int i = 0; i < this->t; i++)
	{
		this->p[i] = this->p[i] - v.p[i];
	}
	return *this;
}
long long int Vector::operator*(const Vector& v)
{
	long long int result=0;
	for (int i = 0; i < this->t; i++)
	{
		result += this->p[i] * v.p[i];
	}
	return result;
}

ostream& operator<<(ostream& output, const Vector& v)
{
	for (int i = 0; i < v.t-1; i++)
	{
		output << v.p[i] << " ";
	}
	output << v.p[v.t - 1];
	return output;
}

istream& operator>>(istream& input, const Vector& v)
{
	for (int i = 0; i < v.t; i++)
	{
		input >> v.p[i];
	}
	return input;
}

int main()
{
	char ope;
	int t;
	while (cin>>ope>>t)
	{
		Vector s1(t), s2(t);
		cin >> s1 >> s2;
		switch (ope)
		{
		case'+':
			s1 = s1 + s2;
			cout << s1 << endl;
			break;
		case'-':
			s1 = s1 - s2;
			cout << s1 << endl;
			break;
		case'*':
			cout<< s1 * s2<<endl;
			break;
		default:
			break;
		}

	}

}
