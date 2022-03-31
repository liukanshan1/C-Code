#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;

bool neg1, neg2, dot3, dot3_11;
short dot1, dot2;
string s1, s2;

//Initialize global variables
void start()
{
	s1.erase(0);
	s2.erase(0);
	dot1 = dot2 = 0;
	neg1 = neg2 = dot3 = dot3_11 = false;
}
//Read numbers
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
//String to Number Linked List
void str_to_num(const string& s, list<int>& num)
{
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		string temp(s, i, 1);
		num.push_back(stoi(temp));
	}
}
// Number Linked List to String
string num_to_str(list<int>& r)
{
	string s;
	for (list<int>::iterator i = r.begin(); i != r.end(); i++)
	{
		s += string(to_string(*i));
	}
	return s;
}
//Adder, to preserve carry to 10 decimal places
string add(string num1, string num2)
{
	string sum, x;
	bool flag = false;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (int i = 0; i < min(num1.length(), num2.length()); i++)
	{
		int s = (flag ? (flag = false, 1) : 0);
		string s_a(num1, i, 1), s_b(num2, i, 1);
		s += stoi(s_a) + stoi(s_b);
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
	if (num1.length() != num2.length())
	{
		x = (num1.length() > num2.length() ? num1 : num2);
		for (int i = min(num1.length(), num2.length()); i < x.length(); i++)
		{
			int s = (flag ? (flag = false, 1) : 0);
			string s_x(x, i, 1);
			s += stoi(s_x);
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
	}
	if (flag)
	{
		sum += '1';
	}
	reverse(sum.begin(), sum.end());
	return sum;
}
//Subtractor, used for division calculations
list<int> sub(list<int> num1, list<int> num2)
{
	list<int> sub;
	bool flag = false;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	list<int>::iterator p1 = num1.begin();
	list<int>::iterator p2 = num2.begin();
	for (; p1 != num1.end() && p2 != num2.end(); p1++, p2++)
	{
		int s = (flag ? (flag = false, -1) : 0);
		s += *p1 - *p2;
		if (s < 0)
		{
			flag = true;
			s += 10;
		}
		sub.push_back(s);
	}
	if (num1.size() != num2.size())
	{
		while (p1 != num1.end())
		{
			int s = (flag ? (flag = false, -1) : 0);
			s += *p1;
			if (s < 0)
			{
				flag = true;
				s += 10;
			}
			sub.push_back(s);
			p1++;
		}
	}
	reverse(sub.begin(), sub.end());
	while (sub.size() != 0 && sub.front() == 0 && sub.size() != 1)
	{
		sub.pop_front(); //Delete the first 0
	}
	return sub;
}
//Compare the numbers
bool compare(list<int>& n1, list<int>& n2)
{
	int len1 = n1.size(), len2 = n2.size();
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
		list<int>::iterator p1 = n1.begin();
		list<int>::iterator p2 = n2.begin();
		while (p1 != n1.end())
		{
			if (*p1 - *p2 > 0)
			{
				return true;
			}
			else if (*p2 - *p1 > 0)
			{
				return false;
			}
			p1++;
			p2++;
		}
		return true; //Equal
	}
}
//Reserve 10 decimal places
void ten_decimal_places(string& s)
{
	string temp;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			temp += s.substr(i + 1, 11);
			s.erase(i);
			break;
		}
	}
	long long n = atoll(temp.c_str());
	if (n - n / 10 * 10 > 4)
	{
		n = n / 10 + 1;
		if (n >= 10000000000)
		{
			n %= 10000000000;
			s = add(s, "1");
		}
	}
	else
	{
		n /= 10;
	}
	if (n != 0)
	{
		s += ".";
		string str = to_string(n);
		while (str.length() < 10)
		{
			str.insert(0, "0");
		}
		s += str;
	}
}
//Output the result of the multiplication
void output_m(list<int>& result)
{
	string s = num_to_str(result);
	reverse(s.begin(), s.end());
	int len = s.length();
	if (dot1 != 0 || dot2 != 0) //Add decimal point and comma
	{
		s.insert(len - dot1 - dot2, ".");
		if (dot1 + dot2 > 10)
		{
			ten_decimal_places(s);
		}
		while (s[0] == '0' && s.length() != 1 && s[1] != '.')
		{
			s.erase(0, 1); //Delete the first 0
		}
		len = s.length();
		int point = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '.')
			{
				point = len - i;
				break;
			}
		}
		for (int i = len - point - 3; i > 0; i -= 3)
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
			else if (s[len - 1] == '0' && point != 0)
			{
				s.erase(len - 1, 1);
			}
			else if (s[len - 1] == '.')
			{
				s.erase(len - 1, 1);
				break;
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		while (s[0] == '0' && s.length() != 1)
		{
			s.erase(0, 1); //Delete the first 0
		}
		len = s.length();
		for (int i = len - 3; i > 0; i -= 3)
		{
			s.insert(i, ",");
		}
	}
	if (((!neg1 && neg2) || (neg1 && !neg2)) && s != "0")
	{
		cout << "-";
	}
	cout << s << endl;
}
//Output the result of the division
void output_d(list<int>& result)
{
	string s = num_to_str(result);
	int len1 = s1.length(), len2 = s2.length();
	int len;
	if (dot3) //Add decimal point and comma
	{
		if (len1 - len2 + 1 >= 0)
		{
			s.insert(len1 - len2 + 1, ".");
		}
		else
		{
			s.insert(0, ".");
		}
		if (s[0] == '.')
		{
			s.insert(0, "0");
		}
		len = s.length();
		if (dot3_11)
		{
			ten_decimal_places(s);
		}
		while (s[0] == '0' && s.length() != 1 && s[1] != '.')
		{
			s.erase(0, 1); //Delete the first 0
		}
		len = s.length();
		int point = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '.')
			{
				point = len - i;
				break;
			}
		}
		for (int i = len - point - 3; i > 0; i -= 3)
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
			else if (s[len - 1] == '0' && point != 0)
			{
				s.erase(len - 1, 1);
			}
			else if (s[len - 1] == '.')
			{
				s.erase(len - 1, 1);
				break;
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		while (s[0] == '0' && s.length() != 1)
		{
			s.erase(0, 1); //Delete the first 0
		}
		len = s.length();
		for (int i = len - 3; i > 0; i -= 3)
		{
			s.insert(i, ",");
		}
	}
	if (((!neg1 && neg2) || (neg1 && !neg2)) && s != "0")
	{
		cout << "-";
	}
	cout << s << endl;
}
//Multiplier
void multiply(list<int>& n1, list<int>& n2, list<int>& result)
{
	int len1 = s1.length(), len2 = s2.length();
	result.resize(len1 + len2, 0); //Initialized to 0
	list<int>::iterator r = result.begin();
	list<int>::iterator pr;
	for (list<int>::iterator p1 = n1.begin(); p1 != n1.end(); p1++, r++)
	{
		pr = r;
		for (list<int>::iterator p2 = n2.begin(); p2 != n2.end(); p2++, pr++)
		{
			*pr += *p1 * *p2; //Multiplication
		}
	}
	for (list<int>::iterator i = result.begin(); i != result.end(); i++)
	{
		if (*i >= 10)
		{
			*(++(list<int>::iterator(i))) += *i / 10;//Carry operation
			*i = *i % 10;
		}
	}
}
//Divider
void devide(list<int>& n1, list<int>& n2, list<int>& result)
{
	int len1 = s1.length(), len2 = s2.length();
	list<int>::iterator st, ed;
	st = n1.begin();
	ed = n1.begin();
	int i = 0;
	while (ed != n1.end() && i < len2 - 1)
	{
		ed++;
		i++;
	}
	list<int> s;
	s.assign(st, ed);
	for (; ed != n1.end(); ed++)
	{
		int count = 0;
		s.push_back(*ed);
		while (compare(s, n2))
		{
			s = sub(s, n2);
			count++;
		}
		result.push_back(count);
	}
	if (s.size() != 0 && s.front() != 0)
	{
		dot3 = true;
		for (int i = 0; i < 11; i++)
		{
			int count = 0;
			s.push_back(0);
			while (compare(s, n2))
			{
				s = sub(s, n2);
				count++;
			}
			result.push_back(count);
			if (i == 10)
			{
				dot3_11 = true;
			}
			if (s.size() != 0 && s.front() == 0)
			{
				break;
			}
		}
	}
}

int main()
{
	long long int n;
	cin >> n;
	while (n--)
	{
		start();
		char ope;
		cin >> ope;
		list<int> n1;
		list<int> n2;
		list<int> result;
		input();
		if (ope == '*')
		{
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			str_to_num(s1, n1);
			str_to_num(s2, n2);
			multiply(n1, n2, result);
			output_m(result);

		}
		else if (ope == '/')
		{
			if (dot2 >= 6)
			{
				string temp(s2, 0, 7);
				if (stoi(temp) < 1)
				{
					cout << "ERROR" << endl;
					continue;
				}
			}
			(dot1 > dot2 ? s2 : s1).append(abs(dot1 - dot2), '0');
			while (s1[0] == '0')
			{
				s1.erase(0, 1);
			}
			while (s2[0] == '0')
			{
				s2.erase(0, 1);
			}
			str_to_num(s1, n1);
			str_to_num(s2, n2);
			devide(n1, n2, result);
			output_d(result);
		}
	}
}