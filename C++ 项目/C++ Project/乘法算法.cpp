#include <iostream>
#include <string>
using namespace std;

int dot1, dot2;
bool neg1, neg2;
string s1, s2;

struct Num
{
	int n;  //����int��Χȷ�����9������
	Num* next;
};

//ȫ�ֱ�����ʼ��
void start()
{
	s1.erase(0);
	s2.erase(0);
	dot1 = 0;
	dot2 = 0;
	neg1 = false;
	neg2 = false;
}
//��������
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
	int len1 = s1.length(), len2 = s2.length();
	for (int i = 0; i < len1; i++)
	{
		if (s1[i] == '.')
		{
			s1.erase(i, 1);
			dot1 = len1 - i - 1;
			break;
		}
	}
	for (int i = 0; i < len2; i++)
	{
		if (s2[i] == '.')
		{
			s2.erase(i, 1);
			dot2 = len2 - i - 1;
			break;
		}
	}
}
//����string�ļӷ���
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
//����string�ļ�����
string sub(string num1, string num2) //num1>num2
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
//����karatsuba�㷨�ĳ˷���
string karatsuba(string num1, string num2)
{
	//�ݹ���ֹ����
	int size1 = num1.length();
	int size2 = num2.length();
	if (size1 == 1 || size2 == 1) return to_string(stoi(num1) * stoi(num2));

	// �����ֳ���
	int halfN = max(size1, size2) / 2;

	// ���Ϊa, b, c, d
	string a = num1.substr(0, size1 - halfN);
	string b = num1.substr(size1 - halfN);
	string c = num2.substr(0, size2 - halfN);
	string d = num2.substr(size2 - halfN);

	//cout << a << " " << b << " " << " " << c << " " << d << endl;
	// ����z2, z0, z1, �˴��ĳ˷�ʹ�õݹ�
	string z2 = karatsuba(a, c);
	string z0 = karatsuba(b, d);
	string z1 = sub(sub(karatsuba(add(a, b), add(c, d)), z0), z2);

	return add(add(z2.append(2 * halfN, '0'), z1.append(halfN, '0')), z0);
}
//�ַ���ת��������
Num* str_to_num(const string& s)
{
	//������������
	Num* head = new Num;
	Num* pre = head;
	//ÿ9λһ�飬������������
	int len = s.length();
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
//��������ת�ַ���
string num_to_str(Num* head)
{
	string s;
	Num* p = head->next;
	while (p != NULL)
	{
		string str = to_string(p->n);
		while (str.length() % 9 != 0)
		{
			str.insert(0, "0"); //����0
		}
		//cout << str << endl;
		reverse(str.begin(), str.end());
		s += str;
		p = p->next;
	}
	reverse(s.begin(), s.end());
	return s;
}
//������
void output(string s)
{
	//string s = num_to_str(head);
	cout << "test:" << s << endl;
	int len = s.length();
	if (dot1 || dot2) //���С����Ͷ���
	{
		s.insert(len - dot1 - dot2, ".");
		while (s[0] == '0' && s.length() != 1 && s[1] != '.')
		{
			s.erase(0, 1); //ɾ����λ0
		}
		len = s.length();
		for (int i = len - dot1 - dot2 - 4; i > 0; i -= 3)
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
	else //û��С����
	{
		while (s[0] == '0' && s.length() != 1)
		{
			s.erase(0, 1); //ɾ����λ�����0
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
		input();
		/*reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		n1 = str_to_num(s1);
		n2 = str_to_num(s2);*/
		if (ope == '*')
		{
			string result = karatsuba(s1, s2);
			if ((neg1 && !neg2) || (!neg1 && neg2))
			{
				cout << "-";
			}
			output(result);

		}
		else if (ope == '/')
		{

		}

	}
}