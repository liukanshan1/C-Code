#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int pre = s.length(), now;
	while ((now = s.rfind(' ',s.length()-1)) != string::npos)
	{
		cout<<s.substr(now+1, pre-now-1)<<" ";
		s.erase(now, 1);
		pre = now;
	}
	cout << s.substr(0, pre) << endl;
}
