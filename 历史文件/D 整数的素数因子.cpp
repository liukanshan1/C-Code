#include <iostream>
using namespace std;
int main()
{
	int num;
	while (cin >> num)
	{
		for (int i = 2; i <= num; i++)
		{
			while (num != i)				//��ȷ��num������2
				if (num % i == 0)           //��num/iû������ʱ��˵��i��num��һ������
				{
					cout << i << " ";       //���i
					num = num / i;			//ȡnum/i��������
				}
				else break;					//Ȼ������������������ʱnum���ˣ�iҲ���2�ˣ���Ϊ���¿�ʼ
		}
		cout << num << " " << endl;
	}
	return 0;
}