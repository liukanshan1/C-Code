#include <iostream>
using namespace std;
int main()
{
	int n = 99;
	int temp[99];
	//ц╟ещеепР
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (temp[i] > temp[j])
			{
				int temp1 = temp[i];
				temp[i] = temp[j];
				temp[j] = temp1;
			}
		}
	}
}