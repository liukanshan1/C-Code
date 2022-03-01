#include <iostream>
using namespace std;
int main()
{
	int b;
	while (cin >> b)
	{
		int a = 1, d;
		int temp0, temp1, temp2;

		d = 1;
		for (int j = 0; j > -1; j++)
		{
			temp1 = d + j;
			if (temp1 > b)
			{
				break;
			}
			else
			{
				d = temp1;
				temp2 = d;
				cout << temp2;
				for (int i = j + 2; i > 0; i++)
				{
					temp0 = temp2 + i;
					if (temp0 > b)
					{
						cout << endl;
						break;
					}
					else
					{
						temp2 = temp0;
						cout << " " << temp2;
					}
				}
			}

		}

	}

}