#include <iostream>
using namespace std;
int main()
{
	int n, a=1, b=1,temp=0;
	while (cin>>n)
	{
		if (n<=1)
		{
			cout << "1" << endl;
		}
		else
		{
			for (int i = 0; i <=n-2; i++)
			{
				temp = a + b;
				a = b;
				b = temp;
			}
			cout << b << endl;
			a = 1; b = 1; temp = 0;
		}
	}
}