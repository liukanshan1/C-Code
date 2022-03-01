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
	int n;  
	Num* next;
};

void start()
{
	s1.erase(0);
	s2.erase(0);
	dot1 = 0;
	dot2 = 0;
	neg1 = false;
	neg2 = false;

}

void input(int n, string& s)
{
	bool flag = false;
	char temp;
	temp = getchar();
	if (int(temp) == 10) //
	{
		temp = getchar();
	}
	while (int(temp) != 10) //
	{
		if (int(temp) == 45)  //
		{
			(n == 1 ? neg1 : neg2) = true;
			temp = getchar();
		}
		if (int(temp) == 46) //
		{
			flag = true;
			temp = getchar();
		}
		if (flag)
		{
			(n == 1 ? dot1 : dot2)++;
		}
		if (int(temp) != 44) //
		{
			s += temp;
		}
		temp = getchar();
	}
}
//
Num* str_to_num(const string& s)
{
	//
	Num* head = new Num;
	Num* pre = head;
	//
	int len = s.length();
	for (int i = 0; i < len; i += 9)
	{
		string temp(s, i, 9);
		reverse(temp.begin(), temp.end());
		Num* p = new Num;  //
		p->n = stoi(temp);
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
//
Num* add(Num* head1, Num* head2)
{
	bool flag = false; //
	Num* p1 = head1->next;
	Num* p2 = head2->next;
	//
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
		Num* p = new Num;  //
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}

	return head;
}
//
string num_to_str(Num* head)
{
	string s;
	Num* p = head->next;
	while (p != NULL)
	{
		string str = to_string(p->n);
		while (str.length() % 9 != 0)
		{
			str.insert(0, "0"); //
		}
		//cout << str << endl;
		reverse(str.begin(), str.end());
		s += str;
		p = p->next;
	}
	reverse(s.begin(), s.end());
	return s;
}
//
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
		return true; //
	}
}
//
Num* sub(Num* head1, Num* head2)
{
	bool flag = false; //
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
		Num* p = new Num;  //
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
		Num* p = new Num;  //
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}

	return head;
}
//
void output(Num* head)
{
	string s = num_to_str(head);
	int len = s.length();
	if (dot1 || dot2) //
	{
		//cout << s << " " << len - max(dot1, dot2) << endl;
		s.insert(len - max(dot1, dot2), ".");
		while (s[0] == '0' && s.length() != 1 && s[1] != '.')
		{
			s.erase(0, 1); //
		}
		len = s.length();
		for (int i = len - max(dot1, dot2) - 3; i >= 0; i -= 3)
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
			s.erase(0, 1); 
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
		Num* n1;
		Num* n2;
		input(1, s1);
		input(2, s2);
		(dot1 > dot2 ? s2 : s1).append(abs(dot1 - dot2), '0'); //
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		n1 = str_to_num(s1);
		n2 = str_to_num(s2);
		if ((ope == '+' && !neg1 && !neg2) || (ope == '-' && !neg1 && neg2)) //
		{
			Num* sum;
			sum = add(n1, n2);
			output(sum);
		}
		else if ((ope == '+' && neg1 && neg2) || (ope == '-' && neg1 && !neg2)) //
		{
			Num* sum;
			sum = add(n1, n2);
			cout << "-";
			output(sum);
		}
		else if ((ope == '+' && !neg1 && neg2) || (ope == '-' && !neg1 && !neg2)) //
		{
			bool flag = compare(s1, s2);
			if (flag)
			{
				Num* result;
				result = sub(n1, n2);
				output(result);
			}
			else
			{
				Num* result;
				result = sub(n2, n1);
				cout << "-";
				output(result);
			}
		}
		else if ((ope == '+' && neg1 && !neg2) || (ope == '-' && neg1 && neg2)) //
		{
			bool flag = compare(s1, s2);
			if (flag)
			{
				Num* result;
				result = sub(n1, n2);
				cout << "-";
				output(result);
			}
			else
			{
				Num* result;
				result = sub(n2, n1);
				output(result);
			}
		}
	}
}