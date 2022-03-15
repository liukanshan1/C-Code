#include<iostream>
using namespace std;
int main()
{
	double a, b;
	char ope;
	while (cin >> a >> ope >> b)
	{
		switch (ope)
		{
		case'+':
			cout << a + b << endl;
			break;
		case'-':
			cout << a - b << endl;
			break;
		case'*':
			cout << a * b << endl;
			break;
		case'/':
			cout << a / b << endl;
			break;
		default:
			break;
		}
	}
}
