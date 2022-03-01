#include <iostream>
using namespace std;
int main()
{
	int num;
	while (cin >> num)
	{
		for (int i = 2; i <= num; i++)
		{
			while (num != i)				//先确定num不等于2
				if (num % i == 0)           //当num/i没有余数时，说明i是num的一个质数
				{
					cout << i << " ";       //输出i
					num = num / i;			//取num/i整数部分
				}
				else break;					//然后跳出，重新来，此时num变了，i也变成2了，因为重新开始
		}
		cout << num << " " << endl;
	}
	return 0;
}