#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool neg1, neg2;
int dot1, dot2;
string s1, s2;

struct Num
{
	int n;  //Store 9 numbers according to the int range
	Num* next;
};

//Initialize global variables
void start()
{
	s1.erase(0);
	s2.erase(0);
	dot1 = dot2 = 0;
	neg1 = neg2 = false;
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
	//Each group of 9 digits, added to the Number Linked List
	int len = s.length();
	for (int i = 0; i < len; i += 9)
	{
		string temp(s, i, 9);
		reverse(temp.begin(), temp.end());
		Num* p = new Num;
		p->n = stoi(temp);
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
//Adder
Num* add(Num* head1, Num* head2)
{
	bool flag = false; //Used to determine whether to carry
	Num* p1 = head1->next;
	Num* p2 = head2->next;
	Num* head = new Num;
	Num* pre = head;
	while (p1 && p2)
	{
		int t = flag ? 1 : 0;
		flag = false;
		t += (p1->n + p2->n);
		if (t >= 1000000000)
		{
			flag = true;
			t -= 1000000000;
		}
		Num* p = new Num;
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1 || p2 || flag)
	{
		int t = flag ? 1 : 0;
		flag = false;
		if (p1)
		{
			t += p1->n;
			p1 = p1->next;
		}
		if (p2)
		{
			t += p2->n;
			p2 = p2->next;
		}
		if (t >= 1000000000)
		{
			flag = true;
			t -= 1000000000;
		}
		Num* p = new Num;
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
//Number Linked List to String
string num_to_str(Num* head)
{
	string s;
	Num* p = head->next;
	while (p != NULL)
	{
		string str = to_string(p->n);
		while (str.length() % 9 != 0)
		{
			str.insert(0, "0"); //Add 0 if less than 9 digits
		}
		reverse(str.begin(), str.end());
		s += str;
		p = p->next;
	}
	reverse(s.begin(), s.end());
	return s;
}
//Compare the numbers
bool compare(string& s1, string& s2) 
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
		reverse(s1.begin(), s1.end()); //The input s1 and s2 are reversed, so flip it
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
		return true; //Equal
	}
}
//Subtractor
Num* sub(Num* head1, Num* head2)
{
	bool flag = false; //Used to determine if a borrow is required
	Num* p1 = head1->next;
	Num* p2 = head2->next;
	Num* head = new Num;
	Num* pre = head;
	while (p2)
	{
		int t = flag ? -1 : 0;
		flag = false;
		t += (p1->n - p2->n);
		if (t < 0)
		{
			flag = true;
			t += 1000000000;
		}
		Num* p = new Num;
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1 || flag)
	{
		int t = flag ? -1 : 0;
		flag = false;
		if (p1)
		{
			t += p1->n;
			p1 = p1->next;
		}
		if (t < 0)
		{
			flag = true;
			t += 1000000000;
		}
		Num* p = new Num;
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
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
//Output result
void output(Num* head, bool flag = false)
{
	string s = num_to_str(head);
	int len = s.length();
	if (dot1 || dot2) //Add decimal point and comma
	{
		s.insert(len - max(dot1, dot2), ".");
		while (s[0] == '0' && s.length() != 1 && s[1] != '.')
		{
			s.erase(0, 1); //Delete the first 0
		}
		len = s.length();
		for (int i = len - max(dot1, dot2) - 4; i > 0; i -= 3)
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
	if (flag && s != "0")
	{
		cout << "-";
	}
	cout << s << endl;
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
		input();
		(dot1 > dot2 ? s2 : s1).append(abs(dot1 - dot2), '0'); //Add 0 to align the decimal point
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		Num* n1 = str_to_num(s1);
		Num* n2 = str_to_num(s2);
		Num* result = NULL;
		if ((ope == '+' && !neg1 && !neg2) || (ope == '-' && !neg1 && neg2)) //+++ +-- (positive number plus positive number and so on)
		{
			result = add(n1, n2);
			output(result);
		}
		else if ((ope == '+' && neg1 && neg2) || (ope == '-' && neg1 && !neg2)) //-+- --+
		{
			result = add(n1, n2);
			output(result,true);
		}
		else if ((ope == '+' && !neg1 && neg2) || (ope == '-' && !neg1 && !neg2)) //++- +-+
		{
			bool flag = compare(s1, s2);
			if (flag)
			{
				result = sub(n1, n2);
				output(result);
			}
			else
			{
				result = sub(n2, n1);
				output(result, true);
			}
		}
		else if ((ope == '+' && neg1 && !neg2) || (ope == '-' && neg1 && neg2)) //-++ ---
		{
			bool flag = compare(s1, s2);
			if (flag)
			{
				result = sub(n1, n2);
				output(result, true);
			}
			else
			{
				result = sub(n2, n1);
				output(result);
			}
		}
		del(n1);
		del(n2);
		del(result);
	}
}