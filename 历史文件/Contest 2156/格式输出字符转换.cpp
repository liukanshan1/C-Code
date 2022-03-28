#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int line = s.length() / 16;
		for (int i = 0; i < line; i++)
		{
			string str = string(s, i * 16, 16);
			cout << setfill('0') << setw(8) << setbase(10) << (i + 1) * 10;
			cout << "  ";
			for (int j = 0; j < 16; j++)
			{
				cout << setfill('0') << setw(2)<< setbase(16)<<(int)str[j];
				cout << " ";
			}
			cout << " " << str << endl;
		}
	}
}