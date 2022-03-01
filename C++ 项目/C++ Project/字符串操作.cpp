#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string ope;
	while (cin >> ope)
	{
		if (ope=="SER")
		{
			string s_ser;
			cin >> s_ser;
			for (int i = 0; i < s.size()-s_ser.size(); i++)
			{
				int cou = 0;
				for (int n = 0; n < s_ser.size(); n++)
				{
					if (s[i+n]==s_ser[n])
					{
						cou += 1;
					}
				}
				if (cou==s_ser.size())
				{
					cout << i << endl;
				}
			}
		}
		else
		{
			string s_out;
			if (ope=="ADD")
			{
				int a;
				string s_add;
				cin >> s_add >> a;
				for (int i = 0; i <= a; i++)
				{
					s_out += s[i];
				}
				for (int m = 0; m < s_add.size(); m++)
				{
					s_out += s_add[m];
				}
				for (int i = a + 1; i < s.size(); i++)
				{
					s_out += s[i];
				}
			}
			else if (ope=="DEL")
			{
				int x, n;
				cin >> x >> n;
				for (int i = 0; i < x; i++)
				{
					s_out += s[i];
				}
				for (int i = x+n; i < s.size(); i++)
				{
					s_out += s[i];
				}
			}
			else if (ope=="CHA")
			{
				int x;
				string s_cha;
				cin >> s_cha >> x;
				for (int i = 0; i < x; i++)
				{
					s_out += s[i];
				}
				for (int i = 0; i < s_cha.size(); i++)
				{
					s_out += s_cha[i];
				}
				for (int i = x+s_cha.size(); i < s.size(); i++)
				{
					s_out += s[i];
				}
			}
			s=s_out;
			cout << s << endl;
		}
	}
}