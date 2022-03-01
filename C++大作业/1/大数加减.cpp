#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

bool neg1, neg2;
string s1, s2;
int length;

struct Num
{
	int n;  //根据int范围确定存放9个数字
	Num* next;
};

//读入数字
void input(int n, string& s)
{
	char temp;
	temp = getchar();
	if (int(temp) == 10) //忽略上一行回车
	{
		temp = getchar();
	}
	while (int(temp) != 10) //回车是10，收到回车时停止
	{
		if (int(temp) == 45)  //负号是45
		{
			(n == 1 ? neg1 : neg2) = true;
			temp = getchar();
		}
		if (int(temp) != 44) //逗号是44，忽略逗号
		{
			s += temp;
		}
		temp = getchar();
	}
	reverse(s.begin(), s.end());
}
//字符串转数字
Num* str_to_num(const string& s)
{
	//生成数字链表
	Num* head = new Num;
	Num* pre = head;
	//每9位一组，加入数字链表
	int len=s.length();
	for (int i = 0; i < len; i += 9)
	{
		string temp(s, i, 9);
		reverse(temp.begin(), temp.end());
		Num* p = new Num;  //生成新的数字节点
		p->n = stoi(temp);
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
//数字转字符串
string num_to_str(Num* head)
{
	string s;
	Num* p = head->next;
	while (p != NULL)
	{
		string str = to_string(p->n);
		while (p != head->next && str.length() % 9 != 0)
		{
			str.insert(0, "0"); //补充0
		}
		reverse(str.begin(), str.end());
		s += str;
		p = p->next;
	}
	reverse(s.begin(), s.end());
	return s;
}
//加法器
Num* add(Num* head1, Num* head2)
{
	bool flag = false; //用于判断是否进位
	Num* p1 = head1->next;
	Num* p2 = head2->next;
	//生成结果链表
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
		length++;
		Num* p = new Num;  //生成新的数字节点
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
		length++;
		Num* p = new Num;  //生成新的数字节点
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}

	return head;
}
//比较数字绝对值大小
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
		return true; //两数相等
	}
}
//减法器
Num* sub(Num* head1, Num* head2)
{
	bool flag = false; //用于判断是否需要借位
	Num* p1 = head1->next;
	Num* p2 = head2->next;
	//生成结果链表
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
		length++;
		Num* p = new Num;  //生成新的数字节点
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1)
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
		length++;
		Num* p = new Num;  //生成新的数字节点
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
//输出结果
void output(Num* head)
{
	string s = num_to_str(head);
	while (s[0]=='0')
	{
		s.erase(0, 1);
	}
	int len = s.length();
	for (int i = len - 3; i > 0; i -= 3) //插入逗号
	{
		s.insert(i, ",");
	}
	cout << s;
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		length = 0;
		s1.erase(0);
		s2.erase(0);
		neg1 = false;
		neg2 = false;
		char ope;
		cin >> ope;
		input(1,s1);
		input(2,s2);
		Num* n1;
		Num* n2;
		n1 = str_to_num(s1);
		n2 = str_to_num(s2);
		if ((ope == '+' && !neg1 && !neg2) || (ope == '-' && !neg1 && neg2)) //正数加正数 正数减负数
		{
			Num* sum;
			sum = add(n1, n2);
			output(sum);
		}
		else if ((ope == '+' && neg1 && neg2) || (ope == '-' && neg1 && !neg2)) //负数加负数 负数减正数
		{
			Num* sum;
			sum = add(n1, n2);
			cout << "-";
			output(sum);
		}
		else if ((ope == '+' && !neg1 && neg2) || (ope == '-' && !neg1 && !neg2)) //正数加负数 正数减正数
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
		else if ((ope == '+' && neg1 && !neg2) || (ope == '-' && neg1 && neg2)) //负数加正数 负数减负数
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
