#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
#include<algorithm>
#include <map>
#include <queue>
using namespace std;

class String
{
public:
	String(int len) { s.resize(len); }
	String() {}
	friend istream& operator>>(istream& in, String& str);
	bool isPalindrome() const{
		string temp = s;
		reverse(temp.begin(), temp.end());
		if (temp==s)
		{
			return true;
		}

		for (int i = 0; i < s.length(); i++)
		{
			string str = s;
			str.erase(i, 1);
			temp = str;
			reverse(temp.begin(), temp.end());
			if (temp == str)
			{
				return true;
			}
		}
		return false;
	}
	bool isIsomorphic(String& str) {
		int len = s.length();
		if (s.length() != str.s.length())
		{
			return false;
		}
		if (len == 0)
		{
			return true;
		}
		map<char, int> mp1;
		map<char, int> mp2;
		for (auto c : s)
		{
			mp1[c]++;
		}
		for (auto c : str.s)
		{
			mp2[c]++;
		}
		priority_queue<int> q1, q2;
		for (auto it : mp1)
		{
			q1.push(it.second);
		}
		for (auto it : mp2)
		{
			q2.push(it.second);
		}

		if (q1.size()!=q2.size())
		{
			return false;
		}
		while (q1.size()!=0)
		{
			if (q1.top() != q2.top())
			{
				return false;
			}
			q1.pop();
			q2.pop();
		}
		return true;
	}
private:
	string s;
};

istream& operator>>(istream& in, String& str)
{
	in >> str.s;
	return in;
}

int main() {

	int n, m;
	while (cin >> n) {

		String s1(n);
	
		cin >> s1;

		cout << s1.isPalindrome() << endl;

		cin >> m;
		String s2(m);
		cin >> s2;

		cout << s2.isIsomorphic(s1) << endl;
	}
	return 0;
}