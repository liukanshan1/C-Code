#include <iostream>
#include <string>
using namespace std;


//定义类模板T_Counter，实现基本类型数据的 + 、 - 、 * 、 = 、 >> 、 << 运算；
template<class T>
class T_Counter
{
public:
	T_Counter();
	~T_Counter();

};

template<class T>
T_Counter<T>::T_Counter()
{
}

template<class T>
T_Counter<T>::~T_Counter()
{
}


//类模板T_Vector，实现向量运算；
template<class T>
class T_Vector
{
public:
	T_Vector(int l);
	T_Vector(const T_Vector& v2);
	~T_Vector();
	void input()
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
	}
	T_Vector operator+(T_Vector v2);
	T_Vector operator-(T_Vector v2);
	int operator*(T_Vector v2);
	friend ostream& operator<<(ostream& output, T_Vector v2);
	int n;
	int* v = nullptr;
};
template<class T>
T_Vector<T>::T_Vector(int l)
{
	n = l;
	v = new int[l];
}
template<class T>
T_Vector<T>::T_Vector(const T_Vector& v2)
{
	this->n = v2.n;
	this->v = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->v[i] = v2.v[i];
	}
}
template<class T>
T_Vector<T>::~T_Vector()
{
	if (v != nullptr)
	{
		delete[] v;
	}
}
template<class T>
T_Vector<T> T_Vector<T>::operator+(T_Vector<T> v2)
{
	static T_Vector temp(this->n);
	for (int i = 0; i < this->n; i++)
	{
		temp.v[i] = (this->v[i] + v2.v[i]);
	}
	return temp;
}
template<class T>
T_Vector<T> T_Vector<T>::operator-(T_Vector<T> v2)
{
	static T_Vector temp(this->n);
	for (int i = 0; i < this->n; i++)
	{
		temp.v[i] = this->v[i] - v2.v[i];
	}
	return temp;
}
template<class T>
int T_Vector<T>::operator*(T_Vector<T> v2)
{
	int t = 0;
	for (int i = 0; i < this->n; i++)
	{
		t += this->v[i] * v2.v[i];
	}
	return t;
}
template<class T>
ostream& operator<<(ostream& output, T_Vector<T> v2)
{
	for (int i = 0; i < v2.n - 1; i++)
	{
		output << v2.v[i] << " ";
	}
	output << v2.v[v2.n - 1];
	return output;
}
//类模板T_Matrix，实现矩阵运算。
template<class T>
class T_Matrix
{
public:
	T_Matrix();
	~T_Matrix();


};
template<class T>
T_Matrix<T>::T_Matrix()
{
}
template<class T>
T_Matrix<T>::~T_Matrix()
{
}

int main()
{
	
}