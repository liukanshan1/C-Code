#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	bool flag = false;
	while (getline(cin, s))
	{
		int i;
		// 处理/**/
		//if (!flag && (i = s.find("/*")) == string::npos) //不处理
		if (!flag && (i = s.find("/*")) != string::npos)
		{
			flag = true;
			s.erase(i);
			if (s.length()!=0)
			{
				cout << s << endl;
			}
			continue;
		}
		if (flag && (i = s.find("*/")) == string::npos)
		{
			continue;
		}
		if (flag && (i = s.find("*/")) != string::npos)
		{
			flag = false;
			s.erase(0, i + 2);
			if (s.length() != 0)
			{
				cout << s << endl;
			}
			continue;
		}
		// 处理//
		if ((i = s.find("//")) != string::npos)
		{
			s.erase(i);
			if (s.length() != 0)
			{
				cout << s << endl;
			}
			continue;
		}
		cout << s << endl;
	}
}