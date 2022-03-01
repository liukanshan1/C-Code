#include <iostream>
using  namespace std;
int main()
{
	int a;
	while (cin>>a)
	{
		int i = 0;
		while (a!=1)
		{
			if (a%2==0)
			{
				a = a / 2;
				i++;
			}
			else
			{
				a = a * 3 + 1;
				i++;
			}
		}
		cout << i << endl;
	}
}