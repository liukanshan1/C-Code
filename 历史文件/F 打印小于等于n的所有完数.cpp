#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 1;
		for (int num = 3; num <= n; num++)
		{
			for (int i = 2; i < num; i++)
			{
				if (num % i == 0)//��num/iû������ʱ��˵��i��num��һ������
				{
					sum = sum + i;
				}

			}
			if (sum == num)
			{
				cout << num << " ";
			}
			else
			{
				sum = 1;
			}
		}
	}

	return 0;
}