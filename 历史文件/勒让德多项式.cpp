#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float x, s,a,b,temp;
	int n,m;
	while (cin>>x>>n)
	{
		if (n==0)
		{
			s = 1;
		}
		else if (n==1)
		{
			s = x;
		}
		else
		{
			a = 1; b = x; temp = 0;
				for (m= 2; m <=n; m++)
				{
					temp = ((2 * m - 1) * b - (m - 1) * a )/ m;
					a = b;
					b = temp;
				}
				s = b;
		}
		cout << fixed << setprecision(2) << s << endl;


		
	}
	
}