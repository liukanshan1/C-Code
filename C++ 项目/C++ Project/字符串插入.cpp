#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	int x;
	while (cin>>s1>>s2>>x)
	{
		s1.insert(x, s2);
		cout << s1 << endl;
	}
}