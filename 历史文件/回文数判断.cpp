#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		string stmp = s;
		reverse(stmp.begin(), stmp.end());
		if (stmp==s)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		
		
	}
	return 0;
}