#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
	long long x = 0;
	
	while (cin >> x)
	{
		string s = "";
		while (x > 0)
		{
			int m = x % 26;
			if (m == 0) m = 26;
			s += (char)(m + 64);
			x = (x - m) / 26;
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}