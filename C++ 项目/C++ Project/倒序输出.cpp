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
		long int length = stmp.size();
		for ( long int i = 0; i < length - 1; ++i)
		{
			cout << "  " << stmp[i];
		}
		cout <<"  " << stmp[length - 1] << endl;
	}
	return 0;
}