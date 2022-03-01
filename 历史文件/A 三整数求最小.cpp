#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		int min;
		min = a > b ? b : a;
		min = min > c ? c : min;
		cout << min << endl;
	}
}
