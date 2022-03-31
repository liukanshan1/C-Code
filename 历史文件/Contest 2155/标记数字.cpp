#include <iostream>
#include <string>
using namespace std;

bool isNum(char c)
{
	if (c - '0' >= 0 && c - '9' <= 0)
	{
		return true;
	}
	return false;
}

int main()
{
	string s;
	while (cin>>s)
	{
		bool flag = false;
		int i = 0;
		while (i < s.length())
		{
			if (isNum(s[i]) && !flag)
			{
				s.insert(i, "*");
				i++;
				flag = true;
			}
			if (!isNum(s[i]) && flag)
			{
				s.insert(i, "*");
				i++;
				flag = false;
			}
			i++;
		}
		if (flag)
		{
			s += "*";
		}
		cout << s << endl;
	}
}