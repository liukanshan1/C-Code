#include <iostream>
#include <iomanip>
using namespace std;

float lerangde(float x,int n)
{
	if (n >= 2)
	{
		return ((2 * n - 1) * (lerangde(x,n - 1)) - (n - 1) * (lerangde(x,n - 2))) / n;
	}
	else if (n == 1)
	{
		return x;
	}
	else
	{
		return 1;
	}

}

int main()
{
	float x;
	int n;
	while (cin >> x >> n)
	{
		float s;
		s=lerangde(x, n);
		cout << fixed << setprecision(2) << s << endl;
	}

}