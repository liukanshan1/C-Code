#include <iostream>
using namespace std;
int main()
{
	int a;
	while (cin >> a)
	{
		if (a == 1)
		{
			cout << "*" << endl;
		}
		else
		{
			for (int i = 0; i < a - 1; i++)
			{
				cout << "* ";
			}
			cout << "*";
			cout << endl;
			for (int c = 0; c < a - 2; c++)
			{
				cout << "* ";
				for (int b = 0; b < a - 2; b++)
				{
					cout << "  ";
				}
				cout << "*" << endl;
			}
			for (int i = 0; i < a-1; i++)
			{
				cout << "* ";
			}
			cout << "*";
			cout << endl;

		}

	}
}