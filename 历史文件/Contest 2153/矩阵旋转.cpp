#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		int** p = new int* [n];
		for (int i = 0; i < n; i++)
		{
			p[i] = new int[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> p[i][j];
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = n - 1; i >= 0; i--)
			{
				cout << p[i][j]<<" ";
			}
			cout << endl;
		}	
		for (int i = 0; i < n; i++)
		{
			delete []p[i];
		}
		delete[]p;
	}
}
