#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	while (cin>>s)
	{
		reverse(s.begin(), s.end());
		string out;
		while (s.length() != 0)
		{
			string t(s,0,1);
			out += s[0];
			s.erase(0, 1);
			int temp = -1;
			while ((temp = s.find(t[0])) != string::npos)
			{
				s.erase(temp, 1);
			}
		}
		cout << out << endl;
	}

}