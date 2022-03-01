#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool neg1, neg2, dot3, dot3_11;
short dot1, dot2;
string s1, s2;

struct Num
{
	int n; 
	Num* next;
};

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
Num* str_to_num(const string& s)
{
	Num* head = new Num;
	Num* pre = head;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		string temp(s, i, 1);
		Num* p = new Num;
		p->n = stoi(temp);
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
// Number Linked List to String
string num_to_str(Num* head)
{
	string s;
	Num* p = head->next;
	while (p != NULL)
	{
		string str = to_string(p->n);
		s += str;
		p = p->next;
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
string sub(string num1, string num2)
{
	string sub;
	bool flag = false;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (int i = 0; i < min(num1.length(), num2.length()); i++)
	{
		int s = (flag ? (flag = false, -1) : 0);
		string s_a(num1, i, 1), s_b(num2, i, 1);
		s += atoi(s_a.c_str()) - atoi(s_b.c_str());
		if (s < 0)
		{
			flag = true;
			s += 10;
		}
		sub += to_string(s);
	}
	if (num1.length() != num2.length())
	{
		for (int i = min(num1.length(), num2.length()); i < num1.length(); i++)
		{
			int s = (flag ? (flag = false, -1) : 0);
			string s_x(num1, i, 1);
			s += atoi(s_x.c_str());
			if (s < 0)
			{
				flag = true;
				s += 10;
			}
			sub += to_string(s);
		}
	}
	reverse(sub.begin(), sub.end());
	while (sub[0] == '0' && sub.length() != 1)
	{
		sub.erase(0, 1); //Delete the first 0
	}
	return sub;
}
//Compare the numbers
bool compare(string num1, string num2)
{
	int len1 = num1.length(), len2 = num2.length();
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
		for (int i = 0; i < len1; i++)
		{
			if (num1[i] - num2[i] > 0)
			{
				return true;
			}
			else if (num2[i] - num1[i] > 0)
			{
				return false;
			}
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
		if (s[i]=='.')
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
		if (n>=10000000000)
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
		while (str.length()<10)
		{
			str.insert(0, "0");
		}
		s += str;
	}
}
//Output the result of the multiplication
void output_m(Num* head)
{
	string s = num_to_str(head);
	reverse(s.begin(), s.end());
	int len = s.length();
	if (dot1!=0 || dot2!=0) //Add decimal point and comma
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
			if (s[i]=='.')
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
void output_d(Num* head)
{
	string s = num_to_str(head);
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
Num* multiply(Num* head1, Num* head2)
{
	int len1 = s1.length(), len2 = s2.length();
	int* a = new int[len1];
	int* b = new int[len2];
	int* c = new int[len1 + len2];
	Num* p = head1->next;
	for (int i = 0; i < len1; i++)
	{
		a[i] = p->n;
		p = p->next;
	}
	p = head2->next;
	for (int i = 0; i < len2; i++)
	{
		b[i] = p->n;
		p = p->next;
	}
	for (int i = 0; i < len1+len2; i++)
	{
		c[i] = 0; //Initialized to 0
	}
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			c[i + j] += a[i] * b[j];  //Multiplication
		}
	}
	for (int i = 0; i < len1+len2; i++)
	{
		if (c[i] >= 10)
		{
			c[i + 1] +=  c[i] / 10;//Carry operation
			c[i] = c[i] % 10;
		}
	}
	Num* head = new Num;
	Num* pre = head;
	for (int i = 0; i < len1 + len2; i++)
	{
		Num* p = new Num;
		p->n = c[i];
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	delete[] a; //Free memory
	delete[] b;
	delete[] c;
	return head;
}
//Divider
Num* devide(Num* head1, Num* head2) 
{
	int len1 = s1.length(), len2 = s2.length();
	Num* head = new Num;
	Num* pre = head;
	string s(s1, 0, len2-1);
	for (int i = len2-1; i < len1; i++)
	{
		int count = 0;
		s += s1[i];
		while (compare(s,s2))
		{
			s = sub(s, s2);
			count++;
		}
		Num* p = new Num;
		p->n = count;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	if (s != "0")
	{
		dot3 = true;
		for (int i = 0; i < 11; i++)
		{
			int count = 0;
			s += "0";
			while (compare(s, s2))
			{
				s = sub(s, s2);
				count++;
			}
			Num* p = new Num;
			p->n = count;
			pre->next = p;
			pre = p;
			p->next = NULL;
			if (i == 10)
			{
				dot3_11 = true;
			}
			if (s == "0")
			{
				break;
			}
		}
	}
	return head;
}
//Free memory
void del(Num* head)
{
	Num* p = head;
	while (p)
	{
		Num* q = p->next;
		delete p;
		p = q;
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
		Num* n1 = NULL;
		Num* n2 = NULL;
		Num* result = NULL;
		input();
		if (ope=='*')
		{
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			n1 = str_to_num(s1);
			n2 = str_to_num(s2);
			result = multiply(n1, n2);
			output_m(result);
			
		}
		else if (ope=='/')
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
			n1 = str_to_num(s1);
			n2 = str_to_num(s2);
			result = devide(n1, n2);
			output_d(result);
		}
		del(n1);
		del(n2);
		del(result);
	}
}