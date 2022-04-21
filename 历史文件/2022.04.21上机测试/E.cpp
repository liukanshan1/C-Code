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
		if (s.length() != str.s.length())
		{
			return false;
		}
		int len = s.length();
		if (len==0)
		{
			return true;
		}
		map<char, int> mp1;
		map<char, int> mp2;
		auto it1 = mp1.begin();
		auto it2 = mp2.begin();
		for (int i = 0; i < len; i++)
		{
			if ((it1 = mp1.find(s[i]) )!= mp1.end())
			{
				mp1[s[i]] += 1;
			}
			else
			{
				mp1.insert(make_pair(s[i], 1));
			}
			if ((it2 = mp2.find(str.s[i]))!= mp2.end())
			{
				mp2[str.s[i]] += 1;
			}
			else
			{
				mp2.insert(make_pair(str.s[i], 1));
			}
		}
		priority_queue<int> q1, q2;
		for (auto it = mp1.begin();it!=mp1.end();it++)
		{
			q1.push(it->second);
		}
		for (auto it = mp2.begin(); it != mp2.end(); it++)
		{
			q2.push(it->second);
		}
		if (q1.size()!=q2.size())
		{
			return false;
		}
		while (q1.size()!=0)
		{
			int a, b;
			a = q1.top();
			b = q2.top();
			q1.pop();
			q2.pop();
			if (a!=b)
			{
				return false;
			}
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