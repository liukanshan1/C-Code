#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<class T>
T average(T arg[])
{
	T temp = 0;
	for (int i = 0; i < 3; i++)
	{
		temp += arg[i];
	}
	return temp / 3.0;
}


int main()
{
	int a[3];
	double b[3];
	while (cin>>a[0]>>a[1]>>a[2])
	{
		cin >> b[0] >> b[1] >> b[2];
		cout << average(a) << endl
			<< setprecision(3) << average(b) << endl;
	}
}