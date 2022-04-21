#include<iostream>
#include<string>
using namespace std;

class String
{
public:
	String(int n)
	{
		s.clear();
		length = n;
	}
	friend istream& operator>> (istream& input, String& a)
	{
		input >> a.s;
		return input;
	}


	bool check()
	{
		int t = length - 1;
		for (int i = 0; i < t; i++)
		{
			if (s[i] != s[t])
			{
				return false; break;
			}
			t--;
		}
		return true;
	}

	bool isPalindrome()
	{
		if (check()) return true;
		else
		{
			bool flag;
			string temp = s;
			int t = length - 2;
			for (int j = 0; j < length; j++)
			{
				temp = s;
				flag = true;
				t = length - 2;
				temp.erase(j, 1);
				for (int i = 0; i < t; i++)
				{
					if (temp[i] != temp[t])
					{
						flag = false; break;
					}
					t--;
				}
				if (flag) { return true; break; }
			}
			return false;
		}
	}
	bool isIsomorphic(String s1)
	{
		int a[128]; int b[128];
		for (int i = 0; i < 128; i++)
		{
			a[i] = 0; b[i] = 0;
		}
		if (this->length != s1.length) return false;

		for (int i = 0; i < this->length; i++)
		{
			if (a[this->s[i]] != b[s1.s[i]]) return false;
			a[this->s[i]] = i;
			b[s1.s[i]] = i;
		}
		return true;

	}


	string s;
	int length;

};

int main() {

	int n, m;
	while (cin >> n) {
		//构造函数 
		String s1(n);
		//输入字符串的元素, 重载operator>> 
		cin >> s1;

		cout << s1.isPalindrome() << endl;

		cin >> m;
		String s2(m);
		cin >> s2;

		cout << s2.isIsomorphic(s1) << endl;
	}
	return 0;
}