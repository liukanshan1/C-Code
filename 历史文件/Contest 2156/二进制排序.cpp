#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int count1 = a.length() / 8, count2 = b.length() / 8;
		int* num = new int[count1 + count2];
		for (int i = 0; i < count1; i++)
		{
			num[i] = stoi(string(a, i * 8, 8));
		}
		for (int i = count1; i < count1 + count2; i++)
		{
			num[i] = stoi(string(b, (i - count1) * 8, 8));
		}
		int i = 0;
		for (int i = 0; i < count1 + count2 - 1; i++)
		{
			for (int j = i + 1; j < count1 + count2; j++)
			{
				if (num[i] > num[j])
				{
					int temp = num[i];
					num[i] = num[j];
					num[j] = temp;
				}
			}
		}
		for (int i = 0; i < count1 + count2; i++)
		{
			cout << setfill('0') << setw(8) << num[i];
		}
		cout << endl;
	}
}
