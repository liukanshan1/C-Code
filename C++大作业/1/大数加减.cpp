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
	int n;  //����int��Χȷ�����9������
	Num* next;
};

//��������
void input(int n, string& s)
{
	char temp;
	temp = getchar();
	if (int(temp) == 10) //������һ�лس�
	{
		temp = getchar();
	}
	while (int(temp) != 10) //�س���10���յ��س�ʱֹͣ
	{
		if (int(temp) == 45)  //������45
		{
			(n == 1 ? neg1 : neg2) = true;
			temp = getchar();
		}
		if (int(temp) != 44) //������44�����Զ���
		{
			s += temp;
		}
		temp = getchar();
	}
	reverse(s.begin(), s.end());
}
//�ַ���ת����
Num* str_to_num(const string& s)
{
	//������������
	Num* head = new Num;
	Num* pre = head;
	//ÿ9λһ�飬������������
	int len=s.length();
	for (int i = 0; i < len; i += 9)
	{
		string temp(s, i, 9);
		reverse(temp.begin(), temp.end());
		Num* p = new Num;  //�����µ����ֽڵ�
		p->n = stoi(temp);
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
//����ת�ַ���
string num_to_str(Num* head)
{
	string s;
	Num* p = head->next;
	while (p != NULL)
	{
		string str = to_string(p->n);
		while (p != head->next && str.length() % 9 != 0)
		{
			str.insert(0, "0"); //����0
		}
		reverse(str.begin(), str.end());
		s += str;
		p = p->next;
	}
	reverse(s.begin(), s.end());
	return s;
}
//�ӷ���
Num* add(Num* head1, Num* head2)
{
	bool flag = false; //�����ж��Ƿ��λ
	Num* p1 = head1->next;
	Num* p2 = head2->next;
	//���ɽ������
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
		Num* p = new Num;  //�����µ����ֽڵ�
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
		Num* p = new Num;  //�����µ����ֽڵ�
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}

	return head;
}
//�Ƚ����־���ֵ��С
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
		return true; //�������
	}
}
//������
Num* sub(Num* head1, Num* head2)
{
	bool flag = false; //�����ж��Ƿ���Ҫ��λ
	Num* p1 = head1->next;
	Num* p2 = head2->next;
	//���ɽ������
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
		Num* p = new Num;  //�����µ����ֽڵ�
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
		Num* p = new Num;  //�����µ����ֽڵ�
		p->n = t;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
//������
void output(Num* head)
{
	string s = num_to_str(head);
	while (s[0]=='0')
	{
		s.erase(0, 1);
	}
	int len = s.length();
	for (int i = len - 3; i > 0; i -= 3) //���붺��
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
		if ((ope == '+' && !neg1 && !neg2) || (ope == '-' && !neg1 && neg2)) //���������� ����������
		{
			Num* sum;
			sum = add(n1, n2);
			output(sum);
		}
		else if ((ope == '+' && neg1 && neg2) || (ope == '-' && neg1 && !neg2)) //�����Ӹ��� ����������
		{
			Num* sum;
			sum = add(n1, n2);
			cout << "-";
			output(sum);
		}
		else if ((ope == '+' && !neg1 && neg2) || (ope == '-' && !neg1 && !neg2)) //�����Ӹ��� ����������
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
		else if ((ope == '+' && neg1 && !neg2) || (ope == '-' && neg1 && neg2)) //���������� ����������
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
