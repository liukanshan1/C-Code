#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool neg1, neg2;
int dot1, dot2;
string s1, s2;

//初始化全局变量
void start()
{
	s1.erase(0);
	s2.erase(0);
	dot1 = 0;
	dot2 = 0;
	neg1 = false;
	neg2 = false;
}
//读入数字
void input()
{
	cin >> s1 >> s2;
	if (s1[0] == '-')
	{
		neg1 = true;
		s1.erase(0, 1);
	}
	if (s2[0] == '-')
	{
		neg2 = true;
		s2.erase(0, 1);
	}
	int n;
	while ((n = s1.find(',')) != string::npos)
	{
		s1.erase(n, 1);
	}
	while ((n = s2.find(',')) != string::npos)
	{
		s2.erase(n, 1);
	}
	int len1 = s1.length(), len2 = s2.length();
	if ((n = s1.find('.')) != string::npos)
	{
		s1.erase(n, 1);
		dot1 = len1 - n - 1;
	}
	if ((n = s2.find('.')) != string::npos)
	{
		s2.erase(n, 1);
		dot2 = len2 - n - 1;
	}
}
//比较数字绝对值大小
bool compare(string s1, string s2)
{
	int len1 = s1.length(), len2 = s2.length();
	if (len1 > len2)
	{
		return true;
	}
	else if (len2 > len1)
	{
		return false;
	}
	else
	{
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		for (int i = 0; i < len1; i++)
		{
			if (s1[i] - s2[i] > 0)
			{
				return true;
			}
			else if (s2[i] - s1[i] > 0)
			{
				return false;
			}
		}
		return true; //两数相等
	}
}
//加法器
string add(string num1, string num2)
{
	string sum, x;
	bool flag = false;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	if (num1.length() == num2.length())
	{
		for (int i = 0; i < num1.length(); i++)
		{
			int s;
			if (flag)
			{
				s = 1;
				flag = false;
			}
			else
			{
				s = 0;
			}
			string s_a, s_b;
			s_a = num1[i];
			s_b = num2[i];
			s += atoi(s_a.c_str()) + atoi(s_b.c_str());
			if (s >= 10)
			{
				flag = true;
				s %= 10;
				sum += to_string(s);
			}
			else
			{
				sum += to_string(s);
			}
		}
		if (flag)
		{
			sum += '1';
		}
	}
	else
	{
		for (int i = 0; i < min(num1.length(), num2.length()); i++)
		{
			int s;
			if (flag)
			{
				s = 1;
				flag = false;
			}
			else
			{
				s = 0;
			}
			string s_a, s_b;
			s_a = num1[i];
			s_b = num2[i];
			s += atoi(s_a.c_str()) + atoi(s_b.c_str());
			if (s >= 10)
			{
				flag = true;
				s = s % 10;
				sum += to_string(s);
			}
			else
			{
				sum += to_string(s);
			}
		}

		if (num1.length() > num2.length())
		{
			x = num1;
		}
		else
		{
			x = num2;
		}

		for (int i = min(num1.length(), num2.length()); i < x.length(); i++)
		{
			int s;
			if (flag)
			{
				s = 1;
				flag = false;
			}
			else
			{
				s = 0;
			}
			string s_x;
			s_x = x[i];
			s += atoi(s_x.c_str());
			if (s >= 10)
			{
				flag = true;
				s = s % 10;
				sum += to_string(s);
			}
			else
			{
				sum += to_string(s);
			}
		}
		if (flag)
		{
			sum += '1';
		}
	}
	reverse(sum.begin(), sum.end());
	return sum;
}
//减法器
string sub(string num1, string num2)
{
	string sub, x;
	bool flag = false;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	if (num1.length() == num2.length())
	{
		for (int i = 0; i < num1.length(); i++)
		{
			int s;
			if (flag)
			{
				s = -1;
				flag = false;
			}
			else
			{
				s = 0;
			}
			string s_a, s_b;
			s_a = num1[i];
			s_b = num2[i];
			s += atoi(s_a.c_str()) - atoi(s_b.c_str());
			if (s < 0)
			{
				flag = true;
				s += 10;
				sub += to_string(s);
			}
			else
			{
				sub += to_string(s);
			}
		}
	}
	else
	{
		x = num1;
		for (int i = 0; i < min(num1.length(), num2.length()); i++)
		{
			int s;
			if (flag)
			{
				s = -1;
				flag = false;
			}
			else
			{
				s = 0;
			}
			string s_a, s_b;
			s_a = num1[i];
			s_b = num2[i];
			s += atoi(s_a.c_str()) - atoi(s_b.c_str());
			if (s < 0)
			{
				flag = true;
				s += 10;
				sub += to_string(s);
			}
			else
			{
				sub += to_string(s);
			}
		}
		for (int i = min(num1.length(), num2.length()); i < x.length(); i++)
		{
			int s;
			if (flag)
			{
				s = -1;
				flag = false;
			}
			else
			{
				s = 0;
			}
			string s_x;
			s_x = x[i];
			s += atoi(s_x.c_str());
			if (s < 0)
			{
				flag = true;
				s += 10;
				sub += to_string(s);
			}
			else
			{
				sub += to_string(s);
			}
		}
	}
	reverse(sub.begin(), sub.end());
	return sub;
}
//输出结果
void output(string s)
{
	int len = s.length();
	if (dot1 || dot2) //添加小数点和逗号
	{
		//cout << s << " " << len - max(dot1, dot2) << endl;
		s.insert(len - max(dot1, dot2), ".");
		while (s[0] == '0' && s.length() != 1 && s[1] != '.')
		{
			s.erase(0, 1); //删除首位0
		}
		len = s.length();
		//cout << s <<  endl;
		for (int i = len - max(dot1, dot2) - 3; i > 0; i -= 3)
		{
			s.insert(i, ",");
		}
		while (true)
		{
			len = s.length();
			if (len == 0)
			{
				s = '0';
				break;
			}
			else if (s[len - 1] == '0')
			{
				s.erase(len - 1, 1);
			}
			else if (s[len - 1] == '.')
			{
				s.erase(len - 1, 1);
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		//cout << s << " " << len - max(dot1, dot2) << endl;
		while (s[0] == '0' && s.length() != 1)
		{
			s.erase(0, 1); //删除首位0
		}
		len = s.length();
		for (int i = len - 3; i > 0; i -= 3)
		{
			s.insert(i, ",");
		}
	}
	cout << s << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		start();
		char ope;
		cin >> ope;
		input();
		(dot1 > dot2 ? s2 : s1).append(abs(dot1 - dot2), '0'); //补充0，小数点对齐
		if ((ope == '+' && !neg1 && !neg2) || (ope == '-' && !neg1 && neg2)) //正数加正数 正数减负数
		{
			string sum = add(s1, s2);
			output(sum);
		}
		else if ((ope == '+' && neg1 && neg2) || (ope == '-' && neg1 && !neg2)) //负数加负数 负数减正数
		{
			string sum = add(s1, s2);
			cout << "-";
			output(sum);
		}
		else if ((ope == '+' && !neg1 && neg2) || (ope == '-' && !neg1 && !neg2)) //正数加负数 正数减正数
		{
			bool flag = compare(s1, s2);
			if (flag)
			{
				string result = sub(s1, s2);
				output(result);
			}
			else
			{
				string result = sub(s2, s1);
				cout << "-";
				output(result);
			}
		}
		else if ((ope == '+' && neg1 && !neg2) || (ope == '-' && neg1 && neg2)) //负数加正数 负数减负数
		{
			bool flag = compare(s1, s2);
			if (flag)
			{
				string result = sub(s1, s2);
				cout << "-";
				output(result);
			}
			else
			{
				string result = sub(s2, s1);
				output(result);
			}
		}
	}
}