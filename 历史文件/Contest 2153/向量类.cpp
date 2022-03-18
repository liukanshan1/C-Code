#include<iostream>
using namespace std;

class Integer
{
protected:
	int n;
};

class Vector :public Integer
{
public:
	Vector(int t);
	Vector(const Vector& v2);
	~Vector();
	void input()
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
	}
	Vector operator+(Vector v2);
	Vector operator-(Vector v2);
	int operator*(Vector v2);
	friend ostream& operator<<(ostream& output, Vector v2);
protected:
	int* v = nullptr;
};

Vector::Vector(int t)
{
	n = t;
	v = new int[n];
}
Vector::Vector(const Vector& v2)
{
	this->n = v2.n;
	this->v = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->v[i] = v2.v[i];
	}
}
Vector::~Vector()
{
	if (v != nullptr)
	{
		delete[]v;
	}
}
Vector Vector::operator+(Vector v2)
{
	static Vector temp(this->n);
	for (int i = 0; i < this->n; i++)
	{
		temp.v[i] = (this->v[i] + v2.v[i]);
	}
	return temp;
}
Vector Vector::operator-(Vector v2)
{
	static Vector temp(this->n);
	for (int i = 0; i < this->n; i++)
	{
		temp.v[i] = this->v[i] - v2.v[i];
	}
	return temp;
}
int Vector::operator*(Vector v2)
{
	int t = 0;
	for (int i = 0; i < this->n; i++)
	{
		t += this->v[i] * v2.v[i];
	}
	return t;
}
ostream& operator<<(ostream& output, Vector v2)
{
	for (int i = 0; i < v2.n - 1; i++)
	{
		output << v2.v[i] << " ";
	}
	output << v2.v[v2.n - 1];
	return output;
}

int main()
{
	int n;
	while (cin >> n)
	{
		Vector v1(n), v2(n);
		v1.input();
		v2.input();
		cout << (v1 + v2)<< endl
			<< (v1 - v2) << endl
			<< v1 * v2 << endl;
	}
}
